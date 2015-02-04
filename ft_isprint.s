%include "return.s"

section .text
global _ft_isprint

_ft_isprint:
	cmp		rdi, ' '
	jb		false
	cmp		rdi, '~'
	ja		false
	jmp		true

