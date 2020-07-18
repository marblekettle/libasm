extern      ___error

section .text
    global  _ft_read

_ft_read:
    mov     rax, 0x2000003
    syscall
    jc      error			;	carry flag set when error occurs
    ret

error:
    push    rcx				;	reallign stack by 8 bytes
    mov     rcx, rax
    call    ___error		;	sets rax to pointer
    mov     [rax], rcx
    mov     rax, -1
    pop     rcx				;	clear stack
    ret
