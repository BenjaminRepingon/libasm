section .text

global _ft_memset

_ft_memset:
	cmp		rdx, 0
	je		memset_ret
	mov		byte [rdi + rdx - 1], sil
	dec		rdx
	jmp		_ft_memset

memset_ret:
	mov		rax, rdi
	ret
