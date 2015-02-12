section .text

global _ft_strcat

extern _ft_strlen

_ft_strcat:
	mov		r10, rdi
	call	_ft_strlen
	add		rdi, rax

cat_loop2:
	cmp		byte [rsi], 0
	je		cat_ret
	mov		rax, [rsi]
	mov		[rdi], al
	inc		rdi
	inc		rsi
	jmp		cat_loop2

cat_ret:
	mov		byte [rdi], 0
	mov		rax, r10
	ret
