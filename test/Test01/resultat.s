.text
.global main
	.type	 main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$42, -4(%rbp)
	movl	-4(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
