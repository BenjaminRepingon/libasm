section .text
global _ft_tolower

_ft_tolower:
	cmp		rdi, 'A'
	jb		tolower_ret
	cmp		rdi, 'Z'
	ja		tolower_ret
	add		rdi, 32
	mov		rax, rdi
	call	tolower_ret

tolower_ret:
	mov		rax, rdi
	ret
