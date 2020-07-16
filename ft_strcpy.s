section .text
    global _ft_strcpy

_ft_strcpy:
    mov rax, rdi
    mov rbx, 0
    jmp loop

loop:
    mov rcx, [rsi + rbx]
    mov [rax + rbx], rcx
    inc rbx
    cmp byte [rax + rbx], 0
    je  done

done:
    ret