section .text
    global _ft_strlen

_ft_strlen:
    mov rax, 0

loop:
    cmp byte [rdi + rax], 0
    je  done
    inc rax
    jmp loop

done:
    ret
