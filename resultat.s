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
	movl	$2, -32(%rbp)
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %eax
	imull	%edx, %eax
	movl	 %eax, -36(%rbp)
	movl	-8(%rbp), %edx
	movl	-36(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -40(%rbp)
	movl	$1, -44(%rbp)
	movl	-40(%rbp), %eax
	movl	-44(%rbp), %edx
	subl	%edx, %eax
	movl	 %eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
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
	movl %eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	-60(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
