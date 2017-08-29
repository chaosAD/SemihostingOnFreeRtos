#ifndef __HOST_H
#define __HOST_H

typedef enum HostSysCall HostSysCall;
enum HostSysCall {
    SYS_OPEN=0x01,
    SYS_CLOSE,
    SYS_WRITEC,
    SYS_WRITE0,
    SYS_WRITE,
    SYS_READ,
    SYS_READC,
    SYS_ISERROR,
    SYS_ISTTY,
    SYS_SEEK,
    SYS_FLEN=0xC,
    SYS_TMPNAM,
    SYS_REMOVE,
    SYS_RENAME,
    SYS_CLOCK,
    SYS_TIME,
    SYS_SYSTEM,
    SYS_ERRNO,
    SYS_GET_CMDLINE=0x15,
    SYS_HEAPINFO,
    SYS_ELAPSED=0x30,
    SYS_TICKFREQ
};

int hostSysWriteString(char *str);
int host_system(char *cmd);

#endif /* __HOST_H */
