%include "return.s"

section .text
global _ft_islower

_ft_islower:
	cmp		rdi, 'a'
	jb		false
	cmp		rdi, 'z'
	jbe		true
	jmp		false
