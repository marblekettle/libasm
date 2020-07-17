section .text
    global _ft_strcmp

_ft_strcmp:
	mov rax, 0
    mov rcx, 0
	mov rdx, 0
    jmp loop

loop:
	mov dh, byte [rdi + rcx]
	cmp dh, byte [rsi + rcx]
	jg	plus
	jl	minus
	cmp	rdx, 0
	je	equal
	inc	rcx
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
