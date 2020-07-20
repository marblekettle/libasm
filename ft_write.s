extern      ___error

section .text
    global  _ft_write

_ft_write:
    mov     rax, 0x2000004
    syscall
    jc      error			;	carry flag set when error occurs
    ret

error:
    push    rax				;	save rax
    call    ___error		;	sets rax to pointer
    pop     qword [rax]
	mov     rax, -1
    ret
