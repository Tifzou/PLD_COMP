.text
.global main
	.type	 main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$1, -8(%rbp)
	movl	$1, -12(%rbp)
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -24(%rbp)
	movl	$1, -28(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -32(%rbp)
	movl	$2, -36(%rbp)
	movl	$3, -40(%rbp)
	movl	-36(%rbp), %edx
	movl	-40(%rbp), %eax
	imull	%edx, %eax
	movl	 %eax, -44(%rbp)
	movl	$4, -48(%rbp)
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	imull	%edx, %eax
	movl	 %eax, -52(%rbp)
	movl	-32(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	movl	 %eax, -56(%rbp)
	movl	$1, -60(%rbp)
	movl	-56(%rbp), %eax
	movl	-60(%rbp), %edx
	subl	%edx, %eax
	movl	 %eax, -64(%rbp)
	movl	$1, -68(%rbp)
	movl	-64(%rbp), %eax
	movl	-68(%rbp), %edx
	subl	%edx, %eax
	movl	 %eax, -72(%rbp)
	movl	$1, -76(%rbp)
	movl	$2, -80(%rbp)
	movl	-76(%rbp), %eax
	movl	-80(%rbp), %edx
	subl	%edx, %eax
	movl	 %eax, -84(%rbp)
	movl	$3, -88(%rbp)
	movl	-84(%rbp), %edx
	movl	-88(%rbp), %eax
	imull	%edx, %eax
	movl	 %eax, -92(%rbp)
	movl	-72(%rbp), %eax
	movl	-92(%rbp), %edx
	subl	%edx, %eax
	movl	 %eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
