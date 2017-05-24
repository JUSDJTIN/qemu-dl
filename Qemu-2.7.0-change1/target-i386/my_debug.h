#ifndef _MY_DEBUG_H
#define _MY_DEBUG_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
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

/*********************SAVE MESSAGE CONFIG***************************/
#define saveallow 1

const char * SAVEPATH ="/home/yc/CAS/log/";

static inline void itoa (int n,char s[])
{
int i,j,sign;
if((sign=n)<0)//记录符号
n=-n;//使n成为正数
i=0;
do{
      s[i++]=n%10+'0';//取下一个数字
}
while ((n/=10)>0);//删除该数字
if(sign<0)
s[i++]='-';
s[i]='\0';
for(j=i;j>=0;j--)//生成的数字是逆序的，所以要逆序输出
     ; // printf("%c",s[j]);
}

static inline void printf_debug(const char  *Path,
                  int DebugAllow, signed int NeedData,const char * name,int num) 
{
    int error; 
    if (unlikely(DebugAllow == 0)) 
        return ;
    struct timeval tt;
    struct tm* p;
    time_t timep;
    time(&timep);
    p = gmtime(&timep);
    gettimeofday(&tt,NULL);
    char s[500] = "";

    char *Temp = NULL;
    char str[25];
//    char str1[25];
    //Temp = (char*)malloc(sizeof(char)*1024);
    Temp = (char*)calloc(1024,sizeof(char*));
    itoa(num,str);
    if (strlen(str) == 2){
            char temp;
            temp = str[0];
            str[0] = str[1];
            str[1] = temp;
        }
    if (strlen(str) == 3){
           char temp;
           temp = str[0];
           str[0] = str[2];
           str[2] = temp;
       }
    strcat (Temp,Path);
    strcat (Temp,name);
    strcat (Temp,"_");
    strcat (Temp,str);
    strcat (Temp,".log");
//    printf("path is %s\n",Temp);

    int fd = open(Temp,O_RDWR | O_CREAT | O_APPEND,
                  S_IRUSR | S_IWUSR );
//    printf(" start writing..... time is %d/%d/%d %d:%d:%d:%ld\n",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,
//p->tm_hour,p->tm_min,p->tm_sec,tt.tv_usec);
    sprintf(s, "%s is 0x%x time is %d/%d/%d %d:%d:%d:%ld\n",name,NeedData,(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,
(p->tm_hour+8)%24,p->tm_min,p->tm_sec,tt.tv_usec);
    error = write(fd,s,strlen(s));
    if (unlikely(error == 0)){
        printf("[error]: write file error");
        return;
    }
//    printf(" write success..... time is %d/%d/%d %d:%d:%d:%ld\n",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,
//p->tm_hour,p->tm_min,p->tm_sec,tt.tv_usec);

    free(Temp);
    Temp = NULL;
    close(fd);
}
static inline void GetTimeYC(void)
{

    struct timeval tt;
    struct tm* p;
    time_t timep;
    time(&timep);
    p = gmtime(&timep);
    gettimeofday(&tt,NULL);
    printf("time is %d/%d/%d %d:%d:%d:%ld\n",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,
(p->tm_hour+8)%24,p->tm_min,p->tm_sec,tt.tv_usec);
}

#endif // MY_DEBUG_H
