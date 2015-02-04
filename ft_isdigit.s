%include "return.s"

section .text
global _ft_isdigit

_ft_isdigit:
	cmp		rdi, '0'
	jb		false
	cmp		rdi, '9'
	ja		false
	jmp		true
