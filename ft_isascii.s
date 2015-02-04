%include "return.s"

section .text
global _ft_isascii

_ft_isascii:
	cmp		rdi, 0
	jb		false
	cmp		rdi, 127
	ja		false
	jmp		true
