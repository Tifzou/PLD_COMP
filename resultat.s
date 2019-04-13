.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$8, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
if0:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$8, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%edx, %eax
	jne else0
	movl	$2, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
if1:
	movl	-8(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	$3, -28(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	cmpl	%edx, %eax
	jne else1
	movl	$88, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif1
else1:
	movl	$43, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -8(%rbp)
endif1:
	movl	-8(%rbp), %eax
	movl	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	jmp endif0
else0:
	movl	$33, -44(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, -8(%rbp)
endif0:
	movl	-8(%rbp), %eax
	movl	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
