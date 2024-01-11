  .file	"my.s"
  .text
  .def	__main;	.scl	2;	.type	32;	.endef
  .globl	main
  .def	main;	.scl	2;	.type	32;	.endef
  .section .data
.Mssg:
  .ascii "HELLO WORLD!\0"
  .section .text
  .seh_proc main
main:
  subq $40,%rsp
  .seh_stackalloc 40
  .seh_endprologue
  call __main
  leaq .Mssg(%rip),%rcx
  call puts
  movq $420,%rax
  addq $40,%rsp
  ret
  .seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 13.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
