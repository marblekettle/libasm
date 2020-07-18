extern      ___error

section .text
    global  _ft_write

_ft_write:
    mov     rax, 0x2000004
    syscall
    jc      error
    ret

error:
    push    rcx
    mov     rcx, rax
    call    ___error
    mov     [rax], rcx
    mov     rax, -1
    pop     rcx
    ret