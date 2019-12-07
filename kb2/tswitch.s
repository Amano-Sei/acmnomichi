	.file	"tswitch.c"
	.text
	.globl	tswitch
	.type	tswitch, @function
tswitch:
.LFB23:
	.cfi_startproc
.L2:
	testl	%esi, %esi
	jle	.L6
	cmpl	$1, %edi
	jne	.L2
	movl	$10, (%rdx)
	ret
.L6:
	rep ret
	.cfi_endproc
.LFE23:
	.size	tswitch, .-tswitch
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
