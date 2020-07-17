section .text
    global _ft_strcmp

_ft_strcmp:
	mov rax, 0
    mov rcx, 0
    jmp loop

loop:
	mov rdx, [rdi + rcx]
	cmp rdx, [rsi + rcx]
	jg	plus
	jl	minus
	cmp	rdx, 0
	je	equal

equal:
	mov rax, 0
	ret

plus:
	mov rax, 1
	ret

minus:
	mov rax, -1
	ret


4 and 0
100 and 000 = 000
100 and 001 = 000
