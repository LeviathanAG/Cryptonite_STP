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

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fclose(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void setbuf(FILE *__stream,char *__buf)

{
  setbuf(__stream,__buf);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

uint alarm(uint __seconds)

{
  uint uVar1;
  
  uVar1 = alarm(__seconds);
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(__filename,__modes);
  return pFVar1;
}



void FUN_00401140(int param_1)

{
                    // WARNING: Subroutine does not return
  exit(param_1);
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



// WARNING: Removing unreachable block (ram,0x0040119d)
// WARNING: Removing unreachable block (ram,0x004011a7)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x004011df)
// WARNING: Removing unreachable block (ram,0x004011e9)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_0 == '\0') {
    deregister_tm_clones();
    completed_0 = 1;
    return;
  }
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



void __constructor__(void)

{
  setbuf(stdin,(char *)0x0);
  setbuf(stdout,(char *)0x0);
  setbuf(stderr,(char *)0x0);
  alarm(0x10);
  return;
}



void duck(void) // ret2win fn

{
  char *pcVar1;
  undefined8 uStack_120;
  char local_118 [256];
  size_t local_18;
  FILE *local_10;
  
  uStack_120 = 0x4012b4;
  local_10 = fopen("flag.txt","r");
  if (local_10 == (FILE *)0x0) {
    uStack_120 = 0x4012ce;
    puts("flag file not found");
    uStack_120 = 0x4012d8;
    FUN_00401140(1);
  }
  uStack_120 = 0x4012f0;
  pcVar1 = fgets(local_118,0x100,local_10);
  if (pcVar1 == (char *)0x0) {
    uStack_120 = 0x401304;
    puts("failed to read flag");
    uStack_120 = 0x401310;
    fclose(local_10);
    uStack_120 = 0x40131a;
    FUN_00401140(1);
  }
  uStack_120 = 0x401326;
  fclose(local_10);
  uStack_120 = 0x401335;
  local_18 = strlen(local_118);
  if ((local_18 != 0) && (local_118[local_18 - 1] == '\n')) {
    local_118[local_18 - 1] = '\0';
  }
  uStack_120 = 0x401382;
  printf("FLAG: %s\n",local_118);
  return;
}



undefined8 main(void)

{
  char local_48 [64];
  
  puts("The Ducks are coming!");
  fgets(local_48,0x50,stdin); // input of 80 into a 64byte buffer
  return 0;
}



void _fini(void)

{
  return;
}



