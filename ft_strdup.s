section .text
global _ft_strdup

extern _ft_strlen
extern _malloc

_ft_strdup:
	call		_ft_strlen
	inc			rax

	mov			r13, rdi
	mov			r14, rax

	mov			rdi, rax
	call		_malloc

	test		rax, rax
	je			dup_err

	cld
	mov			rcx, r14
	mov			rdi, rax
	mov			rsi, r13
	rep movsb
	mov			byte [rdi], 0
	ret

dup_err:
	ret
