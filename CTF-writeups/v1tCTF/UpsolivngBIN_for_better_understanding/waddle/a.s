
chall:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64
  401004:	48 83 ec 08          	sub    rsp,0x8
  401008:	48 8b 05 d1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd1]        # 403fe0 <__gmon_start__@Base>
  40100f:	48 85 c0             	test   rax,rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	call   rax
  401016:	48 83 c4 08          	add    rsp,0x8
  40101a:	c3                   	ret

Disassembly of section .plt:

0000000000401020 <.plt>:
  401020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 403ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 403ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  401030:	f3 0f 1e fa          	endbr64
  401034:	68 00 00 00 00       	push   0x0
  401039:	e9 e2 ff ff ff       	jmp    401020 <_init+0x20>
  40103e:	66 90                	xchg   ax,ax
  401040:	f3 0f 1e fa          	endbr64
  401044:	68 01 00 00 00       	push   0x1
  401049:	e9 d2 ff ff ff       	jmp    401020 <_init+0x20>
  40104e:	66 90                	xchg   ax,ax
  401050:	f3 0f 1e fa          	endbr64
  401054:	68 02 00 00 00       	push   0x2
  401059:	e9 c2 ff ff ff       	jmp    401020 <_init+0x20>
  40105e:	66 90                	xchg   ax,ax
  401060:	f3 0f 1e fa          	endbr64
  401064:	68 03 00 00 00       	push   0x3
  401069:	e9 b2 ff ff ff       	jmp    401020 <_init+0x20>
  40106e:	66 90                	xchg   ax,ax
  401070:	f3 0f 1e fa          	endbr64
  401074:	68 04 00 00 00       	push   0x4
  401079:	e9 a2 ff ff ff       	jmp    401020 <_init+0x20>
  40107e:	66 90                	xchg   ax,ax
  401080:	f3 0f 1e fa          	endbr64
  401084:	68 05 00 00 00       	push   0x5
  401089:	e9 92 ff ff ff       	jmp    401020 <_init+0x20>
  40108e:	66 90                	xchg   ax,ax
  401090:	f3 0f 1e fa          	endbr64
  401094:	68 06 00 00 00       	push   0x6
  401099:	e9 82 ff ff ff       	jmp    401020 <_init+0x20>
  40109e:	66 90                	xchg   ax,ax
  4010a0:	f3 0f 1e fa          	endbr64
  4010a4:	68 07 00 00 00       	push   0x7
  4010a9:	e9 72 ff ff ff       	jmp    401020 <_init+0x20>
  4010ae:	66 90                	xchg   ax,ax
  4010b0:	f3 0f 1e fa          	endbr64
  4010b4:	68 08 00 00 00       	push   0x8
  4010b9:	e9 62 ff ff ff       	jmp    401020 <_init+0x20>
  4010be:	66 90                	xchg   ax,ax

Disassembly of section .plt.sec:

00000000004010c0 <puts@plt>:
  4010c0:	f3 0f 1e fa          	endbr64
  4010c4:	ff 25 36 2f 00 00    	jmp    QWORD PTR [rip+0x2f36]        # 404000 <puts@GLIBC_2.2.5>
  4010ca:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004010d0 <fclose@plt>:
  4010d0:	f3 0f 1e fa          	endbr64
  4010d4:	ff 25 2e 2f 00 00    	jmp    QWORD PTR [rip+0x2f2e]        # 404008 <fclose@GLIBC_2.2.5>
  4010da:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004010e0 <strlen@plt>:
  4010e0:	f3 0f 1e fa          	endbr64
  4010e4:	ff 25 26 2f 00 00    	jmp    QWORD PTR [rip+0x2f26]        # 404010 <strlen@GLIBC_2.2.5>
  4010ea:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004010f0 <setbuf@plt>:
  4010f0:	f3 0f 1e fa          	endbr64
  4010f4:	ff 25 1e 2f 00 00    	jmp    QWORD PTR [rip+0x2f1e]        # 404018 <setbuf@GLIBC_2.2.5>
  4010fa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401100 <printf@plt>:
  401100:	f3 0f 1e fa          	endbr64
  401104:	ff 25 16 2f 00 00    	jmp    QWORD PTR [rip+0x2f16]        # 404020 <printf@GLIBC_2.2.5>
  40110a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401110 <alarm@plt>:
  401110:	f3 0f 1e fa          	endbr64
  401114:	ff 25 0e 2f 00 00    	jmp    QWORD PTR [rip+0x2f0e]        # 404028 <alarm@GLIBC_2.2.5>
  40111a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401120 <fgets@plt>:
  401120:	f3 0f 1e fa          	endbr64
  401124:	ff 25 06 2f 00 00    	jmp    QWORD PTR [rip+0x2f06]        # 404030 <fgets@GLIBC_2.2.5>
  40112a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401130 <fopen@plt>:
  401130:	f3 0f 1e fa          	endbr64
  401134:	ff 25 fe 2e 00 00    	jmp    QWORD PTR [rip+0x2efe]        # 404038 <fopen@GLIBC_2.2.5>
  40113a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401140 <exit@plt>:
  401140:	f3 0f 1e fa          	endbr64
  401144:	ff 25 f6 2e 00 00    	jmp    QWORD PTR [rip+0x2ef6]        # 404040 <exit@GLIBC_2.2.5>
  40114a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

0000000000401150 <_start>:
  401150:	f3 0f 1e fa          	endbr64
  401154:	31 ed                	xor    ebp,ebp
  401156:	49 89 d1             	mov    r9,rdx
  401159:	5e                   	pop    rsi
  40115a:	48 89 e2             	mov    rdx,rsp
  40115d:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  401161:	50                   	push   rax
  401162:	54                   	push   rsp
  401163:	45 31 c0             	xor    r8d,r8d
  401166:	31 c9                	xor    ecx,ecx
  401168:	48 c7 c7 85 13 40 00 	mov    rdi,0x401385
  40116f:	ff 15 63 2e 00 00    	call   QWORD PTR [rip+0x2e63]        # 403fd8 <__libc_start_main@GLIBC_2.34>
  401175:	f4                   	hlt
  401176:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  40117d:	00 00 00 

0000000000401180 <_dl_relocate_static_pie>:
  401180:	f3 0f 1e fa          	endbr64
  401184:	c3                   	ret
  401185:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  40118c:	00 00 00 
  40118f:	90                   	nop

0000000000401190 <deregister_tm_clones>:
  401190:	b8 58 40 40 00       	mov    eax,0x404058
  401195:	48 3d 58 40 40 00    	cmp    rax,0x404058
  40119b:	74 13                	je     4011b0 <deregister_tm_clones+0x20>
  40119d:	b8 00 00 00 00       	mov    eax,0x0
  4011a2:	48 85 c0             	test   rax,rax
  4011a5:	74 09                	je     4011b0 <deregister_tm_clones+0x20>
  4011a7:	bf 58 40 40 00       	mov    edi,0x404058
  4011ac:	ff e0                	jmp    rax
  4011ae:	66 90                	xchg   ax,ax
  4011b0:	c3                   	ret
  4011b1:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  4011b8:	00 00 00 00 
  4011bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004011c0 <register_tm_clones>:
  4011c0:	be 58 40 40 00       	mov    esi,0x404058
  4011c5:	48 81 ee 58 40 40 00 	sub    rsi,0x404058
  4011cc:	48 89 f0             	mov    rax,rsi
  4011cf:	48 c1 ee 3f          	shr    rsi,0x3f
  4011d3:	48 c1 f8 03          	sar    rax,0x3
  4011d7:	48 01 c6             	add    rsi,rax
  4011da:	48 d1 fe             	sar    rsi,1
  4011dd:	74 11                	je     4011f0 <register_tm_clones+0x30>
  4011df:	b8 00 00 00 00       	mov    eax,0x0
  4011e4:	48 85 c0             	test   rax,rax
  4011e7:	74 07                	je     4011f0 <register_tm_clones+0x30>
  4011e9:	bf 58 40 40 00       	mov    edi,0x404058
  4011ee:	ff e0                	jmp    rax
  4011f0:	c3                   	ret
  4011f1:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  4011f8:	00 00 00 00 
  4011fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401200 <__do_global_dtors_aux>:
  401200:	f3 0f 1e fa          	endbr64
  401204:	80 3d 7d 2e 00 00 00 	cmp    BYTE PTR [rip+0x2e7d],0x0        # 404088 <completed.0>
  40120b:	75 13                	jne    401220 <__do_global_dtors_aux+0x20>
  40120d:	55                   	push   rbp
  40120e:	48 89 e5             	mov    rbp,rsp
  401211:	e8 7a ff ff ff       	call   401190 <deregister_tm_clones>
  401216:	c6 05 6b 2e 00 00 01 	mov    BYTE PTR [rip+0x2e6b],0x1        # 404088 <completed.0>
  40121d:	5d                   	pop    rbp
  40121e:	c3                   	ret
  40121f:	90                   	nop
  401220:	c3                   	ret
  401221:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  401228:	00 00 00 00 
  40122c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401230 <frame_dummy>:
  401230:	f3 0f 1e fa          	endbr64
  401234:	eb 8a                	jmp    4011c0 <register_tm_clones>

0000000000401236 <__constructor__>:
  401236:	f3 0f 1e fa          	endbr64
  40123a:	55                   	push   rbp
  40123b:	48 89 e5             	mov    rbp,rsp
  40123e:	48 8b 05 2b 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e2b]        # 404070 <stdin@GLIBC_2.2.5>
  401245:	be 00 00 00 00       	mov    esi,0x0
  40124a:	48 89 c7             	mov    rdi,rax
  40124d:	e8 9e fe ff ff       	call   4010f0 <setbuf@plt>
  401252:	48 8b 05 07 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e07]        # 404060 <stdout@GLIBC_2.2.5>
  401259:	be 00 00 00 00       	mov    esi,0x0
  40125e:	48 89 c7             	mov    rdi,rax
  401261:	e8 8a fe ff ff       	call   4010f0 <setbuf@plt>
  401266:	48 8b 05 13 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e13]        # 404080 <stderr@GLIBC_2.2.5>
  40126d:	be 00 00 00 00       	mov    esi,0x0
  401272:	48 89 c7             	mov    rdi,rax
  401275:	e8 76 fe ff ff       	call   4010f0 <setbuf@plt>
  40127a:	bf 10 00 00 00       	mov    edi,0x10
  40127f:	b8 00 00 00 00       	mov    eax,0x0
  401284:	e8 87 fe ff ff       	call   401110 <alarm@plt>
  401289:	90                   	nop
  40128a:	5d                   	pop    rbp
  40128b:	c3                   	ret

000000000040128c <duck>:
  40128c:	f3 0f 1e fa          	endbr64
  401290:	55                   	push   rbp
  401291:	48 89 e5             	mov    rbp,rsp
  401294:	48 81 ec 10 01 00 00 	sub    rsp,0x110
  40129b:	48 8d 05 62 0d 00 00 	lea    rax,[rip+0xd62]        # 402004 <_IO_stdin_used+0x4>
  4012a2:	48 89 c6             	mov    rsi,rax
  4012a5:	48 8d 05 5a 0d 00 00 	lea    rax,[rip+0xd5a]        # 402006 <_IO_stdin_used+0x6>
  4012ac:	48 89 c7             	mov    rdi,rax
  4012af:	e8 7c fe ff ff       	call   401130 <fopen@plt>
  4012b4:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  4012b8:	48 83 7d f8 00       	cmp    QWORD PTR [rbp-0x8],0x0
  4012bd:	75 19                	jne    4012d8 <duck+0x4c>
  4012bf:	48 8d 05 49 0d 00 00 	lea    rax,[rip+0xd49]        # 40200f <_IO_stdin_used+0xf>
  4012c6:	48 89 c7             	mov    rdi,rax
  4012c9:	e8 f2 fd ff ff       	call   4010c0 <puts@plt>
  4012ce:	bf 01 00 00 00       	mov    edi,0x1
  4012d3:	e8 68 fe ff ff       	call   401140 <exit@plt>
  4012d8:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
  4012dc:	48 8d 85 f0 fe ff ff 	lea    rax,[rbp-0x110]
  4012e3:	be 00 01 00 00       	mov    esi,0x100
  4012e8:	48 89 c7             	mov    rdi,rax
  4012eb:	e8 30 fe ff ff       	call   401120 <fgets@plt>
  4012f0:	48 85 c0             	test   rax,rax
  4012f3:	75 25                	jne    40131a <duck+0x8e>
  4012f5:	48 8d 05 27 0d 00 00 	lea    rax,[rip+0xd27]        # 402023 <_IO_stdin_used+0x23>
  4012fc:	48 89 c7             	mov    rdi,rax
  4012ff:	e8 bc fd ff ff       	call   4010c0 <puts@plt>
  401304:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  401308:	48 89 c7             	mov    rdi,rax
  40130b:	e8 c0 fd ff ff       	call   4010d0 <fclose@plt>
  401310:	bf 01 00 00 00       	mov    edi,0x1
  401315:	e8 26 fe ff ff       	call   401140 <exit@plt>
  40131a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  40131e:	48 89 c7             	mov    rdi,rax
  401321:	e8 aa fd ff ff       	call   4010d0 <fclose@plt>
  401326:	48 8d 85 f0 fe ff ff 	lea    rax,[rbp-0x110]
  40132d:	48 89 c7             	mov    rdi,rax
  401330:	e8 ab fd ff ff       	call   4010e0 <strlen@plt>
  401335:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  401339:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
  40133e:	74 24                	je     401364 <duck+0xd8>
  401340:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  401344:	48 83 e8 01          	sub    rax,0x1
  401348:	0f b6 84 05 f0 fe ff 	movzx  eax,BYTE PTR [rbp+rax*1-0x110]
  40134f:	ff 
  401350:	3c 0a                	cmp    al,0xa
  401352:	75 10                	jne    401364 <duck+0xd8>
  401354:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  401358:	48 83 e8 01          	sub    rax,0x1
  40135c:	c6 84 05 f0 fe ff ff 	mov    BYTE PTR [rbp+rax*1-0x110],0x0
  401363:	00 
  401364:	48 8d 85 f0 fe ff ff 	lea    rax,[rbp-0x110]
  40136b:	48 89 c6             	mov    rsi,rax
  40136e:	48 8d 05 c2 0c 00 00 	lea    rax,[rip+0xcc2]        # 402037 <_IO_stdin_used+0x37>
  401375:	48 89 c7             	mov    rdi,rax
  401378:	b8 00 00 00 00       	mov    eax,0x0
  40137d:	e8 7e fd ff ff       	call   401100 <printf@plt>
  401382:	90                   	nop
  401383:	c9                   	leave
  401384:	c3                   	ret

0000000000401385 <main>:
  401385:	f3 0f 1e fa          	endbr64
  401389:	55                   	push   rbp
  40138a:	48 89 e5             	mov    rbp,rsp
  40138d:	48 83 ec 40          	sub    rsp,0x40
  401391:	48 8d 05 a9 0c 00 00 	lea    rax,[rip+0xca9]        # 402041 <_IO_stdin_used+0x41>
  401398:	48 89 c7             	mov    rdi,rax
  40139b:	e8 20 fd ff ff       	call   4010c0 <puts@plt>
  4013a0:	48 8b 15 c9 2c 00 00 	mov    rdx,QWORD PTR [rip+0x2cc9]        # 404070 <stdin@GLIBC_2.2.5>
  4013a7:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  4013ab:	be 50 00 00 00       	mov    esi,0x50
  4013b0:	48 89 c7             	mov    rdi,rax
  4013b3:	e8 68 fd ff ff       	call   401120 <fgets@plt>
  4013b8:	b8 00 00 00 00       	mov    eax,0x0
  4013bd:	c9                   	leave
  4013be:	c3                   	ret

Disassembly of section .fini:

00000000004013c0 <_fini>:
  4013c0:	f3 0f 1e fa          	endbr64
  4013c4:	48 83 ec 08          	sub    rsp,0x8
  4013c8:	48 83 c4 08          	add    rsp,0x8
  4013cc:	c3                   	ret


# main address: 0x401385
# duck address: 0x40128c