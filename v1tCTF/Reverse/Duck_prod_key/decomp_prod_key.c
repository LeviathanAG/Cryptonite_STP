#include "out.h"



void FUN_140001080(longlong param_1,uint param_2)

{
  undefined1 auStack_a8 [32];
  int local_88 [24];
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140008000 ^ (ulonglong)auStack_a8;
  local_88[0] = 0x67452301;
  local_88[1] = 0xefcdab89;
  local_88[2] = 0x98badcfe;
  local_88[3] = 0x10325476;
  local_88[4] = 0;
  local_88[5] = 0;
  FUN_140001e50(local_88,param_1,param_2);
  FUN_140001120(local_28,local_88);
  FUN_140004320(local_18 ^ (ulonglong)auStack_a8);
  return;
}



void FUN_140001120(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  char *pcVar2;
  code *pcVar3;
  undefined8 *puVar4;
  longlong lVar5;
  uint uVar6;
  void *pvVar7;
  code *pcVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  code *pcVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar13 = (uint)param_2[4] >> 3 & 0x3f;
  uVar6 = -uVar13 + 0x3f;
  *(undefined1 *)((longlong)param_2 + (ulonglong)uVar13 + 0x18) = 0x80;
  if (uVar6 < 8) {
    pvVar7 = FUN_140004280();
    for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
        puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
        puVar4 = (undefined8 *)*puVar4) {
      uVar10 = 0;
      lVar5 = puVar4[4];
      uVar16 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
      if (uVar16 != 0) {
        lVar1 = lVar5 + (ulonglong)uVar16;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar11 = 0;
            uVar9 = 0xffffffffffffffff;
            uVar15 = 0xf8757078;
            lVar14 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar16) + lVar5 +
                              uVar10 * 4) + lVar5;
            do {
              uVar9 = uVar9 + 1;
            } while (*(char *)(lVar14 + uVar9) != '\0');
            if (uVar9 != 0) {
              do {
                pcVar2 = (char *)(uVar11 + lVar14);
                uVar11 = uVar11 + 1;
                uVar15 = ((int)*pcVar2 ^ uVar15) * 0x1000193;
              } while (uVar11 < uVar9);
              if (uVar15 == 0xb484139f) {
                pcVar8 = (code *)((ulonglong)
                                  *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                           (ulonglong)
                                           *(ushort *)
                                            ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar10 * 2
                                            ) * 4) + lVar5);
                goto LAB_140001240;
              }
            }
            uVar15 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar15;
          } while (uVar15 < *(uint *)(lVar1 + 0x18));
        }
      }
    }
    pcVar8 = (code *)0x0;
LAB_140001240:
    (*pcVar8)((longlong)param_2 + (ulonglong)uVar13 + 0x19,0,uVar6);
    FUN_140001660(param_2,param_2 + 6);
    pvVar7 = FUN_140004280();
    for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
        puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
        puVar4 = (undefined8 *)*puVar4) {
      lVar5 = puVar4[4];
      uVar6 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
      if (uVar6 != 0) {
        lVar1 = lVar5 + (ulonglong)uVar6;
        uVar10 = 0;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar9 = 0xffffffffffffffff;
            lVar14 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar6) + lVar5 +
                              uVar10 * 4) + lVar5;
            uVar13 = 0xf8757078;
            do {
              uVar9 = uVar9 + 1;
            } while (*(char *)(lVar14 + uVar9) != '\0');
            uVar11 = 0;
            if (uVar9 != 0) {
              do {
                pcVar2 = (char *)(uVar11 + lVar14);
                uVar11 = uVar11 + 1;
                uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
              } while (uVar11 < uVar9);
              if (uVar13 == 0xb484139f) {
                pcVar8 = (code *)((ulonglong)
                                  *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                           (ulonglong)
                                           *(ushort *)
                                            ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar10 * 2
                                            ) * 4) + lVar5);
                goto LAB_140001327;
              }
            }
            uVar13 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar13;
          } while (uVar13 < *(uint *)(lVar1 + 0x18));
        }
      }
    }
    pcVar8 = (code *)0x0;
LAB_140001327:
    (*pcVar8)(param_2 + 6,0,0x38);
  }
  else {
    pvVar7 = FUN_140004280();
    for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
        puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
        puVar4 = (undefined8 *)*puVar4) {
      uVar10 = 0;
      lVar5 = puVar4[4];
      uVar6 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
      if (uVar6 != 0) {
        lVar1 = lVar5 + (ulonglong)uVar6;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar11 = 0;
            uVar9 = 0xffffffffffffffff;
            uVar16 = 0xf8757078;
            lVar14 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar6) + lVar5 +
                              uVar10 * 4) + lVar5;
            do {
              uVar9 = uVar9 + 1;
            } while (*(char *)(lVar14 + uVar9) != '\0');
            if (uVar9 != 0) {
              do {
                pcVar2 = (char *)(uVar11 + lVar14);
                uVar11 = uVar11 + 1;
                uVar16 = ((int)*pcVar2 ^ uVar16) * 0x1000193;
              } while (uVar11 < uVar9);
              if (uVar16 == 0xb484139f) {
                pcVar8 = (code *)((ulonglong)
                                  *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                           (ulonglong)
                                           *(ushort *)
                                            ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar10 * 2
                                            ) * 4) + lVar5);
                goto LAB_140001430;
              }
            }
            uVar16 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar16;
          } while (uVar16 < *(uint *)(lVar1 + 0x18));
        }
      }
    }
    pcVar8 = (code *)0x0;
LAB_140001430:
    (*pcVar8)((longlong)param_2 + (ulonglong)uVar13 + 0x19,0,-uVar13 + 0x37);
  }
  param_2[0x14] = param_2[4];
  param_2[0x15] = param_2[5];
  FUN_140001660(param_2,param_2 + 6);
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    lVar5 = puVar4[4];
    uVar6 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar6 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar6;
      uVar10 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar9 = 0xffffffffffffffff;
          uVar13 = 0xf8757078;
          lVar14 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar6) + lVar5 +
                            uVar10 * 4) + lVar5;
          do {
            uVar9 = uVar9 + 1;
          } while (*(char *)(lVar14 + uVar9) != '\0');
          uVar11 = 0;
          if (uVar9 != 0) {
            do {
              pcVar2 = (char *)(uVar11 + lVar14);
              uVar11 = uVar11 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar11 < uVar9);
            if (uVar13 == 0xee35fd29) {
              pcVar8 = (code *)((ulonglong)
                                *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                         (ulonglong)
                                         *(ushort *)
                                          ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar10 * 2)
                                         * 4) + lVar5);
              goto LAB_14000154c;
            }
          }
          uVar13 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
  pcVar8 = (code *)0x0;
LAB_14000154c:
  UNRECOVERED_JUMPTABLE = (code *)0x0;
  (*pcVar8)(param_1,param_2,0x10);
  pvVar7 = FUN_140004280();
  puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
  do {
    if (puVar4 == *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28)) {
LAB_140001634:
                    // WARNING: Could not recover jumptable at 0x000140001656. Too many branches
                    // WARNING: Treating indirect jump as call
      (*UNRECOVERED_JUMPTABLE)(param_2,0,8);
      return;
    }
    lVar5 = puVar4[4];
    uVar6 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar6 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar6;
      uVar10 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          pcVar8 = (code *)0xffffffffffffffff;
          uVar13 = 0xf8757078;
          lVar14 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar6) + lVar5 +
                            uVar10 * 4) + lVar5;
          do {
            pcVar8 = pcVar8 + 1;
          } while (pcVar8[lVar14] != (code)0x0);
          pcVar12 = UNRECOVERED_JUMPTABLE;
          if (pcVar8 != (code *)0x0) {
            do {
              pcVar3 = pcVar12 + lVar14;
              pcVar12 = pcVar12 + 1;
              uVar13 = ((int)(char)*pcVar3 ^ uVar13) * 0x1000193;
            } while (pcVar12 < pcVar8);
            if (uVar13 == 0xb484139f) {
              UNRECOVERED_JUMPTABLE =
                   (code *)((ulonglong)
                            *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                     (ulonglong)
                                     *(ushort *)
                                      ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar10 * 2) * 4)
                           + lVar5);
              goto LAB_140001634;
            }
          }
          uVar13 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



void FUN_140001660(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  
  uVar20 = param_1[1];
  uVar19 = param_1[2];
  uVar18 = param_1[3];
  iVar1 = *param_2;
  iVar2 = param_2[5];
  iVar3 = param_2[1];
  uVar17 = *param_1 + -0x28955b88 + ((uVar18 ^ uVar19) & uVar20 ^ uVar18) + iVar1;
  uVar17 = (uVar17 >> 0x19 | uVar17 * 0x80) + uVar20;
  iVar4 = param_2[2];
  uVar18 = uVar18 + 0xe8c7b756 + ((uVar19 ^ uVar20) & uVar17 ^ uVar19) + iVar3;
  uVar18 = (uVar18 >> 0x14 | uVar18 * 0x1000) + uVar17;
  iVar5 = param_2[3];
  uVar19 = uVar19 + 0x242070db + ((uVar20 ^ uVar17) & uVar18 ^ uVar20) + iVar4;
  uVar19 = (uVar19 >> 0xf | uVar19 * 0x20000) + uVar18;
  iVar6 = param_2[4];
  uVar20 = uVar20 + 0xc1bdceee + ((uVar18 ^ uVar17) & uVar19 ^ uVar17) + iVar5;
  uVar21 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar19;
  uVar20 = uVar17 + 0xf57c0faf + ((uVar18 ^ uVar19) & uVar21 ^ uVar18) + iVar6;
  iVar7 = param_2[6];
  uVar17 = (uVar20 >> 0x19 | uVar20 * 0x80) + uVar21;
  uVar20 = uVar18 + 0x4787c62a + ((uVar19 ^ uVar21) & uVar17 ^ uVar19) + iVar2;
  uVar20 = (uVar20 >> 0x14 | uVar20 * 0x1000) + uVar17;
  uVar19 = uVar19 + 0xa8304613 + ((uVar21 ^ uVar17) & uVar20 ^ uVar21) + iVar7;
  uVar19 = (uVar19 >> 0xf | uVar19 * 0x20000) + uVar20;
  iVar8 = param_2[7];
  iVar9 = param_2[8];
  iVar10 = param_2[10];
  iVar11 = param_2[0xc];
  iVar12 = param_2[0xd];
  iVar13 = param_2[0xe];
  iVar14 = param_2[9];
  uVar18 = uVar21 + 0xfd469501 + ((uVar20 ^ uVar17) & uVar19 ^ uVar17) + iVar8;
  uVar18 = (uVar18 >> 10 | uVar18 * 0x400000) + uVar19;
  uVar17 = uVar17 + 0x698098d8 + ((uVar20 ^ uVar19) & uVar18 ^ uVar20) + iVar9;
  uVar21 = (uVar17 >> 0x19 | uVar17 * 0x80) + uVar18;
  uVar20 = uVar20 + 0x8b44f7af + ((uVar19 ^ uVar18) & uVar21 ^ uVar19) + iVar14;
  iVar15 = param_2[0xb];
  uVar17 = (uVar20 >> 0x14 | uVar20 * 0x1000) + uVar21;
  uVar20 = (uVar19 - 0xa44f) + ((uVar18 ^ uVar21) & uVar17 ^ uVar18) + iVar10;
  uVar20 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar17;
  uVar19 = uVar18 + 0x895cd7be + ((uVar17 ^ uVar21) & uVar20 ^ uVar21) + iVar15;
  uVar19 = (uVar19 >> 10 | uVar19 * 0x400000) + uVar20;
  uVar18 = uVar21 + 0x6b901122 + ((uVar17 ^ uVar20) & uVar19 ^ uVar17) + iVar11;
  uVar18 = (uVar18 >> 0x19 | uVar18 * 0x80) + uVar19;
  uVar17 = ((uVar20 ^ uVar19) & uVar18 ^ uVar20) + 0xfd987193 + iVar12 + uVar17;
  uVar17 = (uVar17 >> 0x14 | uVar17 * 0x1000) + uVar18;
  uVar20 = uVar20 + 0xa679438e + ((uVar19 ^ uVar18) & uVar17 ^ uVar19) + iVar13;
  iVar16 = param_2[0xf];
  uVar21 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar17;
  uVar19 = ((uVar17 ^ uVar18) & uVar21 ^ uVar18) + 0x49b40821 + iVar16 + uVar19;
  uVar20 = (uVar19 >> 10 | uVar19 * 0x400000) + uVar21;
  uVar18 = uVar18 + ((uVar21 ^ uVar20) & uVar17 ^ uVar21) + 0xf61e2562 + iVar3;
  uVar19 = (uVar18 >> 0x1b | uVar18 * 0x20) + uVar20;
  uVar17 = uVar17 + ((uVar20 ^ uVar19) & uVar21 ^ uVar20) + 0xc040b340 + iVar7;
  uVar18 = (uVar17 >> 0x17 | uVar17 * 0x200) + uVar19;
  uVar21 = uVar21 + ((uVar18 ^ uVar19) & uVar20 ^ uVar19) + 0x265e5a51 + iVar15;
  uVar17 = (uVar21 >> 0x12 | uVar21 * 0x4000) + uVar18;
  uVar20 = uVar20 + 0xe9b6c7aa + ((uVar18 ^ uVar17) & uVar19 ^ uVar18) + iVar1;
  uVar21 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar17;
  uVar20 = uVar19 + 0xd62f105d + ((uVar17 ^ uVar21) & uVar18 ^ uVar17) + iVar2;
  uVar20 = (uVar20 >> 0x1b | uVar20 * 0x20) + uVar21;
  uVar19 = uVar18 + 0x2441453 + ((uVar21 ^ uVar20) & uVar17 ^ uVar21) + iVar10;
  uVar19 = (uVar19 >> 0x17 | uVar19 * 0x200) + uVar20;
  uVar18 = uVar17 + 0xd8a1e681 + ((uVar19 ^ uVar20) & uVar21 ^ uVar20) + iVar16;
  uVar18 = (uVar18 >> 0x12 | uVar18 * 0x4000) + uVar19;
  uVar17 = uVar21 + 0xe7d3fbc8 + ((uVar19 ^ uVar18) & uVar20 ^ uVar19) + iVar6;
  uVar17 = (uVar17 >> 0xc | uVar17 * 0x100000) + uVar18;
  uVar20 = uVar20 + 0x21e1cde6 + ((uVar18 ^ uVar17) & uVar19 ^ uVar18) + iVar14;
  uVar21 = (uVar20 >> 0x1b | uVar20 * 0x20) + uVar17;
  uVar20 = uVar19 + 0xc33707d6 + ((uVar17 ^ uVar21) & uVar18 ^ uVar17) + iVar13;
  uVar20 = (uVar20 >> 0x17 | uVar20 * 0x200) + uVar21;
  uVar19 = uVar18 + 0xf4d50d87 + ((uVar20 ^ uVar21) & uVar17 ^ uVar21) + iVar5;
  uVar19 = (uVar19 >> 0x12 | uVar19 * 0x4000) + uVar20;
  uVar18 = uVar17 + 0x455a14ed + ((uVar20 ^ uVar19) & uVar21 ^ uVar20) + iVar9;
  uVar22 = (uVar18 >> 0xc | uVar18 * 0x100000) + uVar19;
  uVar18 = uVar21 + 0xa9e3e905 + ((uVar19 ^ uVar22) & uVar20 ^ uVar19) + iVar12;
  uVar18 = (uVar18 >> 0x1b | uVar18 * 0x20) + uVar22;
  uVar20 = uVar20 + 0xfcefa3f8 + ((uVar22 ^ uVar18) & uVar19 ^ uVar22) + iVar4;
  uVar17 = (uVar20 >> 0x17 | uVar20 * 0x200) + uVar18;
  uVar20 = uVar19 + 0x676f02d9 + ((uVar17 ^ uVar18) & uVar22 ^ uVar18) + iVar8;
  uVar21 = (uVar20 >> 0x12 | uVar20 * 0x4000) + uVar17;
  uVar20 = uVar22 + 0x8d2a4c8a + ((uVar17 ^ uVar21) & uVar18 ^ uVar17) + iVar11;
  uVar20 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar21;
  uVar18 = uVar18 + ((uVar17 ^ uVar21 ^ uVar20) - 0x5c6be) + iVar2;
  uVar19 = (uVar18 >> 0x1c | uVar18 * 0x10) + uVar20;
  uVar17 = uVar17 + (uVar21 ^ uVar20 ^ uVar19) + 0x8771f681 + iVar9;
  uVar18 = (uVar17 >> 0x15 | uVar17 * 0x800) + uVar19;
  uVar21 = uVar21 + (uVar18 ^ uVar20 ^ uVar19) + 0x6d9d6122 + iVar15;
  uVar17 = (uVar21 >> 0x10 | uVar21 * 0x10000) + uVar18;
  uVar20 = uVar20 + 0xfde5380c + (uVar18 ^ uVar17 ^ uVar19) + iVar13;
  uVar21 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar17;
  uVar20 = uVar19 + 0xa4beea44 + (uVar18 ^ uVar17 ^ uVar21) + iVar3;
  uVar20 = (uVar20 >> 0x1c | uVar20 * 0x10) + uVar21;
  uVar19 = uVar18 + 0x4bdecfa9 + (uVar17 ^ uVar21 ^ uVar20) + iVar6;
  uVar19 = (uVar19 >> 0x15 | uVar19 * 0x800) + uVar20;
  uVar18 = uVar17 + 0xf6bb4b60 + (uVar19 ^ uVar21 ^ uVar20) + iVar8;
  uVar17 = (uVar18 >> 0x10 | uVar18 * 0x10000) + uVar19;
  uVar18 = uVar21 + 0xbebfbc70 + (uVar19 ^ uVar17 ^ uVar20) + iVar10;
  uVar21 = (uVar18 >> 9 | uVar18 * 0x800000) + uVar17;
  uVar20 = uVar20 + 0x289b7ec6 + (uVar19 ^ uVar17 ^ uVar21) + iVar12;
  uVar22 = (uVar20 >> 0x1c | uVar20 * 0x10) + uVar21;
  uVar19 = uVar19 + (uVar17 ^ uVar21 ^ uVar22) + 0xeaa127fa + iVar1;
  uVar18 = (uVar19 >> 0x15 | uVar19 * 0x800) + uVar22;
  uVar17 = uVar17 + (uVar18 ^ uVar21 ^ uVar22) + 0xd4ef3085 + iVar5;
  uVar17 = (uVar17 >> 0x10 | uVar17 * 0x10000) + uVar18;
  uVar20 = uVar21 + 0x4881d05 + (uVar18 ^ uVar17 ^ uVar22) + iVar7;
  uVar19 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar17;
  uVar22 = (uVar18 ^ uVar17 ^ uVar19) + iVar14 + -0x262b2fc7 + uVar22;
  uVar21 = (uVar22 >> 0x1c | uVar22 * 0x10) + uVar19;
  uVar20 = uVar18 + 0xe6db99e5 + (uVar17 ^ uVar19 ^ uVar21) + iVar11;
  uVar20 = (uVar20 >> 0x15 | uVar20 * 0x800) + uVar21;
  uVar18 = uVar17 + 0x1fa27cf8 + (uVar20 ^ uVar19 ^ uVar21) + iVar16;
  uVar18 = (uVar18 >> 0x10 | uVar18 * 0x10000) + uVar20;
  uVar19 = uVar19 + 0xc4ac5665 + (uVar20 ^ uVar18 ^ uVar21) + iVar4;
  uVar17 = (uVar19 >> 9 | uVar19 * 0x800000) + uVar18;
  uVar19 = uVar21 + 0xf4292244 + ((~uVar20 | uVar17) ^ uVar18) + iVar1;
  uVar19 = (uVar19 >> 0x1a | uVar19 * 0x40) + uVar17;
  uVar20 = uVar20 + 0x432aff97 + ((~uVar18 | uVar19) ^ uVar17) + iVar8;
  uVar21 = (uVar20 >> 0x16 | uVar20 * 0x400) + uVar19;
  uVar20 = uVar18 + 0xab9423a7 + ((~uVar17 | uVar21) ^ uVar19) + iVar13;
  uVar20 = (uVar20 >> 0x11 | uVar20 * 0x8000) + uVar21;
  uVar18 = uVar17 + 0xfc93a039 + ((~uVar19 | uVar20) ^ uVar21) + iVar2;
  uVar18 = (uVar18 >> 0xb | uVar18 * 0x200000) + uVar20;
  uVar19 = uVar19 + 0x655b59c3 + ((~uVar21 | uVar18) ^ uVar20) + iVar11;
  uVar17 = (uVar19 >> 0x1a | uVar19 * 0x40) + uVar18;
  uVar19 = uVar21 + 0x8f0ccc92 + ((~uVar20 | uVar17) ^ uVar18) + iVar5;
  uVar19 = (uVar19 >> 0x16 | uVar19 * 0x400) + uVar17;
  uVar20 = (uVar20 - 0x100b83) + ((~uVar18 | uVar19) ^ uVar17) + iVar10;
  uVar22 = (uVar20 >> 0x11 | uVar20 * 0x8000) + uVar19;
  uVar20 = uVar18 + 0x85845dd1 + ((~uVar17 | uVar22) ^ uVar19) + iVar3;
  uVar20 = (uVar20 >> 0xb | uVar20 * 0x200000) + uVar22;
  uVar18 = uVar17 + 0x6fa87e4f + ((~uVar19 | uVar20) ^ uVar22) + iVar9;
  uVar18 = (uVar18 >> 0x1a | uVar18 * 0x40) + uVar20;
  uVar19 = ((~uVar22 | uVar18) ^ uVar20) + 0xfe2ce6e0 + iVar16 + uVar19;
  uVar21 = (uVar19 >> 0x16 | uVar19 * 0x400) + uVar18;
  uVar19 = uVar22 + 0xa3014314 + ((~uVar20 | uVar21) ^ uVar18) + iVar7;
  uVar19 = (uVar19 >> 0x11 | uVar19 * 0x8000) + uVar21;
  uVar20 = uVar20 + 0x4e0811a1 + ((~uVar18 | uVar19) ^ uVar21) + iVar12;
  uVar22 = (uVar20 >> 0xb | uVar20 * 0x200000) + uVar19;
  uVar18 = uVar18 + ((~uVar21 | uVar22) ^ uVar19) + 0xf7537e82 + iVar6;
  uVar17 = (uVar18 >> 0x1a | uVar18 * 0x40) + uVar22;
  uVar20 = uVar21 + 0xbd3af235 + ((~uVar19 | uVar17) ^ uVar22) + iVar15;
  uVar18 = (uVar20 >> 0x16 | uVar20 * 0x400) + uVar17;
  *param_1 = *param_1 + uVar17;
  uVar19 = ((~uVar22 | uVar18) ^ uVar17) + 0x2ad7d2bb + iVar4 + uVar19;
  uVar19 = (uVar19 >> 0x11 | uVar19 * 0x8000) + uVar18;
  param_1[2] = param_1[2] + uVar19;
  uVar20 = uVar22 + 0xeb86d391 + ((~uVar17 | uVar19) ^ uVar18) + iVar14;
  param_1[3] = param_1[3] + uVar18;
  param_1[1] = (uVar20 >> 0xb | uVar20 * 0x200000) + param_1[1] + uVar19;
  return;
}



void FUN_140001e50(int *param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  char *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  code *pcVar7;
  ulonglong uVar8;
  code *pcVar9;
  code *pcVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong *plVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  code *pcVar18;
  code *pcVar19;
  ulonglong uVar20;
  longlong local_res10;
  uint local_res18;
  
  uVar17 = param_1[4];
  uVar15 = uVar17 + param_3 * 8;
  param_1[4] = uVar15;
  if (uVar15 < uVar17) {
    param_1[5] = param_1[5] + 1;
  }
  param_1[5] = param_1[5] + (param_3 >> 0x1d);
  uVar15 = uVar17 >> 3 & 0x3f;
  local_res10 = param_2;
  local_res18 = param_3;
  if (uVar15 != 0) {
    local_res18 = 0x40 - uVar15;
    if (param_3 < local_res18) {
      pvVar6 = FUN_140004280();
      pcVar19 = (code *)0x0;
      plVar13 = *(longlong **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x20);
      plVar3 = *(longlong **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x28);
      if (plVar13 == plVar3) {
LAB_140001fb9:
        (*pcVar19)((longlong)param_1 + (ulonglong)uVar15 + 0x18,param_2,param_3);
        return;
      }
      do {
        lVar4 = plVar13[4];
        uVar17 = *(uint *)((longlong)*(int *)(lVar4 + 0x3c) + 0x88 + lVar4);
        if (uVar17 != 0) {
          lVar1 = lVar4 + (ulonglong)uVar17;
          pcVar18 = pcVar19;
          if (*(uint *)(lVar1 + 0x18) != 0) {
            do {
              pcVar7 = (code *)0xffffffffffffffff;
              uVar16 = 0xf8757078;
              lVar14 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar4 + 0x20 + (ulonglong)uVar17) + lVar4 +
                                (longlong)pcVar18 * 4) + lVar4;
              do {
                pcVar7 = pcVar7 + 1;
              } while (pcVar7[lVar14] != (code)0x0);
              pcVar9 = pcVar19;
              if (pcVar7 != (code *)0x0) {
                do {
                  pcVar10 = pcVar9 + 1;
                  uVar16 = ((int)(char)pcVar9[lVar14] ^ uVar16) * 0x1000193;
                  pcVar9 = pcVar10;
                } while (pcVar10 < pcVar7);
                if (uVar16 == 0xee35fd29) {
                  pcVar19 = (code *)((ulonglong)
                                     *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar4 +
                                              (ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar4 +
                                               (longlong)pcVar18 * 2) * 4) + lVar4);
                  goto LAB_140001fb9;
                }
              }
              uVar16 = (int)pcVar18 + 1;
              pcVar18 = (code *)(ulonglong)uVar16;
            } while (uVar16 < *(uint *)(lVar1 + 0x18));
          }
        }
        plVar13 = (longlong *)*plVar13;
        if (plVar13 == plVar3) {
          (*(code *)0x0)((longlong)param_1 + (ulonglong)uVar15 + 0x18,param_2,param_3);
          return;
        }
      } while( true );
    }
    pvVar6 = FUN_140004280();
    for (puVar5 = *(undefined8 **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x20);
        puVar5 != *(undefined8 **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x28);
        puVar5 = (undefined8 *)*puVar5) {
      lVar4 = puVar5[4];
      uVar17 = *(uint *)((longlong)*(int *)(lVar4 + 0x3c) + 0x88 + lVar4);
      if (uVar17 != 0) {
        lVar1 = lVar4 + (ulonglong)uVar17;
        uVar20 = 0;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar8 = 0xffffffffffffffff;
            lVar14 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar4 + 0x20 + (ulonglong)uVar17) + lVar4 +
                              uVar20 * 4) + lVar4;
            uVar16 = 0xf8757078;
            do {
              uVar8 = uVar8 + 1;
            } while (*(char *)(lVar14 + uVar8) != '\0');
            uVar11 = 0;
            if (uVar8 != 0) {
              do {
                pcVar2 = (char *)(uVar11 + lVar14);
                uVar11 = uVar11 + 1;
                uVar16 = ((int)*pcVar2 ^ uVar16) * 0x1000193;
              } while (uVar11 < uVar8);
              if (uVar16 == 0xee35fd29) {
                pcVar19 = (code *)((ulonglong)
                                   *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar4 +
                                            (ulonglong)
                                            *(ushort *)
                                             ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar4 +
                                             uVar20 * 2) * 4) + lVar4);
                goto LAB_14000209c;
              }
            }
            uVar16 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar16;
          } while (uVar16 < *(uint *)(lVar1 + 0x18));
        }
      }
    }
    pcVar19 = (code *)0x0;
LAB_14000209c:
    (*pcVar19)((longlong)param_1 + (ulonglong)uVar15 + 0x18,param_2,local_res18);
    FUN_140001660(param_1,param_1 + 6);
    local_res10 = param_2 + (ulonglong)local_res18;
    local_res18 = param_3 - local_res18;
  }
  if (0x3f < local_res18) {
    uVar20 = (ulonglong)(local_res18 >> 6);
    do {
      pvVar6 = FUN_140004280();
      for (puVar5 = *(undefined8 **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x20);
          puVar5 != *(undefined8 **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x28);
          puVar5 = (undefined8 *)*puVar5) {
        lVar4 = puVar5[4];
        uVar15 = *(uint *)((longlong)*(int *)(lVar4 + 0x3c) + 0x88 + lVar4);
        if (uVar15 != 0) {
          lVar1 = lVar4 + (ulonglong)uVar15;
          uVar8 = 0;
          if (*(uint *)(lVar1 + 0x18) != 0) {
            do {
              uVar11 = 0xffffffffffffffff;
              lVar14 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar4 + 0x20 + (ulonglong)uVar15) + lVar4 +
                                uVar8 * 4) + lVar4;
              uVar17 = 0xf8757078;
              do {
                uVar11 = uVar11 + 1;
              } while (*(char *)(lVar14 + uVar11) != '\0');
              uVar12 = 0;
              if (uVar11 != 0) {
                do {
                  pcVar2 = (char *)(uVar12 + lVar14);
                  uVar12 = uVar12 + 1;
                  uVar17 = ((int)*pcVar2 ^ uVar17) * 0x1000193;
                } while (uVar12 < uVar11);
                if (uVar17 == 0xee35fd29) {
                  pcVar19 = (code *)((ulonglong)
                                     *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar4 +
                                              (ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar4 +
                                               uVar8 * 2) * 4) + lVar4);
                  goto LAB_1400021c6;
                }
              }
              uVar17 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar17;
            } while (uVar17 < *(uint *)(lVar1 + 0x18));
          }
        }
      }
      pcVar19 = (code *)0x0;
LAB_1400021c6:
      (*pcVar19)(param_1 + 6,local_res10,0x40);
      FUN_140001660(param_1,param_1 + 6);
      local_res10 = local_res10 + 0x40;
      local_res18 = local_res18 - 0x40;
      uVar20 = uVar20 - 1;
    } while (uVar20 != 0);
  }
  pcVar19 = (code *)0x0;
  pvVar6 = FUN_140004280();
  plVar13 = *(longlong **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x20);
  plVar3 = *(longlong **)(*(longlong *)((longlong)pvVar6 + 0x18) + 0x28);
  if (plVar13 != plVar3) {
    do {
      lVar4 = plVar13[4];
      uVar15 = *(uint *)((longlong)*(int *)(lVar4 + 0x3c) + 0x88 + lVar4);
      if (uVar15 != 0) {
        lVar1 = lVar4 + (ulonglong)uVar15;
        uVar20 = 0;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar8 = 0xffffffffffffffff;
            lVar14 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar4 + 0x20 + (ulonglong)uVar15) + lVar4 +
                              uVar20 * 4) + lVar4;
            uVar17 = 0xf8757078;
            do {
              uVar8 = uVar8 + 1;
            } while (*(char *)(lVar14 + uVar8) != '\0');
            uVar11 = 0;
            if (uVar8 != 0) {
              do {
                pcVar2 = (char *)(uVar11 + lVar14);
                uVar11 = uVar11 + 1;
                uVar17 = ((int)*pcVar2 ^ uVar17) * 0x1000193;
              } while (uVar11 < uVar8);
              if (uVar17 == 0xee35fd29) {
                pcVar19 = (code *)((ulonglong)
                                   *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar4 +
                                            (ulonglong)
                                            *(ushort *)
                                             ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar4 +
                                             uVar20 * 2) * 4) + lVar4);
                goto LAB_1400022c4;
              }
            }
            uVar17 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar17;
          } while (uVar17 < *(uint *)(lVar1 + 0x18));
        }
      }
      plVar13 = (longlong *)*plVar13;
    } while (plVar13 != plVar3);
    pcVar19 = (code *)0x0;
  }
LAB_1400022c4:
  (*pcVar19)(param_1 + 6,local_res10,local_res18);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_140002330(undefined8 param_1)

{
  char *pcVar1;
  undefined8 *puVar2;
  longlong lVar3;
  void *pvVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  code *pcVar12;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = DAT_140008000 ^ (ulonglong)auStack_e8;
  local_40 = 0xed5ad7d0;
  local_3c = 0x45780a38;
  local_50 = 0xbf6b0679c35d63c9;
  uStack_48 = 0x38228a88797d3697;
  local_38 = 0x2d10c88c;
  local_80 = param_1;
  local_78 = FUN_1400032a0(0x2d10c88c,(longlong)&local_50,0x1400080d0,0x18);
  local_70 = 0xf26859df;
  local_6c = 0x3d6542;
  local_68 = 0x2d10c88c;
  local_88 = FUN_1400032a0(0x2d10c88c,(longlong)&local_70,0x1400080c4,7);
  pvVar4 = FUN_140004280();
  for (puVar2 = *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x20);
      puVar2 != *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x28);
      puVar2 = (undefined8 *)*puVar2) {
    lVar3 = puVar2[4];
    uVar10 = *(uint *)((longlong)*(int *)(lVar3 + 0x3c) + 0x88 + lVar3);
    if (uVar10 != 0) {
      lVar5 = lVar3 + (ulonglong)uVar10;
      uVar11 = 0;
      if (*(uint *)(lVar5 + 0x18) != 0) {
        do {
          uVar6 = 0xffffffffffffffff;
          lVar8 = (ulonglong)
                  *(uint *)((ulonglong)*(uint *)(lVar3 + 0x20 + (ulonglong)uVar10) + lVar3 +
                           uVar11 * 4) + lVar3;
          uVar9 = 0x55366ad0;
          do {
            uVar6 = uVar6 + 1;
          } while (*(char *)(lVar8 + uVar6) != '\0');
          uVar7 = 0;
          if (uVar6 != 0) {
            do {
              pcVar1 = (char *)(uVar7 + lVar8);
              uVar7 = uVar7 + 1;
              uVar9 = ((int)*pcVar1 ^ uVar9) * 0x1000193;
            } while (uVar7 < uVar6);
            if (uVar9 == 0xdd6321f4) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar5 + 0x1c) + lVar3 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar5 + 0x24) + lVar3 + uVar11 * 2)
                                          * 4) + lVar3);
              goto LAB_1400024a0;
            }
          }
          uVar9 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar9;
        } while (uVar9 < *(uint *)(lVar5 + 0x18));
      }
    }
  }
  pcVar12 = (code *)0x0;
LAB_1400024a0:
  local_90 = 0;
  local_98 = 0;
  local_a0 = 0;
  local_a8 = local_80;
  local_b0 = 0x14;
  local_b8 = 0x114;
  local_c0 = 4;
  local_c8 = 4;
  (*pcVar12)(0,local_88,local_78,0x50000000);
  local_60 = 0xf26049c9;
  local_5c = 0xb;
  local_58 = 0x2d10c88c;
  local_88 = FUN_1400032a0(0x2d10c88c,(longlong)&local_60,0x1400080e8,5);
  pvVar4 = FUN_140004280();
  for (puVar2 = *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x20);
      puVar2 != *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x28);
      puVar2 = (undefined8 *)*puVar2) {
    lVar3 = puVar2[4];
    uVar10 = *(uint *)((longlong)*(int *)(lVar3 + 0x3c) + 0x88 + lVar3);
    if (uVar10 != 0) {
      lVar5 = (ulonglong)uVar10 + lVar3;
      uVar11 = 0;
      if (*(uint *)(lVar5 + 0x18) != 0) {
        do {
          uVar6 = 0xffffffffffffffff;
          lVar8 = (ulonglong)*(uint *)((ulonglong)*(uint *)(lVar5 + 0x20) + lVar3 + uVar11 * 4) +
                  lVar3;
          uVar10 = 0x55366ad0;
          do {
            uVar6 = uVar6 + 1;
          } while (*(char *)(lVar8 + uVar6) != '\0');
          uVar7 = 0;
          if (uVar6 != 0) {
            do {
              pcVar1 = (char *)(uVar7 + lVar8);
              uVar7 = uVar7 + 1;
              uVar10 = ((int)*pcVar1 ^ uVar10) * 0x1000193;
            } while (uVar7 < uVar6);
            if (uVar10 == 0xdd6321f4) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar5 + 0x1c) + lVar3 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar5 + 0x24) + lVar3 + uVar11 * 2)
                                          * 4) + lVar3);
              goto LAB_1400025f0;
            }
          }
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar10;
        } while (uVar10 < *(uint *)(lVar5 + 0x18));
      }
    }
  }
  pcVar12 = (code *)0x0;
LAB_1400025f0:
  local_90 = 0;
  local_98 = 0;
  local_a0 = 0;
  local_a8 = local_80;
  local_b0 = 0x18;
  local_b8 = 0xe6;
  local_c0 = 0x18;
  local_c8 = 4;
  DAT_140008090 = (*pcVar12)(0,local_88,0,0x50810000);
  local_70 = 0xef7b48da;
  local_6c = 0x3d7f4d;
  local_68 = 0x2d10c88c;
  local_88 = FUN_1400032a0(0x2d10c88c,(longlong)&local_70,0x1400080f8,7);
  local_60 = 0xf27d58ce;
  local_5c = 0x3d6844;
  local_58 = 0x2d10c88c;
  local_78 = FUN_1400032a0(0x2d10c88c,(longlong)&local_60,0x1400080f0,7);
  pvVar4 = FUN_140004280();
  puVar2 = *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x20);
  do {
    if (puVar2 == *(undefined8 **)(*(longlong *)((longlong)pvVar4 + 0x18) + 0x28)) {
      pcVar12 = (code *)0x0;
LAB_140002770:
      local_90 = 0;
      local_98 = 0;
      local_a0 = 0x3e9;
      local_a8 = local_80;
      local_b0 = 0x18;
      local_b8 = 0x50;
      local_c0 = 0x18;
      local_c8 = 0xee;
      _DAT_140008088 = (*pcVar12)(0,local_78,local_88,0x50010001);
      FUN_140004320(local_30 ^ (ulonglong)auStack_e8);
      return;
    }
    lVar3 = puVar2[4];
    uVar10 = *(uint *)((longlong)*(int *)(lVar3 + 0x3c) + 0x88 + lVar3);
    if (uVar10 != 0) {
      lVar5 = (ulonglong)uVar10 + lVar3;
      uVar11 = 0;
      if (*(uint *)(lVar5 + 0x18) != 0) {
        do {
          uVar6 = 0xffffffffffffffff;
          lVar8 = (ulonglong)*(uint *)((ulonglong)*(uint *)(lVar5 + 0x20) + lVar3 + uVar11 * 4) +
                  lVar3;
          uVar10 = 0x55366ad0;
          do {
            uVar6 = uVar6 + 1;
          } while (*(char *)(lVar8 + uVar6) != '\0');
          uVar7 = 0;
          if (uVar6 != 0) {
            do {
              pcVar1 = (char *)(uVar7 + lVar8);
              uVar7 = uVar7 + 1;
              uVar10 = ((int)*pcVar1 ^ uVar10) * 0x1000193;
            } while (uVar7 < uVar6);
            if (uVar10 == 0xdd6321f4) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar5 + 0x1c) + lVar3 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar5 + 0x24) + lVar3 + uVar11 * 2)
                                          * 4) + lVar3);
              goto LAB_140002770;
            }
          }
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar10;
        } while (uVar10 < *(uint *)(lVar5 + 0x18));
      }
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



void FUN_140002830(void)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  short sVar6;
  void *pvVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  code *pcVar12;
  uint uVar13;
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_b8;
  undefined1 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40;
  undefined2 local_3f;
  undefined1 local_3d;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = DAT_140008000 ^ (ulonglong)auStack_138;
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      pcVar12 = (code *)0x0,
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    uVar9 = 0;
    lVar5 = puVar4[4];
    uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar3 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar3;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar10 = 0;
          uVar8 = 0xffffffffffffffff;
          uVar13 = 0x55366ad0;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                            uVar9 * 4) + lVar5;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          if (uVar8 != 0) {
            do {
              pcVar2 = (char *)(uVar10 + lVar11);
              uVar10 = uVar10 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar10 < uVar8);
            if (uVar13 == 0x467b23f1) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2)
                                          * 4) + lVar5);
              goto LAB_140002937;
            }
          }
          uVar13 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
LAB_140002937:
  local_d8 = (*pcVar12)(0);
  pcVar12 = (code *)0x0;
  local_b8 = 0;
  local_b0 = &LAB_1400035a0;
  local_a8 = 0;
  local_80 = 0;
  local_a0 = local_d8;
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    lVar5 = puVar4[4];
    uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar3 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar3;
      uVar9 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar8 = 0xffffffffffffffff;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                            uVar9 * 4) + lVar5;
          uVar13 = 0x55366ad0;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          uVar10 = 0;
          if (uVar8 != 0) {
            do {
              pcVar2 = (char *)(uVar10 + lVar11);
              uVar10 = uVar10 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar10 < uVar8);
            if (uVar13 == 0xb5feee14) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2)
                                          * 4) + lVar5);
              goto LAB_140002a1f;
            }
          }
          uVar13 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
LAB_140002a1f:
  local_98 = (*pcVar12)(0);
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    lVar5 = puVar4[4];
    uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar3 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar3;
      uVar9 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar8 = 0xffffffffffffffff;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                            uVar9 * 4) + lVar5;
          uVar13 = 0x55366ad0;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          uVar10 = 0;
          if (uVar8 != 0) {
            do {
              pcVar2 = (char *)(uVar10 + lVar11);
              uVar10 = uVar10 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar10 < uVar8);
            if (uVar13 == 0xa0067ffd) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2)
                                          * 4) + lVar5);
              goto LAB_140002af2;
            }
          }
          uVar13 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
  pcVar12 = (code *)0x0;
LAB_140002af2:
  local_90 = (*pcVar12)(0);
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    lVar5 = puVar4[4];
    uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar3 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar3;
      uVar9 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar8 = 0xffffffffffffffff;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                            uVar9 * 4) + lVar5;
          uVar13 = 0x55366ad0;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          uVar10 = 0;
          if (uVar8 != 0) {
            do {
              pcVar2 = (char *)(uVar10 + lVar11);
              uVar10 = uVar10 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar10 < uVar8);
            if (uVar13 == 0x69a3250) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2)
                                          * 4) + lVar5);
              goto LAB_140002bc2;
            }
          }
          uVar13 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
  pcVar12 = (code *)0x0;
LAB_140002bc2:
  local_88 = (*pcVar12)(0xf);
  local_58 = 0xcd79fbe1;
  local_54 = 0x2d10c88c;
  local_68 = 0x9b756554e16841ca;
  uStack_60 = 0x1204af870b5c14b8;
  local_78 = FUN_1400032a0(0x2d10c88c,(longlong)&local_68,0x140008100,0x14);
  pvVar7 = FUN_140004280();
  for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar4 = (undefined8 *)*puVar4) {
    lVar5 = puVar4[4];
    uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
    if (uVar3 != 0) {
      lVar1 = lVar5 + (ulonglong)uVar3;
      uVar9 = 0;
      if (*(uint *)(lVar1 + 0x18) != 0) {
        do {
          uVar8 = 0xffffffffffffffff;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                            uVar9 * 4) + lVar5;
          uVar13 = 0x55366ad0;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          uVar10 = 0;
          if (uVar8 != 0) {
            do {
              pcVar2 = (char *)(uVar10 + lVar11);
              uVar10 = uVar10 + 1;
              uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
            } while (uVar10 < uVar8);
            if (uVar13 == 0x61e7d986) {
              pcVar12 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2)
                                          * 4) + lVar5);
              goto LAB_140002cd2;
            }
          }
          uVar13 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar1 + 0x18));
      }
    }
  }
  pcVar12 = (code *)0x0;
LAB_140002cd2:
  sVar6 = (*pcVar12)(&local_b8);
  if (sVar6 != 0) {
    local_40 = 0xa5;
    local_3f = 0;
    local_3d = 0;
    local_50 = 0xac585278cf4e68de;
    uStack_48 = 0x282e8dbc366b0fdb;
    local_3c = 0x2d10c88c;
    local_d0 = FUN_1400032a0(0x2d10c88c,(longlong)&local_50,0x140008130,0x11);
    local_58 = 0xcd79fbe1;
    local_54 = 0x2d10c88c;
    local_68 = 0x9b756554e16841ca;
    uStack_60 = 0x1204af870b5c14b8;
    local_c8 = FUN_1400032a0(0x2d10c88c,(longlong)&local_68,0x140008118,0x14);
    pvVar7 = FUN_140004280();
    for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
        puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
        puVar4 = (undefined8 *)*puVar4) {
      lVar5 = puVar4[4];
      uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
      if (uVar3 != 0) {
        lVar1 = lVar5 + (ulonglong)uVar3;
        uVar9 = 0;
        if (*(uint *)(lVar1 + 0x18) != 0) {
          do {
            uVar8 = 0xffffffffffffffff;
            lVar11 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                              uVar9 * 4) + lVar5;
            uVar13 = 0x55366ad0;
            do {
              uVar8 = uVar8 + 1;
            } while (*(char *)(lVar11 + uVar8) != '\0');
            uVar10 = 0;
            if (uVar8 != 0) {
              do {
                pcVar2 = (char *)(uVar10 + lVar11);
                uVar10 = uVar10 + 1;
                uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
              } while (uVar10 < uVar8);
              if (uVar13 == 0xdd6321f4) {
                pcVar12 = (code *)((ulonglong)
                                   *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                            (ulonglong)
                                            *(ushort *)
                                             ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2
                                             ) * 4) + lVar5);
                goto LAB_140002e22;
              }
            }
            uVar13 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar13;
          } while (uVar13 < *(uint *)(lVar1 + 0x18));
        }
      }
    }
    pcVar12 = (code *)0x0;
LAB_140002e22:
    local_e0 = 0;
    local_e8 = local_d8;
    local_f0 = 0;
    local_f8 = 0;
    local_100 = 0x96;
    local_108 = 0x154;
    local_110 = 0x80000000;
    local_118 = 0x80000000;
    DAT_140008080 = (*pcVar12)(0,local_c8,local_d0,0xc80000);
    if (DAT_140008080 != 0) {
      pvVar7 = FUN_140004280();
      for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
          puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
          puVar4 = (undefined8 *)*puVar4) {
        lVar5 = puVar4[4];
        uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
        if (uVar3 != 0) {
          lVar1 = lVar5 + (ulonglong)uVar3;
          uVar9 = 0;
          if (*(uint *)(lVar1 + 0x18) != 0) {
            do {
              uVar8 = 0xffffffffffffffff;
              lVar11 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                                uVar9 * 4) + lVar5;
              uVar13 = 0x55366ad0;
              do {
                uVar8 = uVar8 + 1;
              } while (*(char *)(lVar11 + uVar8) != '\0');
              uVar10 = 0;
              if (uVar8 != 0) {
                do {
                  pcVar2 = (char *)(uVar10 + lVar11);
                  uVar10 = uVar10 + 1;
                  uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
                } while (uVar10 < uVar8);
                if (uVar13 == 0x77a1b499) {
                  pcVar12 = (code *)((ulonglong)
                                     *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                              (ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 +
                                               uVar9 * 2) * 4) + lVar5);
                  goto LAB_140002f42;
                }
              }
              uVar13 = (int)uVar9 + 1;
              uVar9 = (ulonglong)uVar13;
            } while (uVar13 < *(uint *)(lVar1 + 0x18));
          }
        }
      }
      pcVar12 = (code *)0x0;
LAB_140002f42:
      (*pcVar12)(DAT_140008080);
      pvVar7 = FUN_140004280();
      for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
          puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
          puVar4 = (undefined8 *)*puVar4) {
        lVar5 = puVar4[4];
        uVar3 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
        if (uVar3 != 0) {
          lVar1 = lVar5 + (ulonglong)uVar3;
          uVar9 = 0;
          if (*(uint *)(lVar1 + 0x18) != 0) {
            do {
              uVar8 = 0xffffffffffffffff;
              lVar11 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar3) + lVar5 +
                                uVar9 * 4) + lVar5;
              uVar13 = 0x55366ad0;
              do {
                uVar8 = uVar8 + 1;
              } while (*(char *)(lVar11 + uVar8) != '\0');
              uVar10 = 0;
              if (uVar8 != 0) {
                do {
                  pcVar2 = (char *)(uVar10 + lVar11);
                  uVar10 = uVar10 + 1;
                  uVar13 = ((int)*pcVar2 ^ uVar13) * 0x1000193;
                } while (uVar10 < uVar8);
                if (uVar13 == 0xf70dc191) {
                  (*(code *)((ulonglong)
                             *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                      (ulonglong)
                                      *(ushort *)
                                       ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 + uVar9 * 2) * 4)
                            + lVar5))(DAT_140008080);
                  goto LAB_1400030b0;
                }
              }
              uVar13 = (int)uVar9 + 1;
              uVar9 = (ulonglong)uVar13;
            } while (uVar13 < *(uint *)(lVar1 + 0x18));
          }
        }
      }
      (*(code *)0x0)(DAT_140008080);
    }
  }
LAB_1400030b0:
  FUN_140004320(local_38 ^ (ulonglong)auStack_138);
  return;
}



undefined8 FUN_1400030e0(longlong param_1)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  code *pcVar12;
  longlong lVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(param_1 + lVar7) != '\0');
  if (lVar7 == 0x13) {
    uVar16 = 0;
    do {
      if ((uVar16 < 0xf) && ((0x4210UL >> (uVar16 & 0x3f) & 1) != 0)) {
        if (*(char *)(uVar16 + param_1) != '-') goto LAB_140003147;
      }
      else {
        pvVar8 = FUN_140004280();
        for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar8 + 0x18) + 0x20);
            puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar8 + 0x18) + 0x28);
            puVar4 = (undefined8 *)*puVar4) {
          lVar7 = puVar4[4];
          uVar3 = *(uint *)((longlong)*(int *)(lVar7 + 0x3c) + 0x88 + lVar7);
          if (uVar3 != 0) {
            lVar1 = lVar7 + (ulonglong)uVar3;
            uVar15 = 0;
            if (*(uint *)(lVar1 + 0x18) != 0) {
              do {
                uVar9 = 0xffffffffffffffff;
                lVar13 = (ulonglong)
                         *(uint *)((ulonglong)*(uint *)(lVar7 + 0x20 + (ulonglong)uVar3) + lVar7 +
                                  uVar15 * 4) + lVar7;
                uVar14 = 0x55366ad0;
                do {
                  uVar9 = uVar9 + 1;
                } while (*(char *)(lVar13 + uVar9) != '\0');
                uVar11 = 0;
                if (uVar9 != 0) {
                  do {
                    pcVar2 = (char *)(uVar11 + lVar13);
                    uVar11 = uVar11 + 1;
                    uVar14 = ((int)*pcVar2 ^ uVar14) * 0x1000193;
                  } while (uVar11 < uVar9);
                  if (uVar14 == 0x71ea3633) {
                    pcVar12 = (code *)((ulonglong)
                                       *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar7 +
                                                (ulonglong)
                                                *(ushort *)
                                                 ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar7 +
                                                 uVar15 * 2) * 4) + lVar7);
                    goto LAB_140003236;
                  }
                }
                uVar14 = (int)uVar15 + 1;
                uVar15 = (ulonglong)uVar14;
              } while (uVar14 < *(uint *)(lVar1 + 0x18));
            }
          }
        }
        pcVar12 = (code *)0x0;
LAB_140003236:
        cVar5 = (*pcVar12)((int)*(char *)(uVar16 + param_1));
        if ((byte)(cVar5 + 0xbfU) < 0x1a) {
          iVar6 = cVar5 + -0x41;
        }
        else {
          if (5 < (byte)(cVar5 - 0x32U)) goto LAB_140003147;
          iVar6 = cVar5 + -0x18;
        }
        if (iVar6 == -1) goto LAB_140003147;
      }
      uVar16 = uVar16 + 1;
    } while ((longlong)uVar16 < 0x13);
    uVar10 = 1;
  }
  else {
LAB_140003147:
    uVar10 = 0;
  }
  return uVar10;
}



longlong FUN_1400032a0(uint param_1,longlong param_2,longlong param_3,uint param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = param_1;
  for (local_18 = 0; local_18 < param_4; local_18 = local_18 + 1) {
    *(byte *)(param_3 + (ulonglong)local_18) =
         *(byte *)(param_2 + (ulonglong)local_18) ^ (byte)local_14;
    local_14 = FUN_140003df0(local_14);
  }
  return param_3;
}



void FUN_140003320(longlong param_1,uint *param_2)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  void *pvVar7;
  code *pcVar8;
  uint uVar9;
  code *pcVar11;
  longlong lVar12;
  uint uVar13;
  code *pcVar14;
  undefined1 auStack_a8 [32];
  longlong local_88;
  uint *local_80;
  longlong local_78;
  longlong local_70;
  uint *local_68;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  char local_50 [4];
  undefined1 local_4c;
  ulonglong local_48;
  code *pcVar10;
  
  local_48 = DAT_140008000 ^ (ulonglong)auStack_a8;
  local_88 = param_1;
  local_68 = param_2;
  uVar6 = FUN_1400030e0(param_1);
  if ((int)uVar6 != 0) {
    local_70 = (longlong)&local_60 - (longlong)param_2;
    pcVar14 = (code *)0x0;
    local_78 = 4;
    local_80 = param_2;
    do {
      pvVar7 = FUN_140004280();
      for (puVar4 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
          pcVar10 = pcVar14,
          puVar4 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
          puVar4 = (undefined8 *)*puVar4) {
        lVar5 = puVar4[4];
        uVar9 = *(uint *)((longlong)*(int *)(lVar5 + 0x3c) + 0x88 + lVar5);
        param_1 = local_88;
        if (uVar9 != 0) {
          lVar1 = lVar5 + (ulonglong)uVar9;
          if (*(uint *)(lVar1 + 0x18) != 0) {
            do {
              pcVar8 = (code *)0xffffffffffffffff;
              uVar13 = 0x55366ad0;
              lVar12 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar5 + 0x20 + (ulonglong)uVar9) + lVar5 +
                                (longlong)pcVar10 * 4) + lVar5;
              do {
                pcVar8 = pcVar8 + 1;
              } while (pcVar8[lVar12] != (code)0x0);
              pcVar11 = pcVar14;
              if (pcVar8 != (code *)0x0) {
                do {
                  pcVar2 = pcVar11 + lVar12;
                  pcVar11 = pcVar11 + 1;
                  uVar13 = ((int)(char)*pcVar2 ^ uVar13) * 0x1000193;
                } while (pcVar11 < pcVar8);
                if (uVar13 == 0x1da5a6eb) {
                  pcVar10 = (code *)((ulonglong)
                                     *(uint *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar5 +
                                              (ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*(uint *)(lVar1 + 0x24) + lVar5 +
                                               (longlong)pcVar10 * 2) * 4) + lVar5);
                  goto LAB_14000346d;
                }
              }
              uVar13 = (int)pcVar10 + 1;
              pcVar10 = (code *)(ulonglong)uVar13;
            } while (uVar13 < *(uint *)(lVar1 + 0x18));
          }
        }
      }
LAB_14000346d:
      (*pcVar10)(local_50,param_1,4);
      local_4c = 0;
      pcVar10 = pcVar14;
      pcVar8 = pcVar14;
      do {
        cVar3 = local_50[(longlong)pcVar8];
        if (0x19 < (byte)(cVar3 + 0xbfU)) {
          if ((byte)(cVar3 - 0x32U) < 6) {
            uVar9 = (int)cVar3 - 0x18;
            goto LAB_1400034bf;
          }
LAB_1400034d4:
          uVar9 = 0xffffffff;
          break;
        }
        uVar9 = (int)cVar3 - 0x41;
LAB_1400034bf:
        if (uVar9 == 0xffffffff) goto LAB_1400034d4;
        pcVar8 = pcVar8 + 1;
        uVar9 = (int)pcVar10 << 5 | uVar9;
        pcVar10 = (code *)(ulonglong)uVar9;
      } while ((longlong)pcVar8 < 4);
      param_1 = param_1 + 5;
      *(uint *)(local_70 + (longlong)local_80) = uVar9;
      *local_80 = (int)uVar9 >> 0xc & 0xff;
      local_80 = local_80 + 1;
      local_78 = local_78 + -1;
      local_88 = param_1;
    } while (local_78 != 0);
    local_5c = ((local_60 ^ 0x7b081b4a) * 0x45d9f3b >> 0x13 | (local_60 ^ 0x7b081b4a) * -0x4c18a000)
               ^ local_5c;
    local_58 = (local_5c * 0x45d9f3b >> 0x13 | local_5c * -0x4c18a000) ^ local_58;
    if ((local_58 * 0x45d9f3b >> 0x13 | local_58 * -0x4c18a000 & 0xfffff) == local_54) {
      FUN_140001080((longlong)local_68,0xc);
    }
  }
  FUN_140004320(local_48 ^ (ulonglong)auStack_a8);
  return;
}



uint FUN_140003df0(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 ^ param_1 << 0xd;
  uVar1 = uVar1 ^ uVar1 >> 0x11;
  return (uVar1 ^ uVar1 << 5) % 0x7fffffff;
}



void FUN_140003e30(void)

{
  char *pcVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  void *pvVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  code *pcVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined1 auStack_98 [32];
  undefined1 local_78 [48];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = DAT_140008000 ^ (ulonglong)auStack_98;
  local_48 = 0xd44c7ef9;
  local_44 = 0xba131438;
  local_40 = 0x193397;
  local_3c = 0x2d10c88c;
  lVar6 = FUN_1400032a0(0x2d10c88c,(longlong)&local_48,0x1400081c0,0xb);
  pvVar7 = FUN_140004280();
  for (puVar3 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
      puVar3 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
      puVar3 = (undefined8 *)*puVar3) {
    lVar4 = puVar3[4];
    uVar2 = *(uint *)((longlong)*(int *)(lVar4 + 0x3c) + 0x88 + lVar4);
    if (uVar2 != 0) {
      lVar12 = lVar4 + (ulonglong)uVar2;
      uVar14 = 0;
      if (*(uint *)(lVar12 + 0x18) != 0) {
        do {
          uVar8 = 0xffffffffffffffff;
          lVar11 = (ulonglong)
                   *(uint *)((ulonglong)*(uint *)(lVar4 + 0x20 + (ulonglong)uVar2) + lVar4 +
                            uVar14 * 4) + lVar4;
          uVar13 = 0x55366ad0;
          do {
            uVar8 = uVar8 + 1;
          } while (*(char *)(lVar11 + uVar8) != '\0');
          uVar9 = 0;
          if (uVar8 != 0) {
            do {
              pcVar1 = (char *)(uVar9 + lVar11);
              uVar9 = uVar9 + 1;
              uVar13 = ((int)*pcVar1 ^ uVar13) * 0x1000193;
            } while (uVar9 < uVar8);
            if (uVar13 == 0x146ed342) {
              pcVar10 = (code *)((ulonglong)
                                 *(uint *)((ulonglong)*(uint *)(lVar12 + 0x1c) + lVar4 +
                                          (ulonglong)
                                          *(ushort *)
                                           ((ulonglong)*(uint *)(lVar12 + 0x24) + lVar4 + uVar14 * 2
                                           ) * 4) + lVar4);
              goto LAB_140003f6a;
            }
          }
          uVar13 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(lVar12 + 0x18));
      }
    }
  }
  pcVar10 = (code *)0x0;
LAB_140003f6a:
  (*pcVar10)(lVar6);
  iVar5 = FUN_140002830();
  if (iVar5 != 0) {
LAB_140003f84:
    pvVar7 = FUN_140004280();
    for (puVar3 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
        puVar3 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
        puVar3 = (undefined8 *)*puVar3) {
      lVar6 = puVar3[4];
      uVar2 = *(uint *)((longlong)*(int *)(lVar6 + 0x3c) + 0x88 + lVar6);
      if (uVar2 != 0) {
        lVar4 = lVar6 + (ulonglong)uVar2;
        uVar14 = 0;
        if (*(uint *)(lVar4 + 0x18) != 0) {
          do {
            uVar8 = 0xffffffffffffffff;
            lVar12 = (ulonglong)
                     *(uint *)((ulonglong)*(uint *)(lVar6 + 0x20 + (ulonglong)uVar2) + lVar6 +
                              uVar14 * 4) + lVar6;
            uVar13 = 0x55366ad0;
            do {
              uVar8 = uVar8 + 1;
            } while (*(char *)(lVar12 + uVar8) != '\0');
            uVar9 = 0;
            if (uVar8 != 0) {
              do {
                pcVar1 = (char *)(uVar9 + lVar12);
                uVar9 = uVar9 + 1;
                uVar13 = ((int)*pcVar1 ^ uVar13) * 0x1000193;
              } while (uVar9 < uVar8);
              if (uVar13 == 0x9d3ba21e) {
                pcVar10 = (code *)((ulonglong)
                                   *(uint *)((ulonglong)*(uint *)(lVar4 + 0x1c) + lVar6 +
                                            (ulonglong)
                                            *(ushort *)
                                             ((ulonglong)*(uint *)(lVar4 + 0x24) + lVar6 +
                                             uVar14 * 2) * 4) + lVar6);
                goto LAB_14000404b;
              }
            }
            uVar13 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar13;
          } while (uVar13 < *(uint *)(lVar4 + 0x18));
        }
      }
    }
    pcVar10 = (code *)0x0;
LAB_14000404b:
    iVar5 = (*pcVar10)(local_78,0,0,0);
    if (iVar5 != 0) {
      pvVar7 = FUN_140004280();
      for (puVar3 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
          puVar3 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
          puVar3 = (undefined8 *)*puVar3) {
        lVar6 = puVar3[4];
        uVar2 = *(uint *)((longlong)*(int *)(lVar6 + 0x3c) + 0x88 + lVar6);
        if (uVar2 != 0) {
          lVar4 = lVar6 + (ulonglong)uVar2;
          uVar14 = 0;
          if (*(uint *)(lVar4 + 0x18) != 0) {
            do {
              uVar8 = 0xffffffffffffffff;
              lVar12 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar6 + 0x20 + (ulonglong)uVar2) + lVar6 +
                                uVar14 * 4) + lVar6;
              uVar13 = 0x55366ad0;
              do {
                uVar8 = uVar8 + 1;
              } while (*(char *)(lVar12 + uVar8) != '\0');
              uVar9 = 0;
              if (uVar8 != 0) {
                do {
                  pcVar1 = (char *)(uVar9 + lVar12);
                  uVar9 = uVar9 + 1;
                  uVar13 = ((int)*pcVar1 ^ uVar13) * 0x1000193;
                } while (uVar9 < uVar8);
                if (uVar13 == 0x498c95a5) {
                  pcVar10 = (code *)((ulonglong)
                                     *(uint *)((ulonglong)*(uint *)(lVar4 + 0x1c) + lVar6 +
                                              (ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*(uint *)(lVar4 + 0x24) + lVar6 +
                                               uVar14 * 2) * 4) + lVar6);
                  goto LAB_14000412a;
                }
              }
              uVar13 = (int)uVar14 + 1;
              uVar14 = (ulonglong)uVar13;
            } while (uVar13 < *(uint *)(lVar4 + 0x18));
          }
        }
      }
      pcVar10 = (code *)0x0;
LAB_14000412a:
      (*pcVar10)(local_78);
      pvVar7 = FUN_140004280();
      for (puVar3 = *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x20);
          puVar3 != *(undefined8 **)(*(longlong *)((longlong)pvVar7 + 0x18) + 0x28);
          puVar3 = (undefined8 *)*puVar3) {
        lVar6 = puVar3[4];
        uVar2 = *(uint *)((longlong)*(int *)(lVar6 + 0x3c) + 0x88 + lVar6);
        if (uVar2 != 0) {
          lVar4 = lVar6 + (ulonglong)uVar2;
          uVar14 = 0;
          if (*(uint *)(lVar4 + 0x18) != 0) {
            do {
              uVar8 = 0xffffffffffffffff;
              lVar12 = (ulonglong)
                       *(uint *)((ulonglong)*(uint *)(lVar6 + 0x20 + (ulonglong)uVar2) + lVar6 +
                                uVar14 * 4) + lVar6;
              uVar13 = 0x55366ad0;
              do {
                uVar8 = uVar8 + 1;
              } while (*(char *)(lVar12 + uVar8) != '\0');
              uVar9 = 0;
              if (uVar8 != 0) {
                do {
                  pcVar1 = (char *)(uVar9 + lVar12);
                  uVar9 = uVar9 + 1;
                  uVar13 = ((int)*pcVar1 ^ uVar13) * 0x1000193;
                } while (uVar9 < uVar8);
                if (uVar13 == 0xaa90d368) {
                  (*(code *)((ulonglong)
                             *(uint *)((ulonglong)*(uint *)(lVar4 + 0x1c) + lVar6 +
                                      (ulonglong)
                                      *(ushort *)
                                       ((ulonglong)*(uint *)(lVar4 + 0x24) + lVar6 + uVar14 * 2) * 4
                                      ) + lVar6))(local_78);
                  goto LAB_140003f84;
                }
              }
              uVar13 = (int)uVar14 + 1;
              uVar14 = (ulonglong)uVar13;
            } while (uVar13 < *(uint *)(lVar4 + 0x18));
          }
        }
      }
      (*(code *)0x0)(local_78);
      goto LAB_140003f84;
    }
  }
  FUN_140004320(local_38 ^ (ulonglong)auStack_98);
  return;
}



void * FUN_140004280(void)

{
  return ProcessEnvironmentBlock;
}



// Library Function - Single Match
//  __GSHandlerCheckCommon
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  uVar1 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  if ((*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xf) != 0) {
    param_1 = param_1 + (*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xfffffff0);
  }
  FUN_140004320(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}



void FUN_140004320(longlong param_1)

{
  if ((param_1 == DAT_140008000) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  FUN_1400045e0();
  return;
}



void FUN_140004340(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  undefined7 extraout_var;
  
  _set_app_type(2);
  uVar5 = FUN_140004a20();
  _set_fmode((int)uVar5);
  uVar5 = FUN_140004a14();
  puVar6 = (undefined4 *)__p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_140004cdc();
    atexit((_func_5014 *)&LAB_140004d18);
    uVar7 = FUN_140004a18();
    iVar4 = _configure_narrow_argv(uVar7 & 0xffffffff);
    if (iVar4 == 0) {
      FUN_140004a28();
      bVar2 = FUN_140004a6c();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr(FUN_140004a14);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140004a14();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_140004a38();
      if (cVar3 != '\0') {
        _initialize_narrow_environment();
      }
      FUN_140004a14();
      uVar5 = thunk_FUN_140004a14();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_140004a90(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



undefined8 FUN_1400043f8(void)

{
  FUN_140004a50();
  return 0;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

int FUN_140004424(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  IMAGE_DOS_HEADER *pIVar6;
  undefined8 unaff_RBX;
  
  iVar2 = (int)unaff_RBX;
  uVar3 = FUN_140004764(1);
  if ((char)uVar3 == '\0') {
    FUN_140004a90(7);
  }
  else {
    bVar1 = false;
    uVar3 = __scrt_acquire_startup_lock();
    iVar2 = (int)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar3);
    if (DAT_140008740 != 1) {
      if (DAT_140008740 == 0) {
        DAT_140008740 = 1;
        iVar2 = _initterm_e(&DAT_1400061f0,&DAT_140006208);
        if (iVar2 != 0) {
          return 0xff;
        }
        _initterm(&DAT_1400061d0);
        DAT_140008740 = 2;
      }
      else {
        bVar1 = true;
      }
      __scrt_release_startup_lock((char)uVar3);
      plVar4 = (longlong *)FUN_140004a78();
      if ((*plVar4 != 0) && (uVar5 = FUN_14000482c((longlong)plVar4), (char)uVar5 != '\0')) {
        (*(code *)*plVar4)(0);
      }
      plVar4 = (longlong *)FUN_140004a80();
      if ((*plVar4 != 0) && (uVar5 = FUN_14000482c((longlong)plVar4), (char)uVar5 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar4);
      }
      __scrt_get_show_window_mode();
      _get_narrow_winmain_command_line();
      pIVar6 = &IMAGE_DOS_HEADER_140000000;
      iVar2 = FUN_140003e30();
      uVar5 = FUN_140004c1c();
      if ((char)uVar5 != '\0') {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar6 >> 8),1),'\0');
        return iVar2;
      }
      goto LAB_140004585;
    }
  }
  FUN_140004a90(7);
LAB_140004585:
                    // WARNING: Subroutine does not return
  exit(iVar2);
}



void entry(void)

{
  __security_init_cookie();
  FUN_140004424();
  return;
}



// Library Function - Single Match
//  __raise_securityfailure
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    // WARNING: Could not recover jumptable at 0x0001400045d9. Too many branches
                    // WARNING: Treating indirect jump as call
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_1400045e0(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000460b;
  capture_previous_context((PCONTEXT)&DAT_140008270);
  _DAT_1400081e0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_140008308 = puVar3 + 0x40;
  _DAT_1400082f0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_1400081d0 = 0xc0000409;
  _DAT_1400081d4 = 1;
  _DAT_1400081e8 = 1;
  DAT_1400081f0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140008000;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140008040;
  *(undefined8 *)(puVar3 + -8) = 0x1400046ad;
  DAT_140008368 = _DAT_1400081e0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400062c0);
  return;
}



// Library Function - Single Match
//  capture_previous_context
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



// Library Function - Single Match
//  __scrt_acquire_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

ulonglong __scrt_acquire_startup_lock(void)

{
  void *pvVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar4;
  void *pvVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  pvVar3 = (void *)CONCAT71(extraout_var,bVar2);
  if ((int)pvVar3 == 0) {
LAB_140004756:
    uVar4 = (ulonglong)pvVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      bVar2 = DAT_140008748 == (void *)0x0;
      pvVar1 = StackBase;
      if (!bVar2) {
        pvVar3 = DAT_140008748;
        pvVar1 = DAT_140008748;
      }
      DAT_140008748 = pvVar1;
      UNLOCK();
      if (bVar2) goto LAB_140004756;
    } while (StackBase != pvVar3);
    uVar4 = CONCAT71((int7)((ulonglong)pvVar3 >> 8),1);
  }
  return uVar4;
}



longlong FUN_140004764(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_140008750 = 1;
  }
  FUN_140004d54();
  cVar1 = FUN_140004a38();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_140004a38();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_140004a38();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __scrt_initialize_onexit_tables
// 
// Library: Visual Studio 2019 Release

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_140008751 == '\0') {
    if (1 < param_1) {
      FUN_140004a90(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_140008758 = 0xffffffffffffffff;
      uRam0000000140008760 = 0xffffffffffffffff;
      _DAT_140008768 = 0xffffffffffffffff;
      _DAT_140008770 = 0xffffffffffffffff;
      uRam0000000140008778 = 0xffffffffffffffff;
      _DAT_140008780 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_140008758);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_140008770), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140008751 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



// WARNING: Removing unreachable block (ram,0x0001400048b9)
// WARNING: Enum "SectionFlags": Some values do not have unique names

ulonglong FUN_14000482c(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_140000208; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_1400002d0;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x140000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x140000000U < uVar1)) goto LAB_1400048a2;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_1400048a2:
  if (pIVar3 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (uint7)(uVar1 >> 8);
    if ((int)pIVar3->Characteristics < 0) {
      uVar1 = (ulonglong)uVar2 << 8;
    }
    else {
      uVar1 = CONCAT71(uVar2,1);
    }
  }
  return uVar1;
}



// Library Function - Single Match
//  __scrt_release_startup_lock
// 
// Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_140008748 = 0;
    UNLOCK();
  }
  return;
}



// Library Function - Single Match
//  __scrt_uninitialize_crt
// 
// Library: Visual Studio 2019 Release

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140008750 == '\0') || (param_2 == '\0')) {
    FUN_140004a38();
    FUN_140004a38();
  }
  return 1;
}



// Library Function - Single Match
//  _onexit
// 
// Library: Visual Studio 2019 Release

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_140008758 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140008758);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



// Library Function - Single Match
//  atexit
// 
// Library: Visual Studio 2019 Release

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Library Function - Single Match
//  __security_init_cookie
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_140008000 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_140008000 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_140008000 == 0x2b992ddfa232) {
      DAT_140008000 = 0x2b992ddfa233;
    }
  }
  DAT_140008040 = ~DAT_140008000;
  return;
}



undefined8 FUN_140004a14(void)

{
  return 0;
}



undefined8 FUN_140004a18(void)

{
  return 1;
}



undefined8 FUN_140004a20(void)

{
  return 0x4000;
}



void FUN_140004a28(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004a2f. Too many branches
                    // WARNING: Treating indirect jump as call
  InitializeSListHead(&DAT_140008790);
  return;
}



undefined1 FUN_140004a38(void)

{
  return 1;
}



void _guard_check_icall(void)

{
  return;
}



undefined * FUN_140004a40(void)

{
  return &DAT_1400087a0;
}



undefined * FUN_140004a48(void)

{
  return &DAT_1400087a8;
}



void FUN_140004a50(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_140004a40();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_140004a48();
  *puVar1 = *puVar1 | 2;
  return;
}



bool FUN_140004a6c(void)

{
  return DAT_14000804c == 0;
}



undefined * FUN_140004a78(void)

{
  return &DAT_1400087c0;
}



undefined * FUN_140004a80(void)

{
  return &DAT_1400087b8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_140004a88(void)

{
  _DAT_1400087b0 = 0;
  return;
}



void FUN_140004a90(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140004ac4;
  FUN_140004a88();
  *(undefined8 *)(puVar4 + -8) = 0x140004ad5;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x140004adf;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x140004af9;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x140004b3a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x140004b6c;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x140004b8e;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x140004bab;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x140004bb6;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x140004bc7;
    FUN_140004a88();
  }
  return;
}



// Library Function - Single Match
//  __scrt_get_show_window_mode
// 
// Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}



undefined8 thunk_FUN_140004a14(void)

{
  return 0;
}



ulonglong FUN_140004c1c(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}



void FUN_140004c70(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004c77. Too many branches
                    // WARNING: Treating indirect jump as call
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_140004c80);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_140004cdc(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &DAT_140006770; puVar1 < &DAT_140006770; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x000140004e1e)
// WARNING: Removing unreachable block (ram,0x000140004d8e)
// WARNING: Removing unreachable block (ram,0x000140004d67)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_140004d54(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    _DAT_140008060 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    _DAT_140008058 = 0x8000;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_1400087b4 = DAT_1400087b4 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_1400087b4 = DAT_1400087b4 | 2;
    }
  }
  _DAT_140008050 = 1;
  DAT_140008054 = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_140008050 = 2;
    DAT_140008054 = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_140008054 = 0xe;
      _DAT_140008050 = 3;
      if ((uVar6 & 0x20) != 0) {
        _DAT_140008050 = 5;
        DAT_140008054 = 0x2e;
        if (((uVar6 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
          DAT_140008054 = 0x6e;
          _DAT_140008050 = 6;
        }
      }
    }
  }
  return 0;
}



// Library Function - Single Match
//  __scrt_is_ucrt_dll_in_use
// 
// Library: Visual Studio 2019 Release

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_140008070 != 0;
}



void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140004f10. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __current_exception(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f1c. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception();
  return;
}



void __current_exception_context(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f22. Too many branches
                    // WARNING: Treating indirect jump as call
  __current_exception_context();
  return;
}



void _seh_filter_exe(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f28. Too many branches
                    // WARNING: Treating indirect jump as call
  _seh_filter_exe();
  return;
}



void _set_app_type(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f2e. Too many branches
                    // WARNING: Treating indirect jump as call
  _set_app_type();
  return;
}



void __setusermatherr(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f34. Too many branches
                    // WARNING: Treating indirect jump as call
  __setusermatherr();
  return;
}



void _configure_narrow_argv(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f3a. Too many branches
                    // WARNING: Treating indirect jump as call
  _configure_narrow_argv();
  return;
}



void _initialize_narrow_environment(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f40. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_narrow_environment();
  return;
}



void _get_narrow_winmain_command_line(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f46. Too many branches
                    // WARNING: Treating indirect jump as call
  _get_narrow_winmain_command_line();
  return;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f4c. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f52. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



void __cdecl exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x000140004f58. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  exit(_Code);
  return;
}



void __cdecl _exit(int _Code)

{
                    // WARNING: Could not recover jumptable at 0x000140004f5e. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _exit(_Code);
  return;
}



errno_t __cdecl _set_fmode(int _Mode)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140004f64. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = _set_fmode(_Mode);
  return eVar1;
}



void __cdecl _cexit(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f6a. Too many branches
                    // WARNING: Treating indirect jump as call
  _cexit();
  return;
}



void _register_thread_local_exe_atexit_callback(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f76. Too many branches
                    // WARNING: Treating indirect jump as call
  _register_thread_local_exe_atexit_callback();
  return;
}



int __cdecl _configthreadlocale(int _Flag)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140004f7c. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _configthreadlocale(_Flag);
  return iVar1;
}



void __p__commode(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f88. Too many branches
                    // WARNING: Treating indirect jump as call
  __p__commode();
  return;
}



void _initialize_onexit_table(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f8e. Too many branches
                    // WARNING: Treating indirect jump as call
  _initialize_onexit_table();
  return;
}



void _register_onexit_function(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f94. Too many branches
                    // WARNING: Treating indirect jump as call
  _register_onexit_function();
  return;
}



void _crt_atexit(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004f9a. Too many branches
                    // WARNING: Treating indirect jump as call
  _crt_atexit();
  return;
}



void terminate(void)

{
                    // WARNING: Could not recover jumptable at 0x000140004fa0. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  terminate();
  return;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000140004fc0. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}