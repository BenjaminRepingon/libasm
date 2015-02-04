section .text
global _ft_bzero

_ft_bzero:
bzero_loop:
	cmp		rsi, 0
	je		bzero_stop
	mov		byte [rdi + rsi - 1], 0
	dec		rsi
	jmp		bzero_loop
bzero_stop:
	ret
