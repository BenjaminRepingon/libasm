section .text

global _ft_strncat

extern _ft_strlen

_ft_strncat:
	mov		r10, rdi
	call	_ft_strlen
	add		rdi, rax

cat_loop2:
	cmp		rdx, 0
	je		cat_ret
	cmp		byte [rsi], 0
	je		cat_ret
	mov		rax, [rsi]
	mov		[rdi], al
	inc		rdi
	inc		rsi
	dec		rdx
	jmp		cat_loop2

cat_ret:
	mov		byte [rdi], 0
	mov		rax, r10
	ret
