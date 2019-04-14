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
	movl	-8(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	$3, -28(%rbp)
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	cmpl	%edx, %eax
	jne else1
if2:
	movl	$1, -32(%rbp)
	movl	$2, -36(%rbp)
	movl	-32(%rbp), %edx
	movl	-36(%rbp), %eax
	cmpl	%edx, %eax
	jne else2
	movl	$4, -40(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif2
else2:
	movl	$7, -44(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, -8(%rbp)
if3:
	movl	$1, -48(%rbp)
	movl	$1, -52(%rbp)
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %eax
	cmpl	%edx, %eax
	jne endif3
	movl	$8, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp endif3
endif3:
	endif2:
	jmp endif1
else1:
	movl	$1, -60(%rbp)
	movl	-60(%rbp), %eax
	movl	%eax, -8(%rbp)
endif1:
	jmp endif0
else0:
	movl	$2, -64(%rbp)
	movl	-64(%rbp), %eax
	movl	%eax, -8(%rbp)
endif0:
	movl	-8(%rbp), %eax
	movl	%eax, -68(%rbp)
	movl	-68(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	movq	%rbp, %rsp
	popq	%rbp
	ret
