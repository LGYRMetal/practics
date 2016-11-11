	.file	"words.c"
	.globl	LETTER
	.section	.rodata
	.align 4
	.type	LETTER, @object
	.size	LETTER, 16
LETTER:
	.byte	116
	.byte	104
	.byte	105
	.byte	115
	.byte	119
	.byte	97
	.byte	116
	.byte	115
	.byte	111
	.byte	97
	.byte	104
	.byte	103
	.byte	102
	.byte	103
	.byte	100
	.byte	116
	.globl	WORDS
.LC0:
	.string	"this"
.LC1:
	.string	"two"
.LC2:
	.string	"fat"
.LC3:
	.string	"that"
	.data
	.align 4
	.type	WORDS, @object
	.size	WORDS, 16
WORDS:
	.long	.LC0
	.long	.LC1
	.long	.LC2
	.long	.LC3
	.section	.rodata
.LC4:
	.string	"%s\t"
.LC5:
	.string	"start: (%d, %d)\t"
.LC6:
	.string	"end: (%d, %d)"
	.text
	.globl	exists
	.type	exists, @function
exists:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	subl	$12, %esp
	pushl	8(%ebp)
	call	strlen
	addl	$16, %esp
	movl	%eax, -36(%ebp)
	cmpl	$4, -36(%ebp)
	jg	.L8
	movl	$0, -44(%ebp)
	jmp	.L3
.L7:
	movl	$0, -40(%ebp)
	jmp	.L4
.L5:
	movl	-40(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	-40(%ebp), %eax
	addl	%ecx, %eax
	addl	$LETTER, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	addl	$1, -40(%ebp)
.L4:
	cmpl	$3, -40(%ebp)
	jle	.L5
	movl	-40(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	-32(%ebp)
	call	strstr
	addl	$16, %esp
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	je	.L6
	movl	-44(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -24(%ebp)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$1, %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -16(%ebp)
	movl	-20(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	subl	$1, %eax
	movl	%eax, -12(%ebp)
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	$.LC4
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	pushl	-20(%ebp)
	pushl	-24(%ebp)
	pushl	$.LC5
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	pushl	$.LC6
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
.L6:
	addl	$1, -44(%ebp)
.L3:
	cmpl	$3, -44(%ebp)
	jle	.L7
.L8:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	exists, .-exists
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$4, %esp
	subl	$12, %esp
	pushl	$.LC0
	call	exists
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
