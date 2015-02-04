section .text
global _ft_strcat

extern _ft_strlen

_ft_strcat:
	cmp		rsi, 0
	je		strcat_ret
	call	_ft_strlen
	mov		r8, rdi
	add		r8, rax

strcat_cpy_s2_in_s1:
	mov		byte [r8], 0
	cmp		byte [rsi], 0
	je		strcat_ret
	mov		al, byte [rsi]
	mov		byte [r8], al
	inc		r8
	inc		rsi
	jmp		strcat_cpy_s2_in_s1

strcat_ret:
	mov		rax, rdi
	ret
