section .text
    global _ft_strlen

_ft_strlen:
    mov rax, 0

loop:
    cmp byte [rdi + rax], 0	;	if (*(s + len) == '\0')
    je  done				;	return (len);
    inc rax					;	len++;
    jmp loop

done:
    ret
