.text
.global main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$!t9, %eax
	popq	%rbp
	ret
