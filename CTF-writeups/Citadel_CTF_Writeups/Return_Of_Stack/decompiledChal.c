#include "out.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00401020(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int system(char *__command)

{
  int iVar1;
  
  iVar1 = system(__command);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  int iVar1;
  
  iVar1 = setvbuf(__stream,__buf,__modes,__n);
  return iVar1;
}



undefined8 main(void)

{
  puts(banner);
  setvbuf(stdout,(char *)0x0,2,0);
  vuln();
  return 0;
}



void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void _dl_relocate_static_pie(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x004010fd)
// WARNING: Removing unreachable block (ram,0x00401109)

void FUN_004010f0(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x0040113f)
// WARNING: Removing unreachable block (ram,0x0040114b)

void FUN_00401120(void)

{
  return;
}



void _FINI_0(void)

{
  if (DAT_00404058 == '\0') {
    FUN_004010f0();
    DAT_00404058 = 1;
    return;
  }
  return;
}



void _INIT_0(void)

{
  FUN_00401120();
  return;
}



void win(void)

{
  system("cat flag.txt");
  puts("you got the solve!");
  return;
}



void vuln(void)

{
  char acStack_48 [72];
  
  puts("hahaha vro is cooked.");
  fgets(acStack_48,200,stdin);
  return;
}



void _fini(void)

{
  return;
}


