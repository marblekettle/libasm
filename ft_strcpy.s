section .text
    global _ft_strcpy

_ft_strcpy:
    mov rax, rdi
    mov rcx, 0

loop:
    mov rdx, [rsi + rcx]	;	*(dst + i) = *(src + i);
    mov [rax + rcx], rdx
    cmp byte [rsi + rcx], 0	;	if (*(src + i) == '\0')
    je  done
    inc rcx					;	i++;
	jmp	loop

done:
    ret						;	return (dst);
