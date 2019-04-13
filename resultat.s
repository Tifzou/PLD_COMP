.text
	.global sum
	.type	sum, @function
sum:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%rdi, -4(%rbp)
	movl	%rsi, -8(%rbp)
	movl	$42, -12(%rbp)
	movl	-12(%rbp), %eax
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
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	$2, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -20(%rbp)
	call sum
	movl %eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
