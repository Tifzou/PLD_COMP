.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$7, -4(%rbp)
	movl	$8, -8(%rbp)
	popq	%rbp
	ret
