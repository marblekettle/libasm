section .text
    global _ft_strcpy

_ft_strcpy:
	push	rcx
    push    rdx
    mov 	rax, rdi
    mov 	rcx, 0
    mov     rdx, 0

loop:
    mov 	dl, byte [rsi + rcx]
    mov 	byte [rax + rcx], dl
    cmp 	byte [rsi + rcx], 0
    je  	done
    inc 	rcx
	jmp		loop

done:
    pop     rdx
	pop		rcx
    ret
