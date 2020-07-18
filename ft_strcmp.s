section .text
    global _ft_strcmp

_ft_strcmp:
	push	rcx
	push	rdx
	mov		rcx, 0
	mov		rdx, 0

loop:
	mov		dh, byte [rdi + rcx]
	cmp		dh, byte [rsi + rcx]
	jg		plus
	jl		minus
	inc		rcx
	cmp		rdx, 0
	jne		loop
	mov		rax, 0
	jmp		done

plus:
	mov		rax, 1
	jmp		done

minus:
	mov		rax, -1

done:
	pop		rdx
	pop		rcx
	ret
