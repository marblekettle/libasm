extern      ___error

section .text
    global  _ft_read

_ft_read:
    mov     rax, 0x2000003
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

