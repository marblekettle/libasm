extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy

section .text
	global	_ft_strdup

_ft_strdup:
	call	_ft_strlen
	mov		rdi, rax
	call	_malloc		;	str_out = malloc(ft_strlen);
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy	;	ft_strcpy(str_out, str);
	ret
