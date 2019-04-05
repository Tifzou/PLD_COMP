.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$42, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	popq	%rbp
	ret
