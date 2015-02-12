section .text

global _ft_memcmp

_ft_memcmp:
	mov			rcx, rdx
	repne cmpsb
	mov			al, byte[rdi]
	sub			al, byte[rsi]
	ret
