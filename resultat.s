.text
.global sum
	.type	 sum, @function
sum:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$2, -8(%rbp)
	movl	$3, -12(%rbp)
	movl	$1, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -24(%rbp)
	movl	-12(%rbp), %edx
	movl	-24(%rbp), %eax
	imull	%edx, %eax
	movl	 %eax, -28(%rbp)
	movl	-8(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
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
	call sum
	movl %eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
