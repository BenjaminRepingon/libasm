section .text

global _ft_puts

extern _ft_strlen

_ft_puts:
	call	_ft_strlen
	mov		r8, rdi
	mov		r9, rax
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, r8
	mov		rdx, r9
	syscall

	cmp		rax, -1
	jne		puts_ok
	ret

puts_ok:
	mov		rax, 10
	ret
