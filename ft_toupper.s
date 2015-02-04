section .text
global _ft_toupper

_ft_toupper:
	cmp		rdi, 'a'
	jb		toupper_ret
	cmp		rdi, 'z'
	ja		toupper_ret
	sub		rdi, 32
	mov		rax, rdi
	call	toupper_ret

toupper_ret:
	mov		rax, rdi
	ret
