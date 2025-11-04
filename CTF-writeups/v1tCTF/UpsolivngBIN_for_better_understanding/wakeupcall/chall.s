
chall:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64
  401004:	48 83 ec 08          	sub    rsp,0x8
  401008:	48 8b 05 e9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fe9]        # 403ff8 <__gmon_start__@Base>
  40100f:	48 85 c0             	test   rax,rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	call   rax
  401016:	48 83 c4 08          	add    rsp,0x8
  40101a:	c3                   	ret

Disassembly of section .plt:

0000000000401020 <.plt>:
  401020:	ff 35 9a 2f 00 00    	push   QWORD PTR [rip+0x2f9a]        # 403fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 9c 2f 00 00    	jmp    QWORD PTR [rip+0x2f9c]        # 403fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
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

Disassembly of section .plt.sec:

0000000000401070 <puts@plt>:
  401070:	f3 0f 1e fa          	endbr64
  401074:	ff 25 56 2f 00 00    	jmp    QWORD PTR [rip+0x2f56]        # 403fd0 <puts@GLIBC_2.2.5>
  40107a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401080 <setbuf@plt>:
  401080:	f3 0f 1e fa          	endbr64
  401084:	ff 25 4e 2f 00 00    	jmp    QWORD PTR [rip+0x2f4e]        # 403fd8 <setbuf@GLIBC_2.2.5>
  40108a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000401090 <alarm@plt>:
  401090:	f3 0f 1e fa          	endbr64
  401094:	ff 25 46 2f 00 00    	jmp    QWORD PTR [rip+0x2f46]        # 403fe0 <alarm@GLIBC_2.2.5>
  40109a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004010a0 <read@plt>:
  4010a0:	f3 0f 1e fa          	endbr64
  4010a4:	ff 25 3e 2f 00 00    	jmp    QWORD PTR [rip+0x2f3e]        # 403fe8 <read@GLIBC_2.2.5>
  4010aa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

00000000004010b0 <_start>:
  4010b0:	f3 0f 1e fa          	endbr64
  4010b4:	31 ed                	xor    ebp,ebp
  4010b6:	49 89 d1             	mov    r9,rdx
  4010b9:	5e                   	pop    rsi
  4010ba:	48 89 e2             	mov    rdx,rsp
  4010bd:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  4010c1:	50                   	push   rax
  4010c2:	54                   	push   rsp
  4010c3:	45 31 c0             	xor    r8d,r8d
  4010c6:	31 c9                	xor    ecx,ecx
  4010c8:	48 c7 c7 f7 11 40 00 	mov    rdi,0x4011f7
  4010cf:	ff 15 1b 2f 00 00    	call   QWORD PTR [rip+0x2f1b]        # 403ff0 <__libc_start_main@GLIBC_2.34>
  4010d5:	f4                   	hlt
  4010d6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  4010dd:	00 00 00 

00000000004010e0 <_dl_relocate_static_pie>:
  4010e0:	f3 0f 1e fa          	endbr64
  4010e4:	c3                   	ret
  4010e5:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  4010ec:	00 00 00 
  4010ef:	90                   	nop

00000000004010f0 <deregister_tm_clones>:
  4010f0:	b8 10 40 40 00       	mov    eax,0x404010
  4010f5:	48 3d 10 40 40 00    	cmp    rax,0x404010
  4010fb:	74 13                	je     401110 <deregister_tm_clones+0x20>
  4010fd:	b8 00 00 00 00       	mov    eax,0x0
  401102:	48 85 c0             	test   rax,rax
  401105:	74 09                	je     401110 <deregister_tm_clones+0x20>
  401107:	bf 10 40 40 00       	mov    edi,0x404010
  40110c:	ff e0                	jmp    rax
  40110e:	66 90                	xchg   ax,ax
  401110:	c3                   	ret
  401111:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  401118:	00 00 00 00 
  40111c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401120 <register_tm_clones>:
  401120:	be 10 40 40 00       	mov    esi,0x404010
  401125:	48 81 ee 10 40 40 00 	sub    rsi,0x404010
  40112c:	48 89 f0             	mov    rax,rsi
  40112f:	48 c1 ee 3f          	shr    rsi,0x3f
  401133:	48 c1 f8 03          	sar    rax,0x3
  401137:	48 01 c6             	add    rsi,rax
  40113a:	48 d1 fe             	sar    rsi,1
  40113d:	74 11                	je     401150 <register_tm_clones+0x30>
  40113f:	b8 00 00 00 00       	mov    eax,0x0
  401144:	48 85 c0             	test   rax,rax
  401147:	74 07                	je     401150 <register_tm_clones+0x30>
  401149:	bf 10 40 40 00       	mov    edi,0x404010
  40114e:	ff e0                	jmp    rax
  401150:	c3                   	ret
  401151:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  401158:	00 00 00 00 
  40115c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401160 <__do_global_dtors_aux>:
  401160:	f3 0f 1e fa          	endbr64
  401164:	80 3d dd 2e 00 00 00 	cmp    BYTE PTR [rip+0x2edd],0x0        # 404048 <completed.0>
  40116b:	75 13                	jne    401180 <__do_global_dtors_aux+0x20>
  40116d:	55                   	push   rbp
  40116e:	48 89 e5             	mov    rbp,rsp
  401171:	e8 7a ff ff ff       	call   4010f0 <deregister_tm_clones>
  401176:	c6 05 cb 2e 00 00 01 	mov    BYTE PTR [rip+0x2ecb],0x1        # 404048 <completed.0>
  40117d:	5d                   	pop    rbp
  40117e:	c3                   	ret
  40117f:	90                   	nop
  401180:	c3                   	ret
  401181:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  401188:	00 00 00 00 
  40118c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401190 <frame_dummy>:
  401190:	f3 0f 1e fa          	endbr64
  401194:	eb 8a                	jmp    401120 <register_tm_clones>

0000000000401196 <__constructor__>:
  401196:	f3 0f 1e fa          	endbr64
  40119a:	55                   	push   rbp
  40119b:	48 89 e5             	mov    rbp,rsp
  40119e:	48 8b 05 8b 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e8b]        # 404030 <stdin@GLIBC_2.2.5>
  4011a5:	be 00 00 00 00       	mov    esi,0x0
  4011aa:	48 89 c7             	mov    rdi,rax
  4011ad:	e8 ce fe ff ff       	call   401080 <setbuf@plt>
  4011b2:	48 8b 05 67 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e67]        # 404020 <stdout@GLIBC_2.2.5>
  4011b9:	be 00 00 00 00       	mov    esi,0x0
  4011be:	48 89 c7             	mov    rdi,rax
  4011c1:	e8 ba fe ff ff       	call   401080 <setbuf@plt>
  4011c6:	48 8b 05 73 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e73]        # 404040 <stderr@GLIBC_2.2.5>
  4011cd:	be 00 00 00 00       	mov    esi,0x0
  4011d2:	48 89 c7             	mov    rdi,rax
  4011d5:	e8 a6 fe ff ff       	call   401080 <setbuf@plt>
  4011da:	bf 10 00 00 00       	mov    edi,0x10
  4011df:	e8 ac fe ff ff       	call   401090 <alarm@plt>
  4011e4:	90                   	nop
  4011e5:	5d                   	pop    rbp
  4011e6:	c3                   	ret

00000000004011e7 <__fini>:
  4011e7:	f3 0f 1e fa          	endbr64
  4011eb:	55                   	push   rbp
  4011ec:	48 89 e5             	mov    rbp,rsp
  4011ef:	58                   	pop    rax
  4011f0:	c3                   	ret
  4011f1:	0f 05                	syscall
  4011f3:	c3                   	ret
  4011f4:	90                   	nop
  4011f5:	5d                   	pop    rbp
  4011f6:	c3                   	ret

00000000004011f7 <main>:
  4011f7:	f3 0f 1e fa          	endbr64
  4011fb:	55                   	push   rbp
  4011fc:	48 89 e5             	mov    rbp,rsp
  4011ff:	48 83 c4 80          	add    rsp,0xffffffffffffff80
  401203:	48 8d 05 fe 0d 00 00 	lea    rax,[rip+0xdfe]        # 402008 <_IO_stdin_used+0x8>
  40120a:	48 89 c7             	mov    rdi,rax
  40120d:	e8 5e fe ff ff       	call   401070 <puts@plt>
  401212:	48 8d 45 80          	lea    rax,[rbp-0x80]
  401216:	ba e8 03 00 00       	mov    edx,0x3e8
  40121b:	48 89 c6             	mov    rsi,rax
  40121e:	bf 00 00 00 00       	mov    edi,0x0
  401223:	e8 78 fe ff ff       	call   4010a0 <read@plt>
  401228:	b8 00 00 00 00       	mov    eax,0x0
  40122d:	c9                   	leave
  40122e:	c3                   	ret

Disassembly of section .fini:

0000000000401230 <_fini>:
  401230:	f3 0f 1e fa          	endbr64
  401234:	48 83 ec 08          	sub    rsp,0x8
  401238:	48 83 c4 08          	add    rsp,0x8
  40123c:	c3                   	ret
