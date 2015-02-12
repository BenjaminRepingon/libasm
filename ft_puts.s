section .text

global _ft_puts

extern _ft_strlen

_ft_puts:
	cmp		rdi, 0
	je		puts_error
	call	_ft_strlen
	mov		r8, rdi
	mov		r9, rax
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, r8
	mov		rdx, r9
	syscall
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, new_line
	mov		rdx, 1
	syscall
	cmp		rax, -1
	jne		puts_ok
	ret

puts_ok:
	mov		rax, 10
	ret

puts_error:
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, error_msg
	mov		rdx, 7
	syscall
	jmp		puts_ok

section .data
	new_line db 10
	error_msg db "(null)", 10
