extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy

section .text
	global	_ft_strdup

_ft_strdup:
	push	rdi			;	(store str, align stack)
	call	ft_strlen
	mov		rdi, rax
	call	malloc		;	str_out = malloc(ft_strlen);
	pop		rsi			;	(clear stack)
	mov		rdi, rax
	call	ft_strcpy	;	ft_strcpy(str_out, str);
	ret
