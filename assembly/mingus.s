	.file	"mingus.c"
 # GNU C17 (Rev2, Built by MSYS2 project) version 13.2.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 13.2.0, GMP version 6.3.0, MPFR version 4.2.0-p12, MPC version 1.3.1, isl version isl-0.26-GMP

 # warning: MPFR header version 4.2.0-p12 differs from library version 4.2.1.
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=generic -march=nocona -O2
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Hello World!\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp	 #,
	.seh_stackalloc	40
	.seh_endprologue
 # .\mingus.c:2: int main(){
	call	__main	 #
 # .\mingus.c:3:   puts("Hello World!");
	leaq	.LC0(%rip), %rcx	 #, tmp83
	call	puts	 #
 # .\mingus.c:4: }
	xorl	%eax, %eax	 #
	addq	$40, %rsp	 #,
	ret	
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 13.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
