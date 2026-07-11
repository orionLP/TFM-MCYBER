import abc
import enum
import subprocess

@dataclasses.dataclass
class Compier():
    compiler_name: str
    compiler_command: str


@dataclasses.dataclass
class Machine():
    target_flag: str

class TargetMachines(enum.Enum):
    I686PCWindowsGNU = Machine("i686-pc-windows-gnu")

@dataclasses.dataclass
class Library():
    library_name: str
    library_flag: str

class AvailableLibraries(enum.Enum):
    ACTIVEDS = Library("activeds", "-lactiveds")
    ADSLDPC = Library("adsldpc", "-ladsldpc")
    ADVAPI32 = Library("advapi32", "-ladvapi32")
    AUTHZ = Library("authz", "-lauthz")
    AVRT = Library("avrt", "-lavrt")
    BCRYPT = Library("bcrypt", "-lbcrypt")
    BTHPROPS = Library("bthprops", "-lbthprops")
    CFGMGR32 = Library("cfgmgr32", "-lcfgmgr32")
    CLFSW32 = Library("clfsw32", "-lclfsw32")
    CLUSAPI = Library("clusapi", "-lclusapi")
    CMUTIL = Library("cmutil", "-lcmutil")
    COMCTL32 = Library("comctl32", "-lcomctl32")
    COMDLG32 = Library("comdlg32", "-lcomdlg32")
    CRYPT32 = Library("crypt32", "-lcrypt32")
    CRYPTXML = Library("cryptxml", "-lcryptxml")
    D2D1 = Library("d2d1", "-ld2d1")
    D3D10 = Library("d3d10", "-ld3d10")
    D3D11 = Library("d3d11", "-ld3d11")
    D3D8 = Library("d3d8", "-ld3d8")
    D3D9 = Library("d3d9", "-ld3d9")
    D3DCOMPILER = Library("d3dcompiler", "-ld3dcompiler")
    D3DRM = Library("d3drm", "-ld3drm")
    D3DX9_38 = Library("d3dx9_38", "-ld3dx9_38")
    DAVCLNT = Library("davclnt", "-ldavclnt")
    DAVHLPR = Library("davhlpr", "-ldavhlpr")
    DDRAW = Library("ddraw", "-lddraw")
    DHCPCSVC = Library("dhcpcsvc", "-ldhcpcsvc")
    DHCPCSVC6 = Library("dhcpcsvc6", "-ldhcpcsvc6")
    DHCPSAPI = Library("dhcpsapi", "-ldhcpsapi")
    DINPUT = Library("dinput", "-ldinput")
    DISMAPI = Library("dismapi", "-ldismapi")
    DLCAPI = Library("dlcapi", "-ldlcapi")
    DNSAPI = Library("dnsapi", "-ldnsapi")
    DPLAYX = Library("dplayx", "-ldplayx")
    DPNADDR = Library("dpnaddr", "-ldpnaddr")
    DPNET = Library("dpnet", "-ldpnet")
    DPNLOBBY = Library("dpnlobby", "-ldpnlobby")
    DSOUND = Library("dsound", "-ldsound")
    DSROLE = Library("dsrole", "-ldsrole")
    DSSEC = Library("dssec", "-ldssec")
    DWMAPI = Library("dwmapi", "-ldwmapi")
    DWRITE = Library("dwrite", "-ldwrite")
    DXVA2 = Library("dxva2", "-ldxva2")
    EAPPCFG = Library("eappcfg", "-leappcfg")
    EAPPGNUI = Library("eappgnui", "-leappgnui")
    EAPPPRXY = Library("eappprxy", "-leappprxy")
    ELSCORE = Library("elscore", "-lelscore")
    EVR = Library("evr", "-levr")
    FAULTREP = Library("faultrep", "-lfaultrep")
    FWPUCLNT = Library("fwpuclnt", "-lfwpuclnt")
    GDI32 = Library("gdi32", "-lgdi32")
    GLAUX = Library("glaux", "-lglaux")
    HTTPAPI = Library("httpapi", "-lhttpapi")
    IMM32 = Library("imm32", "-limm32")
    IPHLPAPI = Library("iphlpapi", "-liphlpapi")
    ISCSIDSC = Library("iscsidsc", "-liscsidsc")
    KERNEL32 = Library("kernel32", "-lkernel32")
    KS = Library("ks", "-lks")
    KSECDD = Library("ksecdd", "-lksecdd")
    KSPROXY = Library("ksproxy", "-lksproxy")
    KTMW32 = Library("ktmw32", "-lktmw32")
    LOGONCLI = Library("logoncli", "-llogoncli")
    M = Library("m", "-lm")
    MAPI32 = Library("mapi32", "-lmapi32")
    MF = Library("mf", "-lmf")
    MFPLAT = Library("mfplat", "-lmfplat")
    MFREADWRITE = Library("mfreadwrite", "-lmfreadwrite")
    MMDEVAPI = Library("mmdevapi", "-lmmdevapi")
    MPR = Library("mpr", "-lmpr")
    MPRAPI = Library("mprapi", "-lmprapi")
    MQRT = Library("mqrt", "-lmqrt")
    MSCMS = Library("mscms", "-lmscms")
    MSCTF = Library("msctf", "-lmsctf")
    MSDMO = Library("msdmo", "-lmsdmo")
    MSDRM = Library("msdrm", "-lmsdrm")
    MSI = Library("msi", "-lmsi")
    MSVCR110 = Library("msvcr110", "-lmsvcr110")
    MSVCRT = Library("msvcrt", "-lmsvcrt")
    NCRYPT = Library("ncrypt", "-lncrypt")
    NDFAPI = Library("ndfapi", "-lndfapi")
    NETAPI32 = Library("netapi32", "-lnetapi32")
    NEWDEV = Library("newdev", "-lnewdev")
    NTDLL = Library("ntdll", "-lntdll")
    NTDSAPI = Library("ntdsapi", "-lntdsapi")
    NTOSKRNL = Library("ntoskrnl", "-lntoskrnl")
    OLE32 = Library("ole32", "-lole32")
    OLEAUT32 = Library("oleaut32", "-loleaut32")
    P2P = Library("p2p", "-lp2p")
    PATHCCH = Library("pathcch", "-lpathcch")
    PENWIN32 = Library("penwin32", "-lpenwin32")
    POWRPROF = Library("powrprof", "-lpowrprof")
    PRNTVPT = Library("prntvpt", "-lprntvpt")
    PROPSYS = Library("propsys", "-lpropsys")
    PSAPI = Library("psapi", "-lpsapi")
    QUARTZ = Library("quartz", "-lquartz")
    QUTIL = Library("qutil", "-lqutil")
    QWAVE = Library("qwave", "-lqwave")
    RASAPI32 = Library("rasapi32", "-lrasapi32")
    RASDLG = Library("rasdlg", "-lrasdlg")
    RESUTIL = Library("resutil", "-lresutil")
    RPCRT4 = Library("rpcrt4", "-lrpcrt4")
    RSTRTMGR = Library("rstrtmgr", "-lrstrtmgr")
    RTUTILS = Library("rtutils", "-lrtutils")
    RUNTIMEOBJECT = Library("runtimeobject", "-lruntimeobject")
    SENSAPI = Library("sensapi", "-lsensapi")
    SETUPAPI = Library("setupapi", "-lsetupapi")
    SHCORE = Library("shcore", "-lshcore")
    SHELL32 = Library("shell32", "-lshell32")
    SLC = Library("slc", "-lslc")
    SPOOLSS = Library("spoolss", "-lspoolss")
    SXS = Library("sxs", "-lsxs")
    SYNCHRONIZATION = Library("synchronization", "-lsynchronization")
    T2EMBED = Library("t2embed", "-lt2embed")
    TAPI32 = Library("tapi32", "-ltapi32")
    TBS = Library("tbs", "-ltbs")
    TXFW32 = Library("txfw32", "-ltxfw32")
    URL = Library("url", "-lurl")
    URLMON = Library("urlmon", "-lurlmon")
    USBCAMD = Library("usbcamd", "-lusbcamd")
    USER32 = Library("user32", "-luser32")
    USERENV = Library("userenv", "-luserenv")
    VDMDBG = Library("vdmdbg", "-lvdmdbg")
    VERSION = Library("version", "-lversion")
    VFW32 = Library("vfw32", "-lvfw32")
    VIRTDISK = Library("virtdisk", "-lvirtdisk")
    VSSAPI = Library("vssapi", "-lvssapi")
    WDSCLIENTAPI = Library("wdsclientapi", "-lwdsclientapi")
    WEBAUTHN = Library("webauthn", "-lwebauthn")
    WECAPI = Library("wecapi", "-lwecapi")
    WER = Library("wer", "-lwer")
    WEVTAPI = Library("wevtapi", "-lwevtapi")
    WIN32K = Library("win32k", "-lwin32k")
    WINDOWSAPP = Library("windowsapp", "-lwindowsapp")
    WINDOWSAPPCOMPAT = Library("windowsappcompat", "-lwindowsappcompat")
    WINDOWSCODECS = Library("windowscodecs", "-lwindowscodecs")
    WINHTTP = Library("winhttp", "-lwinhttp")
    WININET = Library("wininet", "-lwininet")
    WINMM = Library("winmm", "-lwinmm")
    WINPTHREAD = Library("winpthread", "-lwinpthread")
    WINSCARD = Library("winscard", "-lwinscard")
    WINSPOOL = Library("winspool", "-lwinspool")
    WINTRUST = Library("wintrust", "-lwintrust")
    WINUSB = Library("winusb", "-lwinusb")
    WKSCLI = Library("wkscli", "-lwkscli")
    WLANAPI = Library("wlanapi", "-lwlanapi")
    WOW32 = Library("wow32", "-lwow32")
    WS2_32 = Library("ws2_32", "-lws2_32")
    WSDAPI = Library("wsdapi", "-lwsdapi")
    WSNMP32 = Library("wsnmp32", "-lwsnmp32")
    WSOCK32 = Library("wsock32", "-lwsock32")
    WTSAPI32 = Library("wtsapi32", "-lwtsapi32")
    XAUDIO2_8 = Library("xaudio2_8", "-lxaudio2_8")
    XINPUT1_3 = Library("xinput1_3", "-lxinput1_3")

class CompilationHandler(abc.ABC):

    def __init__(self, used_machine: TargetMachines, used_libraries: list[AvailableLibraries]) -> None: 
        self.target = used_machine
        self.libraries = used_libraries
    
    @property
    def target(self) -> TargetMachines:
        self._target_machine

    @target.setter
    def target(self, target_machine: TargetMachines) -> None:
        self._target_machine = target_machine   

    @property
    def libraries(self) -> list[AvailableLibraries]:
        return self._target_libraries
    
    @libraries.setter
    def libraries(self, list_of_libraries: list[AvailableLibraries]) -> None:
        self._target_libraries = list_of_libraries
    
    @abc.abstractmethod
    def compile_file(self, target_file: str, output_file: str | None) -> bool:
        pass

class CompilationFileChecker(FileChecker):

    def __init__(self, library_commands: list[str]) -> None:
        self._libraries = library_commands
    
    def check_file(self, file_path: str) -> bool:
        try:
            cmd = ["clang", "--target=i686-pc-windows-gnu", "-o", "/tmp/tmpfile_compilation_checker.exe"] + self._libraries + [file_path]

            result = subprocess.run(
                cmd,
                capture_output=True,
                timeout=30
            )
 
            return result.returncode == 0
        except Exception as e:
            return False