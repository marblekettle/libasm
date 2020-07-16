section .text
    global _ft_strcpy

_ft_strcpy:
    mov rax, rdi
    mov rcx, 0
    jmp loop

loop:
    mov rdx, [rsi + rcx]
    mov [rax + rcx], rdx
    inc rcx
    cmp byte [rax + rcx], 0
    je  done

done:
    ret