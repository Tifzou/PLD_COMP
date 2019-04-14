.text
.global main
	.type	 main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
if0:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$1, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	cmpl	%edx, %eax
	jne else0
	movl	$3, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
if1:
	movl	$1, -24(%rbp)
	movl	$2, -28(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	cmpl	%edx, %eax
	jne else1
	movl	$4, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif1
else1:
	movl	$7, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -8(%rbp)
if2:
	movl	$1, -40(%rbp)
	movl	$1, -44(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%edx, %eax
	jne endif2
	movl	$8, -48(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif2
else2:
endif2:
	jmp endif1
	jmp endif0
else0:
	movl	$2, -52(%rbp)
	movl	-52(%rbp), %eax
	movl	%eax, -8(%rbp)
endif0:
endif0:
	movl	-8(%rbp), %eax
	movl	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
