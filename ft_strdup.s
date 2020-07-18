extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy

section .text
	global	_ft_strdup

_ft_strdup:
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	call	_malloc		;	str_out = malloc(ft_strlen);
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy	;	ft_strcpy(str_out, str);
	ret
