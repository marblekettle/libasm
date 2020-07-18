section .text
    global _ft_strcmp

_ft_strcmp:
	mov	rcx, 0
	mov	rdx, 0

loop:
	mov dh, byte [rdi + rcx]
	cmp dh, byte [rsi + rcx]
	jg	plus				;	if (*(s1 + i) > *(s2 + i)) return (1);
	jl	minus				;	if (*(s1 + i) < *(s2 + i)) return (-1);
	cmp	rdx, 0				;	if (*(s1 + i) == '\0') return (0);
	je	equal				;	(only checked if *s1 and *s2 equal '\0')
	inc	rcx					;	i++;
	jmp	loop

equal:
	mov rax, 0
	ret

plus:
	mov rax, 1
	ret

minus:
	mov rax, -1
	ret
