section .text
    global _ft_strcmp

_ft_strcmp:
    mov rbx, 0                  ;   i = 0;
    jmp loop                    ;   while (s1[i] == s2[i]) {

loop:
    mov rax, 0                  ;   cmp = 0;
    mov rdx, 0                  ;
    mov ah, byte [rdi + rbx]    ;
    mov dh, byte [rsi + rbx]    ;
    cmp rax, rdx                ;   cmp = s1[i] - s2[i];
    inc rbx                     ;   i++;
    mov ch, byte [rdi + rbx]    ;
    mov cl, byte [rsi + rbx]    ;
    and ch, cl                  ;   if (s1[i] == 0 || s2[i] == 0)
    cmp ch, 0                   ;
    je  done                    ;   break ;
    cmp rax, 0                  ;   (s1[i] == s2[i])
    je  loop                    ;   }

done:
    ret                         ;   return (cmp);
