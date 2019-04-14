.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
if0:
	movl	$1, -12(%rbp)
	movl	$2, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%edx, %eax
	jne endif0
	movl	$0, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif0
	movq	%rbp, %rsp
	popq	%rbp
	ret
