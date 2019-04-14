.text
	.global sum
	.type	sum, @function
sum:
	pushq	%rbp
	movq	%rsp, %rbp
.global main
	.type	 main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$5, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
	call sum
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
