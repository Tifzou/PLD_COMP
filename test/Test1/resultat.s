.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$42, -4(%rbp)
	movl	-4(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
