extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy

section .text
	global	_ft_strdup

_ft_strdup:
	push	rdi			;	(store str, align stack)
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc		;	str_out = malloc(ft_strlen + 1);
	cmp		rax, 0
	je		error
	mov		rsi, rdi
	pop		rsi			;	(clear stack)
	mov		rdi, rax
	push	rax
	call	_ft_strcpy	;	ft_strcpy(str_out, str);
	pop		rax
	ret

error:
	pop		rdi			;	(clear stack if malloc returns null)
	ret
