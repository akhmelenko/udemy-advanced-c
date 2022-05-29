	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"socket() error=%d (%s)\n"
.LC1:
	.string	"Socket %d created\n"
	.text
	.globl	SocketCreate
	.type	SocketCreate, @function
SocketCreate:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket@PLT
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	jne	.L2
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-1, %eax
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
.L3:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	SocketCreate, .-SocketCreate
	.section	.rodata
.LC2:
	.string	"127.0.0.1"
.LC3:
	.string	"connect() error=%d (%s)\n"
	.text
	.globl	Connect
	.type	Connect, @function
Connect:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movw	$2, -48(%rbp)
	leaq	.LC2(%rip), %rdi
	call	inet_addr@PLT
	movl	%eax, -44(%rbp)
	movl	-56(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons@PLT
	movw	%ax, -46(%rbp)
	leaq	-48(%rbp), %rcx
	movl	-52(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect@PLT
	cmpl	$-1, %eax
	jne	.L4
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
.L4:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	Connect, .-Connect
	.section	.rodata
.LC4:
	.string	"setsockopt() error=%d (%s)\n"
.LC5:
	.string	"send() error=%d (%s)\n"
.LC6:
	.string	"message sent"
	.text
	.globl	SocketSend
	.type	SocketSend, @function
SocketSend:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movl	%edx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$20, -48(%rbp)
	movq	$0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	movl	-68(%rbp), %eax
	movl	$16, %r8d
	movq	%rdx, %rcx
	movl	$21, %edx
	movl	$1, %esi
	movl	%eax, %edi
	call	setsockopt@PLT
	cmpl	$-1, %eax
	jne	.L9
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L8
.L9:
	movl	-72(%rbp), %eax
	movslq	%eax, %rdx
	movq	-80(%rbp), %rsi
	movl	-68(%rbp), %eax
	movl	$0, %ecx
	movl	%eax, %edi
	call	send@PLT
	movl	%eax, -52(%rbp)
	cmpl	$-1, -52(%rbp)
	jne	.L11
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L8
.L11:
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
.L8:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	SocketSend, .-SocketSend
	.section	.rodata
.LC7:
	.string	"recv() error=%d (%s)\n"
	.align 8
.LC8:
	.string	"message received size=%d, message=%s\n"
	.text
	.globl	SocketReceive
	.type	SocketReceive, @function
SocketReceive:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movl	%edx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$20, -48(%rbp)
	movq	$0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	movl	-68(%rbp), %eax
	movl	$16, %r8d
	movq	%rdx, %rcx
	movl	$20, %edx
	movl	$1, %esi
	movl	%eax, %edi
	call	setsockopt@PLT
	cmpl	$-1, %eax
	jne	.L15
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L14
.L15:
	movl	-72(%rbp), %eax
	movslq	%eax, %rdx
	movq	-80(%rbp), %rsi
	movl	-68(%rbp), %eax
	movl	$0, %ecx
	movl	%eax, %edi
	call	recv@PLT
	movl	%eax, -52(%rbp)
	cmpl	$-1, -52(%rbp)
	jne	.L17
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movq	%rbx, %rcx
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	jmp	.L14
.L17:
	movq	-80(%rbp), %rdx
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L14:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L19
	call	__stack_chk_fail@PLT
.L19:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	SocketReceive, .-SocketReceive
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$224, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	SocketCreate
	movl	%eax, -212(%rbp)
	movl	-212(%rbp), %eax
	movl	$12345, %esi
	movl	%eax, %edi
	call	Connect
	movq	$0, -208(%rbp)
	movq	$0, -200(%rbp)
	movq	$0, -192(%rbp)
	movq	$0, -184(%rbp)
	movq	$0, -176(%rbp)
	movq	$0, -168(%rbp)
	movq	$0, -160(%rbp)
	movq	$0, -152(%rbp)
	movq	$0, -144(%rbp)
	movq	$0, -136(%rbp)
	movq	$0, -128(%rbp)
	movq	$0, -120(%rbp)
	movq	$0, -112(%rbp)
	movq	$0, -104(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	leaq	-208(%rbp), %rcx
	movl	-212(%rbp), %eax
	movl	$200, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	SocketReceive
	movl	-212(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L22
	call	__stack_chk_fail@PLT
.L22:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
