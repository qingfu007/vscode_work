	.file	"mstore.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	nop
	addq	$40, %rsp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 4.9.2"
