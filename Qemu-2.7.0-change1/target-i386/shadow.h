#ifndef _SHADOW_H
#define _SHADOW_H
/*******************debug config****************/

#define DEBUG_QEMU_TRANS_MODE           1

#define  ALLOW_CALL_OPEN                1
#define  TB_FIND_FAST                   1
#define  DISAS_INSN                     0
#define  CPU_EXEC                       0 
#define  TRANSLATE                      1 

//void printf_debug(char *Path,
//                  int DebugAllow, signed int NeedData);

/*********************SHADOW_STACK CONFIG***************************/
#define SHADOWSTACK                     0    //yc 
#define SAFEINS                         0 



#endif //SHADOW_H 
