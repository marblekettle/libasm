extern      ___error

section .text
    global  _ft_write

_ft_write:
    mov     rax, 0x2000004
    syscall
    jc      error			;	carry flag set when error occurs
    ret

error:
    push    rcx				;	save rcx
    mov     rcx, rax
    call    ___error		;	sets rax to pointer
    mov     [rax], rcx
    mov     rax, -1
    pop     rcx				;	clear stack
    ret
