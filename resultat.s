.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$5, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
if0:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$5, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%edx, %eax
	popq	%rbp
	ret
