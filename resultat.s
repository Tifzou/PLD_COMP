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
	jne else0
	movl	$3, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif0
else0:
	movl	$5, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
endif0:
	movl	-8(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
