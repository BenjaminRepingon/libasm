%include "return.s"

section .text
global _ft_isalpha

_ft_isalpha:
	cmp		rdi, 'A'
	jb		false
	cmp		rdi, 'z'
	ja		false
	cmp		rdi, 'Z'
	jbe		true
	cmp		rdi, 'a'
	jae		true
	jmp		false
