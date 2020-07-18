section .text
    global _ft_strcpy

_ft_strcpy:
    mov rax, rdi

loop:
    mov rdx, [rsi + rcx]	;	*(dst + i) = *(src + i);
    mov [rax + rcx], rdx
    inc rcx					;	i++;
    cmp byte [rsi + rcx], 0	;	if (*(src + i) == '\0')
    je  done
	jmp	loop

done:
    ret						;	return (dst);
