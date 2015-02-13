%define		STD_OUT			1
%define		SYS_READ		0x2000003
%define		SYS_WRITE		0x2000004
%define		BUFF_SIZE		1024

section .text

global _ft_cat

_ft_cat:
	mov			r12, rdi
	mov			rsi, buff

cat_loop:
	mov			rax, SYS_READ
	mov			rdi, r12
	mov			rdx, BUFF_SIZE
	syscall
	jc			done

	cmp			rax, 0
	jle			done

	mov			rdx, rax
	mov			rax, SYS_WRITE
	mov			rdi, STD_OUT
	syscall

	jmp cat_loop

done:
	ret

section .bss
	buff				resb	BUFF_SIZE
