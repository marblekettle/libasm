extern      ___error

section .text
    global  _ft_write

_ft_write:
    mov     rax, 0x2000004
    syscall
    jc      error
    ret

error:
    push    r8
    mov     r8, rax
    call    ___error
    mov     [rax], r8
    mov     rax, -1
    pop     r8
    ret