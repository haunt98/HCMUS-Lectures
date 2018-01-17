; Use C library
; compile with nasm -f elf64 hola.asm && gcc hola.o -no-pie

        global main
        extern puts

        section .text
main:
        mov rdi, msg    ; first argument
        call puts       ; puts(msg)
        ret             ; return from main back to C library wrapper

msg:
        db "Hola, mundo", 0     ; 0 is terminated string in C
