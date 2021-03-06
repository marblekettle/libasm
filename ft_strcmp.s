section .text
    global _ft_strcmp

_ft_strcmp:
	push	rcx
	push	rdx
	mov		rcx, 0

loop:
	mov		rax, 0
	mov		rdx, 0
	mov		al, byte [rdi + rcx]
	mov		dl, byte [rsi + rcx]
	sub		rax, rdx
	cmp		rax, 0
	jg		done
	jl		done
	inc		rcx
	cmp		rdx, 0
	jne		loop
	mov		rax, 0
	jmp		done

done:
	pop		rdx
	pop		rcx
	ret
