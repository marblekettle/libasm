extern      ___error

section .text
    global  _ft_read

_ft_read:
    cmp     rdi, 0
    jl      error
    cmp     rsi, 0
    je      error
    cmp     rdx, 0
    jl      error
    mov     rax, 0x2000003
    syscall
    jc      error
    ret

error:
    push    rax
    mov     r8, rax
    call    ___error
    mov     [rax], r8
    mov     rax, -1
    pop     r8
    ret

