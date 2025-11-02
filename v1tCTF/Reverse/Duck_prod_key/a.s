
product_key_chall.exe:     file format pei-x86-64


Disassembly of section .text:

0000000140001000 <.text>:
   140001000:	48 83 ec 58          	sub    rsp,0x58
   140001004:	48 8b 05 f5 6f 00 00 	mov    rax,QWORD PTR [rip+0x6ff5]        # 0x140008000
   14000100b:	48 33 c4             	xor    rax,rsp
   14000100e:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
   140001013:	66 0f 6f 05 15 52 00 	movdqa xmm0,XMMWORD PTR [rip+0x5215]        # 0x140006230
   14000101a:	00 
   14000101b:	4c 8d 05 7e 70 00 00 	lea    r8,[rip+0x707e]        # 0x1400080a0
   140001022:	66 0f 6f 0d 26 52 00 	movdqa xmm1,XMMWORD PTR [rip+0x5226]        # 0x140006250
   140001029:	00 
   14000102a:	48 8d 54 24 20       	lea    rdx,[rsp+0x20]
   14000102f:	33 c0                	xor    eax,eax
   140001031:	c6 44 24 40 b1       	mov    BYTE PTR [rsp+0x40],0xb1
   140001036:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   14000103b:	66 89 44 24 41       	mov    WORD PTR [rsp+0x41],ax
   140001040:	f3 0f 7f 44 24 20    	movdqu XMMWORD PTR [rsp+0x20],xmm0
   140001046:	88 44 24 43          	mov    BYTE PTR [rsp+0x43],al
   14000104a:	44 8d 48 21          	lea    r9d,[rax+0x21]
   14000104e:	c7 44 24 44 8c c8 10 	mov    DWORD PTR [rsp+0x44],0x2d10c88c
   140001055:	2d 
   140001056:	f3 0f 7f 4c 24 30    	movdqu XMMWORD PTR [rsp+0x30],xmm1
   14000105c:	e8 3f 22 00 00       	call   0x1400032a0
   140001061:	48 89 05 30 70 00 00 	mov    QWORD PTR [rip+0x7030],rax        # 0x140008098
   140001068:	48 8b 4c 24 48       	mov    rcx,QWORD PTR [rsp+0x48]
   14000106d:	48 33 cc             	xor    rcx,rsp
   140001070:	e8 ab 32 00 00       	call   0x140004320
   140001075:	48 83 c4 58          	add    rsp,0x58
   140001079:	c3                   	ret
   14000107a:	cc                   	int3
   14000107b:	cc                   	int3
   14000107c:	cc                   	int3
   14000107d:	cc                   	int3
   14000107e:	cc                   	int3
   14000107f:	cc                   	int3
   140001080:	48 81 ec a8 00 00 00 	sub    rsp,0xa8
   140001087:	48 8b 05 72 6f 00 00 	mov    rax,QWORD PTR [rip+0x6f72]        # 0x140008000
   14000108e:	48 33 c4             	xor    rax,rsp
   140001091:	48 89 84 24 90 00 00 	mov    QWORD PTR [rsp+0x90],rax
   140001098:	00 
   140001099:	44 8b c2             	mov    r8d,edx
   14000109c:	c7 44 24 20 01 23 45 	mov    DWORD PTR [rsp+0x20],0x67452301
   1400010a3:	67 
   1400010a4:	48 8b d1             	mov    rdx,rcx
   1400010a7:	c7 44 24 24 89 ab cd 	mov    DWORD PTR [rsp+0x24],0xefcdab89
   1400010ae:	ef 
   1400010af:	33 c0                	xor    eax,eax
   1400010b1:	c7 44 24 28 fe dc ba 	mov    DWORD PTR [rsp+0x28],0x98badcfe
   1400010b8:	98 
   1400010b9:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   1400010be:	48 c7 44 24 2c 76 54 	mov    QWORD PTR [rsp+0x2c],0x10325476
   1400010c5:	32 10 
   1400010c7:	89 44 24 34          	mov    DWORD PTR [rsp+0x34],eax
   1400010cb:	e8 80 0d 00 00       	call   0x140001e50
   1400010d0:	48 8d 54 24 20       	lea    rdx,[rsp+0x20]
   1400010d5:	48 8d 8c 24 80 00 00 	lea    rcx,[rsp+0x80]
   1400010dc:	00 
   1400010dd:	e8 3e 00 00 00       	call   0x140001120
   1400010e2:	8b 84 24 8c 00 00 00 	mov    eax,DWORD PTR [rsp+0x8c]
   1400010e9:	33 84 24 80 00 00 00 	xor    eax,DWORD PTR [rsp+0x80]
   1400010f0:	33 84 24 84 00 00 00 	xor    eax,DWORD PTR [rsp+0x84]
   1400010f7:	33 84 24 88 00 00 00 	xor    eax,DWORD PTR [rsp+0x88]
   1400010fe:	48 8b 8c 24 90 00 00 	mov    rcx,QWORD PTR [rsp+0x90]
   140001105:	00 
   140001106:	48 33 cc             	xor    rcx,rsp
   140001109:	e8 12 32 00 00       	call   0x140004320
   14000110e:	48 81 c4 a8 00 00 00 	add    rsp,0xa8
   140001115:	c3                   	ret
   140001116:	cc                   	int3
   140001117:	cc                   	int3
   140001118:	cc                   	int3
   140001119:	cc                   	int3
   14000111a:	cc                   	int3
   14000111b:	cc                   	int3
   14000111c:	cc                   	int3
   14000111d:	cc                   	int3
   14000111e:	cc                   	int3
   14000111f:	cc                   	int3
   140001120:	48 89 5c 24 20       	mov    QWORD PTR [rsp+0x20],rbx
   140001125:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   14000112a:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   14000112f:	55                   	push   rbp
   140001130:	56                   	push   rsi
   140001131:	57                   	push   rdi
   140001132:	41 54                	push   r12
   140001134:	41 55                	push   r13
   140001136:	41 56                	push   r14
   140001138:	41 57                	push   r15
   14000113a:	48 83 ec 20          	sub    rsp,0x20
   14000113e:	44 8b 42 10          	mov    r8d,DWORD PTR [rdx+0x10]
   140001142:	b8 3f 00 00 00       	mov    eax,0x3f
   140001147:	41 c1 e8 03          	shr    r8d,0x3
   14000114b:	41 83 e0 3f          	and    r8d,0x3f
   14000114f:	41 2b c0             	sub    eax,r8d
   140001152:	45 8b e8             	mov    r13d,r8d
   140001155:	4c 03 ea             	add    r13,rdx
   140001158:	89 44 24 70          	mov    DWORD PTR [rsp+0x70],eax
   14000115c:	41 c6 45 18 80       	mov    BYTE PTR [r13+0x18],0x80
   140001161:	83 f8 08             	cmp    eax,0x8
   140001164:	0f 83 f2 01 00 00    	jae    0x14000135c
   14000116a:	e8 11 31 00 00       	call   0x140004280
   14000116f:	33 d2                	xor    edx,edx
   140001171:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001175:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140001179:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   14000117d:	49 3b dc             	cmp    rbx,r12
   140001180:	0f 84 b7 00 00 00    	je     0x14000123d
   140001186:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   14000118d:	00 00 00 
   140001190:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140001194:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001198:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000119f:	00 
   1400011a0:	85 c9                	test   ecx,ecx
   1400011a2:	0f 84 89 00 00 00    	je     0x140001231
   1400011a8:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   1400011ad:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400011b1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400011b5:	49 03 eb             	add    rbp,r11
   1400011b8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400011bc:	4d 03 f3             	add    r14,r11
   1400011bf:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400011c2:	4d 03 fb             	add    r15,r11
   1400011c5:	44 8b d2             	mov    r10d,edx
   1400011c8:	85 ff                	test   edi,edi
   1400011ca:	74 65                	je     0x140001231
   1400011cc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400011d0:	41 8b f2             	mov    esi,r10d
   1400011d3:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400011da:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   1400011e0:	44 8b 44 b5 00       	mov    r8d,DWORD PTR [rbp+rsi*4+0x0]
   1400011e5:	4d 03 c3             	add    r8,r11
   1400011e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400011ef:	00 
   1400011f0:	48 ff c1             	inc    rcx
   1400011f3:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400011f8:	75 f6                	jne    0x1400011f0
   1400011fa:	48 85 c9             	test   rcx,rcx
   1400011fd:	74 25                	je     0x140001224
   1400011ff:	90                   	nop
   140001200:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140001205:	48 ff c2             	inc    rdx
   140001208:	41 33 c1             	xor    eax,r9d
   14000120b:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140001212:	48 3b d1             	cmp    rdx,rcx
   140001215:	72 e9                	jb     0x140001200
   140001217:	41 81 f9 9f 13 84 b4 	cmp    r9d,0xb484139f
   14000121e:	0f 84 19 01 00 00    	je     0x14000133d
   140001224:	41 ff c2             	inc    r10d
   140001227:	ba 00 00 00 00       	mov    edx,0x0
   14000122c:	44 3b d7             	cmp    r10d,edi
   14000122f:	72 9f                	jb     0x1400011d0
   140001231:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   140001234:	49 3b dc             	cmp    rbx,r12
   140001237:	0f 85 53 ff ff ff    	jne    0x140001190
   14000123d:	4c 8b ca             	mov    r9,rdx
   140001240:	44 8b 44 24 70       	mov    r8d,DWORD PTR [rsp+0x70]
   140001245:	49 8d 4d 19          	lea    rcx,[r13+0x19]
   140001249:	33 d2                	xor    edx,edx
   14000124b:	41 ff d1             	call   r9
   14000124e:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   140001253:	48 8b c8             	mov    rcx,rax
   140001256:	4c 8d 68 18          	lea    r13,[rax+0x18]
   14000125a:	49 8b d5             	mov    rdx,r13
   14000125d:	e8 fe 03 00 00       	call   0x140001660
   140001262:	e8 19 30 00 00       	call   0x140004280
   140001267:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   14000126b:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   14000126f:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140001273:	49 3b f4             	cmp    rsi,r12
   140001276:	0f 84 a8 00 00 00    	je     0x140001324
   14000127c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140001280:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140001284:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001288:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000128f:	00 
   140001290:	85 c9                	test   ecx,ecx
   140001292:	0f 84 80 00 00 00    	je     0x140001318
   140001298:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   14000129d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400012a1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400012a5:	49 03 eb             	add    rbp,r11
   1400012a8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400012ac:	4d 03 f3             	add    r14,r11
   1400012af:	8b 58 18             	mov    ebx,DWORD PTR [rax+0x18]
   1400012b2:	4d 03 fb             	add    r15,r11
   1400012b5:	45 33 d2             	xor    r10d,r10d
   1400012b8:	85 db                	test   ebx,ebx
   1400012ba:	74 5c                	je     0x140001318
   1400012bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400012c0:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   1400012c5:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400012cc:	4d 03 c3             	add    r8,r11
   1400012cf:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   1400012d5:	48 ff c1             	inc    rcx
   1400012d8:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400012dd:	75 f6                	jne    0x1400012d5
   1400012df:	33 d2                	xor    edx,edx
   1400012e1:	48 85 c9             	test   rcx,rcx
   1400012e4:	74 2a                	je     0x140001310
   1400012e6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   1400012ed:	00 00 00 
   1400012f0:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400012f5:	48 ff c2             	inc    rdx
   1400012f8:	41 33 c1             	xor    eax,r9d
   1400012fb:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140001302:	48 3b d1             	cmp    rdx,rcx
   140001305:	72 e9                	jb     0x1400012f0
   140001307:	41 81 f9 9f 13 84 b4 	cmp    r9d,0xb484139f
   14000130e:	74 3e                	je     0x14000134e
   140001310:	41 ff c2             	inc    r10d
   140001313:	44 3b d3             	cmp    r10d,ebx
   140001316:	72 a8                	jb     0x1400012c0
   140001318:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   14000131b:	49 3b f4             	cmp    rsi,r12
   14000131e:	0f 85 5c ff ff ff    	jne    0x140001280
   140001324:	45 33 c9             	xor    r9d,r9d
   140001327:	33 d2                	xor    edx,edx
   140001329:	49 8b cd             	mov    rcx,r13
   14000132c:	44 8d 42 38          	lea    r8d,[rdx+0x38]
   140001330:	41 ff d1             	call   r9
   140001333:	48 8b 4c 24 68       	mov    rcx,QWORD PTR [rsp+0x68]
   140001338:	e9 0e 01 00 00       	jmp    0x14000144b
   14000133d:	41 0f b7 04 76       	movzx  eax,WORD PTR [r14+rsi*2]
   140001342:	45 8b 0c 87          	mov    r9d,DWORD PTR [r15+rax*4]
   140001346:	4d 03 cb             	add    r9,r11
   140001349:	e9 f2 fe ff ff       	jmp    0x140001240
   14000134e:	43 0f b7 04 56       	movzx  eax,WORD PTR [r14+r10*2]
   140001353:	45 8b 0c 87          	mov    r9d,DWORD PTR [r15+rax*4]
   140001357:	4d 03 cb             	add    r9,r11
   14000135a:	eb cb                	jmp    0x140001327
   14000135c:	e8 1f 2f 00 00       	call   0x140004280
   140001361:	33 d2                	xor    edx,edx
   140001363:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001367:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   14000136b:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   14000136f:	49 3b dc             	cmp    rbx,r12
   140001372:	0f 84 b5 00 00 00    	je     0x14000142d
   140001378:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14000137f:	00 
   140001380:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140001384:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001388:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000138f:	00 
   140001390:	85 c9                	test   ecx,ecx
   140001392:	0f 84 89 00 00 00    	je     0x140001421
   140001398:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   14000139d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400013a1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400013a5:	49 03 eb             	add    rbp,r11
   1400013a8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400013ac:	4d 03 f3             	add    r14,r11
   1400013af:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400013b2:	4d 03 fb             	add    r15,r11
   1400013b5:	44 8b d2             	mov    r10d,edx
   1400013b8:	85 ff                	test   edi,edi
   1400013ba:	74 65                	je     0x140001421
   1400013bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400013c0:	41 8b f2             	mov    esi,r10d
   1400013c3:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400013ca:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   1400013d0:	44 8b 44 b5 00       	mov    r8d,DWORD PTR [rbp+rsi*4+0x0]
   1400013d5:	4d 03 c3             	add    r8,r11
   1400013d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400013df:	00 
   1400013e0:	48 ff c1             	inc    rcx
   1400013e3:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400013e8:	75 f6                	jne    0x1400013e0
   1400013ea:	48 85 c9             	test   rcx,rcx
   1400013ed:	74 25                	je     0x140001414
   1400013ef:	90                   	nop
   1400013f0:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400013f5:	48 ff c2             	inc    rdx
   1400013f8:	41 33 c1             	xor    eax,r9d
   1400013fb:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140001402:	48 3b d1             	cmp    rdx,rcx
   140001405:	72 e9                	jb     0x1400013f0
   140001407:	41 81 f9 9f 13 84 b4 	cmp    r9d,0xb484139f
   14000140e:	0f 84 13 01 00 00    	je     0x140001527
   140001414:	41 ff c2             	inc    r10d
   140001417:	ba 00 00 00 00       	mov    edx,0x0
   14000141c:	44 3b d7             	cmp    r10d,edi
   14000141f:	72 9f                	jb     0x1400013c0
   140001421:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   140001424:	49 3b dc             	cmp    rbx,r12
   140001427:	0f 85 53 ff ff ff    	jne    0x140001380
   14000142d:	4c 8b ca             	mov    r9,rdx
   140001430:	44 8b 44 24 70       	mov    r8d,DWORD PTR [rsp+0x70]
   140001435:	49 8d 4d 19          	lea    rcx,[r13+0x19]
   140001439:	41 83 c0 f8          	add    r8d,0xfffffff8
   14000143d:	33 d2                	xor    edx,edx
   14000143f:	41 ff d1             	call   r9
   140001442:	48 8b 4c 24 68       	mov    rcx,QWORD PTR [rsp+0x68]
   140001447:	4c 8d 69 18          	lea    r13,[rcx+0x18]
   14000144b:	8b 41 10             	mov    eax,DWORD PTR [rcx+0x10]
   14000144e:	49 8b d5             	mov    rdx,r13
   140001451:	89 41 50             	mov    DWORD PTR [rcx+0x50],eax
   140001454:	8b 41 14             	mov    eax,DWORD PTR [rcx+0x14]
   140001457:	89 41 54             	mov    DWORD PTR [rcx+0x54],eax
   14000145a:	e8 01 02 00 00       	call   0x140001660
   14000145f:	e8 1c 2e 00 00       	call   0x140004280
   140001464:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001468:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   14000146c:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140001470:	49 3b f4             	cmp    rsi,r12
   140001473:	0f 84 cd 00 00 00    	je     0x140001546
   140001479:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   140001480:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140001484:	45 33 ed             	xor    r13d,r13d
   140001487:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   14000148b:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140001492:	00 
   140001493:	85 c9                	test   ecx,ecx
   140001495:	0f 84 7e 00 00 00    	je     0x140001519
   14000149b:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   1400014a0:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400014a4:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400014a8:	49 03 eb             	add    rbp,r11
   1400014ab:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400014af:	4d 03 f3             	add    r14,r11
   1400014b2:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400014b5:	4d 03 fb             	add    r15,r11
   1400014b8:	45 8b d5             	mov    r10d,r13d
   1400014bb:	85 ff                	test   edi,edi
   1400014bd:	74 5a                	je     0x140001519
   1400014bf:	90                   	nop
   1400014c0:	41 8b da             	mov    ebx,r10d
   1400014c3:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400014ca:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   1400014d0:	44 8b 44 9d 00       	mov    r8d,DWORD PTR [rbp+rbx*4+0x0]
   1400014d5:	4d 03 c3             	add    r8,r11
   1400014d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400014df:	00 
   1400014e0:	48 ff c1             	inc    rcx
   1400014e3:	45 38 2c 08          	cmp    BYTE PTR [r8+rcx*1],r13b
   1400014e7:	75 f7                	jne    0x1400014e0
   1400014e9:	49 8b d5             	mov    rdx,r13
   1400014ec:	48 85 c9             	test   rcx,rcx
   1400014ef:	74 20                	je     0x140001511
   1400014f1:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400014f6:	48 ff c2             	inc    rdx
   1400014f9:	41 33 c1             	xor    eax,r9d
   1400014fc:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140001503:	48 3b d1             	cmp    rdx,rcx
   140001506:	72 e9                	jb     0x1400014f1
   140001508:	41 81 f9 29 fd 35 ee 	cmp    r9d,0xee35fd29
   14000150f:	74 27                	je     0x140001538
   140001511:	41 ff c2             	inc    r10d
   140001514:	44 3b d7             	cmp    r10d,edi
   140001517:	72 a7                	jb     0x1400014c0
   140001519:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   14000151c:	49 3b f4             	cmp    rsi,r12
   14000151f:	0f 85 5b ff ff ff    	jne    0x140001480
   140001525:	eb 22                	jmp    0x140001549
   140001527:	41 0f b7 04 76       	movzx  eax,WORD PTR [r14+rsi*2]
   14000152c:	45 8b 0c 87          	mov    r9d,DWORD PTR [r15+rax*4]
   140001530:	4d 03 cb             	add    r9,r11
   140001533:	e9 f8 fe ff ff       	jmp    0x140001430
   140001538:	41 0f b7 04 5e       	movzx  eax,WORD PTR [r14+rbx*2]
   14000153d:	45 8b 0c 87          	mov    r9d,DWORD PTR [r15+rax*4]
   140001541:	4d 03 cb             	add    r9,r11
   140001544:	eb 06                	jmp    0x14000154c
   140001546:	45 33 ed             	xor    r13d,r13d
   140001549:	4d 8b cd             	mov    r9,r13
   14000154c:	48 8b 54 24 68       	mov    rdx,QWORD PTR [rsp+0x68]
   140001551:	41 b8 10 00 00 00    	mov    r8d,0x10
   140001557:	48 8b 4c 24 60       	mov    rcx,QWORD PTR [rsp+0x60]
   14000155c:	41 ff d1             	call   r9
   14000155f:	e8 1c 2d 00 00       	call   0x140004280
   140001564:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001568:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   14000156c:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140001570:	49 3b f4             	cmp    rsi,r12
   140001573:	0f 84 bb 00 00 00    	je     0x140001634
   140001579:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   140001580:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140001584:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001588:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000158f:	00 
   140001590:	85 c9                	test   ecx,ecx
   140001592:	0f 84 82 00 00 00    	je     0x14000161a
   140001598:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   14000159d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400015a1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400015a5:	49 03 eb             	add    rbp,r11
   1400015a8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400015ac:	4d 03 f3             	add    r14,r11
   1400015af:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400015b2:	4d 03 fb             	add    r15,r11
   1400015b5:	45 8b d5             	mov    r10d,r13d
   1400015b8:	85 ff                	test   edi,edi
   1400015ba:	74 5e                	je     0x14000161a
   1400015bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400015c0:	41 8b da             	mov    ebx,r10d
   1400015c3:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   1400015ca:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   1400015d0:	44 8b 44 9d 00       	mov    r8d,DWORD PTR [rbp+rbx*4+0x0]
   1400015d5:	4d 03 c3             	add    r8,r11
   1400015d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400015df:	00 
   1400015e0:	48 ff c0             	inc    rax
   1400015e3:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   1400015e8:	75 f6                	jne    0x1400015e0
   1400015ea:	49 8b d5             	mov    rdx,r13
   1400015ed:	48 85 c0             	test   rax,rax
   1400015f0:	74 20                	je     0x140001612
   1400015f2:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   1400015f7:	48 ff c2             	inc    rdx
   1400015fa:	41 33 c9             	xor    ecx,r9d
   1400015fd:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140001604:	48 3b d0             	cmp    rdx,rax
   140001607:	72 e9                	jb     0x1400015f2
   140001609:	41 81 f9 9f 13 84 b4 	cmp    r9d,0xb484139f
   140001610:	74 16                	je     0x140001628
   140001612:	41 ff c2             	inc    r10d
   140001615:	44 3b d7             	cmp    r10d,edi
   140001618:	72 a6                	jb     0x1400015c0
   14000161a:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   14000161d:	49 3b f4             	cmp    rsi,r12
   140001620:	0f 85 5a ff ff ff    	jne    0x140001580
   140001626:	eb 0c                	jmp    0x140001634
   140001628:	41 0f b7 04 5e       	movzx  eax,WORD PTR [r14+rbx*2]
   14000162d:	45 8b 2c 87          	mov    r13d,DWORD PTR [r15+rax*4]
   140001631:	4d 03 eb             	add    r13,r11
   140001634:	48 8b 4c 24 68       	mov    rcx,QWORD PTR [rsp+0x68]
   140001639:	33 d2                	xor    edx,edx
   14000163b:	44 8d 42 08          	lea    r8d,[rdx+0x8]
   14000163f:	49 8b c5             	mov    rax,r13
   140001642:	48 8b 5c 24 78       	mov    rbx,QWORD PTR [rsp+0x78]
   140001647:	48 83 c4 20          	add    rsp,0x20
   14000164b:	41 5f                	pop    r15
   14000164d:	41 5e                	pop    r14
   14000164f:	41 5d                	pop    r13
   140001651:	41 5c                	pop    r12
   140001653:	5f                   	pop    rdi
   140001654:	5e                   	pop    rsi
   140001655:	5d                   	pop    rbp
   140001656:	48 ff e0             	rex.W jmp rax
   140001659:	cc                   	int3
   14000165a:	cc                   	int3
   14000165b:	cc                   	int3
   14000165c:	cc                   	int3
   14000165d:	cc                   	int3
   14000165e:	cc                   	int3
   14000165f:	cc                   	int3
   140001660:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   140001665:	53                   	push   rbx
   140001666:	55                   	push   rbp
   140001667:	56                   	push   rsi
   140001668:	57                   	push   rdi
   140001669:	41 54                	push   r12
   14000166b:	41 55                	push   r13
   14000166d:	41 56                	push   r14
   14000166f:	41 57                	push   r15
   140001671:	48 83 ec 28          	sub    rsp,0x28
   140001675:	44 8b 51 04          	mov    r10d,DWORD PTR [rcx+0x4]
   140001679:	48 8b da             	mov    rbx,rdx
   14000167c:	44 8b 49 08          	mov    r9d,DWORD PTR [rcx+0x8]
   140001680:	44 8b 41 0c          	mov    r8d,DWORD PTR [rcx+0xc]
   140001684:	41 8b c0             	mov    eax,r8d
   140001687:	8b 11                	mov    edx,DWORD PTR [rcx]
   140001689:	41 33 c1             	xor    eax,r9d
   14000168c:	41 23 c2             	and    eax,r10d
   14000168f:	8b 0b                	mov    ecx,DWORD PTR [rbx]
   140001691:	41 33 c0             	xor    eax,r8d
   140001694:	44 8b 63 14          	mov    r12d,DWORD PTR [rbx+0x14]
   140001698:	03 c1                	add    eax,ecx
   14000169a:	89 4c 24 78          	mov    DWORD PTR [rsp+0x78],ecx
   14000169e:	8d 8a 78 a4 6a d7    	lea    ecx,[rdx-0x28955b88]
   1400016a4:	8b 53 04             	mov    edx,DWORD PTR [rbx+0x4]
   1400016a7:	03 c8                	add    ecx,eax
   1400016a9:	89 94 24 88 00 00 00 	mov    DWORD PTR [rsp+0x88],edx
   1400016b0:	c1 c9 19             	ror    ecx,0x19
   1400016b3:	41 8b c1             	mov    eax,r9d
   1400016b6:	41 33 c2             	xor    eax,r10d
   1400016b9:	41 03 ca             	add    ecx,r10d
   1400016bc:	23 c1                	and    eax,ecx
   1400016be:	41 33 c1             	xor    eax,r9d
   1400016c1:	03 c2                	add    eax,edx
   1400016c3:	41 8d 90 56 b7 c7 e8 	lea    edx,[r8-0x173848aa]
   1400016ca:	44 8b 43 08          	mov    r8d,DWORD PTR [rbx+0x8]
   1400016ce:	03 d0                	add    edx,eax
   1400016d0:	c1 ca 14             	ror    edx,0x14
   1400016d3:	41 8b c2             	mov    eax,r10d
   1400016d6:	33 c1                	xor    eax,ecx
   1400016d8:	44 89 44 24 0c       	mov    DWORD PTR [rsp+0xc],r8d
   1400016dd:	03 d1                	add    edx,ecx
   1400016df:	23 c2                	and    eax,edx
   1400016e1:	41 33 c2             	xor    eax,r10d
   1400016e4:	41 03 c0             	add    eax,r8d
   1400016e7:	45 8d 81 db 70 20 24 	lea    r8d,[r9+0x242070db]
   1400016ee:	44 8b 4b 0c          	mov    r9d,DWORD PTR [rbx+0xc]
   1400016f2:	44 03 c0             	add    r8d,eax
   1400016f5:	8b c2                	mov    eax,edx
   1400016f7:	44 89 8c 24 80 00 00 	mov    DWORD PTR [rsp+0x80],r9d
   1400016fe:	00 
   1400016ff:	33 c1                	xor    eax,ecx
   140001701:	41 c1 c8 0f          	ror    r8d,0xf
   140001705:	44 03 c2             	add    r8d,edx
   140001708:	41 23 c0             	and    eax,r8d
   14000170b:	33 c1                	xor    eax,ecx
   14000170d:	41 03 c1             	add    eax,r9d
   140001710:	45 8d 8a ee ce bd c1 	lea    r9d,[r10-0x3e423112]
   140001717:	44 8b 53 10          	mov    r10d,DWORD PTR [rbx+0x10]
   14000171b:	44 03 c8             	add    r9d,eax
   14000171e:	8b c2                	mov    eax,edx
   140001720:	44 89 54 24 04       	mov    DWORD PTR [rsp+0x4],r10d
   140001725:	41 33 c0             	xor    eax,r8d
   140001728:	41 c1 c9 0a          	ror    r9d,0xa
   14000172c:	45 03 c8             	add    r9d,r8d
   14000172f:	41 23 c1             	and    eax,r9d
   140001732:	33 c2                	xor    eax,edx
   140001734:	41 03 c2             	add    eax,r10d
   140001737:	44 8d 91 af 0f 7c f5 	lea    r10d,[rcx-0xa83f051]
   14000173e:	44 03 d0             	add    r10d,eax
   140001741:	8d 8a 2a c6 87 47    	lea    ecx,[rdx+0x4787c62a]
   140001747:	8b 53 18             	mov    edx,DWORD PTR [rbx+0x18]
   14000174a:	41 8b c0             	mov    eax,r8d
   14000174d:	41 33 c1             	xor    eax,r9d
   140001750:	89 14 24             	mov    DWORD PTR [rsp],edx
   140001753:	41 c1 ca 19          	ror    r10d,0x19
   140001757:	45 03 d1             	add    r10d,r9d
   14000175a:	41 23 c2             	and    eax,r10d
   14000175d:	41 33 c0             	xor    eax,r8d
   140001760:	41 03 c4             	add    eax,r12d
   140001763:	03 c8                	add    ecx,eax
   140001765:	41 8b c1             	mov    eax,r9d
   140001768:	41 33 c2             	xor    eax,r10d
   14000176b:	c1 c9 14             	ror    ecx,0x14
   14000176e:	41 03 ca             	add    ecx,r10d
   140001771:	23 c1                	and    eax,ecx
   140001773:	41 33 c1             	xor    eax,r9d
   140001776:	03 c2                	add    eax,edx
   140001778:	41 8d 90 13 46 30 a8 	lea    edx,[r8-0x57cfb9ed]
   14000177f:	03 d0                	add    edx,eax
   140001781:	c1 ca 0f             	ror    edx,0xf
   140001784:	03 d1                	add    edx,ecx
   140001786:	8b 6b 1c             	mov    ebp,DWORD PTR [rbx+0x1c]
   140001789:	45 8d 81 01 95 46 fd 	lea    r8d,[r9-0x2b96aff]
   140001790:	44 8b 6b 20          	mov    r13d,DWORD PTR [rbx+0x20]
   140001794:	45 8d 8a d8 98 80 69 	lea    r9d,[r10+0x698098d8]
   14000179b:	44 8b 73 28          	mov    r14d,DWORD PTR [rbx+0x28]
   14000179f:	8b c1                	mov    eax,ecx
   1400017a1:	41 33 c2             	xor    eax,r10d
   1400017a4:	8b 73 30             	mov    esi,DWORD PTR [rbx+0x30]
   1400017a7:	23 c2                	and    eax,edx
   1400017a9:	44 8b 7b 34          	mov    r15d,DWORD PTR [rbx+0x34]
   1400017ad:	41 33 c2             	xor    eax,r10d
   1400017b0:	8b 7b 38             	mov    edi,DWORD PTR [rbx+0x38]
   1400017b3:	44 8b 53 24          	mov    r10d,DWORD PTR [rbx+0x24]
   1400017b7:	03 c5                	add    eax,ebp
   1400017b9:	44 03 c0             	add    r8d,eax
   1400017bc:	44 89 54 24 10       	mov    DWORD PTR [rsp+0x10],r10d
   1400017c1:	41 c1 c8 0a          	ror    r8d,0xa
   1400017c5:	8b c1                	mov    eax,ecx
   1400017c7:	33 c2                	xor    eax,edx
   1400017c9:	44 03 c2             	add    r8d,edx
   1400017cc:	41 23 c0             	and    eax,r8d
   1400017cf:	33 c1                	xor    eax,ecx
   1400017d1:	41 03 c5             	add    eax,r13d
   1400017d4:	44 03 c8             	add    r9d,eax
   1400017d7:	45 8d 98 be d7 5c 89 	lea    r11d,[r8-0x76a32842]
   1400017de:	8b c2                	mov    eax,edx
   1400017e0:	41 c1 c9 19          	ror    r9d,0x19
   1400017e4:	41 33 c0             	xor    eax,r8d
   1400017e7:	45 03 c8             	add    r9d,r8d
   1400017ea:	41 23 c1             	and    eax,r9d
   1400017ed:	33 c2                	xor    eax,edx
   1400017ef:	41 03 c2             	add    eax,r10d
   1400017f2:	44 8d 91 af f7 44 8b 	lea    r10d,[rcx-0x74bb0851]
   1400017f9:	44 03 d0             	add    r10d,eax
   1400017fc:	8d 8a b1 5b ff ff    	lea    ecx,[rdx-0xa44f]
   140001802:	8b 53 2c             	mov    edx,DWORD PTR [rbx+0x2c]
   140001805:	41 8b c0             	mov    eax,r8d
   140001808:	41 33 c1             	xor    eax,r9d
   14000180b:	89 54 24 08          	mov    DWORD PTR [rsp+0x8],edx
   14000180f:	41 c1 ca 14          	ror    r10d,0x14
   140001813:	45 03 d1             	add    r10d,r9d
   140001816:	41 23 c2             	and    eax,r10d
   140001819:	41 33 c0             	xor    eax,r8d
   14000181c:	41 03 c6             	add    eax,r14d
   14000181f:	03 c8                	add    ecx,eax
   140001821:	41 8b c2             	mov    eax,r10d
   140001824:	41 33 c1             	xor    eax,r9d
   140001827:	c1 c9 0f             	ror    ecx,0xf
   14000182a:	41 03 ca             	add    ecx,r10d
   14000182d:	23 c1                	and    eax,ecx
   14000182f:	44 8b c1             	mov    r8d,ecx
   140001832:	41 33 c1             	xor    eax,r9d
   140001835:	03 c2                	add    eax,edx
   140001837:	41 8d 91 22 11 90 6b 	lea    edx,[r9+0x6b901122]
   14000183e:	44 03 d8             	add    r11d,eax
   140001841:	44 8d 89 8e 43 79 a6 	lea    r9d,[rcx-0x5986bc72]
   140001848:	41 c1 cb 0a          	ror    r11d,0xa
   14000184c:	41 8b c2             	mov    eax,r10d
   14000184f:	33 c1                	xor    eax,ecx
   140001851:	44 03 d9             	add    r11d,ecx
   140001854:	41 23 c3             	and    eax,r11d
   140001857:	45 33 c3             	xor    r8d,r11d
   14000185a:	41 33 c2             	xor    eax,r10d
   14000185d:	03 c6                	add    eax,esi
   14000185f:	03 d0                	add    edx,eax
   140001861:	41 8b c3             	mov    eax,r11d
   140001864:	c1 ca 19             	ror    edx,0x19
   140001867:	41 03 d3             	add    edx,r11d
   14000186a:	44 23 c2             	and    r8d,edx
   14000186d:	33 c2                	xor    eax,edx
   14000186f:	44 33 c1             	xor    r8d,ecx
   140001872:	41 81 c0 93 71 98 fd 	add    r8d,0xfd987193
   140001879:	45 03 c7             	add    r8d,r15d
   14000187c:	45 03 c2             	add    r8d,r10d
   14000187f:	41 c1 c8 14          	ror    r8d,0x14
   140001883:	44 03 c2             	add    r8d,edx
   140001886:	41 23 c0             	and    eax,r8d
   140001889:	41 33 c3             	xor    eax,r11d
   14000188c:	03 c7                	add    eax,edi
   14000188e:	44 03 c8             	add    r9d,eax
   140001891:	41 c1 c9 0f          	ror    r9d,0xf
   140001895:	8b 5b 3c             	mov    ebx,DWORD PTR [rbx+0x3c]
   140001898:	45 03 c8             	add    r9d,r8d
   14000189b:	41 8b c8             	mov    ecx,r8d
   14000189e:	41 8b c1             	mov    eax,r9d
   1400018a1:	33 ca                	xor    ecx,edx
   1400018a3:	41 23 c9             	and    ecx,r9d
   1400018a6:	33 ca                	xor    ecx,edx
   1400018a8:	81 c1 21 08 b4 49    	add    ecx,0x49b40821
   1400018ae:	03 cb                	add    ecx,ebx
   1400018b0:	41 03 cb             	add    ecx,r11d
   1400018b3:	c1 c9 0a             	ror    ecx,0xa
   1400018b6:	41 03 c9             	add    ecx,r9d
   1400018b9:	33 c1                	xor    eax,ecx
   1400018bb:	41 23 c0             	and    eax,r8d
   1400018be:	41 33 c1             	xor    eax,r9d
   1400018c1:	05 62 25 1e f6       	add    eax,0xf61e2562
   1400018c6:	44 8d 91 aa c7 b6 e9 	lea    r10d,[rcx-0x16493856]
   1400018cd:	03 84 24 88 00 00 00 	add    eax,DWORD PTR [rsp+0x88]
   1400018d4:	03 d0                	add    edx,eax
   1400018d6:	8b c1                	mov    eax,ecx
   1400018d8:	c1 ca 1b             	ror    edx,0x1b
   1400018db:	03 d1                	add    edx,ecx
   1400018dd:	33 c2                	xor    eax,edx
   1400018df:	41 23 c1             	and    eax,r9d
   1400018e2:	33 c1                	xor    eax,ecx
   1400018e4:	05 40 b3 40 c0       	add    eax,0xc040b340
   1400018e9:	03 04 24             	add    eax,DWORD PTR [rsp]
   1400018ec:	44 03 c0             	add    r8d,eax
   1400018ef:	41 c1 c8 17          	ror    r8d,0x17
   1400018f3:	44 03 c2             	add    r8d,edx
   1400018f6:	41 8b c0             	mov    eax,r8d
   1400018f9:	33 c2                	xor    eax,edx
   1400018fb:	23 c1                	and    eax,ecx
   1400018fd:	8d 8a 5d 10 2f d6    	lea    ecx,[rdx-0x29d0efa3]
   140001903:	33 c2                	xor    eax,edx
   140001905:	05 51 5a 5e 26       	add    eax,0x265e5a51
   14000190a:	03 44 24 08          	add    eax,DWORD PTR [rsp+0x8]
   14000190e:	44 03 c8             	add    r9d,eax
   140001911:	41 8b c0             	mov    eax,r8d
   140001914:	41 c1 c9 12          	ror    r9d,0x12
   140001918:	45 03 c8             	add    r9d,r8d
   14000191b:	41 33 c1             	xor    eax,r9d
   14000191e:	23 c2                	and    eax,edx
   140001920:	41 8d 90 53 14 44 02 	lea    edx,[r8+0x2441453]
   140001927:	41 33 c0             	xor    eax,r8d
   14000192a:	03 44 24 78          	add    eax,DWORD PTR [rsp+0x78]
   14000192e:	44 03 d0             	add    r10d,eax
   140001931:	41 8b c1             	mov    eax,r9d
   140001934:	41 c1 ca 0c          	ror    r10d,0xc
   140001938:	45 03 d1             	add    r10d,r9d
   14000193b:	41 33 c2             	xor    eax,r10d
   14000193e:	41 23 c0             	and    eax,r8d
   140001941:	45 8d 81 81 e6 a1 d8 	lea    r8d,[r9-0x275e197f]
   140001948:	41 33 c1             	xor    eax,r9d
   14000194b:	41 03 c4             	add    eax,r12d
   14000194e:	03 c8                	add    ecx,eax
   140001950:	41 8b c2             	mov    eax,r10d
   140001953:	c1 c9 1b             	ror    ecx,0x1b
   140001956:	41 03 ca             	add    ecx,r10d
   140001959:	33 c1                	xor    eax,ecx
   14000195b:	41 23 c1             	and    eax,r9d
   14000195e:	45 8d 8a c8 fb d3 e7 	lea    r9d,[r10-0x182c0438]
   140001965:	41 33 c2             	xor    eax,r10d
   140001968:	41 03 c6             	add    eax,r14d
   14000196b:	03 d0                	add    edx,eax
   14000196d:	c1 ca 17             	ror    edx,0x17
   140001970:	03 d1                	add    edx,ecx
   140001972:	8b c2                	mov    eax,edx
   140001974:	33 c1                	xor    eax,ecx
   140001976:	41 23 c2             	and    eax,r10d
   140001979:	33 c1                	xor    eax,ecx
   14000197b:	03 c3                	add    eax,ebx
   14000197d:	44 03 c0             	add    r8d,eax
   140001980:	8b c2                	mov    eax,edx
   140001982:	41 c1 c8 12          	ror    r8d,0x12
   140001986:	44 03 c2             	add    r8d,edx
   140001989:	41 33 c0             	xor    eax,r8d
   14000198c:	23 c1                	and    eax,ecx
   14000198e:	33 c2                	xor    eax,edx
   140001990:	03 44 24 04          	add    eax,DWORD PTR [rsp+0x4]
   140001994:	44 03 c8             	add    r9d,eax
   140001997:	44 8d 91 e6 cd e1 21 	lea    r10d,[rcx+0x21e1cde6]
   14000199e:	41 c1 c9 0c          	ror    r9d,0xc
   1400019a2:	45 03 c8             	add    r9d,r8d
   1400019a5:	8d 8a d6 07 37 c3    	lea    ecx,[rdx-0x3cc8f82a]
   1400019ab:	41 8b c0             	mov    eax,r8d
   1400019ae:	41 33 c1             	xor    eax,r9d
   1400019b1:	23 c2                	and    eax,edx
   1400019b3:	41 8d 90 87 0d d5 f4 	lea    edx,[r8-0xb2af279]
   1400019ba:	41 33 c0             	xor    eax,r8d
   1400019bd:	45 8d 99 ed 14 5a 45 	lea    r11d,[r9+0x455a14ed]
   1400019c4:	03 44 24 10          	add    eax,DWORD PTR [rsp+0x10]
   1400019c8:	44 03 d0             	add    r10d,eax
   1400019cb:	41 8b c1             	mov    eax,r9d
   1400019ce:	41 c1 ca 1b          	ror    r10d,0x1b
   1400019d2:	45 03 d1             	add    r10d,r9d
   1400019d5:	41 33 c2             	xor    eax,r10d
   1400019d8:	41 23 c0             	and    eax,r8d
   1400019db:	41 33 c1             	xor    eax,r9d
   1400019de:	03 c7                	add    eax,edi
   1400019e0:	45 8d 82 05 e9 e3 a9 	lea    r8d,[r10-0x561c16fb]
   1400019e7:	03 c8                	add    ecx,eax
   1400019e9:	c1 c9 17             	ror    ecx,0x17
   1400019ec:	41 03 ca             	add    ecx,r10d
   1400019ef:	8b c1                	mov    eax,ecx
   1400019f1:	41 33 c2             	xor    eax,r10d
   1400019f4:	41 23 c1             	and    eax,r9d
   1400019f7:	41 33 c2             	xor    eax,r10d
   1400019fa:	44 8d 89 f8 a3 ef fc 	lea    r9d,[rcx-0x3105c08]
   140001a01:	03 84 24 80 00 00 00 	add    eax,DWORD PTR [rsp+0x80]
   140001a08:	03 d0                	add    edx,eax
   140001a0a:	8b c1                	mov    eax,ecx
   140001a0c:	c1 ca 12             	ror    edx,0x12
   140001a0f:	03 d1                	add    edx,ecx
   140001a11:	33 c2                	xor    eax,edx
   140001a13:	41 23 c2             	and    eax,r10d
   140001a16:	33 c1                	xor    eax,ecx
   140001a18:	41 03 c5             	add    eax,r13d
   140001a1b:	44 8d 92 d9 02 6f 67 	lea    r10d,[rdx+0x676f02d9]
   140001a22:	44 03 d8             	add    r11d,eax
   140001a25:	8b c2                	mov    eax,edx
   140001a27:	41 c1 cb 0c          	ror    r11d,0xc
   140001a2b:	44 03 da             	add    r11d,edx
   140001a2e:	41 33 c3             	xor    eax,r11d
   140001a31:	23 c1                	and    eax,ecx
   140001a33:	33 c2                	xor    eax,edx
   140001a35:	41 03 c7             	add    eax,r15d
   140001a38:	44 03 c0             	add    r8d,eax
   140001a3b:	41 8b c3             	mov    eax,r11d
   140001a3e:	41 c1 c8 1b          	ror    r8d,0x1b
   140001a42:	45 03 c3             	add    r8d,r11d
   140001a45:	41 33 c0             	xor    eax,r8d
   140001a48:	23 c2                	and    eax,edx
   140001a4a:	41 8d 93 8a 4c 2a 8d 	lea    edx,[r11-0x72d5b376]
   140001a51:	41 33 c3             	xor    eax,r11d
   140001a54:	03 44 24 0c          	add    eax,DWORD PTR [rsp+0xc]
   140001a58:	44 03 c8             	add    r9d,eax
   140001a5b:	41 c1 c9 17          	ror    r9d,0x17
   140001a5f:	45 03 c8             	add    r9d,r8d
   140001a62:	41 8b c1             	mov    eax,r9d
   140001a65:	41 8b c9             	mov    ecx,r9d
   140001a68:	41 33 c0             	xor    eax,r8d
   140001a6b:	41 23 c3             	and    eax,r11d
   140001a6e:	41 33 c0             	xor    eax,r8d
   140001a71:	03 c5                	add    eax,ebp
   140001a73:	44 03 d0             	add    r10d,eax
   140001a76:	41 c1 ca 12          	ror    r10d,0x12
   140001a7a:	45 03 d1             	add    r10d,r9d
   140001a7d:	41 33 ca             	xor    ecx,r10d
   140001a80:	8b c1                	mov    eax,ecx
   140001a82:	41 23 c0             	and    eax,r8d
   140001a85:	41 33 c1             	xor    eax,r9d
   140001a88:	03 c6                	add    eax,esi
   140001a8a:	03 d0                	add    edx,eax
   140001a8c:	c1 ca 0c             	ror    edx,0xc
   140001a8f:	41 03 d2             	add    edx,r10d
   140001a92:	33 ca                	xor    ecx,edx
   140001a94:	81 c1 42 39 fa ff    	add    ecx,0xfffa3942
   140001a9a:	41 03 cc             	add    ecx,r12d
   140001a9d:	44 03 c1             	add    r8d,ecx
   140001aa0:	41 c1 c8 1c          	ror    r8d,0x1c
   140001aa4:	44 03 c2             	add    r8d,edx
   140001aa7:	41 8b c2             	mov    eax,r10d
   140001aaa:	44 8d 9a 0c 38 e5 fd 	lea    r11d,[rdx-0x21ac7f4]
   140001ab1:	33 c2                	xor    eax,edx
   140001ab3:	41 33 c0             	xor    eax,r8d
   140001ab6:	05 81 f6 71 87       	add    eax,0x8771f681
   140001abb:	41 03 c5             	add    eax,r13d
   140001abe:	44 03 c8             	add    r9d,eax
   140001ac1:	41 c1 c9 15          	ror    r9d,0x15
   140001ac5:	45 03 c8             	add    r9d,r8d
   140001ac8:	41 8b c1             	mov    eax,r9d
   140001acb:	41 8b c9             	mov    ecx,r9d
   140001ace:	33 c2                	xor    eax,edx
   140001ad0:	41 8d 90 44 ea be a4 	lea    edx,[r8-0x5b4115bc]
   140001ad7:	41 33 c0             	xor    eax,r8d
   140001ada:	05 22 61 9d 6d       	add    eax,0x6d9d6122
   140001adf:	03 44 24 08          	add    eax,DWORD PTR [rsp+0x8]
   140001ae3:	44 03 d0             	add    r10d,eax
   140001ae6:	41 c1 ca 10          	ror    r10d,0x10
   140001aea:	45 03 d1             	add    r10d,r9d
   140001aed:	41 33 ca             	xor    ecx,r10d
   140001af0:	8b c1                	mov    eax,ecx
   140001af2:	41 33 c0             	xor    eax,r8d
   140001af5:	45 8d 81 a9 cf de 4b 	lea    r8d,[r9+0x4bdecfa9]
   140001afc:	03 c7                	add    eax,edi
   140001afe:	45 8d 8a 60 4b bb f6 	lea    r9d,[r10-0x944b4a0]
   140001b05:	44 03 d8             	add    r11d,eax
   140001b08:	41 8b c2             	mov    eax,r10d
   140001b0b:	41 c1 cb 09          	ror    r11d,0x9
   140001b0f:	45 03 da             	add    r11d,r10d
   140001b12:	41 33 c3             	xor    eax,r11d
   140001b15:	41 33 cb             	xor    ecx,r11d
   140001b18:	03 8c 24 88 00 00 00 	add    ecx,DWORD PTR [rsp+0x88]
   140001b1f:	03 d1                	add    edx,ecx
   140001b21:	45 8d 93 70 bc bf be 	lea    r10d,[r11-0x41404390]
   140001b28:	c1 ca 1c             	ror    edx,0x1c
   140001b2b:	41 03 d3             	add    edx,r11d
   140001b2e:	33 c2                	xor    eax,edx
   140001b30:	03 44 24 04          	add    eax,DWORD PTR [rsp+0x4]
   140001b34:	44 03 c0             	add    r8d,eax
   140001b37:	41 c1 c8 15          	ror    r8d,0x15
   140001b3b:	44 03 c2             	add    r8d,edx
   140001b3e:	41 8b c0             	mov    eax,r8d
   140001b41:	41 8b c8             	mov    ecx,r8d
   140001b44:	41 33 c3             	xor    eax,r11d
   140001b47:	44 8d 9a c6 7e 9b 28 	lea    r11d,[rdx+0x289b7ec6]
   140001b4e:	33 c2                	xor    eax,edx
   140001b50:	03 c5                	add    eax,ebp
   140001b52:	44 03 c8             	add    r9d,eax
   140001b55:	41 c1 c9 10          	ror    r9d,0x10
   140001b59:	45 03 c8             	add    r9d,r8d
   140001b5c:	41 33 c9             	xor    ecx,r9d
   140001b5f:	8b c1                	mov    eax,ecx
   140001b61:	33 c2                	xor    eax,edx
   140001b63:	41 03 c6             	add    eax,r14d
   140001b66:	44 03 d0             	add    r10d,eax
   140001b69:	41 8b c1             	mov    eax,r9d
   140001b6c:	41 c1 ca 09          	ror    r10d,0x9
   140001b70:	45 03 d1             	add    r10d,r9d
   140001b73:	41 33 c2             	xor    eax,r10d
   140001b76:	41 33 ca             	xor    ecx,r10d
   140001b79:	41 03 cf             	add    ecx,r15d
   140001b7c:	44 03 d9             	add    r11d,ecx
   140001b7f:	41 c1 cb 1c          	ror    r11d,0x1c
   140001b83:	45 03 da             	add    r11d,r10d
   140001b86:	41 33 c3             	xor    eax,r11d
   140001b89:	05 fa 27 a1 ea       	add    eax,0xeaa127fa
   140001b8e:	03 44 24 78          	add    eax,DWORD PTR [rsp+0x78]
   140001b92:	44 03 c0             	add    r8d,eax
   140001b95:	41 c1 c8 15          	ror    r8d,0x15
   140001b99:	45 03 c3             	add    r8d,r11d
   140001b9c:	41 8b c0             	mov    eax,r8d
   140001b9f:	41 8b c8             	mov    ecx,r8d
   140001ba2:	41 33 c2             	xor    eax,r10d
   140001ba5:	41 33 c3             	xor    eax,r11d
   140001ba8:	05 85 30 ef d4       	add    eax,0xd4ef3085
   140001bad:	03 84 24 80 00 00 00 	add    eax,DWORD PTR [rsp+0x80]
   140001bb4:	44 03 c8             	add    r9d,eax
   140001bb7:	41 c1 c9 10          	ror    r9d,0x10
   140001bbb:	45 03 c8             	add    r9d,r8d
   140001bbe:	41 33 c9             	xor    ecx,r9d
   140001bc1:	8b c1                	mov    eax,ecx
   140001bc3:	41 33 c3             	xor    eax,r11d
   140001bc6:	41 8d 92 05 1d 88 04 	lea    edx,[r10+0x4881d05]
   140001bcd:	03 04 24             	add    eax,DWORD PTR [rsp]
   140001bd0:	03 d0                	add    edx,eax
   140001bd2:	41 8b c1             	mov    eax,r9d
   140001bd5:	c1 ca 09             	ror    edx,0x9
   140001bd8:	41 03 d1             	add    edx,r9d
   140001bdb:	33 c2                	xor    eax,edx
   140001bdd:	33 ca                	xor    ecx,edx
   140001bdf:	03 4c 24 10          	add    ecx,DWORD PTR [rsp+0x10]
   140001be3:	44 8d 91 39 d0 d4 d9 	lea    r10d,[rcx-0x262b2fc7]
   140001bea:	41 8d 88 e5 99 db e6 	lea    ecx,[r8-0x1924661b]
   140001bf1:	45 03 d3             	add    r10d,r11d
   140001bf4:	45 8d 81 f8 7c a2 1f 	lea    r8d,[r9+0x1fa27cf8]
   140001bfb:	41 c1 ca 1c          	ror    r10d,0x1c
   140001bff:	44 03 d2             	add    r10d,edx
   140001c02:	44 8d 8a 65 56 ac c4 	lea    r9d,[rdx-0x3b53a99b]
   140001c09:	41 33 c2             	xor    eax,r10d
   140001c0c:	03 c6                	add    eax,esi
   140001c0e:	03 c8                	add    ecx,eax
   140001c10:	c1 c9 15             	ror    ecx,0x15
   140001c13:	41 03 ca             	add    ecx,r10d
   140001c16:	8b c1                	mov    eax,ecx
   140001c18:	33 c2                	xor    eax,edx
   140001c1a:	41 8d 92 44 22 29 f4 	lea    edx,[r10-0xbd6ddbc]
   140001c21:	41 33 c2             	xor    eax,r10d
   140001c24:	03 c3                	add    eax,ebx
   140001c26:	44 03 c0             	add    r8d,eax
   140001c29:	8b c1                	mov    eax,ecx
   140001c2b:	41 c1 c8 10          	ror    r8d,0x10
   140001c2f:	44 03 c1             	add    r8d,ecx
   140001c32:	41 33 c0             	xor    eax,r8d
   140001c35:	41 33 c2             	xor    eax,r10d
   140001c38:	44 8d 91 97 ff 2a 43 	lea    r10d,[rcx+0x432aff97]
   140001c3f:	03 44 24 0c          	add    eax,DWORD PTR [rsp+0xc]
   140001c43:	44 03 c8             	add    r9d,eax
   140001c46:	8b c1                	mov    eax,ecx
   140001c48:	f7 d0                	not    eax
   140001c4a:	41 c1 c9 09          	ror    r9d,0x9
   140001c4e:	45 03 c8             	add    r9d,r8d
   140001c51:	41 8d 88 a7 23 94 ab 	lea    ecx,[r8-0x546bdc59]
   140001c58:	41 0b c1             	or     eax,r9d
   140001c5b:	41 33 c0             	xor    eax,r8d
   140001c5e:	03 44 24 78          	add    eax,DWORD PTR [rsp+0x78]
   140001c62:	03 d0                	add    edx,eax
   140001c64:	41 8b c0             	mov    eax,r8d
   140001c67:	f7 d0                	not    eax
   140001c69:	c1 ca 1a             	ror    edx,0x1a
   140001c6c:	41 03 d1             	add    edx,r9d
   140001c6f:	45 8d 81 39 a0 93 fc 	lea    r8d,[r9-0x36c5fc7]
   140001c76:	0b c2                	or     eax,edx
   140001c78:	41 33 c1             	xor    eax,r9d
   140001c7b:	03 c5                	add    eax,ebp
   140001c7d:	44 03 d0             	add    r10d,eax
   140001c80:	41 8b c1             	mov    eax,r9d
   140001c83:	f7 d0                	not    eax
   140001c85:	41 c1 ca 16          	ror    r10d,0x16
   140001c89:	44 03 d2             	add    r10d,edx
   140001c8c:	44 8d 8a c3 59 5b 65 	lea    r9d,[rdx+0x655b59c3]
   140001c93:	41 0b c2             	or     eax,r10d
   140001c96:	33 c2                	xor    eax,edx
   140001c98:	03 c7                	add    eax,edi
   140001c9a:	03 c8                	add    ecx,eax
   140001c9c:	8b c2                	mov    eax,edx
   140001c9e:	f7 d0                	not    eax
   140001ca0:	c1 c9 11             	ror    ecx,0x11
   140001ca3:	41 03 ca             	add    ecx,r10d
   140001ca6:	0b c1                	or     eax,ecx
   140001ca8:	41 33 c2             	xor    eax,r10d
   140001cab:	41 03 c4             	add    eax,r12d
   140001cae:	44 03 c0             	add    r8d,eax
   140001cb1:	41 8b c2             	mov    eax,r10d
   140001cb4:	f7 d0                	not    eax
   140001cb6:	41 c1 c8 0b          	ror    r8d,0xb
   140001cba:	44 03 c1             	add    r8d,ecx
   140001cbd:	41 0b c0             	or     eax,r8d
   140001cc0:	33 c1                	xor    eax,ecx
   140001cc2:	03 c6                	add    eax,esi
   140001cc4:	44 03 c8             	add    r9d,eax
   140001cc7:	41 c1 c9 1a          	ror    r9d,0x1a
   140001ccb:	45 03 c8             	add    r9d,r8d
   140001cce:	41 8d 92 92 cc 0c 8f 	lea    edx,[r10-0x70f3336e]
   140001cd5:	8b c1                	mov    eax,ecx
   140001cd7:	f7 d0                	not    eax
   140001cd9:	44 8d 91 7d f4 ef ff 	lea    r10d,[rcx-0x100b83]
   140001ce0:	41 0b c1             	or     eax,r9d
   140001ce3:	41 8d 88 d1 5d 84 85 	lea    ecx,[r8-0x7a7ba22f]
   140001cea:	41 33 c0             	xor    eax,r8d
   140001ced:	03 84 24 80 00 00 00 	add    eax,DWORD PTR [rsp+0x80]
   140001cf4:	03 d0                	add    edx,eax
   140001cf6:	41 8b c0             	mov    eax,r8d
   140001cf9:	f7 d0                	not    eax
   140001cfb:	c1 ca 16             	ror    edx,0x16
   140001cfe:	41 03 d1             	add    edx,r9d
   140001d01:	45 8d 81 4f 7e a8 6f 	lea    r8d,[r9+0x6fa87e4f]
   140001d08:	0b c2                	or     eax,edx
   140001d0a:	41 33 c1             	xor    eax,r9d
   140001d0d:	41 03 c6             	add    eax,r14d
   140001d10:	44 03 d0             	add    r10d,eax
   140001d13:	41 8b c1             	mov    eax,r9d
   140001d16:	f7 d0                	not    eax
   140001d18:	41 c1 ca 11          	ror    r10d,0x11
   140001d1c:	44 03 d2             	add    r10d,edx
   140001d1f:	41 0b c2             	or     eax,r10d
   140001d22:	45 8b ca             	mov    r9d,r10d
   140001d25:	33 c2                	xor    eax,edx
   140001d27:	41 f7 d1             	not    r9d
   140001d2a:	03 84 24 88 00 00 00 	add    eax,DWORD PTR [rsp+0x88]
   140001d31:	03 c8                	add    ecx,eax
   140001d33:	45 8d 9a 14 43 01 a3 	lea    r11d,[r10-0x5cfebcec]
   140001d3a:	8b c2                	mov    eax,edx
   140001d3c:	c1 c9 0b             	ror    ecx,0xb
   140001d3f:	f7 d0                	not    eax
   140001d41:	41 03 ca             	add    ecx,r10d
   140001d44:	0b c1                	or     eax,ecx
   140001d46:	41 33 c2             	xor    eax,r10d
   140001d49:	41 03 c5             	add    eax,r13d
   140001d4c:	44 03 c0             	add    r8d,eax
   140001d4f:	44 8d 91 a1 11 08 4e 	lea    r10d,[rcx+0x4e0811a1]
   140001d56:	41 c1 c8 1a          	ror    r8d,0x1a
   140001d5a:	8b c1                	mov    eax,ecx
   140001d5c:	f7 d0                	not    eax
   140001d5e:	44 03 c1             	add    r8d,ecx
   140001d61:	45 0b c8             	or     r9d,r8d
   140001d64:	44 33 c9             	xor    r9d,ecx
   140001d67:	41 81 c1 e0 e6 2c fe 	add    r9d,0xfe2ce6e0
   140001d6e:	44 03 cb             	add    r9d,ebx
   140001d71:	44 03 ca             	add    r9d,edx
   140001d74:	41 c1 c9 16          	ror    r9d,0x16
   140001d78:	45 03 c8             	add    r9d,r8d
   140001d7b:	41 0b c1             	or     eax,r9d
   140001d7e:	41 33 c0             	xor    eax,r8d
   140001d81:	03 04 24             	add    eax,DWORD PTR [rsp]
   140001d84:	44 03 d8             	add    r11d,eax
   140001d87:	41 8d 91 35 f2 3a bd 	lea    edx,[r9-0x42c50dcb]
   140001d8e:	41 8b c0             	mov    eax,r8d
   140001d91:	41 c1 cb 11          	ror    r11d,0x11
   140001d95:	f7 d0                	not    eax
   140001d97:	45 03 d9             	add    r11d,r9d
   140001d9a:	41 0b c3             	or     eax,r11d
   140001d9d:	41 33 c1             	xor    eax,r9d
   140001da0:	41 03 c7             	add    eax,r15d
   140001da3:	44 03 d0             	add    r10d,eax
   140001da6:	41 8b c1             	mov    eax,r9d
   140001da9:	f7 d0                	not    eax
   140001dab:	41 c1 ca 0b          	ror    r10d,0xb
   140001daf:	45 03 d3             	add    r10d,r11d
   140001db2:	41 0b c2             	or     eax,r10d
   140001db5:	41 33 c3             	xor    eax,r11d
   140001db8:	05 82 7e 53 f7       	add    eax,0xf7537e82
   140001dbd:	03 44 24 04          	add    eax,DWORD PTR [rsp+0x4]
   140001dc1:	44 03 c0             	add    r8d,eax
   140001dc4:	41 8b c3             	mov    eax,r11d
   140001dc7:	f7 d0                	not    eax
   140001dc9:	41 c1 c8 1a          	ror    r8d,0x1a
   140001dcd:	45 03 c2             	add    r8d,r10d
   140001dd0:	41 0b c0             	or     eax,r8d
   140001dd3:	41 33 c2             	xor    eax,r10d
   140001dd6:	03 44 24 08          	add    eax,DWORD PTR [rsp+0x8]
   140001dda:	03 d0                	add    edx,eax
   140001ddc:	c1 ca 16             	ror    edx,0x16
   140001ddf:	41 03 d0             	add    edx,r8d
   140001de2:	4c 8b 4c 24 70       	mov    r9,QWORD PTR [rsp+0x70]
   140001de7:	41 8d 82 91 d3 86 eb 	lea    eax,[r10-0x14792c6f]
   140001dee:	41 8b ca             	mov    ecx,r10d
   140001df1:	f7 d1                	not    ecx
   140001df3:	0b ca                	or     ecx,edx
   140001df5:	45 01 01             	add    DWORD PTR [r9],r8d
   140001df8:	41 33 c8             	xor    ecx,r8d
   140001dfb:	81 c1 bb d2 d7 2a    	add    ecx,0x2ad7d2bb
   140001e01:	41 f7 d0             	not    r8d
   140001e04:	03 4c 24 0c          	add    ecx,DWORD PTR [rsp+0xc]
   140001e08:	41 03 cb             	add    ecx,r11d
   140001e0b:	c1 c9 11             	ror    ecx,0x11
   140001e0e:	03 ca                	add    ecx,edx
   140001e10:	41 01 49 08          	add    DWORD PTR [r9+0x8],ecx
   140001e14:	44 0b c1             	or     r8d,ecx
   140001e17:	44 33 c2             	xor    r8d,edx
   140001e1a:	44 03 44 24 10       	add    r8d,DWORD PTR [rsp+0x10]
   140001e1f:	41 03 c0             	add    eax,r8d
   140001e22:	c1 c8 0b             	ror    eax,0xb
   140001e25:	41 03 41 04          	add    eax,DWORD PTR [r9+0x4]
   140001e29:	03 c1                	add    eax,ecx
   140001e2b:	41 01 51 0c          	add    DWORD PTR [r9+0xc],edx
   140001e2f:	41 89 41 04          	mov    DWORD PTR [r9+0x4],eax
   140001e33:	48 83 c4 28          	add    rsp,0x28
   140001e37:	41 5f                	pop    r15
   140001e39:	41 5e                	pop    r14
   140001e3b:	41 5d                	pop    r13
   140001e3d:	41 5c                	pop    r12
   140001e3f:	5f                   	pop    rdi
   140001e40:	5e                   	pop    rsi
   140001e41:	5d                   	pop    rbp
   140001e42:	5b                   	pop    rbx
   140001e43:	c3                   	ret
   140001e44:	cc                   	int3
   140001e45:	cc                   	int3
   140001e46:	cc                   	int3
   140001e47:	cc                   	int3
   140001e48:	cc                   	int3
   140001e49:	cc                   	int3
   140001e4a:	cc                   	int3
   140001e4b:	cc                   	int3
   140001e4c:	cc                   	int3
   140001e4d:	cc                   	int3
   140001e4e:	cc                   	int3
   140001e4f:	cc                   	int3
   140001e50:	44 89 44 24 18       	mov    DWORD PTR [rsp+0x18],r8d
   140001e55:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   140001e5a:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   140001e5f:	55                   	push   rbp
   140001e60:	56                   	push   rsi
   140001e61:	57                   	push   rdi
   140001e62:	41 56                	push   r14
   140001e64:	48 83 ec 38          	sub    rsp,0x38
   140001e68:	44 8b 49 10          	mov    r9d,DWORD PTR [rcx+0x10]
   140001e6c:	41 8b e8             	mov    ebp,r8d
   140001e6f:	4c 8b f2             	mov    r14,rdx
   140001e72:	48 8b f1             	mov    rsi,rcx
   140001e75:	43 8d 04 c1          	lea    eax,[r9+r8*8]
   140001e79:	89 41 10             	mov    DWORD PTR [rcx+0x10],eax
   140001e7c:	41 3b c1             	cmp    eax,r9d
   140001e7f:	73 03                	jae    0x140001e84
   140001e81:	ff 41 14             	inc    DWORD PTR [rcx+0x14]
   140001e84:	48 89 5c 24 78       	mov    QWORD PTR [rsp+0x78],rbx
   140001e89:	41 8b c0             	mov    eax,r8d
   140001e8c:	c1 e8 1d             	shr    eax,0x1d
   140001e8f:	33 ff                	xor    edi,edi
   140001e91:	01 41 14             	add    DWORD PTR [rcx+0x14],eax
   140001e94:	4c 89 64 24 30       	mov    QWORD PTR [rsp+0x30],r12
   140001e99:	41 c1 e9 03          	shr    r9d,0x3
   140001e9d:	4c 89 6c 24 28       	mov    QWORD PTR [rsp+0x28],r13
   140001ea2:	4c 89 7c 24 20       	mov    QWORD PTR [rsp+0x20],r15
   140001ea7:	41 83 e1 3f          	and    r9d,0x3f
   140001eab:	0f 84 39 02 00 00    	je     0x1400020ea
   140001eb1:	45 8b e9             	mov    r13d,r9d
   140001eb4:	41 bc 40 00 00 00    	mov    r12d,0x40
   140001eba:	4c 03 e9             	add    r13,rcx
   140001ebd:	45 2b e1             	sub    r12d,r9d
   140001ec0:	45 3b c4             	cmp    r8d,r12d
   140001ec3:	0f 83 06 01 00 00    	jae    0x140001fcf
   140001ec9:	e8 b2 23 00 00       	call   0x140004280
   140001ece:	45 33 e4             	xor    r12d,r12d
   140001ed1:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001ed5:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140001ed9:	4c 8b 79 28          	mov    r15,QWORD PTR [rcx+0x28]
   140001edd:	49 3b df             	cmp    rbx,r15
   140001ee0:	0f 84 d3 00 00 00    	je     0x140001fb9
   140001ee6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140001eed:	00 00 00 
   140001ef0:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140001ef4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001ef8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140001eff:	00 
   140001f00:	85 c9                	test   ecx,ecx
   140001f02:	0f 84 80 00 00 00    	je     0x140001f88
   140001f08:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140001f0d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140001f11:	8b 68 24             	mov    ebp,DWORD PTR [rax+0x24]
   140001f14:	49 03 f3             	add    rsi,r11
   140001f17:	44 8b 70 1c          	mov    r14d,DWORD PTR [rax+0x1c]
   140001f1b:	49 03 eb             	add    rbp,r11
   140001f1e:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140001f21:	4d 03 f3             	add    r14,r11
   140001f24:	45 8b d4             	mov    r10d,r12d
   140001f27:	85 ff                	test   edi,edi
   140001f29:	74 5d                	je     0x140001f88
   140001f2b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   140001f30:	41 8b c2             	mov    eax,r10d
   140001f33:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140001f3a:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   140001f40:	44 8b 04 86          	mov    r8d,DWORD PTR [rsi+rax*4]
   140001f44:	4d 03 c3             	add    r8,r11
   140001f47:	48 ff c1             	inc    rcx
   140001f4a:	45 38 24 08          	cmp    BYTE PTR [r8+rcx*1],r12b
   140001f4e:	75 f7                	jne    0x140001f47
   140001f50:	49 8b d4             	mov    rdx,r12
   140001f53:	48 85 c9             	test   rcx,rcx
   140001f56:	74 28                	je     0x140001f80
   140001f58:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140001f5f:	00 
   140001f60:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140001f65:	48 ff c2             	inc    rdx
   140001f68:	41 33 c1             	xor    eax,r9d
   140001f6b:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140001f72:	48 3b d1             	cmp    rdx,rcx
   140001f75:	72 e9                	jb     0x140001f60
   140001f77:	41 81 f9 29 fd 35 ee 	cmp    r9d,0xee35fd29
   140001f7e:	74 2a                	je     0x140001faa
   140001f80:	41 ff c2             	inc    r10d
   140001f83:	44 3b d7             	cmp    r10d,edi
   140001f86:	72 a8                	jb     0x140001f30
   140001f88:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   140001f8b:	49 3b df             	cmp    rbx,r15
   140001f8e:	0f 85 5c ff ff ff    	jne    0x140001ef0
   140001f94:	44 8b 44 24 70       	mov    r8d,DWORD PTR [rsp+0x70]
   140001f99:	49 8d 4d 18          	lea    rcx,[r13+0x18]
   140001f9d:	48 8b 54 24 68       	mov    rdx,QWORD PTR [rsp+0x68]
   140001fa2:	41 ff d4             	call   r12
   140001fa5:	e9 29 03 00 00       	jmp    0x1400022d3
   140001faa:	41 8b c2             	mov    eax,r10d
   140001fad:	0f b7 4c 45 00       	movzx  ecx,WORD PTR [rbp+rax*2+0x0]
   140001fb2:	45 8b 24 8e          	mov    r12d,DWORD PTR [r14+rcx*4]
   140001fb6:	4d 03 e3             	add    r12,r11
   140001fb9:	44 8b 44 24 70       	mov    r8d,DWORD PTR [rsp+0x70]
   140001fbe:	49 8d 4d 18          	lea    rcx,[r13+0x18]
   140001fc2:	48 8b 54 24 68       	mov    rdx,QWORD PTR [rsp+0x68]
   140001fc7:	41 ff d4             	call   r12
   140001fca:	e9 04 03 00 00       	jmp    0x1400022d3
   140001fcf:	e8 ac 22 00 00       	call   0x140004280
   140001fd4:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140001fd8:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140001fdc:	4c 8b 79 28          	mov    r15,QWORD PTR [rcx+0x28]
   140001fe0:	49 3b df             	cmp    rbx,r15
   140001fe3:	0f 84 b0 00 00 00    	je     0x140002099
   140001fe9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   140001ff0:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140001ff4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140001ff8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140001fff:	00 
   140002000:	85 c9                	test   ecx,ecx
   140002002:	74 79                	je     0x14000207d
   140002004:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140002009:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000200d:	8b 68 24             	mov    ebp,DWORD PTR [rax+0x24]
   140002010:	49 03 f3             	add    rsi,r11
   140002013:	44 8b 70 1c          	mov    r14d,DWORD PTR [rax+0x1c]
   140002017:	49 03 eb             	add    rbp,r11
   14000201a:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000201d:	4d 03 f3             	add    r14,r11
   140002020:	45 33 d2             	xor    r10d,r10d
   140002023:	85 ff                	test   edi,edi
   140002025:	74 56                	je     0x14000207d
   140002027:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   14000202e:	00 00 
   140002030:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002034:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   14000203b:	4d 03 c3             	add    r8,r11
   14000203e:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   140002044:	48 ff c1             	inc    rcx
   140002047:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   14000204c:	75 f6                	jne    0x140002044
   14000204e:	33 d2                	xor    edx,edx
   140002050:	48 85 c9             	test   rcx,rcx
   140002053:	74 20                	je     0x140002075
   140002055:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   14000205a:	48 ff c2             	inc    rdx
   14000205d:	41 33 c1             	xor    eax,r9d
   140002060:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002067:	48 3b d1             	cmp    rdx,rcx
   14000206a:	72 e9                	jb     0x140002055
   14000206c:	41 81 f9 29 fd 35 ee 	cmp    r9d,0xee35fd29
   140002073:	74 56                	je     0x1400020cb
   140002075:	41 ff c2             	inc    r10d
   140002078:	44 3b d7             	cmp    r10d,edi
   14000207b:	72 b3                	jb     0x140002030
   14000207d:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   140002080:	49 3b df             	cmp    rbx,r15
   140002083:	0f 85 67 ff ff ff    	jne    0x140001ff0
   140002089:	48 8b 74 24 60       	mov    rsi,QWORD PTR [rsp+0x60]
   14000208e:	33 ff                	xor    edi,edi
   140002090:	8b 6c 24 70          	mov    ebp,DWORD PTR [rsp+0x70]
   140002094:	4c 8b 74 24 68       	mov    r14,QWORD PTR [rsp+0x68]
   140002099:	48 8b c7             	mov    rax,rdi
   14000209c:	45 8b c4             	mov    r8d,r12d
   14000209f:	49 8d 4d 18          	lea    rcx,[r13+0x18]
   1400020a3:	49 8b d6             	mov    rdx,r14
   1400020a6:	41 8b dc             	mov    ebx,r12d
   1400020a9:	ff d0                	call   rax
   1400020ab:	4c 8d 6e 18          	lea    r13,[rsi+0x18]
   1400020af:	48 8b ce             	mov    rcx,rsi
   1400020b2:	49 8b d5             	mov    rdx,r13
   1400020b5:	e8 a6 f5 ff ff       	call   0x140001660
   1400020ba:	4c 03 f3             	add    r14,rbx
   1400020bd:	41 2b ec             	sub    ebp,r12d
   1400020c0:	4c 89 74 24 68       	mov    QWORD PTR [rsp+0x68],r14
   1400020c5:	89 6c 24 70          	mov    DWORD PTR [rsp+0x70],ebp
   1400020c9:	eb 23                	jmp    0x1400020ee
   1400020cb:	42 0f b7 4c 55 00    	movzx  ecx,WORD PTR [rbp+r10*2+0x0]
   1400020d1:	48 8b 74 24 60       	mov    rsi,QWORD PTR [rsp+0x60]
   1400020d6:	8b 6c 24 70          	mov    ebp,DWORD PTR [rsp+0x70]
   1400020da:	41 8b 04 8e          	mov    eax,DWORD PTR [r14+rcx*4]
   1400020de:	4c 8b 74 24 68       	mov    r14,QWORD PTR [rsp+0x68]
   1400020e3:	49 03 c3             	add    rax,r11
   1400020e6:	33 ff                	xor    edi,edi
   1400020e8:	eb b2                	jmp    0x14000209c
   1400020ea:	4c 8d 69 18          	lea    r13,[rcx+0x18]
   1400020ee:	83 fd 40             	cmp    ebp,0x40
   1400020f1:	0f 82 09 01 00 00    	jb     0x140002200
   1400020f7:	44 8b e5             	mov    r12d,ebp
   1400020fa:	49 c1 ec 06          	shr    r12,0x6
   1400020fe:	66 90                	xchg   ax,ax
   140002100:	e8 7b 21 00 00       	call   0x140004280
   140002105:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002109:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   14000210d:	4c 8b 79 28          	mov    r15,QWORD PTR [rcx+0x28]
   140002111:	49 3b df             	cmp    rbx,r15
   140002114:	0f 84 a9 00 00 00    	je     0x1400021c3
   14000211a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   140002120:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140002124:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002128:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000212f:	00 
   140002130:	85 c9                	test   ecx,ecx
   140002132:	74 7d                	je     0x1400021b1
   140002134:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140002139:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000213d:	8b 68 24             	mov    ebp,DWORD PTR [rax+0x24]
   140002140:	49 03 f3             	add    rsi,r11
   140002143:	44 8b 70 1c          	mov    r14d,DWORD PTR [rax+0x1c]
   140002147:	49 03 eb             	add    rbp,r11
   14000214a:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000214d:	4d 03 f3             	add    r14,r11
   140002150:	45 33 d2             	xor    r10d,r10d
   140002153:	85 ff                	test   edi,edi
   140002155:	74 5a                	je     0x1400021b1
   140002157:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   14000215e:	00 00 
   140002160:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002164:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   14000216b:	4d 03 c3             	add    r8,r11
   14000216e:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   140002174:	48 ff c0             	inc    rax
   140002177:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   14000217c:	75 f6                	jne    0x140002174
   14000217e:	33 d2                	xor    edx,edx
   140002180:	48 85 c0             	test   rax,rax
   140002183:	74 24                	je     0x1400021a9
   140002185:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   14000218a:	48 ff c2             	inc    rdx
   14000218d:	41 33 c9             	xor    ecx,r9d
   140002190:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140002197:	48 3b d0             	cmp    rdx,rax
   14000219a:	72 e9                	jb     0x140002185
   14000219c:	41 81 f9 29 fd 35 ee 	cmp    r9d,0xee35fd29
   1400021a3:	0f 84 48 01 00 00    	je     0x1400022f1
   1400021a9:	41 ff c2             	inc    r10d
   1400021ac:	44 3b d7             	cmp    r10d,edi
   1400021af:	72 af                	jb     0x140002160
   1400021b1:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   1400021b4:	49 3b df             	cmp    rbx,r15
   1400021b7:	0f 85 63 ff ff ff    	jne    0x140002120
   1400021bd:	8b 6c 24 70          	mov    ebp,DWORD PTR [rsp+0x70]
   1400021c1:	33 ff                	xor    edi,edi
   1400021c3:	48 8b c7             	mov    rax,rdi
   1400021c6:	4c 8b 74 24 68       	mov    r14,QWORD PTR [rsp+0x68]
   1400021cb:	41 b8 40 00 00 00    	mov    r8d,0x40
   1400021d1:	49 8b d6             	mov    rdx,r14
   1400021d4:	49 8b cd             	mov    rcx,r13
   1400021d7:	ff d0                	call   rax
   1400021d9:	48 8b 4c 24 60       	mov    rcx,QWORD PTR [rsp+0x60]
   1400021de:	49 8b d5             	mov    rdx,r13
   1400021e1:	e8 7a f4 ff ff       	call   0x140001660
   1400021e6:	49 83 c6 40          	add    r14,0x40
   1400021ea:	83 c5 c0             	add    ebp,0xffffffc0
   1400021ed:	4c 89 74 24 68       	mov    QWORD PTR [rsp+0x68],r14
   1400021f2:	89 6c 24 70          	mov    DWORD PTR [rsp+0x70],ebp
   1400021f6:	49 83 ec 01          	sub    r12,0x1
   1400021fa:	0f 85 00 ff ff ff    	jne    0x140002100
   140002200:	e8 7b 20 00 00       	call   0x140004280
   140002205:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002209:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   14000220d:	4c 8b 79 28          	mov    r15,QWORD PTR [rcx+0x28]
   140002211:	49 3b df             	cmp    rbx,r15
   140002214:	0f 84 aa 00 00 00    	je     0x1400022c4
   14000221a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   140002220:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140002224:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002228:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000222f:	00 
   140002230:	85 c9                	test   ecx,ecx
   140002232:	74 79                	je     0x1400022ad
   140002234:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140002239:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000223d:	8b 68 24             	mov    ebp,DWORD PTR [rax+0x24]
   140002240:	49 03 f3             	add    rsi,r11
   140002243:	44 8b 70 1c          	mov    r14d,DWORD PTR [rax+0x1c]
   140002247:	49 03 eb             	add    rbp,r11
   14000224a:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000224d:	4d 03 f3             	add    r14,r11
   140002250:	45 33 d2             	xor    r10d,r10d
   140002253:	85 ff                	test   edi,edi
   140002255:	74 56                	je     0x1400022ad
   140002257:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   14000225e:	00 00 
   140002260:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002264:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   14000226b:	4d 03 c3             	add    r8,r11
   14000226e:	41 b9 78 70 75 f8    	mov    r9d,0xf8757078
   140002274:	48 ff c1             	inc    rcx
   140002277:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   14000227c:	75 f6                	jne    0x140002274
   14000227e:	33 d2                	xor    edx,edx
   140002280:	48 85 c9             	test   rcx,rcx
   140002283:	74 20                	je     0x1400022a5
   140002285:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   14000228a:	48 ff c2             	inc    rdx
   14000228d:	41 33 c1             	xor    eax,r9d
   140002290:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002297:	48 3b d1             	cmp    rdx,rcx
   14000229a:	72 e9                	jb     0x140002285
   14000229c:	41 81 f9 29 fd 35 ee 	cmp    r9d,0xee35fd29
   1400022a3:	74 64                	je     0x140002309
   1400022a5:	41 ff c2             	inc    r10d
   1400022a8:	44 3b d7             	cmp    r10d,edi
   1400022ab:	72 b3                	jb     0x140002260
   1400022ad:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   1400022b0:	49 3b df             	cmp    rbx,r15
   1400022b3:	0f 85 67 ff ff ff    	jne    0x140002220
   1400022b9:	4c 8b 6c 24 60       	mov    r13,QWORD PTR [rsp+0x60]
   1400022be:	49 83 c5 18          	add    r13,0x18
   1400022c2:	33 ff                	xor    edi,edi
   1400022c4:	44 8b 44 24 70       	mov    r8d,DWORD PTR [rsp+0x70]
   1400022c9:	49 8b cd             	mov    rcx,r13
   1400022cc:	48 8b 54 24 68       	mov    rdx,QWORD PTR [rsp+0x68]
   1400022d1:	ff d7                	call   rdi
   1400022d3:	4c 8b 7c 24 20       	mov    r15,QWORD PTR [rsp+0x20]
   1400022d8:	4c 8b 6c 24 28       	mov    r13,QWORD PTR [rsp+0x28]
   1400022dd:	4c 8b 64 24 30       	mov    r12,QWORD PTR [rsp+0x30]
   1400022e2:	48 8b 5c 24 78       	mov    rbx,QWORD PTR [rsp+0x78]
   1400022e7:	48 83 c4 38          	add    rsp,0x38
   1400022eb:	41 5e                	pop    r14
   1400022ed:	5f                   	pop    rdi
   1400022ee:	5e                   	pop    rsi
   1400022ef:	5d                   	pop    rbp
   1400022f0:	c3                   	ret
   1400022f1:	42 0f b7 4c 55 00    	movzx  ecx,WORD PTR [rbp+r10*2+0x0]
   1400022f7:	8b 6c 24 70          	mov    ebp,DWORD PTR [rsp+0x70]
   1400022fb:	41 8b 04 8e          	mov    eax,DWORD PTR [r14+rcx*4]
   1400022ff:	49 03 c3             	add    rax,r11
   140002302:	33 ff                	xor    edi,edi
   140002304:	e9 bd fe ff ff       	jmp    0x1400021c6
   140002309:	42 0f b7 4c 55 00    	movzx  ecx,WORD PTR [rbp+r10*2+0x0]
   14000230f:	4c 8b 6c 24 60       	mov    r13,QWORD PTR [rsp+0x60]
   140002314:	41 8b 3c 8e          	mov    edi,DWORD PTR [r14+rcx*4]
   140002318:	49 03 fb             	add    rdi,r11
   14000231b:	49 83 c5 18          	add    r13,0x18
   14000231f:	eb a3                	jmp    0x1400022c4
   140002321:	cc                   	int3
   140002322:	cc                   	int3
   140002323:	cc                   	int3
   140002324:	cc                   	int3
   140002325:	cc                   	int3
   140002326:	cc                   	int3
   140002327:	cc                   	int3
   140002328:	cc                   	int3
   140002329:	cc                   	int3
   14000232a:	cc                   	int3
   14000232b:	cc                   	int3
   14000232c:	cc                   	int3
   14000232d:	cc                   	int3
   14000232e:	cc                   	int3
   14000232f:	cc                   	int3
   140002330:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
   140002335:	48 89 74 24 18       	mov    QWORD PTR [rsp+0x18],rsi
   14000233a:	48 89 7c 24 20       	mov    QWORD PTR [rsp+0x20],rdi
   14000233f:	55                   	push   rbp
   140002340:	41 54                	push   r12
   140002342:	41 55                	push   r13
   140002344:	41 56                	push   r14
   140002346:	41 57                	push   r15
   140002348:	48 8d 6c 24 c9       	lea    rbp,[rsp-0x37]
   14000234d:	48 81 ec c0 00 00 00 	sub    rsp,0xc0
   140002354:	48 8b 05 a5 5c 00 00 	mov    rax,QWORD PTR [rip+0x5ca5]        # 0x140008000
   14000235b:	48 33 c4             	xor    rax,rsp
   14000235e:	48 89 45 2f          	mov    QWORD PTR [rbp+0x2f],rax
   140002362:	66 0f 6f 05 16 3f 00 	movdqa xmm0,XMMWORD PTR [rip+0x3f16]        # 0x140006280
   140002369:	00 
   14000236a:	4c 8d 05 5f 5d 00 00 	lea    r8,[rip+0x5d5f]        # 0x1400080d0
   140002371:	48 89 4d df          	mov    QWORD PTR [rbp-0x21],rcx
   140002375:	48 8d 55 0f          	lea    rdx,[rbp+0xf]
   140002379:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   14000237e:	c7 45 1f d0 d7 5a ed 	mov    DWORD PTR [rbp+0x1f],0xed5ad7d0
   140002385:	41 b9 18 00 00 00    	mov    r9d,0x18
   14000238b:	c7 45 23 38 0a 78 45 	mov    DWORD PTR [rbp+0x23],0x45780a38
   140002392:	f3 0f 7f 45 0f       	movdqu XMMWORD PTR [rbp+0xf],xmm0
   140002397:	c7 45 27 8c c8 10 2d 	mov    DWORD PTR [rbp+0x27],0x2d10c88c
   14000239e:	e8 fd 0e 00 00       	call   0x1400032a0
   1400023a3:	41 b9 07 00 00 00    	mov    r9d,0x7
   1400023a9:	48 89 45 e7          	mov    QWORD PTR [rbp-0x19],rax
   1400023ad:	4c 8d 05 10 5d 00 00 	lea    r8,[rip+0x5d10]        # 0x1400080c4
   1400023b4:	c7 45 ef df 59 68 f2 	mov    DWORD PTR [rbp-0x11],0xf26859df
   1400023bb:	48 8d 55 ef          	lea    rdx,[rbp-0x11]
   1400023bf:	c7 45 f3 42 65 3d 00 	mov    DWORD PTR [rbp-0xd],0x3d6542
   1400023c6:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   1400023cb:	c7 45 f7 8c c8 10 2d 	mov    DWORD PTR [rbp-0x9],0x2d10c88c
   1400023d2:	e8 c9 0e 00 00       	call   0x1400032a0
   1400023d7:	48 89 45 d7          	mov    QWORD PTR [rbp-0x29],rax
   1400023db:	e8 a0 1e 00 00       	call   0x140004280
   1400023e0:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   1400023e4:	4c 8b 71 20          	mov    r14,QWORD PTR [rcx+0x20]
   1400023e8:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   1400023ec:	4d 3b f5             	cmp    r14,r13
   1400023ef:	0f 84 a8 00 00 00    	je     0x14000249d
   1400023f5:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   1400023fc:	00 00 00 00 
   140002400:	4d 8b 5e 20          	mov    r11,QWORD PTR [r14+0x20]
   140002404:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002408:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000240f:	00 
   140002410:	85 c9                	test   ecx,ecx
   140002412:	74 7d                	je     0x140002491
   140002414:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140002419:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000241d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002421:	49 03 f3             	add    rsi,r11
   140002424:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002428:	4d 03 fb             	add    r15,r11
   14000242b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000242e:	4d 03 e3             	add    r12,r11
   140002431:	45 33 d2             	xor    r10d,r10d
   140002434:	85 ff                	test   edi,edi
   140002436:	74 59                	je     0x140002491
   140002438:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14000243f:	00 
   140002440:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002444:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   14000244b:	4d 03 c3             	add    r8,r11
   14000244e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002454:	48 ff c1             	inc    rcx
   140002457:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   14000245c:	75 f6                	jne    0x140002454
   14000245e:	33 d2                	xor    edx,edx
   140002460:	48 85 c9             	test   rcx,rcx
   140002463:	74 24                	je     0x140002489
   140002465:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   14000246a:	48 ff c2             	inc    rdx
   14000246d:	41 33 c1             	xor    eax,r9d
   140002470:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002477:	48 3b d1             	cmp    rdx,rcx
   14000247a:	72 e9                	jb     0x140002465
   14000247c:	41 81 f9 f4 21 63 dd 	cmp    r9d,0xdd6321f4
   140002483:	0f 84 72 03 00 00    	je     0x1400027fb
   140002489:	41 ff c2             	inc    r10d
   14000248c:	44 3b d7             	cmp    r10d,edi
   14000248f:	72 af                	jb     0x140002440
   140002491:	4d 8b 36             	mov    r14,QWORD PTR [r14]
   140002494:	4d 3b f5             	cmp    r14,r13
   140002497:	0f 85 63 ff ff ff    	jne    0x140002400
   14000249d:	45 33 d2             	xor    r10d,r10d
   1400024a0:	48 8b 45 df          	mov    rax,QWORD PTR [rbp-0x21]
   1400024a4:	41 b9 00 00 00 50    	mov    r9d,0x50000000
   1400024aa:	4c 8b 45 e7          	mov    r8,QWORD PTR [rbp-0x19]
   1400024ae:	33 c9                	xor    ecx,ecx
   1400024b0:	48 8b 55 d7          	mov    rdx,QWORD PTR [rbp-0x29]
   1400024b4:	48 c7 44 24 58 00 00 	mov    QWORD PTR [rsp+0x58],0x0
   1400024bb:	00 00 
   1400024bd:	48 c7 44 24 50 00 00 	mov    QWORD PTR [rsp+0x50],0x0
   1400024c4:	00 00 
   1400024c6:	48 c7 44 24 48 00 00 	mov    QWORD PTR [rsp+0x48],0x0
   1400024cd:	00 00 
   1400024cf:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
   1400024d4:	c7 44 24 38 14 00 00 	mov    DWORD PTR [rsp+0x38],0x14
   1400024db:	00 
   1400024dc:	c7 44 24 30 14 01 00 	mov    DWORD PTR [rsp+0x30],0x114
   1400024e3:	00 
   1400024e4:	c7 44 24 28 04 00 00 	mov    DWORD PTR [rsp+0x28],0x4
   1400024eb:	00 
   1400024ec:	c7 44 24 20 04 00 00 	mov    DWORD PTR [rsp+0x20],0x4
   1400024f3:	00 
   1400024f4:	41 ff d2             	call   r10
   1400024f7:	33 c0                	xor    eax,eax
   1400024f9:	c7 45 ff c9 49 60 f2 	mov    DWORD PTR [rbp-0x1],0xf26049c9
   140002500:	4c 8d 05 e1 5b 00 00 	lea    r8,[rip+0x5be1]        # 0x1400080e8
   140002507:	c6 45 03 0b          	mov    BYTE PTR [rbp+0x3],0xb
   14000250b:	48 8d 55 ff          	lea    rdx,[rbp-0x1]
   14000250f:	66 89 45 04          	mov    WORD PTR [rbp+0x4],ax
   140002513:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140002518:	88 45 06             	mov    BYTE PTR [rbp+0x6],al
   14000251b:	44 8d 48 05          	lea    r9d,[rax+0x5]
   14000251f:	c7 45 07 8c c8 10 2d 	mov    DWORD PTR [rbp+0x7],0x2d10c88c
   140002526:	e8 75 0d 00 00       	call   0x1400032a0
   14000252b:	48 89 45 d7          	mov    QWORD PTR [rbp-0x29],rax
   14000252f:	e8 4c 1d 00 00       	call   0x140004280
   140002534:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002538:	4c 8b 71 20          	mov    r14,QWORD PTR [rcx+0x20]
   14000253c:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002540:	4d 3b f5             	cmp    r14,r13
   140002543:	0f 84 a4 00 00 00    	je     0x1400025ed
   140002549:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   140002550:	4d 8b 5e 20          	mov    r11,QWORD PTR [r14+0x20]
   140002554:	49 63 4b 3c          	movsxd rcx,DWORD PTR [r11+0x3c]
   140002558:	42 8b 84 19 88 00 00 	mov    eax,DWORD PTR [rcx+r11*1+0x88]
   14000255f:	00 
   140002560:	85 c0                	test   eax,eax
   140002562:	74 7d                	je     0x1400025e1
   140002564:	49 03 c3             	add    rax,r11
   140002567:	45 33 d2             	xor    r10d,r10d
   14000256a:	8b 70 20             	mov    esi,DWORD PTR [rax+0x20]
   14000256d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002571:	49 03 f3             	add    rsi,r11
   140002574:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002578:	4d 03 fb             	add    r15,r11
   14000257b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000257e:	4d 03 e3             	add    r12,r11
   140002581:	85 ff                	test   edi,edi
   140002583:	74 5c                	je     0x1400025e1
   140002585:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   14000258c:	00 00 00 00 
   140002590:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002594:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   14000259b:	4d 03 c3             	add    r8,r11
   14000259e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400025a4:	48 ff c1             	inc    rcx
   1400025a7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400025ac:	75 f6                	jne    0x1400025a4
   1400025ae:	33 d2                	xor    edx,edx
   1400025b0:	48 85 c9             	test   rcx,rcx
   1400025b3:	74 24                	je     0x1400025d9
   1400025b5:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400025ba:	48 ff c2             	inc    rdx
   1400025bd:	41 33 c1             	xor    eax,r9d
   1400025c0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   1400025c7:	48 3b d1             	cmp    rdx,rcx
   1400025ca:	72 e9                	jb     0x1400025b5
   1400025cc:	41 81 f9 f4 21 63 dd 	cmp    r9d,0xdd6321f4
   1400025d3:	0f 84 33 02 00 00    	je     0x14000280c
   1400025d9:	41 ff c2             	inc    r10d
   1400025dc:	44 3b d7             	cmp    r10d,edi
   1400025df:	72 af                	jb     0x140002590
   1400025e1:	4d 8b 36             	mov    r14,QWORD PTR [r14]
   1400025e4:	4d 3b f5             	cmp    r14,r13
   1400025e7:	0f 85 63 ff ff ff    	jne    0x140002550
   1400025ed:	45 33 d2             	xor    r10d,r10d
   1400025f0:	48 8b 45 df          	mov    rax,QWORD PTR [rbp-0x21]
   1400025f4:	41 b9 00 00 81 50    	mov    r9d,0x50810000
   1400025fa:	48 8b 55 d7          	mov    rdx,QWORD PTR [rbp-0x29]
   1400025fe:	45 33 c0             	xor    r8d,r8d
   140002601:	48 c7 44 24 58 00 00 	mov    QWORD PTR [rsp+0x58],0x0
   140002608:	00 00 
   14000260a:	33 c9                	xor    ecx,ecx
   14000260c:	48 c7 44 24 50 00 00 	mov    QWORD PTR [rsp+0x50],0x0
   140002613:	00 00 
   140002615:	48 c7 44 24 48 00 00 	mov    QWORD PTR [rsp+0x48],0x0
   14000261c:	00 00 
   14000261e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
   140002623:	c7 44 24 38 18 00 00 	mov    DWORD PTR [rsp+0x38],0x18
   14000262a:	00 
   14000262b:	c7 44 24 30 e6 00 00 	mov    DWORD PTR [rsp+0x30],0xe6
   140002632:	00 
   140002633:	c7 44 24 28 18 00 00 	mov    DWORD PTR [rsp+0x28],0x18
   14000263a:	00 
   14000263b:	c7 44 24 20 04 00 00 	mov    DWORD PTR [rsp+0x20],0x4
   140002642:	00 
   140002643:	41 ff d2             	call   r10
   140002646:	41 b9 07 00 00 00    	mov    r9d,0x7
   14000264c:	48 89 05 3d 5a 00 00 	mov    QWORD PTR [rip+0x5a3d],rax        # 0x140008090
   140002653:	4c 8d 05 9e 5a 00 00 	lea    r8,[rip+0x5a9e]        # 0x1400080f8
   14000265a:	c7 45 ef da 48 7b ef 	mov    DWORD PTR [rbp-0x11],0xef7b48da
   140002661:	48 8d 55 ef          	lea    rdx,[rbp-0x11]
   140002665:	c7 45 f3 4d 7f 3d 00 	mov    DWORD PTR [rbp-0xd],0x3d7f4d
   14000266c:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140002671:	c7 45 f7 8c c8 10 2d 	mov    DWORD PTR [rbp-0x9],0x2d10c88c
   140002678:	e8 23 0c 00 00       	call   0x1400032a0
   14000267d:	41 b9 07 00 00 00    	mov    r9d,0x7
   140002683:	48 89 45 d7          	mov    QWORD PTR [rbp-0x29],rax
   140002687:	4c 8d 05 62 5a 00 00 	lea    r8,[rip+0x5a62]        # 0x1400080f0
   14000268e:	c7 45 ff ce 58 7d f2 	mov    DWORD PTR [rbp-0x1],0xf27d58ce
   140002695:	48 8d 55 ff          	lea    rdx,[rbp-0x1]
   140002699:	c7 45 03 44 68 3d 00 	mov    DWORD PTR [rbp+0x3],0x3d6844
   1400026a0:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   1400026a5:	c7 45 07 8c c8 10 2d 	mov    DWORD PTR [rbp+0x7],0x2d10c88c
   1400026ac:	e8 ef 0b 00 00       	call   0x1400032a0
   1400026b1:	48 89 45 e7          	mov    QWORD PTR [rbp-0x19],rax
   1400026b5:	e8 c6 1b 00 00       	call   0x140004280
   1400026ba:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   1400026be:	4c 8b 71 20          	mov    r14,QWORD PTR [rcx+0x20]
   1400026c2:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   1400026c6:	4d 3b f5             	cmp    r14,r13
   1400026c9:	0f 84 9e 00 00 00    	je     0x14000276d
   1400026cf:	90                   	nop
   1400026d0:	4d 8b 5e 20          	mov    r11,QWORD PTR [r14+0x20]
   1400026d4:	49 63 4b 3c          	movsxd rcx,DWORD PTR [r11+0x3c]
   1400026d8:	42 8b 84 19 88 00 00 	mov    eax,DWORD PTR [rcx+r11*1+0x88]
   1400026df:	00 
   1400026e0:	85 c0                	test   eax,eax
   1400026e2:	74 7d                	je     0x140002761
   1400026e4:	49 03 c3             	add    rax,r11
   1400026e7:	45 33 d2             	xor    r10d,r10d
   1400026ea:	8b 70 20             	mov    esi,DWORD PTR [rax+0x20]
   1400026ed:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400026f1:	49 03 f3             	add    rsi,r11
   1400026f4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400026f8:	4d 03 fb             	add    r15,r11
   1400026fb:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400026fe:	4d 03 e3             	add    r12,r11
   140002701:	85 ff                	test   edi,edi
   140002703:	74 5c                	je     0x140002761
   140002705:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   14000270c:	00 00 00 00 
   140002710:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002714:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   14000271b:	4d 03 c3             	add    r8,r11
   14000271e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002724:	48 ff c0             	inc    rax
   140002727:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   14000272c:	75 f6                	jne    0x140002724
   14000272e:	33 d2                	xor    edx,edx
   140002730:	48 85 c0             	test   rax,rax
   140002733:	74 24                	je     0x140002759
   140002735:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   14000273a:	48 ff c2             	inc    rdx
   14000273d:	41 33 c9             	xor    ecx,r9d
   140002740:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140002747:	48 3b d0             	cmp    rdx,rax
   14000274a:	72 e9                	jb     0x140002735
   14000274c:	41 81 f9 f4 21 63 dd 	cmp    r9d,0xdd6321f4
   140002753:	0f 84 c4 00 00 00    	je     0x14000281d
   140002759:	41 ff c2             	inc    r10d
   14000275c:	44 3b d7             	cmp    r10d,edi
   14000275f:	72 af                	jb     0x140002710
   140002761:	4d 8b 36             	mov    r14,QWORD PTR [r14]
   140002764:	4d 3b f5             	cmp    r14,r13
   140002767:	0f 85 63 ff ff ff    	jne    0x1400026d0
   14000276d:	45 33 d2             	xor    r10d,r10d
   140002770:	48 8b 45 df          	mov    rax,QWORD PTR [rbp-0x21]
   140002774:	41 b9 01 00 01 50    	mov    r9d,0x50010001
   14000277a:	4c 8b 45 d7          	mov    r8,QWORD PTR [rbp-0x29]
   14000277e:	33 c9                	xor    ecx,ecx
   140002780:	48 8b 55 e7          	mov    rdx,QWORD PTR [rbp-0x19]
   140002784:	48 c7 44 24 58 00 00 	mov    QWORD PTR [rsp+0x58],0x0
   14000278b:	00 00 
   14000278d:	48 c7 44 24 50 00 00 	mov    QWORD PTR [rsp+0x50],0x0
   140002794:	00 00 
   140002796:	48 c7 44 24 48 e9 03 	mov    QWORD PTR [rsp+0x48],0x3e9
   14000279d:	00 00 
   14000279f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
   1400027a4:	c7 44 24 38 18 00 00 	mov    DWORD PTR [rsp+0x38],0x18
   1400027ab:	00 
   1400027ac:	c7 44 24 30 50 00 00 	mov    DWORD PTR [rsp+0x30],0x50
   1400027b3:	00 
   1400027b4:	c7 44 24 28 18 00 00 	mov    DWORD PTR [rsp+0x28],0x18
   1400027bb:	00 
   1400027bc:	c7 44 24 20 ee 00 00 	mov    DWORD PTR [rsp+0x20],0xee
   1400027c3:	00 
   1400027c4:	41 ff d2             	call   r10
   1400027c7:	48 89 05 ba 58 00 00 	mov    QWORD PTR [rip+0x58ba],rax        # 0x140008088
   1400027ce:	48 8b 4d 2f          	mov    rcx,QWORD PTR [rbp+0x2f]
   1400027d2:	48 33 cc             	xor    rcx,rsp
   1400027d5:	e8 46 1b 00 00       	call   0x140004320
   1400027da:	4c 8d 9c 24 c0 00 00 	lea    r11,[rsp+0xc0]
   1400027e1:	00 
   1400027e2:	49 8b 5b 38          	mov    rbx,QWORD PTR [r11+0x38]
   1400027e6:	49 8b 73 40          	mov    rsi,QWORD PTR [r11+0x40]
   1400027ea:	49 8b 7b 48          	mov    rdi,QWORD PTR [r11+0x48]
   1400027ee:	49 8b e3             	mov    rsp,r11
   1400027f1:	41 5f                	pop    r15
   1400027f3:	41 5e                	pop    r14
   1400027f5:	41 5d                	pop    r13
   1400027f7:	41 5c                	pop    r12
   1400027f9:	5d                   	pop    rbp
   1400027fa:	c3                   	ret
   1400027fb:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140002800:	45 8b 14 84          	mov    r10d,DWORD PTR [r12+rax*4]
   140002804:	4d 03 d3             	add    r10,r11
   140002807:	e9 94 fc ff ff       	jmp    0x1400024a0
   14000280c:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140002811:	45 8b 14 84          	mov    r10d,DWORD PTR [r12+rax*4]
   140002815:	4d 03 d3             	add    r10,r11
   140002818:	e9 d3 fd ff ff       	jmp    0x1400025f0
   14000281d:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140002822:	45 8b 14 84          	mov    r10d,DWORD PTR [r12+rax*4]
   140002826:	4d 03 d3             	add    r10,r11
   140002829:	e9 42 ff ff ff       	jmp    0x140002770
   14000282e:	cc                   	int3
   14000282f:	cc                   	int3
   140002830:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140002835:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
   14000283a:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
   14000283f:	55                   	push   rbp
   140002840:	41 54                	push   r12
   140002842:	41 55                	push   r13
   140002844:	41 56                	push   r14
   140002846:	41 57                	push   r15
   140002848:	48 8d 6c 24 f0       	lea    rbp,[rsp-0x10]
   14000284d:	48 81 ec 10 01 00 00 	sub    rsp,0x110
   140002854:	48 8b 05 a5 57 00 00 	mov    rax,QWORD PTR [rip+0x57a5]        # 0x140008000
   14000285b:	48 33 c4             	xor    rax,rsp
   14000285e:	48 89 45 00          	mov    QWORD PTR [rbp+0x0],rax
   140002862:	e8 19 1a 00 00       	call   0x140004280
   140002867:	33 d2                	xor    edx,edx
   140002869:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   14000286d:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002871:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002875:	49 3b f5             	cmp    rsi,r13
   140002878:	0f 84 b9 00 00 00    	je     0x140002937
   14000287e:	66 90                	xchg   ax,ax
   140002880:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002884:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002888:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000288f:	00 
   140002890:	85 c9                	test   ecx,ecx
   140002892:	0f 84 85 00 00 00    	je     0x14000291d
   140002898:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   14000289d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400028a1:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400028a5:	4d 03 f3             	add    r14,r11
   1400028a8:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400028ac:	4d 03 fb             	add    r15,r11
   1400028af:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400028b2:	4d 03 e3             	add    r12,r11
   1400028b5:	44 8b d2             	mov    r10d,edx
   1400028b8:	85 ff                	test   edi,edi
   1400028ba:	74 61                	je     0x14000291d
   1400028bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400028c0:	41 8b da             	mov    ebx,r10d
   1400028c3:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400028ca:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400028d0:	45 8b 04 9e          	mov    r8d,DWORD PTR [r14+rbx*4]
   1400028d4:	4d 03 c3             	add    r8,r11
   1400028d7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1400028de:	00 00 
   1400028e0:	48 ff c1             	inc    rcx
   1400028e3:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400028e8:	75 f6                	jne    0x1400028e0
   1400028ea:	48 85 c9             	test   rcx,rcx
   1400028ed:	74 21                	je     0x140002910
   1400028ef:	90                   	nop
   1400028f0:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400028f5:	48 ff c2             	inc    rdx
   1400028f8:	41 33 c1             	xor    eax,r9d
   1400028fb:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002902:	48 3b d1             	cmp    rdx,rcx
   140002905:	72 e9                	jb     0x1400028f0
   140002907:	41 81 f9 f1 23 7b 46 	cmp    r9d,0x467b23f1
   14000290e:	74 1b                	je     0x14000292b
   140002910:	41 ff c2             	inc    r10d
   140002913:	ba 00 00 00 00       	mov    edx,0x0
   140002918:	44 3b d7             	cmp    r10d,edi
   14000291b:	72 a3                	jb     0x1400028c0
   14000291d:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002920:	49 3b f5             	cmp    rsi,r13
   140002923:	0f 85 57 ff ff ff    	jne    0x140002880
   140002929:	eb 0c                	jmp    0x140002937
   14000292b:	41 0f b7 04 5f       	movzx  eax,WORD PTR [r15+rbx*2]
   140002930:	41 8b 14 84          	mov    edx,DWORD PTR [r12+rax*4]
   140002934:	49 03 d3             	add    rdx,r11
   140002937:	33 c9                	xor    ecx,ecx
   140002939:	ff d2                	call   rdx
   14000293b:	33 db                	xor    ebx,ebx
   14000293d:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
   140002942:	48 8d 0d 57 0c 00 00 	lea    rcx,[rip+0xc57]        # 0x1400035a0
   140002949:	48 89 5d 80          	mov    QWORD PTR [rbp-0x80],rbx
   14000294d:	48 89 4d 88          	mov    QWORD PTR [rbp-0x78],rcx
   140002951:	48 89 5d 90          	mov    QWORD PTR [rbp-0x70],rbx
   140002955:	48 89 5d b8          	mov    QWORD PTR [rbp-0x48],rbx
   140002959:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
   14000295d:	e8 1e 19 00 00       	call   0x140004280
   140002962:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002966:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   14000296a:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   14000296e:	49 3b f5             	cmp    rsi,r13
   140002971:	0f 84 a5 00 00 00    	je     0x140002a1c
   140002977:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   14000297e:	00 00 
   140002980:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002984:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002988:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000298f:	00 
   140002990:	85 c9                	test   ecx,ecx
   140002992:	74 7c                	je     0x140002a10
   140002994:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002999:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000299d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400029a1:	4d 03 f3             	add    r14,r11
   1400029a4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400029a8:	4d 03 fb             	add    r15,r11
   1400029ab:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400029ae:	4d 03 e3             	add    r12,r11
   1400029b1:	45 33 d2             	xor    r10d,r10d
   1400029b4:	85 ff                	test   edi,edi
   1400029b6:	74 58                	je     0x140002a10
   1400029b8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400029bf:	00 
   1400029c0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   1400029c4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400029cb:	4d 03 c3             	add    r8,r11
   1400029ce:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400029d4:	48 ff c1             	inc    rcx
   1400029d7:	41 38 1c 08          	cmp    BYTE PTR [r8+rcx*1],bl
   1400029db:	75 f7                	jne    0x1400029d4
   1400029dd:	33 d2                	xor    edx,edx
   1400029df:	48 85 c9             	test   rcx,rcx
   1400029e2:	74 24                	je     0x140002a08
   1400029e4:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400029e9:	48 ff c2             	inc    rdx
   1400029ec:	41 33 c1             	xor    eax,r9d
   1400029ef:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   1400029f6:	48 3b d1             	cmp    rdx,rcx
   1400029f9:	72 e9                	jb     0x1400029e4
   1400029fb:	41 81 f9 14 ee fe b5 	cmp    r9d,0xb5feee14
   140002a02:	0f 84 1a 06 00 00    	je     0x140003022
   140002a08:	41 ff c2             	inc    r10d
   140002a0b:	44 3b d7             	cmp    r10d,edi
   140002a0e:	72 b0                	jb     0x1400029c0
   140002a10:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002a13:	49 3b f5             	cmp    rsi,r13
   140002a16:	0f 85 64 ff ff ff    	jne    0x140002980
   140002a1c:	4c 8b c3             	mov    r8,rbx
   140002a1f:	ba 00 7f 00 00       	mov    edx,0x7f00
   140002a24:	33 c9                	xor    ecx,ecx
   140002a26:	41 ff d0             	call   r8
   140002a29:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
   140002a2d:	e8 4e 18 00 00       	call   0x140004280
   140002a32:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002a36:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002a3a:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002a3e:	49 3b f5             	cmp    rsi,r13
   140002a41:	0f 84 a8 00 00 00    	je     0x140002aef
   140002a47:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   140002a4e:	00 00 
   140002a50:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002a54:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002a58:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002a5f:	00 
   140002a60:	85 c9                	test   ecx,ecx
   140002a62:	74 7d                	je     0x140002ae1
   140002a64:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002a69:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002a6d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002a71:	4d 03 f3             	add    r14,r11
   140002a74:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002a78:	4d 03 fb             	add    r15,r11
   140002a7b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002a7e:	4d 03 e3             	add    r12,r11
   140002a81:	45 33 d2             	xor    r10d,r10d
   140002a84:	85 ff                	test   edi,edi
   140002a86:	74 59                	je     0x140002ae1
   140002a88:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002a8f:	00 
   140002a90:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140002a94:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140002a9b:	4d 03 c3             	add    r8,r11
   140002a9e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002aa4:	48 ff c1             	inc    rcx
   140002aa7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140002aac:	75 f6                	jne    0x140002aa4
   140002aae:	33 d2                	xor    edx,edx
   140002ab0:	48 85 c9             	test   rcx,rcx
   140002ab3:	74 24                	je     0x140002ad9
   140002ab5:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140002aba:	48 ff c2             	inc    rdx
   140002abd:	41 33 c1             	xor    eax,r9d
   140002ac0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002ac7:	48 3b d1             	cmp    rdx,rcx
   140002aca:	72 e9                	jb     0x140002ab5
   140002acc:	41 81 f9 fd 7f 06 a0 	cmp    r9d,0xa0067ffd
   140002ad3:	0f 84 5a 05 00 00    	je     0x140003033
   140002ad9:	41 ff c2             	inc    r10d
   140002adc:	44 3b d7             	cmp    r10d,edi
   140002adf:	72 af                	jb     0x140002a90
   140002ae1:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002ae4:	49 3b f5             	cmp    rsi,r13
   140002ae7:	0f 85 63 ff ff ff    	jne    0x140002a50
   140002aed:	33 db                	xor    ebx,ebx
   140002aef:	4c 8b c3             	mov    r8,rbx
   140002af2:	ba 00 7f 00 00       	mov    edx,0x7f00
   140002af7:	33 c9                	xor    ecx,ecx
   140002af9:	41 ff d0             	call   r8
   140002afc:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
   140002b00:	e8 7b 17 00 00       	call   0x140004280
   140002b05:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002b09:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002b0d:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002b11:	49 3b f5             	cmp    rsi,r13
   140002b14:	0f 84 a5 00 00 00    	je     0x140002bbf
   140002b1a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   140002b20:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002b24:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002b28:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002b2f:	00 
   140002b30:	85 c9                	test   ecx,ecx
   140002b32:	74 7d                	je     0x140002bb1
   140002b34:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002b39:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002b3d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002b41:	4d 03 f3             	add    r14,r11
   140002b44:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002b48:	4d 03 fb             	add    r15,r11
   140002b4b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002b4e:	4d 03 e3             	add    r12,r11
   140002b51:	45 33 d2             	xor    r10d,r10d
   140002b54:	85 ff                	test   edi,edi
   140002b56:	74 59                	je     0x140002bb1
   140002b58:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002b5f:	00 
   140002b60:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140002b64:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140002b6b:	4d 03 c3             	add    r8,r11
   140002b6e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002b74:	48 ff c1             	inc    rcx
   140002b77:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140002b7c:	75 f6                	jne    0x140002b74
   140002b7e:	33 d2                	xor    edx,edx
   140002b80:	48 85 c9             	test   rcx,rcx
   140002b83:	74 24                	je     0x140002ba9
   140002b85:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140002b8a:	48 ff c2             	inc    rdx
   140002b8d:	41 33 c1             	xor    eax,r9d
   140002b90:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002b97:	48 3b d1             	cmp    rdx,rcx
   140002b9a:	72 e9                	jb     0x140002b85
   140002b9c:	41 81 f9 50 32 9a 06 	cmp    r9d,0x69a3250
   140002ba3:	0f 84 9d 04 00 00    	je     0x140003046
   140002ba9:	41 ff c2             	inc    r10d
   140002bac:	44 3b d7             	cmp    r10d,edi
   140002baf:	72 af                	jb     0x140002b60
   140002bb1:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002bb4:	49 3b f5             	cmp    rsi,r13
   140002bb7:	0f 85 63 ff ff ff    	jne    0x140002b20
   140002bbd:	33 db                	xor    ebx,ebx
   140002bbf:	48 8b d3             	mov    rdx,rbx
   140002bc2:	b9 0f 00 00 00       	mov    ecx,0xf
   140002bc7:	ff d2                	call   rdx
   140002bc9:	66 0f 6f 05 6f 36 00 	movdqa xmm0,XMMWORD PTR [rip+0x366f]        # 0x140006240
   140002bd0:	00 
   140002bd1:	4c 8d 05 28 55 00 00 	lea    r8,[rip+0x5528]        # 0x140008100
   140002bd8:	41 b9 14 00 00 00    	mov    r9d,0x14
   140002bde:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
   140002be2:	48 8d 55 d0          	lea    rdx,[rbp-0x30]
   140002be6:	c7 45 e0 e1 fb 79 cd 	mov    DWORD PTR [rbp-0x20],0xcd79fbe1
   140002bed:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140002bf2:	c7 45 e4 8c c8 10 2d 	mov    DWORD PTR [rbp-0x1c],0x2d10c88c
   140002bf9:	f3 0f 7f 45 d0       	movdqu XMMWORD PTR [rbp-0x30],xmm0
   140002bfe:	e8 9d 06 00 00       	call   0x1400032a0
   140002c03:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
   140002c07:	e8 74 16 00 00       	call   0x140004280
   140002c0c:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002c10:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002c14:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002c18:	49 3b f5             	cmp    rsi,r13
   140002c1b:	0f 84 ae 00 00 00    	je     0x140002ccf
   140002c21:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140002c25:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   140002c2c:	00 00 00 00 
   140002c30:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002c34:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002c38:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002c3f:	00 
   140002c40:	85 c9                	test   ecx,ecx
   140002c42:	74 7d                	je     0x140002cc1
   140002c44:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002c49:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002c4d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002c51:	4d 03 f3             	add    r14,r11
   140002c54:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002c58:	4d 03 fb             	add    r15,r11
   140002c5b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002c5e:	4d 03 e3             	add    r12,r11
   140002c61:	45 33 d2             	xor    r10d,r10d
   140002c64:	85 ff                	test   edi,edi
   140002c66:	74 59                	je     0x140002cc1
   140002c68:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002c6f:	00 
   140002c70:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140002c74:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140002c7b:	4d 03 c3             	add    r8,r11
   140002c7e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002c84:	48 ff c1             	inc    rcx
   140002c87:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140002c8c:	75 f6                	jne    0x140002c84
   140002c8e:	33 d2                	xor    edx,edx
   140002c90:	48 85 c9             	test   rcx,rcx
   140002c93:	74 24                	je     0x140002cb9
   140002c95:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140002c9a:	48 ff c2             	inc    rdx
   140002c9d:	41 33 c1             	xor    eax,r9d
   140002ca0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002ca7:	48 3b d1             	cmp    rdx,rcx
   140002caa:	72 e9                	jb     0x140002c95
   140002cac:	41 81 f9 86 d9 e7 61 	cmp    r9d,0x61e7d986
   140002cb3:	0f 84 a0 03 00 00    	je     0x140003059
   140002cb9:	41 ff c2             	inc    r10d
   140002cbc:	44 3b d7             	cmp    r10d,edi
   140002cbf:	72 af                	jb     0x140002c70
   140002cc1:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002cc4:	49 3b f5             	cmp    rsi,r13
   140002cc7:	0f 85 63 ff ff ff    	jne    0x140002c30
   140002ccd:	33 db                	xor    ebx,ebx
   140002ccf:	48 8b d3             	mov    rdx,rbx
   140002cd2:	48 8d 4d 80          	lea    rcx,[rbp-0x80]
   140002cd6:	ff d2                	call   rdx
   140002cd8:	66 85 c0             	test   ax,ax
   140002cdb:	0f 84 cd 03 00 00    	je     0x1400030ae
   140002ce1:	66 0f 6f 05 77 35 00 	movdqa xmm0,XMMWORD PTR [rip+0x3577]        # 0x140006260
   140002ce8:	00 
   140002ce9:	4c 8d 05 40 54 00 00 	lea    r8,[rip+0x5440]        # 0x140008130
   140002cf0:	33 c0                	xor    eax,eax
   140002cf2:	c6 45 f8 a5          	mov    BYTE PTR [rbp-0x8],0xa5
   140002cf6:	48 8d 55 e8          	lea    rdx,[rbp-0x18]
   140002cfa:	66 89 45 f9          	mov    WORD PTR [rbp-0x7],ax
   140002cfe:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140002d03:	88 45 fb             	mov    BYTE PTR [rbp-0x5],al
   140002d06:	f3 0f 7f 45 e8       	movdqu XMMWORD PTR [rbp-0x18],xmm0
   140002d0b:	44 8d 48 11          	lea    r9d,[rax+0x11]
   140002d0f:	c7 45 fc 8c c8 10 2d 	mov    DWORD PTR [rbp-0x4],0x2d10c88c
   140002d16:	e8 85 05 00 00       	call   0x1400032a0
   140002d1b:	66 0f 6f 05 1d 35 00 	movdqa xmm0,XMMWORD PTR [rip+0x351d]        # 0x140006240
   140002d22:	00 
   140002d23:	4c 8d 05 ee 53 00 00 	lea    r8,[rip+0x53ee]        # 0x140008118
   140002d2a:	41 b9 14 00 00 00    	mov    r9d,0x14
   140002d30:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   140002d35:	48 8d 55 d0          	lea    rdx,[rbp-0x30]
   140002d39:	c7 45 e0 e1 fb 79 cd 	mov    DWORD PTR [rbp-0x20],0xcd79fbe1
   140002d40:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140002d45:	c7 45 e4 8c c8 10 2d 	mov    DWORD PTR [rbp-0x1c],0x2d10c88c
   140002d4c:	f3 0f 7f 45 d0       	movdqu XMMWORD PTR [rbp-0x30],xmm0
   140002d51:	e8 4a 05 00 00       	call   0x1400032a0
   140002d56:	48 89 44 24 70       	mov    QWORD PTR [rsp+0x70],rax
   140002d5b:	e8 20 15 00 00       	call   0x140004280
   140002d60:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002d64:	4c 8b 71 20          	mov    r14,QWORD PTR [rcx+0x20]
   140002d68:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002d6c:	4d 3b f5             	cmp    r14,r13
   140002d6f:	0f 84 aa 00 00 00    	je     0x140002e1f
   140002d75:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   140002d7c:	00 00 00 00 
   140002d80:	4d 8b 5e 20          	mov    r11,QWORD PTR [r14+0x20]
   140002d84:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002d88:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002d8f:	00 
   140002d90:	85 c9                	test   ecx,ecx
   140002d92:	74 7d                	je     0x140002e11
   140002d94:	41 8b 74 0b 20       	mov    esi,DWORD PTR [r11+rcx*1+0x20]
   140002d99:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002d9d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002da1:	49 03 f3             	add    rsi,r11
   140002da4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002da8:	4d 03 fb             	add    r15,r11
   140002dab:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002dae:	4d 03 e3             	add    r12,r11
   140002db1:	45 33 d2             	xor    r10d,r10d
   140002db4:	85 ff                	test   edi,edi
   140002db6:	74 59                	je     0x140002e11
   140002db8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002dbf:	00 
   140002dc0:	46 8b 04 96          	mov    r8d,DWORD PTR [rsi+r10*4]
   140002dc4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140002dcb:	4d 03 c3             	add    r8,r11
   140002dce:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002dd4:	48 ff c1             	inc    rcx
   140002dd7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140002ddc:	75 f6                	jne    0x140002dd4
   140002dde:	33 d2                	xor    edx,edx
   140002de0:	48 85 c9             	test   rcx,rcx
   140002de3:	74 24                	je     0x140002e09
   140002de5:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140002dea:	48 ff c2             	inc    rdx
   140002ded:	41 33 c1             	xor    eax,r9d
   140002df0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002df7:	48 3b d1             	cmp    rdx,rcx
   140002dfa:	72 e9                	jb     0x140002de5
   140002dfc:	41 81 f9 f4 21 63 dd 	cmp    r9d,0xdd6321f4
   140002e03:	0f 84 63 02 00 00    	je     0x14000306c
   140002e09:	41 ff c2             	inc    r10d
   140002e0c:	44 3b d7             	cmp    r10d,edi
   140002e0f:	72 af                	jb     0x140002dc0
   140002e11:	4d 8b 36             	mov    r14,QWORD PTR [r14]
   140002e14:	4d 3b f5             	cmp    r14,r13
   140002e17:	0f 85 63 ff ff ff    	jne    0x140002d80
   140002e1d:	33 db                	xor    ebx,ebx
   140002e1f:	4c 8b d3             	mov    r10,rbx
   140002e22:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
   140002e27:	41 b9 00 00 c8 00    	mov    r9d,0xc80000
   140002e2d:	4c 8b 44 24 68       	mov    r8,QWORD PTR [rsp+0x68]
   140002e32:	33 c9                	xor    ecx,ecx
   140002e34:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   140002e39:	48 89 5c 24 58       	mov    QWORD PTR [rsp+0x58],rbx
   140002e3e:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
   140002e43:	48 89 5c 24 48       	mov    QWORD PTR [rsp+0x48],rbx
   140002e48:	48 89 5c 24 40       	mov    QWORD PTR [rsp+0x40],rbx
   140002e4d:	c7 44 24 38 96 00 00 	mov    DWORD PTR [rsp+0x38],0x96
   140002e54:	00 
   140002e55:	c7 44 24 30 54 01 00 	mov    DWORD PTR [rsp+0x30],0x154
   140002e5c:	00 
   140002e5d:	c7 44 24 28 00 00 00 	mov    DWORD PTR [rsp+0x28],0x80000000
   140002e64:	80 
   140002e65:	c7 44 24 20 00 00 00 	mov    DWORD PTR [rsp+0x20],0x80000000
   140002e6c:	80 
   140002e6d:	41 ff d2             	call   r10
   140002e70:	48 89 05 09 52 00 00 	mov    QWORD PTR [rip+0x5209],rax        # 0x140008080
   140002e77:	48 85 c0             	test   rax,rax
   140002e7a:	0f 84 2e 02 00 00    	je     0x1400030ae
   140002e80:	e8 fb 13 00 00       	call   0x140004280
   140002e85:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002e89:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002e8d:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002e91:	49 3b f5             	cmp    rsi,r13
   140002e94:	0f 84 a5 00 00 00    	je     0x140002f3f
   140002e9a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   140002ea0:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002ea4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002ea8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002eaf:	00 
   140002eb0:	85 c9                	test   ecx,ecx
   140002eb2:	74 7d                	je     0x140002f31
   140002eb4:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002eb9:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002ebd:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002ec1:	4d 03 f3             	add    r14,r11
   140002ec4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002ec8:	4d 03 fb             	add    r15,r11
   140002ecb:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002ece:	4d 03 e3             	add    r12,r11
   140002ed1:	45 33 d2             	xor    r10d,r10d
   140002ed4:	85 ff                	test   edi,edi
   140002ed6:	74 59                	je     0x140002f31
   140002ed8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002edf:	00 
   140002ee0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140002ee4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140002eeb:	4d 03 c3             	add    r8,r11
   140002eee:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002ef4:	48 ff c1             	inc    rcx
   140002ef7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140002efc:	75 f6                	jne    0x140002ef4
   140002efe:	33 d2                	xor    edx,edx
   140002f00:	48 85 c9             	test   rcx,rcx
   140002f03:	74 24                	je     0x140002f29
   140002f05:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140002f0a:	48 ff c2             	inc    rdx
   140002f0d:	41 33 c1             	xor    eax,r9d
   140002f10:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140002f17:	48 3b d1             	cmp    rdx,rcx
   140002f1a:	72 e9                	jb     0x140002f05
   140002f1c:	41 81 f9 99 b4 a1 77 	cmp    r9d,0x77a1b499
   140002f23:	0f 84 56 01 00 00    	je     0x14000307f
   140002f29:	41 ff c2             	inc    r10d
   140002f2c:	44 3b d7             	cmp    r10d,edi
   140002f2f:	72 af                	jb     0x140002ee0
   140002f31:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140002f34:	49 3b f5             	cmp    rsi,r13
   140002f37:	0f 85 63 ff ff ff    	jne    0x140002ea0
   140002f3d:	33 db                	xor    ebx,ebx
   140002f3f:	4c 8b c3             	mov    r8,rbx
   140002f42:	48 8b 0d 37 51 00 00 	mov    rcx,QWORD PTR [rip+0x5137]        # 0x140008080
   140002f49:	ba 05 00 00 00       	mov    edx,0x5
   140002f4e:	41 ff d0             	call   r8
   140002f51:	e8 2a 13 00 00       	call   0x140004280
   140002f56:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140002f5a:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140002f5e:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140002f62:	49 3b f5             	cmp    rsi,r13
   140002f65:	0f 84 a4 00 00 00    	je     0x14000300f
   140002f6b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   140002f70:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140002f74:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140002f78:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140002f7f:	00 
   140002f80:	85 c9                	test   ecx,ecx
   140002f82:	74 7d                	je     0x140003001
   140002f84:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140002f89:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140002f8d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140002f91:	4d 03 f3             	add    r14,r11
   140002f94:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140002f98:	4d 03 fb             	add    r15,r11
   140002f9b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140002f9e:	4d 03 e3             	add    r12,r11
   140002fa1:	45 33 d2             	xor    r10d,r10d
   140002fa4:	85 ff                	test   edi,edi
   140002fa6:	74 59                	je     0x140003001
   140002fa8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140002faf:	00 
   140002fb0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140002fb4:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   140002fbb:	4d 03 c3             	add    r8,r11
   140002fbe:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140002fc4:	48 ff c0             	inc    rax
   140002fc7:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   140002fcc:	75 f6                	jne    0x140002fc4
   140002fce:	33 d2                	xor    edx,edx
   140002fd0:	48 85 c0             	test   rax,rax
   140002fd3:	74 24                	je     0x140002ff9
   140002fd5:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   140002fda:	48 ff c2             	inc    rdx
   140002fdd:	41 33 c9             	xor    ecx,r9d
   140002fe0:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140002fe7:	48 3b d0             	cmp    rdx,rax
   140002fea:	72 e9                	jb     0x140002fd5
   140002fec:	41 81 f9 91 c1 0d f7 	cmp    r9d,0xf70dc191
   140002ff3:	0f 84 99 00 00 00    	je     0x140003092
   140002ff9:	41 ff c2             	inc    r10d
   140002ffc:	44 3b d7             	cmp    r10d,edi
   140002fff:	72 af                	jb     0x140002fb0
   140003001:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003004:	49 3b f5             	cmp    rsi,r13
   140003007:	0f 85 63 ff ff ff    	jne    0x140002f70
   14000300d:	33 db                	xor    ebx,ebx
   14000300f:	48 8b 0d 6a 50 00 00 	mov    rcx,QWORD PTR [rip+0x506a]        # 0x140008080
   140003016:	ff d3                	call   rbx
   140003018:	b8 01 00 00 00       	mov    eax,0x1
   14000301d:	e9 8e 00 00 00       	jmp    0x1400030b0
   140003022:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003027:	45 8b 04 84          	mov    r8d,DWORD PTR [r12+rax*4]
   14000302b:	4d 03 c3             	add    r8,r11
   14000302e:	e9 ec f9 ff ff       	jmp    0x140002a1f
   140003033:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003038:	45 8b 04 84          	mov    r8d,DWORD PTR [r12+rax*4]
   14000303c:	4d 03 c3             	add    r8,r11
   14000303f:	33 db                	xor    ebx,ebx
   140003041:	e9 ac fa ff ff       	jmp    0x140002af2
   140003046:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   14000304b:	41 8b 14 84          	mov    edx,DWORD PTR [r12+rax*4]
   14000304f:	49 03 d3             	add    rdx,r11
   140003052:	33 db                	xor    ebx,ebx
   140003054:	e9 69 fb ff ff       	jmp    0x140002bc2
   140003059:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   14000305e:	41 8b 14 84          	mov    edx,DWORD PTR [r12+rax*4]
   140003062:	49 03 d3             	add    rdx,r11
   140003065:	33 db                	xor    ebx,ebx
   140003067:	e9 66 fc ff ff       	jmp    0x140002cd2
   14000306c:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003071:	45 8b 14 84          	mov    r10d,DWORD PTR [r12+rax*4]
   140003075:	4d 03 d3             	add    r10,r11
   140003078:	33 db                	xor    ebx,ebx
   14000307a:	e9 a3 fd ff ff       	jmp    0x140002e22
   14000307f:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003084:	45 8b 04 84          	mov    r8d,DWORD PTR [r12+rax*4]
   140003088:	4d 03 c3             	add    r8,r11
   14000308b:	33 db                	xor    ebx,ebx
   14000308d:	e9 b0 fe ff ff       	jmp    0x140002f42
   140003092:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003097:	48 8b 0d e2 4f 00 00 	mov    rcx,QWORD PTR [rip+0x4fe2]        # 0x140008080
   14000309e:	41 8b 1c 84          	mov    ebx,DWORD PTR [r12+rax*4]
   1400030a2:	49 03 db             	add    rbx,r11
   1400030a5:	ff d3                	call   rbx
   1400030a7:	b8 01 00 00 00       	mov    eax,0x1
   1400030ac:	eb 02                	jmp    0x1400030b0
   1400030ae:	33 c0                	xor    eax,eax
   1400030b0:	48 8b 4d 00          	mov    rcx,QWORD PTR [rbp+0x0]
   1400030b4:	48 33 cc             	xor    rcx,rsp
   1400030b7:	e8 64 12 00 00       	call   0x140004320
   1400030bc:	4c 8d 9c 24 10 01 00 	lea    r11,[rsp+0x110]
   1400030c3:	00 
   1400030c4:	49 8b 5b 30          	mov    rbx,QWORD PTR [r11+0x30]
   1400030c8:	49 8b 73 38          	mov    rsi,QWORD PTR [r11+0x38]
   1400030cc:	49 8b 7b 40          	mov    rdi,QWORD PTR [r11+0x40]
   1400030d0:	49 8b e3             	mov    rsp,r11
   1400030d3:	41 5f                	pop    r15
   1400030d5:	41 5e                	pop    r14
   1400030d7:	41 5d                	pop    r13
   1400030d9:	41 5c                	pop    r12
   1400030db:	5d                   	pop    rbp
   1400030dc:	c3                   	ret
   1400030dd:	cc                   	int3
   1400030de:	cc                   	int3
   1400030df:	cc                   	int3
   1400030e0:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   1400030e5:	48 83 ec 48          	sub    rsp,0x48
   1400030e9:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   1400030f0:	48 ff c0             	inc    rax
   1400030f3:	80 3c 01 00          	cmp    BYTE PTR [rcx+rax*1],0x0
   1400030f7:	75 f7                	jne    0x1400030f0
   1400030f9:	48 89 5c 24 58       	mov    QWORD PTR [rsp+0x58],rbx
   1400030fe:	48 89 6c 24 60       	mov    QWORD PTR [rsp+0x60],rbp
   140003103:	48 89 74 24 68       	mov    QWORD PTR [rsp+0x68],rsi
   140003108:	48 89 7c 24 40       	mov    QWORD PTR [rsp+0x40],rdi
   14000310d:	4c 89 64 24 38       	mov    QWORD PTR [rsp+0x38],r12
   140003112:	4c 89 6c 24 30       	mov    QWORD PTR [rsp+0x30],r13
   140003117:	4c 89 74 24 28       	mov    QWORD PTR [rsp+0x28],r14
   14000311c:	4c 89 7c 24 20       	mov    QWORD PTR [rsp+0x20],r15
   140003121:	48 83 f8 13          	cmp    rax,0x13
   140003125:	75 20                	jne    0x140003147
   140003127:	45 33 f6             	xor    r14d,r14d
   14000312a:	b8 10 42 00 00       	mov    eax,0x4210
   14000312f:	90                   	nop
   140003130:	49 83 fe 0e          	cmp    r14,0xe
   140003134:	77 40                	ja     0x140003176
   140003136:	4c 0f a3 f0          	bt     rax,r14
   14000313a:	73 3a                	jae    0x140003176
   14000313c:	41 80 3c 0e 2d       	cmp    BYTE PTR [r14+rcx*1],0x2d
   140003141:	0f 84 3f 01 00 00    	je     0x140003286
   140003147:	33 c0                	xor    eax,eax
   140003149:	4c 8b 7c 24 20       	mov    r15,QWORD PTR [rsp+0x20]
   14000314e:	4c 8b 74 24 28       	mov    r14,QWORD PTR [rsp+0x28]
   140003153:	4c 8b 6c 24 30       	mov    r13,QWORD PTR [rsp+0x30]
   140003158:	4c 8b 64 24 38       	mov    r12,QWORD PTR [rsp+0x38]
   14000315d:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   140003162:	48 8b 74 24 68       	mov    rsi,QWORD PTR [rsp+0x68]
   140003167:	48 8b 6c 24 60       	mov    rbp,QWORD PTR [rsp+0x60]
   14000316c:	48 8b 5c 24 58       	mov    rbx,QWORD PTR [rsp+0x58]
   140003171:	48 83 c4 48          	add    rsp,0x48
   140003175:	c3                   	ret
   140003176:	e8 05 11 00 00       	call   0x140004280
   14000317b:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   14000317f:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140003183:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003187:	49 3b dd             	cmp    rbx,r13
   14000318a:	0f 84 a4 00 00 00    	je     0x140003234
   140003190:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140003194:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003198:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000319f:	00 
   1400031a0:	85 c9                	test   ecx,ecx
   1400031a2:	0f 84 80 00 00 00    	je     0x140003228
   1400031a8:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   1400031ad:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400031b1:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400031b5:	49 03 eb             	add    rbp,r11
   1400031b8:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400031bc:	4d 03 fb             	add    r15,r11
   1400031bf:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400031c2:	4d 03 e3             	add    r12,r11
   1400031c5:	45 33 d2             	xor    r10d,r10d
   1400031c8:	85 ff                	test   edi,edi
   1400031ca:	74 5c                	je     0x140003228
   1400031cc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400031d0:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   1400031d5:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   1400031dc:	4d 03 c3             	add    r8,r11
   1400031df:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400031e5:	48 ff c0             	inc    rax
   1400031e8:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   1400031ed:	75 f6                	jne    0x1400031e5
   1400031ef:	33 d2                	xor    edx,edx
   1400031f1:	48 85 c0             	test   rax,rax
   1400031f4:	74 2a                	je     0x140003220
   1400031f6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   1400031fd:	00 00 00 
   140003200:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   140003205:	48 ff c2             	inc    rdx
   140003208:	41 33 c9             	xor    ecx,r9d
   14000320b:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140003212:	48 3b d0             	cmp    rdx,rax
   140003215:	72 e9                	jb     0x140003200
   140003217:	41 81 f9 33 36 ea 71 	cmp    r9d,0x71ea3633
   14000321e:	74 34                	je     0x140003254
   140003220:	41 ff c2             	inc    r10d
   140003223:	44 3b d7             	cmp    r10d,edi
   140003226:	72 a8                	jb     0x1400031d0
   140003228:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   14000322b:	49 3b dd             	cmp    rbx,r13
   14000322e:	0f 85 5c ff ff ff    	jne    0x140003190
   140003234:	33 d2                	xor    edx,edx
   140003236:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
   14000323b:	41 0f be 0c 06       	movsx  ecx,BYTE PTR [r14+rax*1]
   140003240:	ff d2                	call   rdx
   140003242:	8b d0                	mov    edx,eax
   140003244:	8d 48 bf             	lea    ecx,[rax-0x41]
   140003247:	80 f9 19             	cmp    cl,0x19
   14000324a:	77 16                	ja     0x140003262
   14000324c:	0f be c2             	movsx  eax,dl
   14000324f:	83 c0 bf             	add    eax,0xffffffbf
   140003252:	eb 1f                	jmp    0x140003273
   140003254:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003259:	41 8b 14 84          	mov    edx,DWORD PTR [r12+rax*4]
   14000325d:	49 03 d3             	add    rdx,r11
   140003260:	eb d4                	jmp    0x140003236
   140003262:	83 c0 ce             	add    eax,0xffffffce
   140003265:	3c 05                	cmp    al,0x5
   140003267:	0f 87 da fe ff ff    	ja     0x140003147
   14000326d:	0f be c2             	movsx  eax,dl
   140003270:	83 c0 e8             	add    eax,0xffffffe8
   140003273:	83 f8 ff             	cmp    eax,0xffffffff
   140003276:	0f 84 cb fe ff ff    	je     0x140003147
   14000327c:	48 8b 4c 24 50       	mov    rcx,QWORD PTR [rsp+0x50]
   140003281:	b8 10 42 00 00       	mov    eax,0x4210
   140003286:	49 ff c6             	inc    r14
   140003289:	49 83 fe 13          	cmp    r14,0x13
   14000328d:	0f 8c 9d fe ff ff    	jl     0x140003130
   140003293:	b8 01 00 00 00       	mov    eax,0x1
   140003298:	e9 ac fe ff ff       	jmp    0x140003149
   14000329d:	cc                   	int3
   14000329e:	cc                   	int3
   14000329f:	cc                   	int3
   1400032a0:	44 89 4c 24 20       	mov    DWORD PTR [rsp+0x20],r9d
   1400032a5:	4c 89 44 24 18       	mov    QWORD PTR [rsp+0x18],r8
   1400032aa:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   1400032af:	89 4c 24 08          	mov    DWORD PTR [rsp+0x8],ecx
   1400032b3:	48 83 ec 38          	sub    rsp,0x38
   1400032b7:	c7 44 24 20 00 00 00 	mov    DWORD PTR [rsp+0x20],0x0
   1400032be:	00 
   1400032bf:	8b 44 24 40          	mov    eax,DWORD PTR [rsp+0x40]
   1400032c3:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   1400032c7:	eb 0a                	jmp    0x1400032d3
   1400032c9:	8b 44 24 20          	mov    eax,DWORD PTR [rsp+0x20]
   1400032cd:	ff c0                	inc    eax
   1400032cf:	89 44 24 20          	mov    DWORD PTR [rsp+0x20],eax
   1400032d3:	8b 44 24 58          	mov    eax,DWORD PTR [rsp+0x58]
   1400032d7:	39 44 24 20          	cmp    DWORD PTR [rsp+0x20],eax
   1400032db:	73 2c                	jae    0x140003309
   1400032dd:	8b 44 24 20          	mov    eax,DWORD PTR [rsp+0x20]
   1400032e1:	48 8b 4c 24 48       	mov    rcx,QWORD PTR [rsp+0x48]
   1400032e6:	0f be 04 01          	movsx  eax,BYTE PTR [rcx+rax*1]
   1400032ea:	33 44 24 24          	xor    eax,DWORD PTR [rsp+0x24]
   1400032ee:	8b 4c 24 20          	mov    ecx,DWORD PTR [rsp+0x20]
   1400032f2:	48 8b 54 24 50       	mov    rdx,QWORD PTR [rsp+0x50]
   1400032f7:	88 04 0a             	mov    BYTE PTR [rdx+rcx*1],al
   1400032fa:	8b 4c 24 24          	mov    ecx,DWORD PTR [rsp+0x24]
   1400032fe:	e8 ed 0a 00 00       	call   0x140003df0
   140003303:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   140003307:	eb c0                	jmp    0x1400032c9
   140003309:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
   14000330e:	48 83 c4 38          	add    rsp,0x38
   140003312:	c3                   	ret
   140003313:	cc                   	int3
   140003314:	cc                   	int3
   140003315:	cc                   	int3
   140003316:	cc                   	int3
   140003317:	cc                   	int3
   140003318:	cc                   	int3
   140003319:	cc                   	int3
   14000331a:	cc                   	int3
   14000331b:	cc                   	int3
   14000331c:	cc                   	int3
   14000331d:	cc                   	int3
   14000331e:	cc                   	int3
   14000331f:	cc                   	int3
   140003320:	40 53                	rex push rbx
   140003322:	56                   	push   rsi
   140003323:	41 56                	push   r14
   140003325:	48 81 ec 90 00 00 00 	sub    rsp,0x90
   14000332c:	48 8b 05 cd 4c 00 00 	mov    rax,QWORD PTR [rip+0x4ccd]        # 0x140008000
   140003333:	48 33 c4             	xor    rax,rsp
   140003336:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
   14000333b:	48 8b da             	mov    rbx,rdx
   14000333e:	48 89 54 24 40       	mov    QWORD PTR [rsp+0x40],rdx
   140003343:	48 8b f1             	mov    rsi,rcx
   140003346:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
   14000334b:	e8 90 fd ff ff       	call   0x1400030e0
   140003350:	85 c0                	test   eax,eax
   140003352:	0f 84 2b 02 00 00    	je     0x140003583
   140003358:	48 89 ac 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rbp
   14000335f:	00 
   140003360:	48 8d 44 24 48       	lea    rax,[rsp+0x48]
   140003365:	48 89 bc 24 88 00 00 	mov    QWORD PTR [rsp+0x88],rdi
   14000336c:	00 
   14000336d:	48 2b c3             	sub    rax,rbx
   140003370:	4c 89 a4 24 80 00 00 	mov    QWORD PTR [rsp+0x80],r12
   140003377:	00 
   140003378:	45 33 f6             	xor    r14d,r14d
   14000337b:	4c 89 6c 24 78       	mov    QWORD PTR [rsp+0x78],r13
   140003380:	4c 89 7c 24 70       	mov    QWORD PTR [rsp+0x70],r15
   140003385:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
   14000338a:	48 89 5c 24 28       	mov    QWORD PTR [rsp+0x28],rbx
   14000338f:	48 c7 44 24 30 04 00 	mov    QWORD PTR [rsp+0x30],0x4
   140003396:	00 00 
   140003398:	e8 e3 0e 00 00       	call   0x140004280
   14000339d:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   1400033a1:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   1400033a5:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   1400033a9:	49 3b dd             	cmp    rbx,r13
   1400033ac:	0f 84 b8 00 00 00    	je     0x14000346a
   1400033b2:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400033b6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   1400033bd:	00 00 00 
   1400033c0:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   1400033c4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   1400033c8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   1400033cf:	00 
   1400033d0:	85 c9                	test   ecx,ecx
   1400033d2:	0f 84 81 00 00 00    	je     0x140003459
   1400033d8:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   1400033dd:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400033e1:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400033e5:	49 03 eb             	add    rbp,r11
   1400033e8:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400033ec:	4d 03 fb             	add    r15,r11
   1400033ef:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400033f2:	4d 03 e3             	add    r12,r11
   1400033f5:	45 8b d6             	mov    r10d,r14d
   1400033f8:	85 ff                	test   edi,edi
   1400033fa:	74 5d                	je     0x140003459
   1400033fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003400:	41 8b f2             	mov    esi,r10d
   140003403:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   14000340a:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003410:	44 8b 44 b5 00       	mov    r8d,DWORD PTR [rbp+rsi*4+0x0]
   140003415:	4d 03 c3             	add    r8,r11
   140003418:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14000341f:	00 
   140003420:	48 ff c0             	inc    rax
   140003423:	45 38 34 00          	cmp    BYTE PTR [r8+rax*1],r14b
   140003427:	75 f7                	jne    0x140003420
   140003429:	49 8b d6             	mov    rdx,r14
   14000342c:	48 85 c0             	test   rax,rax
   14000342f:	74 20                	je     0x140003451
   140003431:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   140003436:	48 ff c2             	inc    rdx
   140003439:	41 33 c9             	xor    ecx,r9d
   14000343c:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140003443:	48 3b d0             	cmp    rdx,rax
   140003446:	72 e9                	jb     0x140003431
   140003448:	41 81 f9 eb a6 a5 1d 	cmp    r9d,0x1da5a6eb
   14000344f:	74 51                	je     0x1400034a2
   140003451:	41 ff c2             	inc    r10d
   140003454:	44 3b d7             	cmp    r10d,edi
   140003457:	72 a7                	jb     0x140003400
   140003459:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   14000345c:	49 3b dd             	cmp    rbx,r13
   14000345f:	0f 85 5b ff ff ff    	jne    0x1400033c0
   140003465:	48 8b 74 24 20       	mov    rsi,QWORD PTR [rsp+0x20]
   14000346a:	4d 8b ce             	mov    r9,r14
   14000346d:	41 b8 04 00 00 00    	mov    r8d,0x4
   140003473:	48 8d 4c 24 58       	lea    rcx,[rsp+0x58]
   140003478:	48 8b d6             	mov    rdx,rsi
   14000347b:	41 ff d1             	call   r9
   14000347e:	41 8b ce             	mov    ecx,r14d
   140003481:	44 88 74 24 5c       	mov    BYTE PTR [rsp+0x5c],r14b
   140003486:	4d 8b c6             	mov    r8,r14
   140003489:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   140003490:	42 0f be 54 04 58    	movsx  edx,BYTE PTR [rsp+r8*1+0x58]
   140003496:	8d 42 bf             	lea    eax,[rdx-0x41]
   140003499:	3c 19                	cmp    al,0x19
   14000349b:	77 18                	ja     0x1400034b5
   14000349d:	8d 42 bf             	lea    eax,[rdx-0x41]
   1400034a0:	eb 1d                	jmp    0x1400034bf
   1400034a2:	41 0f b7 04 77       	movzx  eax,WORD PTR [r15+rsi*2]
   1400034a7:	48 8b 74 24 20       	mov    rsi,QWORD PTR [rsp+0x20]
   1400034ac:	45 8b 0c 84          	mov    r9d,DWORD PTR [r12+rax*4]
   1400034b0:	4d 03 cb             	add    r9,r11
   1400034b3:	eb b8                	jmp    0x14000346d
   1400034b5:	8d 42 ce             	lea    eax,[rdx-0x32]
   1400034b8:	3c 05                	cmp    al,0x5
   1400034ba:	77 18                	ja     0x1400034d4
   1400034bc:	8d 42 e8             	lea    eax,[rdx-0x18]
   1400034bf:	83 f8 ff             	cmp    eax,0xffffffff
   1400034c2:	74 10                	je     0x1400034d4
   1400034c4:	c1 e1 05             	shl    ecx,0x5
   1400034c7:	49 ff c0             	inc    r8
   1400034ca:	0b c8                	or     ecx,eax
   1400034cc:	49 83 f8 04          	cmp    r8,0x4
   1400034d0:	7c be                	jl     0x140003490
   1400034d2:	eb 05                	jmp    0x1400034d9
   1400034d4:	b9 ff ff ff ff       	mov    ecx,0xffffffff
   1400034d9:	48 8b 7c 24 28       	mov    rdi,QWORD PTR [rsp+0x28]
   1400034de:	48 83 c6 05          	add    rsi,0x5
   1400034e2:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
   1400034e7:	48 89 74 24 20       	mov    QWORD PTR [rsp+0x20],rsi
   1400034ec:	89 0c 38             	mov    DWORD PTR [rax+rdi*1],ecx
   1400034ef:	c1 f9 0c             	sar    ecx,0xc
   1400034f2:	0f b6 c1             	movzx  eax,cl
   1400034f5:	89 07                	mov    DWORD PTR [rdi],eax
   1400034f7:	48 83 c7 04          	add    rdi,0x4
   1400034fb:	48 83 6c 24 30 01    	sub    QWORD PTR [rsp+0x30],0x1
   140003501:	48 89 7c 24 28       	mov    QWORD PTR [rsp+0x28],rdi
   140003506:	0f 85 8c fe ff ff    	jne    0x140003398
   14000350c:	8b 44 24 48          	mov    eax,DWORD PTR [rsp+0x48]
   140003510:	4c 8b 7c 24 70       	mov    r15,QWORD PTR [rsp+0x70]
   140003515:	35 4a 1b 08 7b       	xor    eax,0x7b081b4a
   14000351a:	4c 8b 6c 24 78       	mov    r13,QWORD PTR [rsp+0x78]
   14000351f:	4c 8b a4 24 80 00 00 	mov    r12,QWORD PTR [rsp+0x80]
   140003526:	00 
   140003527:	48 8b bc 24 88 00 00 	mov    rdi,QWORD PTR [rsp+0x88]
   14000352e:	00 
   14000352f:	48 8b ac 24 c0 00 00 	mov    rbp,QWORD PTR [rsp+0xc0]
   140003536:	00 
   140003537:	69 d0 3b 9f 5d 04    	imul   edx,eax,0x45d9f3b
   14000353d:	c1 ca 13             	ror    edx,0x13
   140003540:	33 54 24 4c          	xor    edx,DWORD PTR [rsp+0x4c]
   140003544:	69 c2 3b 9f 5d 04    	imul   eax,edx,0x45d9f3b
   14000354a:	c1 c8 13             	ror    eax,0x13
   14000354d:	33 44 24 50          	xor    eax,DWORD PTR [rsp+0x50]
   140003551:	69 d0 3b 9f 5d 04    	imul   edx,eax,0x45d9f3b
   140003557:	c1 ca 13             	ror    edx,0x13
   14000355a:	81 e2 ff ff 0f 00    	and    edx,0xfffff
   140003560:	3b 54 24 54          	cmp    edx,DWORD PTR [rsp+0x54]
   140003564:	75 1d                	jne    0x140003583
   140003566:	48 8b 4c 24 40       	mov    rcx,QWORD PTR [rsp+0x40]
   14000356b:	ba 0c 00 00 00       	mov    edx,0xc
   140003570:	e8 0b db ff ff       	call   0x140001080
   140003575:	3d a8 45 7f 36       	cmp    eax,0x367f45a8
   14000357a:	41 0f 94 c6          	sete   r14b
   14000357e:	41 8b c6             	mov    eax,r14d
   140003581:	eb 02                	jmp    0x140003585
   140003583:	33 c0                	xor    eax,eax
   140003585:	48 8b 4c 24 60       	mov    rcx,QWORD PTR [rsp+0x60]
   14000358a:	48 33 cc             	xor    rcx,rsp
   14000358d:	e8 8e 0d 00 00       	call   0x140004320
   140003592:	48 81 c4 90 00 00 00 	add    rsp,0x90
   140003599:	41 5e                	pop    r14
   14000359b:	5e                   	pop    rsi
   14000359c:	5b                   	pop    rbx
   14000359d:	c3                   	ret
   14000359e:	cc                   	int3
   14000359f:	cc                   	int3
   1400035a0:	40 55                	rex push rbp
   1400035a2:	53                   	push   rbx
   1400035a3:	56                   	push   rsi
   1400035a4:	57                   	push   rdi
   1400035a5:	41 54                	push   r12
   1400035a7:	41 55                	push   r13
   1400035a9:	41 56                	push   r14
   1400035ab:	41 57                	push   r15
   1400035ad:	48 8d ac 24 d8 fd ff 	lea    rbp,[rsp-0x228]
   1400035b4:	ff 
   1400035b5:	48 81 ec 28 03 00 00 	sub    rsp,0x328
   1400035bc:	48 8b 05 3d 4a 00 00 	mov    rax,QWORD PTR [rip+0x4a3d]        # 0x140008000
   1400035c3:	48 33 c4             	xor    rax,rsp
   1400035c6:	48 89 85 10 02 00 00 	mov    QWORD PTR [rbp+0x210],rax
   1400035cd:	8b c2                	mov    eax,edx
   1400035cf:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
   1400035d4:	83 e8 01             	sub    eax,0x1
   1400035d7:	0f 84 e4 07 00 00    	je     0x140003dc1
   1400035dd:	83 e8 0f             	sub    eax,0xf
   1400035e0:	0f 84 ef 06 00 00    	je     0x140003cd5
   1400035e6:	3d 01 01 00 00       	cmp    eax,0x101
   1400035eb:	74 0b                	je     0x1400035f8
   1400035ed:	ff 15 95 2a 00 00    	call   QWORD PTR [rip+0x2a95]        # 0x140006088
   1400035f3:	e9 d0 07 00 00       	jmp    0x140003dc8
   1400035f8:	b8 e9 03 00 00       	mov    eax,0x3e9
   1400035fd:	66 44 3b c0          	cmp    r8w,ax
   140003601:	0f 85 bf 07 00 00    	jne    0x140003dc6
   140003607:	49 c1 e8 10          	shr    r8,0x10
   14000360b:	66 45 85 c0          	test   r8w,r8w
   14000360f:	0f 85 b1 07 00 00    	jne    0x140003dc6
   140003615:	e8 66 0c 00 00       	call   0x140004280
   14000361a:	33 d2                	xor    edx,edx
   14000361c:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003620:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140003624:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003628:	49 3b f5             	cmp    rsi,r13
   14000362b:	0f 84 bc 00 00 00    	je     0x1400036ed
   140003631:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003635:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   14000363c:	00 00 00 00 
   140003640:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140003644:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003648:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000364f:	00 
   140003650:	85 c9                	test   ecx,ecx
   140003652:	0f 84 89 00 00 00    	je     0x1400036e1
   140003658:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   14000365d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003661:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140003665:	4d 03 f3             	add    r14,r11
   140003668:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   14000366c:	4d 03 fb             	add    r15,r11
   14000366f:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140003672:	4d 03 e3             	add    r12,r11
   140003675:	44 8b d2             	mov    r10d,edx
   140003678:	85 ff                	test   edi,edi
   14000367a:	74 65                	je     0x1400036e1
   14000367c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003680:	41 8b da             	mov    ebx,r10d
   140003683:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   14000368a:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003690:	45 8b 04 9e          	mov    r8d,DWORD PTR [r14+rbx*4]
   140003694:	4d 03 c3             	add    r8,r11
   140003697:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   14000369e:	00 00 
   1400036a0:	48 ff c1             	inc    rcx
   1400036a3:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400036a8:	75 f6                	jne    0x1400036a0
   1400036aa:	48 85 c9             	test   rcx,rcx
   1400036ad:	74 25                	je     0x1400036d4
   1400036af:	90                   	nop
   1400036b0:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400036b5:	48 ff c2             	inc    rdx
   1400036b8:	41 33 c1             	xor    eax,r9d
   1400036bb:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   1400036c2:	48 3b d1             	cmp    rdx,rcx
   1400036c5:	72 e9                	jb     0x1400036b0
   1400036c7:	41 81 f9 92 05 3b 71 	cmp    r9d,0x713b0592
   1400036ce:	0f 84 62 04 00 00    	je     0x140003b36
   1400036d4:	41 ff c2             	inc    r10d
   1400036d7:	ba 00 00 00 00       	mov    edx,0x0
   1400036dc:	44 3b d7             	cmp    r10d,edi
   1400036df:	72 9f                	jb     0x140003680
   1400036e1:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   1400036e4:	49 3b f5             	cmp    rsi,r13
   1400036e7:	0f 85 53 ff ff ff    	jne    0x140003640
   1400036ed:	4c 8b ca             	mov    r9,rdx
   1400036f0:	48 8b 0d 99 49 00 00 	mov    rcx,QWORD PTR [rip+0x4999]        # 0x140008090
   1400036f7:	48 8d 95 10 01 00 00 	lea    rdx,[rbp+0x110]
   1400036fe:	41 b8 00 01 00 00    	mov    r8d,0x100
   140003704:	41 ff d1             	call   r9
   140003707:	48 8d 55 80          	lea    rdx,[rbp-0x80]
   14000370b:	48 8d 8d 10 01 00 00 	lea    rcx,[rbp+0x110]
   140003712:	e8 09 fc ff ff       	call   0x140003320
   140003717:	85 c0                	test   eax,eax
   140003719:	0f 84 5c 04 00 00    	je     0x140003b7b
   14000371f:	33 d2                	xor    edx,edx
   140003721:	48 8d 4d 10          	lea    rcx,[rbp+0x10]
   140003725:	41 b8 00 01 00 00    	mov    r8d,0x100
   14000372b:	e8 e0 17 00 00       	call   0x140004f10
   140003730:	66 0f 6f 05 38 2b 00 	movdqa xmm0,XMMWORD PTR [rip+0x2b38]        # 0x140006270
   140003737:	00 
   140003738:	4c 8d 05 09 4a 00 00 	lea    r8,[rip+0x4a09]        # 0x140008148
   14000373f:	41 b9 1c 00 00 00    	mov    r9d,0x1c
   140003745:	c7 44 24 50 85 cd 41 	mov    DWORD PTR [rsp+0x50],0xb841cd85
   14000374c:	b8 
   14000374d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
   140003752:	c7 44 24 54 01 4f 67 	mov    DWORD PTR [rsp+0x54],0x29674f01
   140003759:	29 
   14000375a:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   14000375f:	c7 44 24 58 42 6d c2 	mov    DWORD PTR [rsp+0x58],0x65c26d42
   140003766:	65 
   140003767:	f3 0f 7f 44 24 40    	movdqu XMMWORD PTR [rsp+0x40],xmm0
   14000376d:	c7 44 24 5c 8c c8 10 	mov    DWORD PTR [rsp+0x5c],0x2d10c88c
   140003774:	2d 
   140003775:	e8 26 fb ff ff       	call   0x1400032a0
   14000377a:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
   14000377f:	e8 fc 0a 00 00       	call   0x140004280
   140003784:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003788:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   14000378c:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003790:	49 3b f5             	cmp    rsi,r13
   140003793:	0f 84 a4 00 00 00    	je     0x14000383d
   140003799:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1400037a0:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   1400037a4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   1400037a8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   1400037af:	00 
   1400037b0:	85 c9                	test   ecx,ecx
   1400037b2:	74 7d                	je     0x140003831
   1400037b4:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   1400037b9:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400037bd:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   1400037c1:	4d 03 f3             	add    r14,r11
   1400037c4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   1400037c8:	4d 03 fb             	add    r15,r11
   1400037cb:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400037ce:	4d 03 e3             	add    r12,r11
   1400037d1:	45 33 d2             	xor    r10d,r10d
   1400037d4:	85 ff                	test   edi,edi
   1400037d6:	74 59                	je     0x140003831
   1400037d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400037df:	00 
   1400037e0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   1400037e4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400037eb:	4d 03 c3             	add    r8,r11
   1400037ee:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400037f4:	48 ff c1             	inc    rcx
   1400037f7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400037fc:	75 f6                	jne    0x1400037f4
   1400037fe:	33 d2                	xor    edx,edx
   140003800:	48 85 c9             	test   rcx,rcx
   140003803:	74 24                	je     0x140003829
   140003805:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   14000380a:	48 ff c2             	inc    rdx
   14000380d:	41 33 c1             	xor    eax,r9d
   140003810:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140003817:	48 3b d1             	cmp    rdx,rcx
   14000381a:	72 e9                	jb     0x140003805
   14000381c:	41 81 f9 c1 11 08 1b 	cmp    r9d,0x1b0811c1
   140003823:	0f 84 1e 03 00 00    	je     0x140003b47
   140003829:	41 ff c2             	inc    r10d
   14000382c:	44 3b d7             	cmp    r10d,edi
   14000382f:	72 af                	jb     0x1400037e0
   140003831:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003834:	49 3b f5             	cmp    rsi,r13
   140003837:	0f 85 63 ff ff ff    	jne    0x1400037a0
   14000383d:	33 db                	xor    ebx,ebx
   14000383f:	44 8b c3             	mov    r8d,ebx
   140003842:	48 8b 54 24 20       	mov    rdx,QWORD PTR [rsp+0x20]
   140003847:	48 8d 4d 10          	lea    rcx,[rbp+0x10]
   14000384b:	41 ff d0             	call   r8
   14000384e:	66 0f 6f 0d 4a 2a 00 	movdqa xmm1,XMMWORD PTR [rip+0x2a4a]        # 0x1400062a0
   140003855:	00 
   140003856:	4c 8d 05 0b 49 00 00 	lea    r8,[rip+0x490b]        # 0x140008168
   14000385d:	0f 57 c0             	xorps  xmm0,xmm0
   140003860:	c7 44 24 60 5c 2f 65 	mov    DWORD PTR [rsp+0x60],0xc9652f5c
   140003867:	c9 
   140003868:	0f 11 45 90          	movups XMMWORD PTR [rbp-0x70],xmm0
   14000386c:	41 b9 2a 00 00 00    	mov    r9d,0x2a
   140003872:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
   140003877:	0f 11 45 a0          	movups XMMWORD PTR [rbp-0x60],xmm0
   14000387b:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140003880:	c7 44 24 64 e3 da 62 	mov    DWORD PTR [rsp+0x64],0x3462dae3
   140003887:	34 
   140003888:	0f 11 45 b0          	movups XMMWORD PTR [rbp-0x50],xmm0
   14000388c:	c7 44 24 68 0d 4d 00 	mov    DWORD PTR [rsp+0x68],0x4d0d
   140003893:	00 
   140003894:	0f 11 45 c0          	movups XMMWORD PTR [rbp-0x40],xmm0
   140003898:	c7 44 24 6c 8c c8 10 	mov    DWORD PTR [rsp+0x6c],0x2d10c88c
   14000389f:	2d 
   1400038a0:	0f 11 45 d0          	movups XMMWORD PTR [rbp-0x30],xmm0
   1400038a4:	0f 11 45 e0          	movups XMMWORD PTR [rbp-0x20],xmm0
   1400038a8:	0f 11 45 f0          	movups XMMWORD PTR [rbp-0x10],xmm0
   1400038ac:	0f 11 45 00          	movups XMMWORD PTR [rbp+0x0],xmm0
   1400038b0:	66 0f 6f 05 f8 29 00 	movdqa xmm0,XMMWORD PTR [rip+0x29f8]        # 0x1400062b0
   1400038b7:	00 
   1400038b8:	f3 0f 7f 44 24 40    	movdqu XMMWORD PTR [rsp+0x40],xmm0
   1400038be:	f3 0f 7f 4c 24 50    	movdqu XMMWORD PTR [rsp+0x50],xmm1
   1400038c4:	e8 d7 f9 ff ff       	call   0x1400032a0
   1400038c9:	4c 8b c0             	mov    r8,rax
   1400038cc:	44 8b cb             	mov    r9d,ebx
   1400038cf:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   1400038d6:	48 ff c0             	inc    rax
   1400038d9:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   1400038de:	75 f6                	jne    0x1400038d6
   1400038e0:	48 85 c0             	test   rax,rax
   1400038e3:	74 63                	je     0x140003948
   1400038e5:	48 8d 45 90          	lea    rax,[rbp-0x70]
   1400038e9:	4d 8b d8             	mov    r11,r8
   1400038ec:	4c 2b d8             	sub    r11,rax
   1400038ef:	4c 8d 55 90          	lea    r10,[rbp-0x70]
   1400038f3:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400038f7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1400038fe:	00 00 
   140003900:	41 8b c9             	mov    ecx,r9d
   140003903:	4d 8d 52 01          	lea    r10,[r10+0x1]
   140003907:	b8 56 55 55 55       	mov    eax,0x55555556
   14000390c:	41 f7 e9             	imul   r9d
   14000390f:	8b c2                	mov    eax,edx
   140003911:	c1 e8 1f             	shr    eax,0x1f
   140003914:	03 d0                	add    edx,eax
   140003916:	8d 04 52             	lea    eax,[rdx+rdx*2]
   140003919:	2b c8                	sub    ecx,eax
   14000391b:	48 63 c1             	movsxd rax,ecx
   14000391e:	0f b6 4c 85 80       	movzx  ecx,BYTE PTR [rbp+rax*4-0x80]
   140003923:	43 32 4c 13 ff       	xor    cl,BYTE PTR [r11+r10*1-0x1]
   140003928:	41 88 4a ff          	mov    BYTE PTR [r10-0x1],cl
   14000392c:	41 ff c1             	inc    r9d
   14000392f:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140003936:	48 ff c1             	inc    rcx
   140003939:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   14000393e:	75 f6                	jne    0x140003936
   140003940:	49 63 c1             	movsxd rax,r9d
   140003943:	48 3b c1             	cmp    rax,rcx
   140003946:	72 b8                	jb     0x140003900
   140003948:	e8 33 09 00 00       	call   0x140004280
   14000394d:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003951:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140003955:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003959:	49 3b f5             	cmp    rsi,r13
   14000395c:	0f 84 ad 00 00 00    	je     0x140003a0f
   140003962:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003966:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   14000396d:	00 00 00 
   140003970:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140003974:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003978:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000397f:	00 
   140003980:	85 c9                	test   ecx,ecx
   140003982:	74 7d                	je     0x140003a01
   140003984:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140003989:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   14000398d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140003991:	4d 03 f3             	add    r14,r11
   140003994:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140003998:	4d 03 fb             	add    r15,r11
   14000399b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   14000399e:	4d 03 e3             	add    r12,r11
   1400039a1:	45 33 d2             	xor    r10d,r10d
   1400039a4:	85 ff                	test   edi,edi
   1400039a6:	74 59                	je     0x140003a01
   1400039a8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1400039af:	00 
   1400039b0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   1400039b4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400039bb:	4d 03 c3             	add    r8,r11
   1400039be:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400039c4:	48 ff c1             	inc    rcx
   1400039c7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400039cc:	75 f6                	jne    0x1400039c4
   1400039ce:	33 d2                	xor    edx,edx
   1400039d0:	48 85 c9             	test   rcx,rcx
   1400039d3:	74 24                	je     0x1400039f9
   1400039d5:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400039da:	48 ff c2             	inc    rdx
   1400039dd:	41 33 c1             	xor    eax,r9d
   1400039e0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   1400039e7:	48 3b d1             	cmp    rdx,rcx
   1400039ea:	72 e9                	jb     0x1400039d5
   1400039ec:	41 81 f9 c1 11 08 1b 	cmp    r9d,0x1b0811c1
   1400039f3:	0f 84 61 01 00 00    	je     0x140003b5a
   1400039f9:	41 ff c2             	inc    r10d
   1400039fc:	44 3b d7             	cmp    r10d,edi
   1400039ff:	72 af                	jb     0x1400039b0
   140003a01:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003a04:	49 3b f5             	cmp    rsi,r13
   140003a07:	0f 85 63 ff ff ff    	jne    0x140003970
   140003a0d:	33 db                	xor    ebx,ebx
   140003a0f:	4c 8b c3             	mov    r8,rbx
   140003a12:	48 8d 55 90          	lea    rdx,[rbp-0x70]
   140003a16:	48 8d 4d 10          	lea    rcx,[rbp+0x10]
   140003a1a:	41 ff d0             	call   r8
   140003a1d:	33 c0                	xor    eax,eax
   140003a1f:	c7 44 24 30 c5 63 4f 	mov    DWORD PTR [rsp+0x30],0xc94f63c5
   140003a26:	c9 
   140003a27:	4c 8d 05 66 47 00 00 	lea    r8,[rip+0x4766]        # 0x140008194
   140003a2e:	c6 44 24 34 0b       	mov    BYTE PTR [rsp+0x34],0xb
   140003a33:	48 8d 54 24 30       	lea    rdx,[rsp+0x30]
   140003a38:	66 89 44 24 35       	mov    WORD PTR [rsp+0x35],ax
   140003a3d:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140003a42:	88 44 24 37          	mov    BYTE PTR [rsp+0x37],al
   140003a46:	44 8d 48 05          	lea    r9d,[rax+0x5]
   140003a4a:	c7 44 24 38 8c c8 10 	mov    DWORD PTR [rsp+0x38],0x2d10c88c
   140003a51:	2d 
   140003a52:	e8 49 f8 ff ff       	call   0x1400032a0
   140003a57:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
   140003a5c:	e8 1f 08 00 00       	call   0x140004280
   140003a61:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003a65:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140003a69:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003a6d:	49 3b f5             	cmp    rsi,r13
   140003a70:	0f 84 a5 00 00 00    	je     0x140003b1b
   140003a76:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140003a7d:	00 00 00 
   140003a80:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140003a84:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003a88:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140003a8f:	00 
   140003a90:	85 c9                	test   ecx,ecx
   140003a92:	74 79                	je     0x140003b0d
   140003a94:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140003a99:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003a9d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140003aa1:	4d 03 f3             	add    r14,r11
   140003aa4:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140003aa8:	4d 03 fb             	add    r15,r11
   140003aab:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140003aae:	4d 03 e3             	add    r12,r11
   140003ab1:	45 33 d2             	xor    r10d,r10d
   140003ab4:	85 ff                	test   edi,edi
   140003ab6:	74 55                	je     0x140003b0d
   140003ab8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140003abf:	00 
   140003ac0:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140003ac4:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140003acb:	4d 03 c3             	add    r8,r11
   140003ace:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003ad4:	48 ff c1             	inc    rcx
   140003ad7:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140003adc:	75 f6                	jne    0x140003ad4
   140003ade:	33 d2                	xor    edx,edx
   140003ae0:	48 85 c9             	test   rcx,rcx
   140003ae3:	74 20                	je     0x140003b05
   140003ae5:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140003aea:	48 ff c2             	inc    rdx
   140003aed:	41 33 c1             	xor    eax,r9d
   140003af0:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140003af7:	48 3b d1             	cmp    rdx,rcx
   140003afa:	72 e9                	jb     0x140003ae5
   140003afc:	41 81 f9 db e2 c4 b6 	cmp    r9d,0xb6c4e2db
   140003b03:	74 68                	je     0x140003b6d
   140003b05:	41 ff c2             	inc    r10d
   140003b08:	44 3b d7             	cmp    r10d,edi
   140003b0b:	72 b3                	jb     0x140003ac0
   140003b0d:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003b10:	49 3b f5             	cmp    rsi,r13
   140003b13:	0f 85 67 ff ff ff    	jne    0x140003a80
   140003b19:	33 db                	xor    ebx,ebx
   140003b1b:	4c 8b 44 24 20       	mov    r8,QWORD PTR [rsp+0x20]
   140003b20:	48 8d 55 10          	lea    rdx,[rbp+0x10]
   140003b24:	48 8b 4c 24 28       	mov    rcx,QWORD PTR [rsp+0x28]
   140003b29:	41 b9 40 00 00 00    	mov    r9d,0x40
   140003b2f:	ff d3                	call   rbx
   140003b31:	e9 90 02 00 00       	jmp    0x140003dc6
   140003b36:	41 0f b7 04 5f       	movzx  eax,WORD PTR [r15+rbx*2]
   140003b3b:	45 8b 0c 84          	mov    r9d,DWORD PTR [r12+rax*4]
   140003b3f:	4d 03 cb             	add    r9,r11
   140003b42:	e9 a9 fb ff ff       	jmp    0x1400036f0
   140003b47:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003b4c:	45 8b 04 84          	mov    r8d,DWORD PTR [r12+rax*4]
   140003b50:	4d 03 c3             	add    r8,r11
   140003b53:	33 db                	xor    ebx,ebx
   140003b55:	e9 e8 fc ff ff       	jmp    0x140003842
   140003b5a:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003b5f:	45 8b 04 84          	mov    r8d,DWORD PTR [r12+rax*4]
   140003b63:	4d 03 c3             	add    r8,r11
   140003b66:	33 db                	xor    ebx,ebx
   140003b68:	e9 a5 fe ff ff       	jmp    0x140003a12
   140003b6d:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003b72:	41 8b 1c 84          	mov    ebx,DWORD PTR [r12+rax*4]
   140003b76:	49 03 db             	add    rbx,r11
   140003b79:	eb a0                	jmp    0x140003b1b
   140003b7b:	41 b9 06 00 00 00    	mov    r9d,0x6
   140003b81:	c7 44 24 70 c9 7f 5b 	mov    DWORD PTR [rsp+0x70],0xc95b7fc9
   140003b88:	c9 
   140003b89:	4c 8d 05 24 46 00 00 	lea    r8,[rip+0x4624]        # 0x1400081b4
   140003b90:	c7 44 24 74 79 26 00 	mov    DWORD PTR [rsp+0x74],0x2679
   140003b97:	00 
   140003b98:	48 8d 54 24 70       	lea    rdx,[rsp+0x70]
   140003b9d:	c7 44 24 78 8c c8 10 	mov    DWORD PTR [rsp+0x78],0x2d10c88c
   140003ba4:	2d 
   140003ba5:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140003baa:	e8 f1 f6 ff ff       	call   0x1400032a0
   140003baf:	66 0f 6f 05 d9 26 00 	movdqa xmm0,XMMWORD PTR [rip+0x26d9]        # 0x140006290
   140003bb6:	00 
   140003bb7:	4c 8d 05 e2 45 00 00 	lea    r8,[rip+0x45e2]        # 0x1400081a0
   140003bbe:	41 b9 14 00 00 00    	mov    r9d,0x14
   140003bc4:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
   140003bc9:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
   140003bce:	c7 44 24 50 ce d1 57 	mov    DWORD PTR [rsp+0x50],0xcd57d1ce
   140003bd5:	cd 
   140003bd6:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140003bdb:	c7 44 24 54 8c c8 10 	mov    DWORD PTR [rsp+0x54],0x2d10c88c
   140003be2:	2d 
   140003be3:	f3 0f 7f 44 24 40    	movdqu XMMWORD PTR [rsp+0x40],xmm0
   140003be9:	e8 b2 f6 ff ff       	call   0x1400032a0
   140003bee:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   140003bf3:	e8 88 06 00 00       	call   0x140004280
   140003bf8:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003bfc:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140003c00:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003c04:	49 3b f5             	cmp    rsi,r13
   140003c07:	0f 84 9c 00 00 00    	je     0x140003ca9
   140003c0d:	0f 1f 00             	nop    DWORD PTR [rax]
   140003c10:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140003c14:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003c18:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140003c1f:	00 
   140003c20:	85 c9                	test   ecx,ecx
   140003c22:	74 79                	je     0x140003c9d
   140003c24:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140003c29:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003c2d:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140003c31:	4d 03 f3             	add    r14,r11
   140003c34:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140003c38:	4d 03 fb             	add    r15,r11
   140003c3b:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140003c3e:	4d 03 e3             	add    r12,r11
   140003c41:	45 33 d2             	xor    r10d,r10d
   140003c44:	85 ff                	test   edi,edi
   140003c46:	74 55                	je     0x140003c9d
   140003c48:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140003c4f:	00 
   140003c50:	47 8b 04 96          	mov    r8d,DWORD PTR [r14+r10*4]
   140003c54:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140003c5b:	4d 03 c3             	add    r8,r11
   140003c5e:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003c64:	48 ff c1             	inc    rcx
   140003c67:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140003c6c:	75 f6                	jne    0x140003c64
   140003c6e:	33 d2                	xor    edx,edx
   140003c70:	48 85 c9             	test   rcx,rcx
   140003c73:	74 20                	je     0x140003c95
   140003c75:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140003c7a:	48 ff c2             	inc    rdx
   140003c7d:	41 33 c1             	xor    eax,r9d
   140003c80:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140003c87:	48 3b d1             	cmp    rdx,rcx
   140003c8a:	72 e9                	jb     0x140003c75
   140003c8c:	41 81 f9 db e2 c4 b6 	cmp    r9d,0xb6c4e2db
   140003c93:	74 32                	je     0x140003cc7
   140003c95:	41 ff c2             	inc    r10d
   140003c98:	44 3b d7             	cmp    r10d,edi
   140003c9b:	72 b3                	jb     0x140003c50
   140003c9d:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003ca0:	49 3b f5             	cmp    rsi,r13
   140003ca3:	0f 85 67 ff ff ff    	jne    0x140003c10
   140003ca9:	33 db                	xor    ebx,ebx
   140003cab:	4c 8b 44 24 20       	mov    r8,QWORD PTR [rsp+0x20]
   140003cb0:	41 b9 10 00 00 00    	mov    r9d,0x10
   140003cb6:	48 8b 54 24 30       	mov    rdx,QWORD PTR [rsp+0x30]
   140003cbb:	48 8b 4c 24 28       	mov    rcx,QWORD PTR [rsp+0x28]
   140003cc0:	ff d3                	call   rbx
   140003cc2:	e9 ff 00 00 00       	jmp    0x140003dc6
   140003cc7:	43 0f b7 04 57       	movzx  eax,WORD PTR [r15+r10*2]
   140003ccc:	41 8b 1c 84          	mov    ebx,DWORD PTR [r12+rax*4]
   140003cd0:	49 03 db             	add    rbx,r11
   140003cd3:	eb d6                	jmp    0x140003cab
   140003cd5:	e8 a6 05 00 00       	call   0x140004280
   140003cda:	33 d2                	xor    edx,edx
   140003cdc:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003ce0:	48 8b 71 20          	mov    rsi,QWORD PTR [rcx+0x20]
   140003ce4:	4c 8b 69 28          	mov    r13,QWORD PTR [rcx+0x28]
   140003ce8:	49 3b f5             	cmp    rsi,r13
   140003ceb:	0f 84 ca 00 00 00    	je     0x140003dbb
   140003cf1:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003cf5:	66 66 66 0f 1f 84 00 	data16 data16 nop WORD PTR [rax+rax*1+0x0]
   140003cfc:	00 00 00 00 
   140003d00:	4c 8b 5e 20          	mov    r11,QWORD PTR [rsi+0x20]
   140003d04:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003d08:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140003d0f:	00 
   140003d10:	85 c9                	test   ecx,ecx
   140003d12:	0f 84 85 00 00 00    	je     0x140003d9d
   140003d18:	45 8b 74 0b 20       	mov    r14d,DWORD PTR [r11+rcx*1+0x20]
   140003d1d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003d21:	44 8b 78 24          	mov    r15d,DWORD PTR [rax+0x24]
   140003d25:	4d 03 f3             	add    r14,r11
   140003d28:	44 8b 60 1c          	mov    r12d,DWORD PTR [rax+0x1c]
   140003d2c:	4d 03 fb             	add    r15,r11
   140003d2f:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140003d32:	4d 03 e3             	add    r12,r11
   140003d35:	44 8b d2             	mov    r10d,edx
   140003d38:	85 ff                	test   edi,edi
   140003d3a:	74 61                	je     0x140003d9d
   140003d3c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003d40:	41 8b da             	mov    ebx,r10d
   140003d43:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   140003d4a:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003d50:	45 8b 04 9e          	mov    r8d,DWORD PTR [r14+rbx*4]
   140003d54:	4d 03 c3             	add    r8,r11
   140003d57:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   140003d5e:	00 00 
   140003d60:	48 ff c0             	inc    rax
   140003d63:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   140003d68:	75 f6                	jne    0x140003d60
   140003d6a:	48 85 c0             	test   rax,rax
   140003d6d:	74 21                	je     0x140003d90
   140003d6f:	90                   	nop
   140003d70:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   140003d75:	48 ff c2             	inc    rdx
   140003d78:	41 33 c9             	xor    ecx,r9d
   140003d7b:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   140003d82:	48 3b d0             	cmp    rdx,rax
   140003d85:	72 e9                	jb     0x140003d70
   140003d87:	41 81 f9 68 bf 27 1a 	cmp    r9d,0x1a27bf68
   140003d8e:	74 1f                	je     0x140003daf
   140003d90:	41 ff c2             	inc    r10d
   140003d93:	ba 00 00 00 00       	mov    edx,0x0
   140003d98:	44 3b d7             	cmp    r10d,edi
   140003d9b:	72 a3                	jb     0x140003d40
   140003d9d:	48 8b 36             	mov    rsi,QWORD PTR [rsi]
   140003da0:	49 3b f5             	cmp    rsi,r13
   140003da3:	0f 85 57 ff ff ff    	jne    0x140003d00
   140003da9:	33 c9                	xor    ecx,ecx
   140003dab:	ff d2                	call   rdx
   140003dad:	eb 17                	jmp    0x140003dc6
   140003daf:	41 0f b7 04 5f       	movzx  eax,WORD PTR [r15+rbx*2]
   140003db4:	41 8b 14 84          	mov    edx,DWORD PTR [r12+rax*4]
   140003db8:	49 03 d3             	add    rdx,r11
   140003dbb:	33 c9                	xor    ecx,ecx
   140003dbd:	ff d2                	call   rdx
   140003dbf:	eb 05                	jmp    0x140003dc6
   140003dc1:	e8 6a e5 ff ff       	call   0x140002330
   140003dc6:	33 c0                	xor    eax,eax
   140003dc8:	48 8b 8d 10 02 00 00 	mov    rcx,QWORD PTR [rbp+0x210]
   140003dcf:	48 33 cc             	xor    rcx,rsp
   140003dd2:	e8 49 05 00 00       	call   0x140004320
   140003dd7:	48 81 c4 28 03 00 00 	add    rsp,0x328
   140003dde:	41 5f                	pop    r15
   140003de0:	41 5e                	pop    r14
   140003de2:	41 5d                	pop    r13
   140003de4:	41 5c                	pop    r12
   140003de6:	5f                   	pop    rdi
   140003de7:	5e                   	pop    rsi
   140003de8:	5b                   	pop    rbx
   140003de9:	5d                   	pop    rbp
   140003dea:	c3                   	ret
   140003deb:	cc                   	int3
   140003dec:	cc                   	int3
   140003ded:	cc                   	int3
   140003dee:	cc                   	int3
   140003def:	cc                   	int3
   140003df0:	8b c1                	mov    eax,ecx
   140003df2:	c1 e0 0d             	shl    eax,0xd
   140003df5:	33 c8                	xor    ecx,eax
   140003df7:	8b c1                	mov    eax,ecx
   140003df9:	c1 e8 11             	shr    eax,0x11
   140003dfc:	33 c8                	xor    ecx,eax
   140003dfe:	8b c1                	mov    eax,ecx
   140003e00:	c1 e0 05             	shl    eax,0x5
   140003e03:	33 c8                	xor    ecx,eax
   140003e05:	b8 03 00 00 00       	mov    eax,0x3
   140003e0a:	f7 e1                	mul    ecx
   140003e0c:	8b c1                	mov    eax,ecx
   140003e0e:	2b c2                	sub    eax,edx
   140003e10:	d1 e8                	shr    eax,1
   140003e12:	03 c2                	add    eax,edx
   140003e14:	c1 e8 1e             	shr    eax,0x1e
   140003e17:	69 c0 ff ff ff 7f    	imul   eax,eax,0x7fffffff
   140003e1d:	2b c8                	sub    ecx,eax
   140003e1f:	8b c1                	mov    eax,ecx
   140003e21:	c3                   	ret
   140003e22:	cc                   	int3
   140003e23:	cc                   	int3
   140003e24:	cc                   	int3
   140003e25:	cc                   	int3
   140003e26:	cc                   	int3
   140003e27:	cc                   	int3
   140003e28:	cc                   	int3
   140003e29:	cc                   	int3
   140003e2a:	cc                   	int3
   140003e2b:	cc                   	int3
   140003e2c:	cc                   	int3
   140003e2d:	cc                   	int3
   140003e2e:	cc                   	int3
   140003e2f:	cc                   	int3
   140003e30:	4c 8b dc             	mov    r11,rsp
   140003e33:	49 89 5b 10          	mov    QWORD PTR [r11+0x10],rbx
   140003e37:	49 89 6b 18          	mov    QWORD PTR [r11+0x18],rbp
   140003e3b:	56                   	push   rsi
   140003e3c:	57                   	push   rdi
   140003e3d:	41 54                	push   r12
   140003e3f:	41 56                	push   r14
   140003e41:	41 57                	push   r15
   140003e43:	48 83 ec 70          	sub    rsp,0x70
   140003e47:	48 8b 05 b2 41 00 00 	mov    rax,QWORD PTR [rip+0x41b2]        # 0x140008000
   140003e4e:	48 33 c4             	xor    rax,rsp
   140003e51:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
   140003e56:	41 b9 0b 00 00 00    	mov    r9d,0xb
   140003e5c:	4d 89 6b 08          	mov    QWORD PTR [r11+0x8],r13
   140003e60:	4c 8d 05 59 43 00 00 	lea    r8,[rip+0x4359]        # 0x1400081c0
   140003e67:	c7 44 24 50 f9 7e 4c 	mov    DWORD PTR [rsp+0x50],0xd44c7ef9
   140003e6e:	d4 
   140003e6f:	49 8d 53 b8          	lea    rdx,[r11-0x48]
   140003e73:	c7 44 24 54 38 14 13 	mov    DWORD PTR [rsp+0x54],0xba131438
   140003e7a:	ba 
   140003e7b:	b9 8c c8 10 2d       	mov    ecx,0x2d10c88c
   140003e80:	c7 44 24 58 97 33 19 	mov    DWORD PTR [rsp+0x58],0x193397
   140003e87:	00 
   140003e88:	c7 44 24 5c 8c c8 10 	mov    DWORD PTR [rsp+0x5c],0x2d10c88c
   140003e8f:	2d 
   140003e90:	e8 0b f4 ff ff       	call   0x1400032a0
   140003e95:	4c 8b e8             	mov    r13,rax
   140003e98:	e8 e3 03 00 00       	call   0x140004280
   140003e9d:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003ea1:	48 8b 79 20          	mov    rdi,QWORD PTR [rcx+0x20]
   140003ea5:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140003ea9:	49 3b fc             	cmp    rdi,r12
   140003eac:	0f 84 b6 00 00 00    	je     0x140003f68
   140003eb2:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003eb6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140003ebd:	00 00 00 
   140003ec0:	4c 8b 5f 20          	mov    r11,QWORD PTR [rdi+0x20]
   140003ec4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003ec8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140003ecf:	00 
   140003ed0:	85 c9                	test   ecx,ecx
   140003ed2:	0f 84 84 00 00 00    	je     0x140003f5c
   140003ed8:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   140003edd:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003ee1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   140003ee5:	49 03 eb             	add    rbp,r11
   140003ee8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   140003eec:	4d 03 f3             	add    r14,r11
   140003eef:	8b 58 18             	mov    ebx,DWORD PTR [rax+0x18]
   140003ef2:	4d 03 fb             	add    r15,r11
   140003ef5:	45 33 d2             	xor    r10d,r10d
   140003ef8:	85 db                	test   ebx,ebx
   140003efa:	74 60                	je     0x140003f5c
   140003efc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003f00:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   140003f05:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140003f0c:	4d 03 c3             	add    r8,r11
   140003f0f:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003f15:	48 ff c1             	inc    rcx
   140003f18:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140003f1d:	75 f6                	jne    0x140003f15
   140003f1f:	33 d2                	xor    edx,edx
   140003f21:	48 85 c9             	test   rcx,rcx
   140003f24:	74 2e                	je     0x140003f54
   140003f26:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140003f2d:	00 00 00 
   140003f30:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140003f35:	48 ff c2             	inc    rdx
   140003f38:	41 33 c1             	xor    eax,r9d
   140003f3b:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140003f42:	48 3b d1             	cmp    rdx,rcx
   140003f45:	72 e9                	jb     0x140003f30
   140003f47:	41 81 f9 42 d3 6e 14 	cmp    r9d,0x146ed342
   140003f4e:	0f 84 ae 02 00 00    	je     0x140004202
   140003f54:	41 ff c2             	inc    r10d
   140003f57:	44 3b d3             	cmp    r10d,ebx
   140003f5a:	72 a4                	jb     0x140003f00
   140003f5c:	48 8b 3f             	mov    rdi,QWORD PTR [rdi]
   140003f5f:	49 3b fc             	cmp    rdi,r12
   140003f62:	0f 85 58 ff ff ff    	jne    0x140003ec0
   140003f68:	33 d2                	xor    edx,edx
   140003f6a:	49 8b cd             	mov    rcx,r13
   140003f6d:	ff d2                	call   rdx
   140003f6f:	e8 bc e8 ff ff       	call   0x140002830
   140003f74:	4c 8b ac 24 a0 00 00 	mov    r13,QWORD PTR [rsp+0xa0]
   140003f7b:	00 
   140003f7c:	85 c0                	test   eax,eax
   140003f7e:	0f 84 c9 02 00 00    	je     0x14000424d
   140003f84:	e8 f7 02 00 00       	call   0x140004280
   140003f89:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   140003f8d:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140003f91:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140003f95:	49 3b dc             	cmp    rbx,r12
   140003f98:	0f 84 aa 00 00 00    	je     0x140004048
   140003f9e:	66 90                	xchg   ax,ax
   140003fa0:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140003fa4:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140003fa8:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   140003faf:	00 
   140003fb0:	85 c9                	test   ecx,ecx
   140003fb2:	0f 84 84 00 00 00    	je     0x14000403c
   140003fb8:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   140003fbd:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140003fc1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   140003fc5:	49 03 eb             	add    rbp,r11
   140003fc8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   140003fcc:	4d 03 f3             	add    r14,r11
   140003fcf:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140003fd2:	4d 03 fb             	add    r15,r11
   140003fd5:	45 33 d2             	xor    r10d,r10d
   140003fd8:	85 ff                	test   edi,edi
   140003fda:	74 60                	je     0x14000403c
   140003fdc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140003fe0:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   140003fe5:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   140003fec:	4d 03 c3             	add    r8,r11
   140003fef:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   140003ff5:	48 ff c1             	inc    rcx
   140003ff8:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   140003ffd:	75 f6                	jne    0x140003ff5
   140003fff:	33 d2                	xor    edx,edx
   140004001:	48 85 c9             	test   rcx,rcx
   140004004:	74 2e                	je     0x140004034
   140004006:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   14000400d:	00 00 00 
   140004010:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   140004015:	48 ff c2             	inc    rdx
   140004018:	41 33 c1             	xor    eax,r9d
   14000401b:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140004022:	48 3b d1             	cmp    rdx,rcx
   140004025:	72 e9                	jb     0x140004010
   140004027:	41 81 f9 1e a2 3b 9d 	cmp    r9d,0x9d3ba21e
   14000402e:	0f 84 df 01 00 00    	je     0x140004213
   140004034:	41 ff c2             	inc    r10d
   140004037:	44 3b d7             	cmp    r10d,edi
   14000403a:	72 a4                	jb     0x140003fe0
   14000403c:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   14000403f:	49 3b dc             	cmp    rbx,r12
   140004042:	0f 85 58 ff ff ff    	jne    0x140003fa0
   140004048:	45 33 d2             	xor    r10d,r10d
   14000404b:	45 33 c9             	xor    r9d,r9d
   14000404e:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   140004053:	45 33 c0             	xor    r8d,r8d
   140004056:	33 d2                	xor    edx,edx
   140004058:	41 ff d2             	call   r10
   14000405b:	85 c0                	test   eax,eax
   14000405d:	0f 84 ea 01 00 00    	je     0x14000424d
   140004063:	e8 18 02 00 00       	call   0x140004280
   140004068:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   14000406c:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   140004070:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140004074:	49 3b dc             	cmp    rbx,r12
   140004077:	0f 84 ab 00 00 00    	je     0x140004128
   14000407d:	0f 1f 00             	nop    DWORD PTR [rax]
   140004080:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140004084:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140004088:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000408f:	00 
   140004090:	85 c9                	test   ecx,ecx
   140004092:	0f 84 84 00 00 00    	je     0x14000411c
   140004098:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   14000409d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   1400040a1:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   1400040a5:	49 03 eb             	add    rbp,r11
   1400040a8:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   1400040ac:	4d 03 f3             	add    r14,r11
   1400040af:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   1400040b2:	4d 03 fb             	add    r15,r11
   1400040b5:	45 33 d2             	xor    r10d,r10d
   1400040b8:	85 ff                	test   edi,edi
   1400040ba:	74 60                	je     0x14000411c
   1400040bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1400040c0:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   1400040c5:	48 c7 c1 ff ff ff ff 	mov    rcx,0xffffffffffffffff
   1400040cc:	4d 03 c3             	add    r8,r11
   1400040cf:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400040d5:	48 ff c1             	inc    rcx
   1400040d8:	41 80 3c 08 00       	cmp    BYTE PTR [r8+rcx*1],0x0
   1400040dd:	75 f6                	jne    0x1400040d5
   1400040df:	33 d2                	xor    edx,edx
   1400040e1:	48 85 c9             	test   rcx,rcx
   1400040e4:	74 2e                	je     0x140004114
   1400040e6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   1400040ed:	00 00 00 
   1400040f0:	42 0f be 04 02       	movsx  eax,BYTE PTR [rdx+r8*1]
   1400040f5:	48 ff c2             	inc    rdx
   1400040f8:	41 33 c1             	xor    eax,r9d
   1400040fb:	44 69 c8 93 01 00 01 	imul   r9d,eax,0x1000193
   140004102:	48 3b d1             	cmp    rdx,rcx
   140004105:	72 e9                	jb     0x1400040f0
   140004107:	41 81 f9 a5 95 8c 49 	cmp    r9d,0x498c95a5
   14000410e:	0f 84 10 01 00 00    	je     0x140004224
   140004114:	41 ff c2             	inc    r10d
   140004117:	44 3b d7             	cmp    r10d,edi
   14000411a:	72 a4                	jb     0x1400040c0
   14000411c:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   14000411f:	49 3b dc             	cmp    rbx,r12
   140004122:	0f 85 58 ff ff ff    	jne    0x140004080
   140004128:	33 d2                	xor    edx,edx
   14000412a:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   14000412f:	ff d2                	call   rdx
   140004131:	e8 4a 01 00 00       	call   0x140004280
   140004136:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
   14000413a:	48 8b 59 20          	mov    rbx,QWORD PTR [rcx+0x20]
   14000413e:	4c 8b 61 28          	mov    r12,QWORD PTR [rcx+0x28]
   140004142:	49 3b dc             	cmp    rbx,r12
   140004145:	0f 84 a9 00 00 00    	je     0x1400041f4
   14000414b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   140004150:	4c 8b 5b 20          	mov    r11,QWORD PTR [rbx+0x20]
   140004154:	49 63 43 3c          	movsxd rax,DWORD PTR [r11+0x3c]
   140004158:	42 8b 8c 18 88 00 00 	mov    ecx,DWORD PTR [rax+r11*1+0x88]
   14000415f:	00 
   140004160:	85 c9                	test   ecx,ecx
   140004162:	0f 84 80 00 00 00    	je     0x1400041e8
   140004168:	41 8b 6c 0b 20       	mov    ebp,DWORD PTR [r11+rcx*1+0x20]
   14000416d:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
   140004171:	44 8b 70 24          	mov    r14d,DWORD PTR [rax+0x24]
   140004175:	49 03 eb             	add    rbp,r11
   140004178:	44 8b 78 1c          	mov    r15d,DWORD PTR [rax+0x1c]
   14000417c:	4d 03 f3             	add    r14,r11
   14000417f:	8b 78 18             	mov    edi,DWORD PTR [rax+0x18]
   140004182:	4d 03 fb             	add    r15,r11
   140004185:	45 33 d2             	xor    r10d,r10d
   140004188:	85 ff                	test   edi,edi
   14000418a:	74 5c                	je     0x1400041e8
   14000418c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   140004190:	46 8b 44 95 00       	mov    r8d,DWORD PTR [rbp+r10*4+0x0]
   140004195:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   14000419c:	4d 03 c3             	add    r8,r11
   14000419f:	41 b9 d0 6a 36 55    	mov    r9d,0x55366ad0
   1400041a5:	48 ff c0             	inc    rax
   1400041a8:	41 80 3c 00 00       	cmp    BYTE PTR [r8+rax*1],0x0
   1400041ad:	75 f6                	jne    0x1400041a5
   1400041af:	33 d2                	xor    edx,edx
   1400041b1:	48 85 c0             	test   rax,rax
   1400041b4:	74 2a                	je     0x1400041e0
   1400041b6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   1400041bd:	00 00 00 
   1400041c0:	42 0f be 0c 02       	movsx  ecx,BYTE PTR [rdx+r8*1]
   1400041c5:	48 ff c2             	inc    rdx
   1400041c8:	41 33 c9             	xor    ecx,r9d
   1400041cb:	44 69 c9 93 01 00 01 	imul   r9d,ecx,0x1000193
   1400041d2:	48 3b d0             	cmp    rdx,rax
   1400041d5:	72 e9                	jb     0x1400041c0
   1400041d7:	41 81 f9 68 d3 90 aa 	cmp    r9d,0xaa90d368
   1400041de:	74 55                	je     0x140004235
   1400041e0:	41 ff c2             	inc    r10d
   1400041e3:	44 3b d7             	cmp    r10d,edi
   1400041e6:	72 a8                	jb     0x140004190
   1400041e8:	48 8b 1b             	mov    rbx,QWORD PTR [rbx]
   1400041eb:	49 3b dc             	cmp    rbx,r12
   1400041ee:	0f 85 5c ff ff ff    	jne    0x140004150
   1400041f4:	33 d2                	xor    edx,edx
   1400041f6:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   1400041fb:	ff d2                	call   rdx
   1400041fd:	e9 82 fd ff ff       	jmp    0x140003f84
   140004202:	43 0f b7 04 56       	movzx  eax,WORD PTR [r14+r10*2]
   140004207:	41 8b 14 87          	mov    edx,DWORD PTR [r15+rax*4]
   14000420b:	49 03 d3             	add    rdx,r11
   14000420e:	e9 57 fd ff ff       	jmp    0x140003f6a
   140004213:	43 0f b7 04 56       	movzx  eax,WORD PTR [r14+r10*2]
   140004218:	45 8b 14 87          	mov    r10d,DWORD PTR [r15+rax*4]
   14000421c:	4d 03 d3             	add    r10,r11
   14000421f:	e9 27 fe ff ff       	jmp    0x14000404b
   140004224:	43 0f b7 04 56       	movzx  eax,WORD PTR [r14+r10*2]
   140004229:	41 8b 14 87          	mov    edx,DWORD PTR [r15+rax*4]
   14000422d:	49 03 d3             	add    rdx,r11
   140004230:	e9 f5 fe ff ff       	jmp    0x14000412a
   140004235:	43 0f b7 04 56       	movzx  eax,WORD PTR [r14+r10*2]
   14000423a:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   14000423f:	41 8b 14 87          	mov    edx,DWORD PTR [r15+rax*4]
   140004243:	49 03 d3             	add    rdx,r11
   140004246:	ff d2                	call   rdx
   140004248:	e9 37 fd ff ff       	jmp    0x140003f84
   14000424d:	33 c0                	xor    eax,eax
   14000424f:	48 8b 4c 24 60       	mov    rcx,QWORD PTR [rsp+0x60]
   140004254:	48 33 cc             	xor    rcx,rsp
   140004257:	e8 c4 00 00 00       	call   0x140004320
   14000425c:	4c 8d 5c 24 70       	lea    r11,[rsp+0x70]
   140004261:	49 8b 5b 38          	mov    rbx,QWORD PTR [r11+0x38]
   140004265:	49 8b 6b 40          	mov    rbp,QWORD PTR [r11+0x40]
   140004269:	49 8b e3             	mov    rsp,r11
   14000426c:	41 5f                	pop    r15
   14000426e:	41 5e                	pop    r14
   140004270:	41 5c                	pop    r12
   140004272:	5f                   	pop    rdi
   140004273:	5e                   	pop    rsi
   140004274:	c3                   	ret
   140004275:	cc                   	int3
   140004276:	cc                   	int3
   140004277:	cc                   	int3
   140004278:	cc                   	int3
   140004279:	cc                   	int3
   14000427a:	cc                   	int3
   14000427b:	cc                   	int3
   14000427c:	cc                   	int3
   14000427d:	cc                   	int3
   14000427e:	cc                   	int3
   14000427f:	cc                   	int3
   140004280:	65 48 8b 04 25 60 00 	mov    rax,QWORD PTR gs:0x60
   140004287:	00 00 
   140004289:	c3                   	ret
   14000428a:	cc                   	int3
   14000428b:	cc                   	int3
   14000428c:	48 83 ec 28          	sub    rsp,0x28
   140004290:	4d 8b 41 38          	mov    r8,QWORD PTR [r9+0x38]
   140004294:	48 8b ca             	mov    rcx,rdx
   140004297:	49 8b d1             	mov    rdx,r9
   14000429a:	e8 0d 00 00 00       	call   0x1400042ac
   14000429f:	b8 01 00 00 00       	mov    eax,0x1
   1400042a4:	48 83 c4 28          	add    rsp,0x28
   1400042a8:	c3                   	ret
   1400042a9:	cc                   	int3
   1400042aa:	cc                   	int3
   1400042ab:	cc                   	int3
   1400042ac:	40 53                	rex push rbx
   1400042ae:	45 8b 18             	mov    r11d,DWORD PTR [r8]
   1400042b1:	48 8b da             	mov    rbx,rdx
   1400042b4:	41 83 e3 f8          	and    r11d,0xfffffff8
   1400042b8:	4c 8b c9             	mov    r9,rcx
   1400042bb:	41 f6 00 04          	test   BYTE PTR [r8],0x4
   1400042bf:	4c 8b d1             	mov    r10,rcx
   1400042c2:	74 13                	je     0x1400042d7
   1400042c4:	41 8b 40 08          	mov    eax,DWORD PTR [r8+0x8]
   1400042c8:	4d 63 50 04          	movsxd r10,DWORD PTR [r8+0x4]
   1400042cc:	f7 d8                	neg    eax
   1400042ce:	4c 03 d1             	add    r10,rcx
   1400042d1:	48 63 c8             	movsxd rcx,eax
   1400042d4:	4c 23 d1             	and    r10,rcx
   1400042d7:	49 63 c3             	movsxd rax,r11d
   1400042da:	4a 8b 14 10          	mov    rdx,QWORD PTR [rax+r10*1]
   1400042de:	48 8b 43 10          	mov    rax,QWORD PTR [rbx+0x10]
   1400042e2:	8b 48 08             	mov    ecx,DWORD PTR [rax+0x8]
   1400042e5:	48 8b 43 08          	mov    rax,QWORD PTR [rbx+0x8]
   1400042e9:	f6 44 01 03 0f       	test   BYTE PTR [rcx+rax*1+0x3],0xf
   1400042ee:	74 0b                	je     0x1400042fb
   1400042f0:	0f b6 44 01 03       	movzx  eax,BYTE PTR [rcx+rax*1+0x3]
   1400042f5:	83 e0 f0             	and    eax,0xfffffff0
   1400042f8:	4c 03 c8             	add    r9,rax
   1400042fb:	4c 33 ca             	xor    r9,rdx
   1400042fe:	49 8b c9             	mov    rcx,r9
   140004301:	5b                   	pop    rbx
   140004302:	e9 19 00 00 00       	jmp    0x140004320
   140004307:	cc                   	int3
   140004308:	cc                   	int3
   140004309:	cc                   	int3
   14000430a:	cc                   	int3
   14000430b:	cc                   	int3
   14000430c:	cc                   	int3
   14000430d:	cc                   	int3
   14000430e:	cc                   	int3
   14000430f:	cc                   	int3
   140004310:	cc                   	int3
   140004311:	cc                   	int3
   140004312:	cc                   	int3
   140004313:	cc                   	int3
   140004314:	cc                   	int3
   140004315:	cc                   	int3
   140004316:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   14000431d:	00 00 00 
   140004320:	48 3b 0d d9 3c 00 00 	cmp    rcx,QWORD PTR [rip+0x3cd9]        # 0x140008000
   140004327:	75 10                	jne    0x140004339
   140004329:	48 c1 c1 10          	rol    rcx,0x10
   14000432d:	66 f7 c1 ff ff       	test   cx,0xffff
   140004332:	75 01                	jne    0x140004335
   140004334:	c3                   	ret
   140004335:	48 c1 c9 10          	ror    rcx,0x10
   140004339:	e9 a2 02 00 00       	jmp    0x1400045e0
   14000433e:	cc                   	int3
   14000433f:	cc                   	int3
   140004340:	40 53                	rex push rbx
   140004342:	48 83 ec 20          	sub    rsp,0x20
   140004346:	b9 02 00 00 00       	mov    ecx,0x2
   14000434b:	e8 de 0b 00 00       	call   0x140004f2e
   140004350:	e8 cb 06 00 00       	call   0x140004a20
   140004355:	8b c8                	mov    ecx,eax
   140004357:	e8 08 0c 00 00       	call   0x140004f64
   14000435c:	e8 b3 06 00 00       	call   0x140004a14
   140004361:	8b d8                	mov    ebx,eax
   140004363:	e8 20 0c 00 00       	call   0x140004f88
   140004368:	b9 01 00 00 00       	mov    ecx,0x1
   14000436d:	89 18                	mov    DWORD PTR [rax],ebx
   14000436f:	e8 2c 04 00 00       	call   0x1400047a0
   140004374:	84 c0                	test   al,al
   140004376:	74 73                	je     0x1400043eb
   140004378:	e8 5f 09 00 00       	call   0x140004cdc
   14000437d:	48 8d 0d 94 09 00 00 	lea    rcx,[rip+0x994]        # 0x140004d18
   140004384:	e8 c7 05 00 00       	call   0x140004950
   140004389:	e8 8a 06 00 00       	call   0x140004a18
   14000438e:	8b c8                	mov    ecx,eax
   140004390:	e8 a5 0b 00 00       	call   0x140004f3a
   140004395:	85 c0                	test   eax,eax
   140004397:	75 52                	jne    0x1400043eb
   140004399:	e8 8a 06 00 00       	call   0x140004a28
   14000439e:	e8 c9 06 00 00       	call   0x140004a6c
   1400043a3:	85 c0                	test   eax,eax
   1400043a5:	74 0c                	je     0x1400043b3
   1400043a7:	48 8d 0d 66 06 00 00 	lea    rcx,[rip+0x666]        # 0x140004a14
   1400043ae:	e8 81 0b 00 00       	call   0x140004f34
   1400043b3:	e8 84 06 00 00       	call   0x140004a3c
   1400043b8:	e8 7f 06 00 00       	call   0x140004a3c
   1400043bd:	e8 52 06 00 00       	call   0x140004a14
   1400043c2:	8b c8                	mov    ecx,eax
   1400043c4:	e8 b3 0b 00 00       	call   0x140004f7c
   1400043c9:	e8 6a 06 00 00       	call   0x140004a38
   1400043ce:	84 c0                	test   al,al
   1400043d0:	74 05                	je     0x1400043d7
   1400043d2:	e8 69 0b 00 00       	call   0x140004f40
   1400043d7:	e8 38 06 00 00       	call   0x140004a14
   1400043dc:	e8 33 08 00 00       	call   0x140004c14
   1400043e1:	85 c0                	test   eax,eax
   1400043e3:	75 06                	jne    0x1400043eb
   1400043e5:	48 83 c4 20          	add    rsp,0x20
   1400043e9:	5b                   	pop    rbx
   1400043ea:	c3                   	ret
   1400043eb:	b9 07 00 00 00       	mov    ecx,0x7
   1400043f0:	e8 9b 06 00 00       	call   0x140004a90
   1400043f5:	cc                   	int3
   1400043f6:	cc                   	int3
   1400043f7:	cc                   	int3
   1400043f8:	48 83 ec 28          	sub    rsp,0x28
   1400043fc:	e8 4f 06 00 00       	call   0x140004a50
   140004401:	33 c0                	xor    eax,eax
   140004403:	48 83 c4 28          	add    rsp,0x28
   140004407:	c3                   	ret
   140004408:	48 83 ec 28          	sub    rsp,0x28
   14000440c:	e8 5f 08 00 00       	call   0x140004c70
   140004411:	e8 fe 05 00 00       	call   0x140004a14
   140004416:	8b c8                	mov    ecx,eax
   140004418:	48 83 c4 28          	add    rsp,0x28
   14000441c:	e9 61 0b 00 00       	jmp    0x140004f82
   140004421:	cc                   	int3
   140004422:	cc                   	int3
   140004423:	cc                   	int3
   140004424:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140004429:	57                   	push   rdi
   14000442a:	48 83 ec 30          	sub    rsp,0x30
   14000442e:	b9 01 00 00 00       	mov    ecx,0x1
   140004433:	e8 2c 03 00 00       	call   0x140004764
   140004438:	84 c0                	test   al,al
   14000443a:	0f 84 30 01 00 00    	je     0x140004570
   140004440:	40 32 ff             	xor    dil,dil
   140004443:	40 88 7c 24 20       	mov    BYTE PTR [rsp+0x20],dil
   140004448:	e8 db 02 00 00       	call   0x140004728
   14000444d:	8a d8                	mov    bl,al
   14000444f:	8b 0d eb 42 00 00    	mov    ecx,DWORD PTR [rip+0x42eb]        # 0x140008740
   140004455:	83 f9 01             	cmp    ecx,0x1
   140004458:	0f 84 1d 01 00 00    	je     0x14000457b
   14000445e:	85 c9                	test   ecx,ecx
   140004460:	75 4a                	jne    0x1400044ac
   140004462:	c7 05 d4 42 00 00 01 	mov    DWORD PTR [rip+0x42d4],0x1        # 0x140008740
   140004469:	00 00 00 
   14000446c:	48 8d 15 95 1d 00 00 	lea    rdx,[rip+0x1d95]        # 0x140006208
   140004473:	48 8d 0d 76 1d 00 00 	lea    rcx,[rip+0x1d76]        # 0x1400061f0
   14000447a:	e8 d3 0a 00 00       	call   0x140004f52
   14000447f:	85 c0                	test   eax,eax
   140004481:	74 0a                	je     0x14000448d
   140004483:	b8 ff 00 00 00       	mov    eax,0xff
   140004488:	e9 d8 00 00 00       	jmp    0x140004565
   14000448d:	48 8d 15 54 1d 00 00 	lea    rdx,[rip+0x1d54]        # 0x1400061e8
   140004494:	48 8d 0d 35 1d 00 00 	lea    rcx,[rip+0x1d35]        # 0x1400061d0
   14000449b:	e8 ac 0a 00 00       	call   0x140004f4c
   1400044a0:	c7 05 96 42 00 00 02 	mov    DWORD PTR [rip+0x4296],0x2        # 0x140008740
   1400044a7:	00 00 00 
   1400044aa:	eb 08                	jmp    0x1400044b4
   1400044ac:	40 b7 01             	mov    dil,0x1
   1400044af:	40 88 7c 24 20       	mov    BYTE PTR [rsp+0x20],dil
   1400044b4:	8a cb                	mov    cl,bl
   1400044b6:	e8 09 04 00 00       	call   0x1400048c4
   1400044bb:	e8 b8 05 00 00       	call   0x140004a78
   1400044c0:	48 8b d8             	mov    rbx,rax
   1400044c3:	48 83 38 00          	cmp    QWORD PTR [rax],0x0
   1400044c7:	74 1e                	je     0x1400044e7
   1400044c9:	48 8b c8             	mov    rcx,rax
   1400044cc:	e8 5b 03 00 00       	call   0x14000482c
   1400044d1:	84 c0                	test   al,al
   1400044d3:	74 12                	je     0x1400044e7
   1400044d5:	45 33 c0             	xor    r8d,r8d
   1400044d8:	41 8d 50 02          	lea    edx,[r8+0x2]
   1400044dc:	33 c9                	xor    ecx,ecx
   1400044de:	48 8b 03             	mov    rax,QWORD PTR [rbx]
   1400044e1:	ff 15 c1 1c 00 00    	call   QWORD PTR [rip+0x1cc1]        # 0x1400061a8
   1400044e7:	e8 94 05 00 00       	call   0x140004a80
   1400044ec:	48 8b d8             	mov    rbx,rax
   1400044ef:	48 83 38 00          	cmp    QWORD PTR [rax],0x0
   1400044f3:	74 14                	je     0x140004509
   1400044f5:	48 8b c8             	mov    rcx,rax
   1400044f8:	e8 2f 03 00 00       	call   0x14000482c
   1400044fd:	84 c0                	test   al,al
   1400044ff:	74 08                	je     0x140004509
   140004501:	48 8b 0b             	mov    rcx,QWORD PTR [rbx]
   140004504:	e8 6d 0a 00 00       	call   0x140004f76
   140004509:	e8 ca 06 00 00       	call   0x140004bd8
   14000450e:	0f b7 d8             	movzx  ebx,ax
   140004511:	e8 30 0a 00 00       	call   0x140004f46
   140004516:	44 8b cb             	mov    r9d,ebx
   140004519:	4c 8b c0             	mov    r8,rax
   14000451c:	33 d2                	xor    edx,edx
   14000451e:	48 8d 0d db ba ff ff 	lea    rcx,[rip+0xffffffffffffbadb]        # 0x140000000
   140004525:	e8 06 f9 ff ff       	call   0x140003e30
   14000452a:	8b d8                	mov    ebx,eax
   14000452c:	e8 eb 06 00 00       	call   0x140004c1c
   140004531:	84 c0                	test   al,al
   140004533:	74 50                	je     0x140004585
   140004535:	40 84 ff             	test   dil,dil
   140004538:	75 05                	jne    0x14000453f
   14000453a:	e8 2b 0a 00 00       	call   0x140004f6a
   14000453f:	33 d2                	xor    edx,edx
   140004541:	b1 01                	mov    cl,0x1
   140004543:	e8 a0 03 00 00       	call   0x1400048e8
   140004548:	8b c3                	mov    eax,ebx
   14000454a:	eb 19                	jmp    0x140004565
   14000454c:	8b d8                	mov    ebx,eax
   14000454e:	e8 c9 06 00 00       	call   0x140004c1c
   140004553:	84 c0                	test   al,al
   140004555:	74 36                	je     0x14000458d
   140004557:	80 7c 24 20 00       	cmp    BYTE PTR [rsp+0x20],0x0
   14000455c:	75 05                	jne    0x140004563
   14000455e:	e8 0d 0a 00 00       	call   0x140004f70
   140004563:	8b c3                	mov    eax,ebx
   140004565:	48 8b 5c 24 40       	mov    rbx,QWORD PTR [rsp+0x40]
   14000456a:	48 83 c4 30          	add    rsp,0x30
   14000456e:	5f                   	pop    rdi
   14000456f:	c3                   	ret
   140004570:	b9 07 00 00 00       	mov    ecx,0x7
   140004575:	e8 16 05 00 00       	call   0x140004a90
   14000457a:	90                   	nop
   14000457b:	b9 07 00 00 00       	mov    ecx,0x7
   140004580:	e8 0b 05 00 00       	call   0x140004a90
   140004585:	8b cb                	mov    ecx,ebx
   140004587:	e8 cc 09 00 00       	call   0x140004f58
   14000458c:	90                   	nop
   14000458d:	8b cb                	mov    ecx,ebx
   14000458f:	e8 ca 09 00 00       	call   0x140004f5e
   140004594:	90                   	nop
   140004595:	cc                   	int3
   140004596:	cc                   	int3
   140004597:	cc                   	int3
   140004598:	48 83 ec 28          	sub    rsp,0x28
   14000459c:	e8 c7 03 00 00       	call   0x140004968
   1400045a1:	48 83 c4 28          	add    rsp,0x28
   1400045a5:	e9 7a fe ff ff       	jmp    0x140004424
   1400045aa:	cc                   	int3
   1400045ab:	cc                   	int3
   1400045ac:	40 53                	rex push rbx
   1400045ae:	48 83 ec 20          	sub    rsp,0x20
   1400045b2:	48 8b d9             	mov    rbx,rcx
   1400045b5:	33 c9                	xor    ecx,ecx
   1400045b7:	ff 15 63 1a 00 00    	call   QWORD PTR [rip+0x1a63]        # 0x140006020
   1400045bd:	48 8b cb             	mov    rcx,rbx
   1400045c0:	ff 15 52 1a 00 00    	call   QWORD PTR [rip+0x1a52]        # 0x140006018
   1400045c6:	ff 15 5c 1a 00 00    	call   QWORD PTR [rip+0x1a5c]        # 0x140006028
   1400045cc:	48 8b c8             	mov    rcx,rax
   1400045cf:	ba 09 04 00 c0       	mov    edx,0xc0000409
   1400045d4:	48 83 c4 20          	add    rsp,0x20
   1400045d8:	5b                   	pop    rbx
   1400045d9:	48 ff 25 50 1a 00 00 	rex.W jmp QWORD PTR [rip+0x1a50]        # 0x140006030
   1400045e0:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   1400045e5:	48 83 ec 38          	sub    rsp,0x38
   1400045e9:	b9 17 00 00 00       	mov    ecx,0x17
   1400045ee:	ff 15 44 1a 00 00    	call   QWORD PTR [rip+0x1a44]        # 0x140006038
   1400045f4:	85 c0                	test   eax,eax
   1400045f6:	74 07                	je     0x1400045ff
   1400045f8:	b9 02 00 00 00       	mov    ecx,0x2
   1400045fd:	cd 29                	int    0x29
   1400045ff:	48 8d 0d 6a 3c 00 00 	lea    rcx,[rip+0x3c6a]        # 0x140008270
   140004606:	e8 a9 00 00 00       	call   0x1400046b4
   14000460b:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
   140004610:	48 89 05 51 3d 00 00 	mov    QWORD PTR [rip+0x3d51],rax        # 0x140008368
   140004617:	48 8d 44 24 38       	lea    rax,[rsp+0x38]
   14000461c:	48 83 c0 08          	add    rax,0x8
   140004620:	48 89 05 e1 3c 00 00 	mov    QWORD PTR [rip+0x3ce1],rax        # 0x140008308
   140004627:	48 8b 05 3a 3d 00 00 	mov    rax,QWORD PTR [rip+0x3d3a]        # 0x140008368
   14000462e:	48 89 05 ab 3b 00 00 	mov    QWORD PTR [rip+0x3bab],rax        # 0x1400081e0
   140004635:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
   14000463a:	48 89 05 af 3c 00 00 	mov    QWORD PTR [rip+0x3caf],rax        # 0x1400082f0
   140004641:	c7 05 85 3b 00 00 09 	mov    DWORD PTR [rip+0x3b85],0xc0000409        # 0x1400081d0
   140004648:	04 00 c0 
   14000464b:	c7 05 7f 3b 00 00 01 	mov    DWORD PTR [rip+0x3b7f],0x1        # 0x1400081d4
   140004652:	00 00 00 
   140004655:	c7 05 89 3b 00 00 01 	mov    DWORD PTR [rip+0x3b89],0x1        # 0x1400081e8
   14000465c:	00 00 00 
   14000465f:	b8 08 00 00 00       	mov    eax,0x8
   140004664:	48 6b c0 00          	imul   rax,rax,0x0
   140004668:	48 8d 0d 81 3b 00 00 	lea    rcx,[rip+0x3b81]        # 0x1400081f0
   14000466f:	48 c7 04 01 02 00 00 	mov    QWORD PTR [rcx+rax*1],0x2
   140004676:	00 
   140004677:	b8 08 00 00 00       	mov    eax,0x8
   14000467c:	48 6b c0 00          	imul   rax,rax,0x0
   140004680:	48 8b 0d 79 39 00 00 	mov    rcx,QWORD PTR [rip+0x3979]        # 0x140008000
   140004687:	48 89 4c 04 20       	mov    QWORD PTR [rsp+rax*1+0x20],rcx
   14000468c:	b8 08 00 00 00       	mov    eax,0x8
   140004691:	48 6b c0 01          	imul   rax,rax,0x1
   140004695:	48 8b 0d a4 39 00 00 	mov    rcx,QWORD PTR [rip+0x39a4]        # 0x140008040
   14000469c:	48 89 4c 04 20       	mov    QWORD PTR [rsp+rax*1+0x20],rcx
   1400046a1:	48 8d 0d 18 1c 00 00 	lea    rcx,[rip+0x1c18]        # 0x1400062c0
   1400046a8:	e8 ff fe ff ff       	call   0x1400045ac
   1400046ad:	48 83 c4 38          	add    rsp,0x38
   1400046b1:	c3                   	ret
   1400046b2:	cc                   	int3
   1400046b3:	cc                   	int3
   1400046b4:	40 53                	rex push rbx
   1400046b6:	56                   	push   rsi
   1400046b7:	57                   	push   rdi
   1400046b8:	48 83 ec 40          	sub    rsp,0x40
   1400046bc:	48 8b d9             	mov    rbx,rcx
   1400046bf:	ff 15 9b 19 00 00    	call   QWORD PTR [rip+0x199b]        # 0x140006060
   1400046c5:	48 8b b3 f8 00 00 00 	mov    rsi,QWORD PTR [rbx+0xf8]
   1400046cc:	33 ff                	xor    edi,edi
   1400046ce:	45 33 c0             	xor    r8d,r8d
   1400046d1:	48 8d 54 24 60       	lea    rdx,[rsp+0x60]
   1400046d6:	48 8b ce             	mov    rcx,rsi
   1400046d9:	ff 15 29 19 00 00    	call   QWORD PTR [rip+0x1929]        # 0x140006008
   1400046df:	48 85 c0             	test   rax,rax
   1400046e2:	74 39                	je     0x14000471d
   1400046e4:	48 83 64 24 38 00    	and    QWORD PTR [rsp+0x38],0x0
   1400046ea:	48 8d 4c 24 68       	lea    rcx,[rsp+0x68]
   1400046ef:	48 8b 54 24 60       	mov    rdx,QWORD PTR [rsp+0x60]
   1400046f4:	4c 8b c8             	mov    r9,rax
   1400046f7:	48 89 4c 24 30       	mov    QWORD PTR [rsp+0x30],rcx
   1400046fc:	4c 8b c6             	mov    r8,rsi
   1400046ff:	48 8d 4c 24 70       	lea    rcx,[rsp+0x70]
   140004704:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
   140004709:	33 c9                	xor    ecx,ecx
   14000470b:	48 89 5c 24 20       	mov    QWORD PTR [rsp+0x20],rbx
   140004710:	ff 15 fa 18 00 00    	call   QWORD PTR [rip+0x18fa]        # 0x140006010
   140004716:	ff c7                	inc    edi
   140004718:	83 ff 02             	cmp    edi,0x2
   14000471b:	7c b1                	jl     0x1400046ce
   14000471d:	48 83 c4 40          	add    rsp,0x40
   140004721:	5f                   	pop    rdi
   140004722:	5e                   	pop    rsi
   140004723:	5b                   	pop    rbx
   140004724:	c3                   	ret
   140004725:	cc                   	int3
   140004726:	cc                   	int3
   140004727:	cc                   	int3
   140004728:	48 83 ec 28          	sub    rsp,0x28
   14000472c:	e8 cf 07 00 00       	call   0x140004f00
   140004731:	85 c0                	test   eax,eax
   140004733:	74 21                	je     0x140004756
   140004735:	65 48 8b 04 25 30 00 	mov    rax,QWORD PTR gs:0x30
   14000473c:	00 00 
   14000473e:	48 8b 48 08          	mov    rcx,QWORD PTR [rax+0x8]
   140004742:	eb 05                	jmp    0x140004749
   140004744:	48 3b c8             	cmp    rcx,rax
   140004747:	74 14                	je     0x14000475d
   140004749:	33 c0                	xor    eax,eax
   14000474b:	f0 48 0f b1 0d f4 3f 	lock cmpxchg QWORD PTR [rip+0x3ff4],rcx        # 0x140008748
   140004752:	00 00 
   140004754:	75 ee                	jne    0x140004744
   140004756:	32 c0                	xor    al,al
   140004758:	48 83 c4 28          	add    rsp,0x28
   14000475c:	c3                   	ret
   14000475d:	b0 01                	mov    al,0x1
   14000475f:	eb f7                	jmp    0x140004758
   140004761:	cc                   	int3
   140004762:	cc                   	int3
   140004763:	cc                   	int3
   140004764:	48 83 ec 28          	sub    rsp,0x28
   140004768:	85 c9                	test   ecx,ecx
   14000476a:	75 07                	jne    0x140004773
   14000476c:	c6 05 dd 3f 00 00 01 	mov    BYTE PTR [rip+0x3fdd],0x1        # 0x140008750
   140004773:	e8 dc 05 00 00       	call   0x140004d54
   140004778:	e8 bb 02 00 00       	call   0x140004a38
   14000477d:	84 c0                	test   al,al
   14000477f:	75 04                	jne    0x140004785
   140004781:	32 c0                	xor    al,al
   140004783:	eb 14                	jmp    0x140004799
   140004785:	e8 ae 02 00 00       	call   0x140004a38
   14000478a:	84 c0                	test   al,al
   14000478c:	75 09                	jne    0x140004797
   14000478e:	33 c9                	xor    ecx,ecx
   140004790:	e8 a3 02 00 00       	call   0x140004a38
   140004795:	eb ea                	jmp    0x140004781
   140004797:	b0 01                	mov    al,0x1
   140004799:	48 83 c4 28          	add    rsp,0x28
   14000479d:	c3                   	ret
   14000479e:	cc                   	int3
   14000479f:	cc                   	int3
   1400047a0:	40 53                	rex push rbx
   1400047a2:	48 83 ec 20          	sub    rsp,0x20
   1400047a6:	80 3d a4 3f 00 00 00 	cmp    BYTE PTR [rip+0x3fa4],0x0        # 0x140008751
   1400047ad:	8b d9                	mov    ebx,ecx
   1400047af:	75 67                	jne    0x140004818
   1400047b1:	83 f9 01             	cmp    ecx,0x1
   1400047b4:	77 6a                	ja     0x140004820
   1400047b6:	e8 45 07 00 00       	call   0x140004f00
   1400047bb:	85 c0                	test   eax,eax
   1400047bd:	74 28                	je     0x1400047e7
   1400047bf:	85 db                	test   ebx,ebx
   1400047c1:	75 24                	jne    0x1400047e7
   1400047c3:	48 8d 0d 8e 3f 00 00 	lea    rcx,[rip+0x3f8e]        # 0x140008758
   1400047ca:	e8 bf 07 00 00       	call   0x140004f8e
   1400047cf:	85 c0                	test   eax,eax
   1400047d1:	75 10                	jne    0x1400047e3
   1400047d3:	48 8d 0d 96 3f 00 00 	lea    rcx,[rip+0x3f96]        # 0x140008770
   1400047da:	e8 af 07 00 00       	call   0x140004f8e
   1400047df:	85 c0                	test   eax,eax
   1400047e1:	74 2e                	je     0x140004811
   1400047e3:	32 c0                	xor    al,al
   1400047e5:	eb 33                	jmp    0x14000481a
   1400047e7:	66 0f 6f 05 e1 1a 00 	movdqa xmm0,XMMWORD PTR [rip+0x1ae1]        # 0x1400062d0
   1400047ee:	00 
   1400047ef:	48 83 c8 ff          	or     rax,0xffffffffffffffff
   1400047f3:	f3 0f 7f 05 5d 3f 00 	movdqu XMMWORD PTR [rip+0x3f5d],xmm0        # 0x140008758
   1400047fa:	00 
   1400047fb:	48 89 05 66 3f 00 00 	mov    QWORD PTR [rip+0x3f66],rax        # 0x140008768
   140004802:	f3 0f 7f 05 66 3f 00 	movdqu XMMWORD PTR [rip+0x3f66],xmm0        # 0x140008770
   140004809:	00 
   14000480a:	48 89 05 6f 3f 00 00 	mov    QWORD PTR [rip+0x3f6f],rax        # 0x140008780
   140004811:	c6 05 39 3f 00 00 01 	mov    BYTE PTR [rip+0x3f39],0x1        # 0x140008751
   140004818:	b0 01                	mov    al,0x1
   14000481a:	48 83 c4 20          	add    rsp,0x20
   14000481e:	5b                   	pop    rbx
   14000481f:	c3                   	ret
   140004820:	b9 05 00 00 00       	mov    ecx,0x5
   140004825:	e8 66 02 00 00       	call   0x140004a90
   14000482a:	cc                   	int3
   14000482b:	cc                   	int3
   14000482c:	48 83 ec 18          	sub    rsp,0x18
   140004830:	4c 8b c1             	mov    r8,rcx
   140004833:	b8 4d 5a 00 00       	mov    eax,0x5a4d
   140004838:	66 39 05 c1 b7 ff ff 	cmp    WORD PTR [rip+0xffffffffffffb7c1],ax        # 0x140000000
   14000483f:	75 78                	jne    0x1400048b9
   140004841:	48 63 0d f4 b7 ff ff 	movsxd rcx,DWORD PTR [rip+0xffffffffffffb7f4]        # 0x14000003c
   140004848:	48 8d 15 b1 b7 ff ff 	lea    rdx,[rip+0xffffffffffffb7b1]        # 0x140000000
   14000484f:	48 03 ca             	add    rcx,rdx
   140004852:	81 39 50 45 00 00    	cmp    DWORD PTR [rcx],0x4550
   140004858:	75 5f                	jne    0x1400048b9
   14000485a:	b8 0b 02 00 00       	mov    eax,0x20b
   14000485f:	66 39 41 18          	cmp    WORD PTR [rcx+0x18],ax
   140004863:	75 54                	jne    0x1400048b9
   140004865:	4c 2b c2             	sub    r8,rdx
   140004868:	0f b7 51 14          	movzx  edx,WORD PTR [rcx+0x14]
   14000486c:	48 83 c2 18          	add    rdx,0x18
   140004870:	48 03 d1             	add    rdx,rcx
   140004873:	0f b7 41 06          	movzx  eax,WORD PTR [rcx+0x6]
   140004877:	48 8d 0c 80          	lea    rcx,[rax+rax*4]
   14000487b:	4c 8d 0c ca          	lea    r9,[rdx+rcx*8]
   14000487f:	48 89 14 24          	mov    QWORD PTR [rsp],rdx
   140004883:	49 3b d1             	cmp    rdx,r9
   140004886:	74 18                	je     0x1400048a0
   140004888:	8b 4a 0c             	mov    ecx,DWORD PTR [rdx+0xc]
   14000488b:	4c 3b c1             	cmp    r8,rcx
   14000488e:	72 0a                	jb     0x14000489a
   140004890:	8b 42 08             	mov    eax,DWORD PTR [rdx+0x8]
   140004893:	03 c1                	add    eax,ecx
   140004895:	4c 3b c0             	cmp    r8,rax
   140004898:	72 08                	jb     0x1400048a2
   14000489a:	48 83 c2 28          	add    rdx,0x28
   14000489e:	eb df                	jmp    0x14000487f
   1400048a0:	33 d2                	xor    edx,edx
   1400048a2:	48 85 d2             	test   rdx,rdx
   1400048a5:	75 04                	jne    0x1400048ab
   1400048a7:	32 c0                	xor    al,al
   1400048a9:	eb 14                	jmp    0x1400048bf
   1400048ab:	83 7a 24 00          	cmp    DWORD PTR [rdx+0x24],0x0
   1400048af:	7d 04                	jge    0x1400048b5
   1400048b1:	32 c0                	xor    al,al
   1400048b3:	eb 0a                	jmp    0x1400048bf
   1400048b5:	b0 01                	mov    al,0x1
   1400048b7:	eb 06                	jmp    0x1400048bf
   1400048b9:	32 c0                	xor    al,al
   1400048bb:	eb 02                	jmp    0x1400048bf
   1400048bd:	32 c0                	xor    al,al
   1400048bf:	48 83 c4 18          	add    rsp,0x18
   1400048c3:	c3                   	ret
   1400048c4:	40 53                	rex push rbx
   1400048c6:	48 83 ec 20          	sub    rsp,0x20
   1400048ca:	8a d9                	mov    bl,cl
   1400048cc:	e8 2f 06 00 00       	call   0x140004f00
   1400048d1:	33 d2                	xor    edx,edx
   1400048d3:	85 c0                	test   eax,eax
   1400048d5:	74 0b                	je     0x1400048e2
   1400048d7:	84 db                	test   bl,bl
   1400048d9:	75 07                	jne    0x1400048e2
   1400048db:	48 87 15 66 3e 00 00 	xchg   QWORD PTR [rip+0x3e66],rdx        # 0x140008748
   1400048e2:	48 83 c4 20          	add    rsp,0x20
   1400048e6:	5b                   	pop    rbx
   1400048e7:	c3                   	ret
   1400048e8:	40 53                	rex push rbx
   1400048ea:	48 83 ec 20          	sub    rsp,0x20
   1400048ee:	80 3d 5b 3e 00 00 00 	cmp    BYTE PTR [rip+0x3e5b],0x0        # 0x140008750
   1400048f5:	8a d9                	mov    bl,cl
   1400048f7:	74 04                	je     0x1400048fd
   1400048f9:	84 d2                	test   dl,dl
   1400048fb:	75 0c                	jne    0x140004909
   1400048fd:	e8 36 01 00 00       	call   0x140004a38
   140004902:	8a cb                	mov    cl,bl
   140004904:	e8 2f 01 00 00       	call   0x140004a38
   140004909:	b0 01                	mov    al,0x1
   14000490b:	48 83 c4 20          	add    rsp,0x20
   14000490f:	5b                   	pop    rbx
   140004910:	c3                   	ret
   140004911:	cc                   	int3
   140004912:	cc                   	int3
   140004913:	cc                   	int3
   140004914:	40 53                	rex push rbx
   140004916:	48 83 ec 20          	sub    rsp,0x20
   14000491a:	48 83 3d 36 3e 00 00 	cmp    QWORD PTR [rip+0x3e36],0xffffffffffffffff        # 0x140008758
   140004921:	ff 
   140004922:	48 8b d9             	mov    rbx,rcx
   140004925:	75 07                	jne    0x14000492e
   140004927:	e8 6e 06 00 00       	call   0x140004f9a
   14000492c:	eb 0f                	jmp    0x14000493d
   14000492e:	48 8b d3             	mov    rdx,rbx
   140004931:	48 8d 0d 20 3e 00 00 	lea    rcx,[rip+0x3e20]        # 0x140008758
   140004938:	e8 57 06 00 00       	call   0x140004f94
   14000493d:	33 d2                	xor    edx,edx
   14000493f:	85 c0                	test   eax,eax
   140004941:	48 0f 44 d3          	cmove  rdx,rbx
   140004945:	48 8b c2             	mov    rax,rdx
   140004948:	48 83 c4 20          	add    rsp,0x20
   14000494c:	5b                   	pop    rbx
   14000494d:	c3                   	ret
   14000494e:	cc                   	int3
   14000494f:	cc                   	int3
   140004950:	48 83 ec 28          	sub    rsp,0x28
   140004954:	e8 bb ff ff ff       	call   0x140004914
   140004959:	48 f7 d8             	neg    rax
   14000495c:	1b c0                	sbb    eax,eax
   14000495e:	f7 d8                	neg    eax
   140004960:	ff c8                	dec    eax
   140004962:	48 83 c4 28          	add    rsp,0x28
   140004966:	c3                   	ret
   140004967:	cc                   	int3
   140004968:	48 89 5c 24 18       	mov    QWORD PTR [rsp+0x18],rbx
   14000496d:	55                   	push   rbp
   14000496e:	48 8b ec             	mov    rbp,rsp
   140004971:	48 83 ec 30          	sub    rsp,0x30
   140004975:	48 8b 05 84 36 00 00 	mov    rax,QWORD PTR [rip+0x3684]        # 0x140008000
   14000497c:	48 bb 32 a2 df 2d 99 	movabs rbx,0x2b992ddfa232
   140004983:	2b 00 00 
   140004986:	48 3b c3             	cmp    rax,rbx
   140004989:	75 74                	jne    0x1400049ff
   14000498b:	48 83 65 10 00       	and    QWORD PTR [rbp+0x10],0x0
   140004990:	48 8d 4d 10          	lea    rcx,[rbp+0x10]
   140004994:	ff 15 66 16 00 00    	call   QWORD PTR [rip+0x1666]        # 0x140006000
   14000499a:	48 8b 45 10          	mov    rax,QWORD PTR [rbp+0x10]
   14000499e:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
   1400049a2:	ff 15 c0 16 00 00    	call   QWORD PTR [rip+0x16c0]        # 0x140006068
   1400049a8:	8b c0                	mov    eax,eax
   1400049aa:	48 31 45 f0          	xor    QWORD PTR [rbp-0x10],rax
   1400049ae:	ff 15 bc 16 00 00    	call   QWORD PTR [rip+0x16bc]        # 0x140006070
   1400049b4:	8b c0                	mov    eax,eax
   1400049b6:	48 8d 4d 18          	lea    rcx,[rbp+0x18]
   1400049ba:	48 31 45 f0          	xor    QWORD PTR [rbp-0x10],rax
   1400049be:	ff 15 b4 16 00 00    	call   QWORD PTR [rip+0x16b4]        # 0x140006078
   1400049c4:	8b 45 18             	mov    eax,DWORD PTR [rbp+0x18]
   1400049c7:	48 8d 4d f0          	lea    rcx,[rbp-0x10]
   1400049cb:	48 c1 e0 20          	shl    rax,0x20
   1400049cf:	48 33 45 18          	xor    rax,QWORD PTR [rbp+0x18]
   1400049d3:	48 33 45 f0          	xor    rax,QWORD PTR [rbp-0x10]
   1400049d7:	48 33 c1             	xor    rax,rcx
   1400049da:	48 b9 ff ff ff ff ff 	movabs rcx,0xffffffffffff
   1400049e1:	ff 00 00 
   1400049e4:	48 23 c1             	and    rax,rcx
   1400049e7:	48 b9 33 a2 df 2d 99 	movabs rcx,0x2b992ddfa233
   1400049ee:	2b 00 00 
   1400049f1:	48 3b c3             	cmp    rax,rbx
   1400049f4:	48 0f 44 c1          	cmove  rax,rcx
   1400049f8:	48 89 05 01 36 00 00 	mov    QWORD PTR [rip+0x3601],rax        # 0x140008000
   1400049ff:	48 8b 5c 24 50       	mov    rbx,QWORD PTR [rsp+0x50]
   140004a04:	48 f7 d0             	not    rax
   140004a07:	48 89 05 32 36 00 00 	mov    QWORD PTR [rip+0x3632],rax        # 0x140008040
   140004a0e:	48 83 c4 30          	add    rsp,0x30
   140004a12:	5d                   	pop    rbp
   140004a13:	c3                   	ret
   140004a14:	33 c0                	xor    eax,eax
   140004a16:	c3                   	ret
   140004a17:	cc                   	int3
   140004a18:	b8 01 00 00 00       	mov    eax,0x1
   140004a1d:	c3                   	ret
   140004a1e:	cc                   	int3
   140004a1f:	cc                   	int3
   140004a20:	b8 00 40 00 00       	mov    eax,0x4000
   140004a25:	c3                   	ret
   140004a26:	cc                   	int3
   140004a27:	cc                   	int3
   140004a28:	48 8d 0d 61 3d 00 00 	lea    rcx,[rip+0x3d61]        # 0x140008790
   140004a2f:	48 ff 25 22 16 00 00 	rex.W jmp QWORD PTR [rip+0x1622]        # 0x140006058
   140004a36:	cc                   	int3
   140004a37:	cc                   	int3
   140004a38:	b0 01                	mov    al,0x1
   140004a3a:	c3                   	ret
   140004a3b:	cc                   	int3
   140004a3c:	c2 00 00             	ret    0x0
   140004a3f:	cc                   	int3
   140004a40:	48 8d 05 59 3d 00 00 	lea    rax,[rip+0x3d59]        # 0x1400087a0
   140004a47:	c3                   	ret
   140004a48:	48 8d 05 59 3d 00 00 	lea    rax,[rip+0x3d59]        # 0x1400087a8
   140004a4f:	c3                   	ret
   140004a50:	48 83 ec 28          	sub    rsp,0x28
   140004a54:	e8 e7 ff ff ff       	call   0x140004a40
   140004a59:	48 83 08 24          	or     QWORD PTR [rax],0x24
   140004a5d:	e8 e6 ff ff ff       	call   0x140004a48
   140004a62:	48 83 08 02          	or     QWORD PTR [rax],0x2
   140004a66:	48 83 c4 28          	add    rsp,0x28
   140004a6a:	c3                   	ret
   140004a6b:	cc                   	int3
   140004a6c:	33 c0                	xor    eax,eax
   140004a6e:	39 05 d8 35 00 00    	cmp    DWORD PTR [rip+0x35d8],eax        # 0x14000804c
   140004a74:	0f 94 c0             	sete   al
   140004a77:	c3                   	ret
   140004a78:	48 8d 05 41 3d 00 00 	lea    rax,[rip+0x3d41]        # 0x1400087c0
   140004a7f:	c3                   	ret
   140004a80:	48 8d 05 31 3d 00 00 	lea    rax,[rip+0x3d31]        # 0x1400087b8
   140004a87:	c3                   	ret
   140004a88:	83 25 21 3d 00 00 00 	and    DWORD PTR [rip+0x3d21],0x0        # 0x1400087b0
   140004a8f:	c3                   	ret
   140004a90:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140004a95:	55                   	push   rbp
   140004a96:	48 8d ac 24 40 fb ff 	lea    rbp,[rsp-0x4c0]
   140004a9d:	ff 
   140004a9e:	48 81 ec c0 05 00 00 	sub    rsp,0x5c0
   140004aa5:	8b d9                	mov    ebx,ecx
   140004aa7:	b9 17 00 00 00       	mov    ecx,0x17
   140004aac:	ff 15 86 15 00 00    	call   QWORD PTR [rip+0x1586]        # 0x140006038
   140004ab2:	85 c0                	test   eax,eax
   140004ab4:	74 04                	je     0x140004aba
   140004ab6:	8b cb                	mov    ecx,ebx
   140004ab8:	cd 29                	int    0x29
   140004aba:	b9 03 00 00 00       	mov    ecx,0x3
   140004abf:	e8 c4 ff ff ff       	call   0x140004a88
   140004ac4:	33 d2                	xor    edx,edx
   140004ac6:	48 8d 4d f0          	lea    rcx,[rbp-0x10]
   140004aca:	41 b8 d0 04 00 00    	mov    r8d,0x4d0
   140004ad0:	e8 3b 04 00 00       	call   0x140004f10
   140004ad5:	48 8d 4d f0          	lea    rcx,[rbp-0x10]
   140004ad9:	ff 15 81 15 00 00    	call   QWORD PTR [rip+0x1581]        # 0x140006060
   140004adf:	48 8b 9d e8 00 00 00 	mov    rbx,QWORD PTR [rbp+0xe8]
   140004ae6:	48 8d 95 d8 04 00 00 	lea    rdx,[rbp+0x4d8]
   140004aed:	48 8b cb             	mov    rcx,rbx
   140004af0:	45 33 c0             	xor    r8d,r8d
   140004af3:	ff 15 0f 15 00 00    	call   QWORD PTR [rip+0x150f]        # 0x140006008
   140004af9:	48 85 c0             	test   rax,rax
   140004afc:	74 3c                	je     0x140004b3a
   140004afe:	48 83 64 24 38 00    	and    QWORD PTR [rsp+0x38],0x0
   140004b04:	48 8d 8d e0 04 00 00 	lea    rcx,[rbp+0x4e0]
   140004b0b:	48 8b 95 d8 04 00 00 	mov    rdx,QWORD PTR [rbp+0x4d8]
   140004b12:	4c 8b c8             	mov    r9,rax
   140004b15:	48 89 4c 24 30       	mov    QWORD PTR [rsp+0x30],rcx
   140004b1a:	4c 8b c3             	mov    r8,rbx
   140004b1d:	48 8d 8d e8 04 00 00 	lea    rcx,[rbp+0x4e8]
   140004b24:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
   140004b29:	48 8d 4d f0          	lea    rcx,[rbp-0x10]
   140004b2d:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
   140004b32:	33 c9                	xor    ecx,ecx
   140004b34:	ff 15 d6 14 00 00    	call   QWORD PTR [rip+0x14d6]        # 0x140006010
   140004b3a:	48 8b 85 c8 04 00 00 	mov    rax,QWORD PTR [rbp+0x4c8]
   140004b41:	48 8d 4c 24 50       	lea    rcx,[rsp+0x50]
   140004b46:	48 89 85 e8 00 00 00 	mov    QWORD PTR [rbp+0xe8],rax
   140004b4d:	33 d2                	xor    edx,edx
   140004b4f:	48 8d 85 c8 04 00 00 	lea    rax,[rbp+0x4c8]
   140004b56:	41 b8 98 00 00 00    	mov    r8d,0x98
   140004b5c:	48 83 c0 08          	add    rax,0x8
   140004b60:	48 89 85 88 00 00 00 	mov    QWORD PTR [rbp+0x88],rax
   140004b67:	e8 a4 03 00 00       	call   0x140004f10
   140004b6c:	48 8b 85 c8 04 00 00 	mov    rax,QWORD PTR [rbp+0x4c8]
   140004b73:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
   140004b78:	c7 44 24 50 15 00 00 	mov    DWORD PTR [rsp+0x50],0x40000015
   140004b7f:	40 
   140004b80:	c7 44 24 54 01 00 00 	mov    DWORD PTR [rsp+0x54],0x1
   140004b87:	00 
   140004b88:	ff 15 c2 14 00 00    	call   QWORD PTR [rip+0x14c2]        # 0x140006050
   140004b8e:	8b d8                	mov    ebx,eax
   140004b90:	33 c9                	xor    ecx,ecx
   140004b92:	48 8d 44 24 50       	lea    rax,[rsp+0x50]
   140004b97:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
   140004b9c:	48 8d 45 f0          	lea    rax,[rbp-0x10]
   140004ba0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
   140004ba5:	ff 15 75 14 00 00    	call   QWORD PTR [rip+0x1475]        # 0x140006020
   140004bab:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
   140004bb0:	ff 15 62 14 00 00    	call   QWORD PTR [rip+0x1462]        # 0x140006018
   140004bb6:	85 c0                	test   eax,eax
   140004bb8:	75 0d                	jne    0x140004bc7
   140004bba:	83 fb 01             	cmp    ebx,0x1
   140004bbd:	74 08                	je     0x140004bc7
   140004bbf:	8d 48 03             	lea    ecx,[rax+0x3]
   140004bc2:	e8 c1 fe ff ff       	call   0x140004a88
   140004bc7:	48 8b 9c 24 d0 05 00 	mov    rbx,QWORD PTR [rsp+0x5d0]
   140004bce:	00 
   140004bcf:	48 81 c4 c0 05 00 00 	add    rsp,0x5c0
   140004bd6:	5d                   	pop    rbp
   140004bd7:	c3                   	ret
   140004bd8:	48 81 ec 98 00 00 00 	sub    rsp,0x98
   140004bdf:	33 d2                	xor    edx,edx
   140004be1:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   140004be6:	44 8d 42 68          	lea    r8d,[rdx+0x68]
   140004bea:	e8 21 03 00 00       	call   0x140004f10
   140004bef:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   140004bf4:	ff 15 4e 14 00 00    	call   QWORD PTR [rip+0x144e]        # 0x140006048
   140004bfa:	f6 44 24 5c 01       	test   BYTE PTR [rsp+0x5c],0x1
   140004bff:	b8 0a 00 00 00       	mov    eax,0xa
   140004c04:	66 0f 45 44 24 60    	cmovne ax,WORD PTR [rsp+0x60]
   140004c0a:	48 81 c4 98 00 00 00 	add    rsp,0x98
   140004c11:	c3                   	ret
   140004c12:	cc                   	int3
   140004c13:	cc                   	int3
   140004c14:	e9 fb fd ff ff       	jmp    0x140004a14
   140004c19:	cc                   	int3
   140004c1a:	cc                   	int3
   140004c1b:	cc                   	int3
   140004c1c:	48 83 ec 28          	sub    rsp,0x28
   140004c20:	33 c9                	xor    ecx,ecx
   140004c22:	ff 15 18 14 00 00    	call   QWORD PTR [rip+0x1418]        # 0x140006040
   140004c28:	48 85 c0             	test   rax,rax
   140004c2b:	74 39                	je     0x140004c66
   140004c2d:	b9 4d 5a 00 00       	mov    ecx,0x5a4d
   140004c32:	66 39 08             	cmp    WORD PTR [rax],cx
   140004c35:	75 2f                	jne    0x140004c66
   140004c37:	48 63 48 3c          	movsxd rcx,DWORD PTR [rax+0x3c]
   140004c3b:	48 03 c8             	add    rcx,rax
   140004c3e:	81 39 50 45 00 00    	cmp    DWORD PTR [rcx],0x4550
   140004c44:	75 20                	jne    0x140004c66
   140004c46:	b8 0b 02 00 00       	mov    eax,0x20b
   140004c4b:	66 39 41 18          	cmp    WORD PTR [rcx+0x18],ax
   140004c4f:	75 15                	jne    0x140004c66
   140004c51:	83 b9 84 00 00 00 0e 	cmp    DWORD PTR [rcx+0x84],0xe
   140004c58:	76 0c                	jbe    0x140004c66
   140004c5a:	83 b9 f8 00 00 00 00 	cmp    DWORD PTR [rcx+0xf8],0x0
   140004c61:	0f 95 c0             	setne  al
   140004c64:	eb 02                	jmp    0x140004c68
   140004c66:	32 c0                	xor    al,al
   140004c68:	48 83 c4 28          	add    rsp,0x28
   140004c6c:	c3                   	ret
   140004c6d:	cc                   	int3
   140004c6e:	cc                   	int3
   140004c6f:	cc                   	int3
   140004c70:	48 8d 0d 09 00 00 00 	lea    rcx,[rip+0x9]        # 0x140004c80
   140004c77:	48 ff 25 a2 13 00 00 	rex.W jmp QWORD PTR [rip+0x13a2]        # 0x140006020
   140004c7e:	cc                   	int3
   140004c7f:	cc                   	int3
   140004c80:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140004c85:	57                   	push   rdi
   140004c86:	48 83 ec 20          	sub    rsp,0x20
   140004c8a:	48 8b 19             	mov    rbx,QWORD PTR [rcx]
   140004c8d:	48 8b f9             	mov    rdi,rcx
   140004c90:	81 3b 63 73 6d e0    	cmp    DWORD PTR [rbx],0xe06d7363
   140004c96:	75 1c                	jne    0x140004cb4
   140004c98:	83 7b 18 04          	cmp    DWORD PTR [rbx+0x18],0x4
   140004c9c:	75 16                	jne    0x140004cb4
   140004c9e:	8b 53 20             	mov    edx,DWORD PTR [rbx+0x20]
   140004ca1:	8d 82 e0 fa 6c e6    	lea    eax,[rdx-0x19930520]
   140004ca7:	83 f8 02             	cmp    eax,0x2
   140004caa:	76 15                	jbe    0x140004cc1
   140004cac:	81 fa 00 40 99 01    	cmp    edx,0x1994000
   140004cb2:	74 0d                	je     0x140004cc1
   140004cb4:	48 8b 5c 24 30       	mov    rbx,QWORD PTR [rsp+0x30]
   140004cb9:	33 c0                	xor    eax,eax
   140004cbb:	48 83 c4 20          	add    rsp,0x20
   140004cbf:	5f                   	pop    rdi
   140004cc0:	c3                   	ret
   140004cc1:	e8 56 02 00 00       	call   0x140004f1c
   140004cc6:	48 89 18             	mov    QWORD PTR [rax],rbx
   140004cc9:	48 8b 5f 08          	mov    rbx,QWORD PTR [rdi+0x8]
   140004ccd:	e8 50 02 00 00       	call   0x140004f22
   140004cd2:	48 89 18             	mov    QWORD PTR [rax],rbx
   140004cd5:	e8 c6 02 00 00       	call   0x140004fa0
   140004cda:	cc                   	int3
   140004cdb:	cc                   	int3
   140004cdc:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140004ce1:	57                   	push   rdi
   140004ce2:	48 83 ec 20          	sub    rsp,0x20
   140004ce6:	48 8d 1d 83 1a 00 00 	lea    rbx,[rip+0x1a83]        # 0x140006770
   140004ced:	48 8d 3d 7c 1a 00 00 	lea    rdi,[rip+0x1a7c]        # 0x140006770
   140004cf4:	eb 12                	jmp    0x140004d08
   140004cf6:	48 8b 03             	mov    rax,QWORD PTR [rbx]
   140004cf9:	48 85 c0             	test   rax,rax
   140004cfc:	74 06                	je     0x140004d04
   140004cfe:	ff 15 a4 14 00 00    	call   QWORD PTR [rip+0x14a4]        # 0x1400061a8
   140004d04:	48 83 c3 08          	add    rbx,0x8
   140004d08:	48 3b df             	cmp    rbx,rdi
   140004d0b:	72 e9                	jb     0x140004cf6
   140004d0d:	48 8b 5c 24 30       	mov    rbx,QWORD PTR [rsp+0x30]
   140004d12:	48 83 c4 20          	add    rsp,0x20
   140004d16:	5f                   	pop    rdi
   140004d17:	c3                   	ret
   140004d18:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
   140004d1d:	57                   	push   rdi
   140004d1e:	48 83 ec 20          	sub    rsp,0x20
   140004d22:	48 8d 1d 57 1a 00 00 	lea    rbx,[rip+0x1a57]        # 0x140006780
   140004d29:	48 8d 3d 50 1a 00 00 	lea    rdi,[rip+0x1a50]        # 0x140006780
   140004d30:	eb 12                	jmp    0x140004d44
   140004d32:	48 8b 03             	mov    rax,QWORD PTR [rbx]
   140004d35:	48 85 c0             	test   rax,rax
   140004d38:	74 06                	je     0x140004d40
   140004d3a:	ff 15 68 14 00 00    	call   QWORD PTR [rip+0x1468]        # 0x1400061a8
   140004d40:	48 83 c3 08          	add    rbx,0x8
   140004d44:	48 3b df             	cmp    rbx,rdi
   140004d47:	72 e9                	jb     0x140004d32
   140004d49:	48 8b 5c 24 30       	mov    rbx,QWORD PTR [rsp+0x30]
   140004d4e:	48 83 c4 20          	add    rsp,0x20
   140004d52:	5f                   	pop    rdi
   140004d53:	c3                   	ret
   140004d54:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
   140004d59:	48 89 74 24 18       	mov    QWORD PTR [rsp+0x18],rsi
   140004d5e:	57                   	push   rdi
   140004d5f:	48 83 ec 10          	sub    rsp,0x10
   140004d63:	33 c0                	xor    eax,eax
   140004d65:	33 c9                	xor    ecx,ecx
   140004d67:	0f a2                	cpuid
   140004d69:	44 8b c1             	mov    r8d,ecx
   140004d6c:	45 33 db             	xor    r11d,r11d
   140004d6f:	44 8b d2             	mov    r10d,edx
   140004d72:	41 81 f0 6e 74 65 6c 	xor    r8d,0x6c65746e
   140004d79:	41 81 f2 69 6e 65 49 	xor    r10d,0x49656e69
   140004d80:	44 8b cb             	mov    r9d,ebx
   140004d83:	8b f0                	mov    esi,eax
   140004d85:	33 c9                	xor    ecx,ecx
   140004d87:	41 8d 43 01          	lea    eax,[r11+0x1]
   140004d8b:	45 0b d0             	or     r10d,r8d
   140004d8e:	0f a2                	cpuid
   140004d90:	41 81 f1 47 65 6e 75 	xor    r9d,0x756e6547
   140004d97:	89 04 24             	mov    DWORD PTR [rsp],eax
   140004d9a:	45 0b d1             	or     r10d,r9d
   140004d9d:	89 5c 24 04          	mov    DWORD PTR [rsp+0x4],ebx
   140004da1:	8b f9                	mov    edi,ecx
   140004da3:	89 4c 24 08          	mov    DWORD PTR [rsp+0x8],ecx
   140004da7:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   140004dab:	75 5b                	jne    0x140004e08
   140004dad:	48 83 0d ab 32 00 00 	or     QWORD PTR [rip+0x32ab],0xffffffffffffffff        # 0x140008060
   140004db4:	ff 
   140004db5:	25 f0 3f ff 0f       	and    eax,0xfff3ff0
   140004dba:	48 c7 05 93 32 00 00 	mov    QWORD PTR [rip+0x3293],0x8000        # 0x140008058
   140004dc1:	00 80 00 00 
   140004dc5:	3d c0 06 01 00       	cmp    eax,0x106c0
   140004dca:	74 28                	je     0x140004df4
   140004dcc:	3d 60 06 02 00       	cmp    eax,0x20660
   140004dd1:	74 21                	je     0x140004df4
   140004dd3:	3d 70 06 02 00       	cmp    eax,0x20670
   140004dd8:	74 1a                	je     0x140004df4
   140004dda:	05 b0 f9 fc ff       	add    eax,0xfffcf9b0
   140004ddf:	83 f8 20             	cmp    eax,0x20
   140004de2:	77 24                	ja     0x140004e08
   140004de4:	48 b9 01 00 01 00 01 	movabs rcx,0x100010001
   140004deb:	00 00 00 
   140004dee:	48 0f a3 c1          	bt     rcx,rax
   140004df2:	73 14                	jae    0x140004e08
   140004df4:	44 8b 05 b9 39 00 00 	mov    r8d,DWORD PTR [rip+0x39b9]        # 0x1400087b4
   140004dfb:	41 83 c8 01          	or     r8d,0x1
   140004dff:	44 89 05 ae 39 00 00 	mov    DWORD PTR [rip+0x39ae],r8d        # 0x1400087b4
   140004e06:	eb 07                	jmp    0x140004e0f
   140004e08:	44 8b 05 a5 39 00 00 	mov    r8d,DWORD PTR [rip+0x39a5]        # 0x1400087b4
   140004e0f:	b8 07 00 00 00       	mov    eax,0x7
   140004e14:	44 8d 48 fb          	lea    r9d,[rax-0x5]
   140004e18:	3b f0                	cmp    esi,eax
   140004e1a:	7c 26                	jl     0x140004e42
   140004e1c:	33 c9                	xor    ecx,ecx
   140004e1e:	0f a2                	cpuid
   140004e20:	89 04 24             	mov    DWORD PTR [rsp],eax
   140004e23:	44 8b db             	mov    r11d,ebx
   140004e26:	89 5c 24 04          	mov    DWORD PTR [rsp+0x4],ebx
   140004e2a:	89 4c 24 08          	mov    DWORD PTR [rsp+0x8],ecx
   140004e2e:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   140004e32:	0f ba e3 09          	bt     ebx,0x9
   140004e36:	73 0a                	jae    0x140004e42
   140004e38:	45 0b c1             	or     r8d,r9d
   140004e3b:	44 89 05 72 39 00 00 	mov    DWORD PTR [rip+0x3972],r8d        # 0x1400087b4
   140004e42:	c7 05 04 32 00 00 01 	mov    DWORD PTR [rip+0x3204],0x1        # 0x140008050
   140004e49:	00 00 00 
   140004e4c:	44 89 0d 01 32 00 00 	mov    DWORD PTR [rip+0x3201],r9d        # 0x140008054
   140004e53:	0f ba e7 14          	bt     edi,0x14
   140004e57:	0f 83 91 00 00 00    	jae    0x140004eee
   140004e5d:	44 89 0d ec 31 00 00 	mov    DWORD PTR [rip+0x31ec],r9d        # 0x140008050
   140004e64:	bb 06 00 00 00       	mov    ebx,0x6
   140004e69:	89 1d e5 31 00 00    	mov    DWORD PTR [rip+0x31e5],ebx        # 0x140008054
   140004e6f:	0f ba e7 1b          	bt     edi,0x1b
   140004e73:	73 79                	jae    0x140004eee
   140004e75:	0f ba e7 1c          	bt     edi,0x1c
   140004e79:	73 73                	jae    0x140004eee
   140004e7b:	33 c9                	xor    ecx,ecx
   140004e7d:	0f 01 d0             	xgetbv
   140004e80:	48 c1 e2 20          	shl    rdx,0x20
   140004e84:	48 0b d0             	or     rdx,rax
   140004e87:	48 89 54 24 20       	mov    QWORD PTR [rsp+0x20],rdx
   140004e8c:	48 8b 44 24 20       	mov    rax,QWORD PTR [rsp+0x20]
   140004e91:	22 c3                	and    al,bl
   140004e93:	3a c3                	cmp    al,bl
   140004e95:	75 57                	jne    0x140004eee
   140004e97:	8b 05 b7 31 00 00    	mov    eax,DWORD PTR [rip+0x31b7]        # 0x140008054
   140004e9d:	83 c8 08             	or     eax,0x8
   140004ea0:	c7 05 a6 31 00 00 03 	mov    DWORD PTR [rip+0x31a6],0x3        # 0x140008050
   140004ea7:	00 00 00 
   140004eaa:	89 05 a4 31 00 00    	mov    DWORD PTR [rip+0x31a4],eax        # 0x140008054
   140004eb0:	41 f6 c3 20          	test   r11b,0x20
   140004eb4:	74 38                	je     0x140004eee
   140004eb6:	83 c8 20             	or     eax,0x20
   140004eb9:	c7 05 8d 31 00 00 05 	mov    DWORD PTR [rip+0x318d],0x5        # 0x140008050
   140004ec0:	00 00 00 
   140004ec3:	89 05 8b 31 00 00    	mov    DWORD PTR [rip+0x318b],eax        # 0x140008054
   140004ec9:	b8 00 00 03 d0       	mov    eax,0xd0030000
   140004ece:	44 23 d8             	and    r11d,eax
   140004ed1:	44 3b d8             	cmp    r11d,eax
   140004ed4:	75 18                	jne    0x140004eee
   140004ed6:	48 8b 44 24 20       	mov    rax,QWORD PTR [rsp+0x20]
   140004edb:	24 e0                	and    al,0xe0
   140004edd:	3c e0                	cmp    al,0xe0
   140004edf:	75 0d                	jne    0x140004eee
   140004ee1:	83 0d 6c 31 00 00 40 	or     DWORD PTR [rip+0x316c],0x40        # 0x140008054
   140004ee8:	89 1d 62 31 00 00    	mov    DWORD PTR [rip+0x3162],ebx        # 0x140008050
   140004eee:	48 8b 5c 24 28       	mov    rbx,QWORD PTR [rsp+0x28]
   140004ef3:	33 c0                	xor    eax,eax
   140004ef5:	48 8b 74 24 30       	mov    rsi,QWORD PTR [rsp+0x30]
   140004efa:	48 83 c4 10          	add    rsp,0x10
   140004efe:	5f                   	pop    rdi
   140004eff:	c3                   	ret
   140004f00:	33 c0                	xor    eax,eax
   140004f02:	39 05 68 31 00 00    	cmp    DWORD PTR [rip+0x3168],eax        # 0x140008070
   140004f08:	0f 95 c0             	setne  al
   140004f0b:	c3                   	ret
   140004f0c:	cc                   	int3
   140004f0d:	cc                   	int3
   140004f0e:	cc                   	int3
   140004f0f:	cc                   	int3
   140004f10:	ff 25 8a 11 00 00    	jmp    QWORD PTR [rip+0x118a]        # 0x1400060a0
   140004f16:	ff 25 7c 11 00 00    	jmp    QWORD PTR [rip+0x117c]        # 0x140006098
   140004f1c:	ff 25 86 11 00 00    	jmp    QWORD PTR [rip+0x1186]        # 0x1400060a8
   140004f22:	ff 25 88 11 00 00    	jmp    QWORD PTR [rip+0x1188]        # 0x1400060b0
   140004f28:	ff 25 e2 11 00 00    	jmp    QWORD PTR [rip+0x11e2]        # 0x140006110
   140004f2e:	ff 25 c4 11 00 00    	jmp    QWORD PTR [rip+0x11c4]        # 0x1400060f8
   140004f34:	ff 25 ae 11 00 00    	jmp    QWORD PTR [rip+0x11ae]        # 0x1400060e8
   140004f3a:	ff 25 28 12 00 00    	jmp    QWORD PTR [rip+0x1228]        # 0x140006168
   140004f40:	ff 25 1a 12 00 00    	jmp    QWORD PTR [rip+0x121a]        # 0x140006160
   140004f46:	ff 25 0c 12 00 00    	jmp    QWORD PTR [rip+0x120c]        # 0x140006158
   140004f4c:	ff 25 fe 11 00 00    	jmp    QWORD PTR [rip+0x11fe]        # 0x140006150
   140004f52:	ff 25 f0 11 00 00    	jmp    QWORD PTR [rip+0x11f0]        # 0x140006148
   140004f58:	ff 25 e2 11 00 00    	jmp    QWORD PTR [rip+0x11e2]        # 0x140006140
   140004f5e:	ff 25 d4 11 00 00    	jmp    QWORD PTR [rip+0x11d4]        # 0x140006138
   140004f64:	ff 25 1e 12 00 00    	jmp    QWORD PTR [rip+0x121e]        # 0x140006188
   140004f6a:	ff 25 c0 11 00 00    	jmp    QWORD PTR [rip+0x11c0]        # 0x140006130
   140004f70:	ff 25 b2 11 00 00    	jmp    QWORD PTR [rip+0x11b2]        # 0x140006128
   140004f76:	ff 25 a4 11 00 00    	jmp    QWORD PTR [rip+0x11a4]        # 0x140006120
   140004f7c:	ff 25 56 11 00 00    	jmp    QWORD PTR [rip+0x1156]        # 0x1400060d8
   140004f82:	ff 25 40 11 00 00    	jmp    QWORD PTR [rip+0x1140]        # 0x1400060c8
   140004f88:	ff 25 f2 11 00 00    	jmp    QWORD PTR [rip+0x11f2]        # 0x140006180
   140004f8e:	ff 25 74 11 00 00    	jmp    QWORD PTR [rip+0x1174]        # 0x140006108
   140004f94:	ff 25 d6 11 00 00    	jmp    QWORD PTR [rip+0x11d6]        # 0x140006170
   140004f9a:	ff 25 60 11 00 00    	jmp    QWORD PTR [rip+0x1160]        # 0x140006100
   140004fa0:	ff 25 72 11 00 00    	jmp    QWORD PTR [rip+0x1172]        # 0x140006118
   140004fa6:	ff 25 0c 11 00 00    	jmp    QWORD PTR [rip+0x110c]        # 0x1400060b8
   140004fac:	cc                   	int3
   140004fad:	cc                   	int3
   140004fae:	cc                   	int3
   140004faf:	cc                   	int3
   140004fb0:	cc                   	int3
   140004fb1:	cc                   	int3
   140004fb2:	cc                   	int3
   140004fb3:	cc                   	int3
   140004fb4:	cc                   	int3
   140004fb5:	cc                   	int3
   140004fb6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140004fbd:	00 00 00 
   140004fc0:	ff e0                	jmp    rax
   140004fc2:	cc                   	int3
   140004fc3:	cc                   	int3
   140004fc4:	cc                   	int3
   140004fc5:	cc                   	int3
   140004fc6:	cc                   	int3
   140004fc7:	cc                   	int3
   140004fc8:	cc                   	int3
   140004fc9:	cc                   	int3
   140004fca:	cc                   	int3
   140004fcb:	cc                   	int3
   140004fcc:	cc                   	int3
   140004fcd:	cc                   	int3
   140004fce:	cc                   	int3
   140004fcf:	cc                   	int3
   140004fd0:	cc                   	int3
   140004fd1:	cc                   	int3
   140004fd2:	cc                   	int3
   140004fd3:	cc                   	int3
   140004fd4:	cc                   	int3
   140004fd5:	cc                   	int3
   140004fd6:	66 66 0f 1f 84 00 00 	data16 nop WORD PTR [rax+rax*1+0x0]
   140004fdd:	00 00 00 
   140004fe0:	ff 25 c2 11 00 00    	jmp    QWORD PTR [rip+0x11c2]        # 0x1400061a8
   140004fe6:	40 55                	rex push rbp
   140004fe8:	48 83 ec 20          	sub    rsp,0x20
   140004fec:	48 8b ea             	mov    rbp,rdx
   140004fef:	48 8b 01             	mov    rax,QWORD PTR [rcx]
   140004ff2:	48 8b d1             	mov    rdx,rcx
   140004ff5:	8b 08                	mov    ecx,DWORD PTR [rax]
   140004ff7:	e8 2c ff ff ff       	call   0x140004f28
   140004ffc:	90                   	nop
   140004ffd:	48 83 c4 20          	add    rsp,0x20
   140005001:	5d                   	pop    rbp
   140005002:	c3                   	ret
   140005003:	cc                   	int3
   140005004:	40 55                	rex push rbp
   140005006:	48 8b ea             	mov    rbp,rdx
   140005009:	48 8b 01             	mov    rax,QWORD PTR [rcx]
   14000500c:	33 c9                	xor    ecx,ecx
   14000500e:	81 38 05 00 00 c0    	cmp    DWORD PTR [rax],0xc0000005
   140005014:	0f 94 c1             	sete   cl
   140005017:	8b c1                	mov    eax,ecx
   140005019:	5d                   	pop    rbp
   14000501a:	c3                   	ret
   14000501b:	cc                   	int3
