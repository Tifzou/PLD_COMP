int main()
{
    int a,b,c;
    b=3;

    c=4;

    a=6;

    return a;
}
/*	.file	"index.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	$3, -12(%rbp) #b<-3
	movl	$1, -8(%rbp) #c<-1

	movl	-12(%rbp), %edx # btemp<-b
	movl	-8(%rbp), %eax # ctemp<-c
	addl	%edx, %eax # ctemp<-btemp + ctemp
	movl	%eax, -4(%rbp) # a<-ctemp

	movl	-4(%rbp), %eax # return a

	popq	%rbp

	ret
 */