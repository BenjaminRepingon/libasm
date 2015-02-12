section .text
global _ft_strlen

_ft_strlen:
	mov			r8, rdi
	mov			rax, 0
	mov			rcx, -1
	; not			rcx
	cld
	repne scasb
	sub			rdi, r8
	dec			rdi
	mov			rax, rdi
	mov			rdi, r8
	ret
