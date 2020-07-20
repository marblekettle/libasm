extern      ___error

section .text
    global  _ft_read

_ft_read:
    mov     rax, 0x2000003
    syscall
    jc      error			;	carry flag set when error occurs
    ret

error:
	push    rax				;	save rax
    call    ___error		;	sets rax to pointer
	pop     qword [rax]		;	clear stack
    mov     rax, -1
    ret
