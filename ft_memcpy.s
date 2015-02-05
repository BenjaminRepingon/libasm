section .text

global _ft_memcpy

_ft_memcpy:
	cld
	mov			rax, rdi
	mov			rcx, rdx
	rep movsb
	ret
