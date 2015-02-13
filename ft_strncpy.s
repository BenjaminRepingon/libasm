section .text

extern	_ft_memcpy

global	_ft_strncpy

_ft_strncpy:
	call	_ft_memcpy
	ret
