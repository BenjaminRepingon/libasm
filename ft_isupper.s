%include "return.s"

section .text
global _ft_isupper

_ft_isupper:
	cmp		rdi, 'A'
	jb		false
	cmp		rdi, 'Z'
	jbe		true
	jmp		false
