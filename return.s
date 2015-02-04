%ifndef RETURN_BOOL
	%define RETURN_BOOL

false:
	mov		rax, 0
	ret

true:
	mov		rax, 1
	ret

%endif
