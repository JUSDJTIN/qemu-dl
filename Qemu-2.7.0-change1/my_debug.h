
/******************debug config******************/

#define DEBUG_QEMU_TRANS_MODE           1

#define  ALLOW_CALL_OPEN                1

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
char *PATH_CALLIP_SUBMIT  = "/home/yc/CAS/call.log";
char *PATH_RETIP_SUBMIT  = "/home/yc/CAS/ret.log";
extern void printf_debug(char *Path,int DebugAllow,signed int NeedData);
