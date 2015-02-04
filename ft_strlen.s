section .text
global _ft_strlen

_ft_strlen:
	mov		r8, 0

strlen_loop:
	cmp		BYTE [rdi + r8], 0
	je		strlen_end
	inc		r8
	jmp		strlen_loop

strlen_end:
	mov		rax, r8
	ret
