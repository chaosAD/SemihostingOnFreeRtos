/**
 * References:
 * [1] https://github.com/embedded2015/freertos-bufbomb/blob/master/src/host.c
 * [2] http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0471c/Bgbjhiea.html
 * [3] http://albert-oma.blogspot.my/2012/04/semihosting.html
 */

#include <string.h>
#include "host.h"

typedef union param_t param;
union param_t {
    int pdInt;
    void *pdPtr;
    char *pdChrPtr;
};


/*action will be in r0, and argv in r1*/
int host_call(HostSysCall action, void *argv) {
    /* For Thumb-2 code use the BKPT instruction instead of SWI.
* Refer to:
* http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0471c/Bgbjhiea.html
* http://en.wikipedia.org/wiki/ARM_Cortex-M#Cortex-M4 */
    int result;
    __asm__( \
      "bkpt 0xAB\n"\
      "nop\n" \
      "bx lr\n"\
        :"=r" (result) ::\
    );
    return result;
}

int hostSysWriteString(char *str) {
  return host_call(SYS_WRITE0, (param []){{.pdChrPtr=str}});
}

int host_system(char *cmd) {
  return host_call(SYS_SYSTEM, (param []){{.pdChrPtr=cmd}, {.pdInt=strlen(cmd)}});
}
