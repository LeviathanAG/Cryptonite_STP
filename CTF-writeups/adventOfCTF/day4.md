# day 4

its a reverse challenge, 


ghidra decomp : 
```c
#include "out.h"



void _DT_INIT(void)

{
  __gmon_start__();
  return;
}



void FUN_00101020(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



void FUN_001010b0(void)

{
  __cxa_finalize();
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

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = strcspn(__s,__reject);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

long ptrace(__ptrace_request __request,...)

{
  long lVar1;
  
  lVar1 = ptrace(__request);
  return lVar1;
}



void __printf_chk(void)

{
  __printf_chk();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



undefined8 _INIT_1(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = ptrace(PTRACE_TRACEME,0,0,0);
  if (lVar1 == -1) {
    puts("Nice try, but Santa sees when you\'re peeking!");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  return param_3;
}



void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  __libc_start_main(&LAB_00101171,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101293)
// WARNING: Removing unreachable block (ram,0x0010129f)

void FUN_00101280(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x001012d4)
// WARNING: Removing unreachable block (ram,0x001012e0)

void FUN_001012b0(void)

{
  return;
}



void _FINI_0(void)

{
  if (DAT_00104018 != '\0') {
    return;
  }
  FUN_001010b0(PTR_LOOP_00104000);
  FUN_00101280();
  DAT_00104018 = 1;
  return;
}



void _INIT_0(void)

{
  FUN_001012b0();
  return;
}



void FUN_00101339(void)

{
  if (DAT_00104008 != -0x21524111) {
    puts("Coal for you! Tampering detected.");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  return;
}



undefined8 FUN_00101362(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if (((int)*(char *)(param_1 + lVar1) ^ 0x42U) != (uint)(byte)(&DAT_00102110)[lVar1]) {
      return 0;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x17);
  return 1;
}



void _DT_FINI(void)

{
  return;
}




```

```
undefined8 FUN_00101362(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if (((int)*(char *)(param_1 + lVar1) ^ 0x42U) != (uint)(byte)(&DAT_00102110)[lVar1]) {
      return 0;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x17);
  return 1;
}
```

we just xor 0x42U with rodata values at 2110 in .rodata.


