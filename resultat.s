.text
	.global sum
	.type	sum, @function
sum:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$10, -4(%rbp)
	movl	-4(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
endif0:
.global main
	.type	 main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$5, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	call sum
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
