global _ft_strdup

extern _ft_strlen
extern _malloc

_ft_strdup:
	call		_ft_strlen
	mov			r8, rdi
	mov			r9, rax
	mov			rdi, rax
	call		_malloc
	cld
	mov			rcx, r9
	mov			rdi, rax
	mov			rsi, r8
	rep movsb
	mov			byte [rdi], 0
	ret
