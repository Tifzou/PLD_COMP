.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$42, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbp
	ret