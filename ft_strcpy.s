section .text
    global _ft_strcpy

_ft_strcpy:
    mov 	rax, rdi
	push	rcx
    mov 	rcx, 0

loop:
    mov 	rdx, [rsi + rcx]
    mov 	[rax + rcx], rdx
    cmp 	byte [rsi + rcx], 0
    je  	done
    inc 	rcx
	jmp		loop

done:
	pop		rcx
    ret
