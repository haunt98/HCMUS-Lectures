section .data   ; declaring constants
        msg db "Hello world", 10        ; 10 is newline

section .text   ; for code
        global _start
_start:
        ; write(1, msg, 13)
        mov rax, 1      ; system call 1 is write
        mov rdi, 1      ; 1 is stdout
        mov rsi, msg    ; address of string
        mov rdx, 13     ; number of bytes
        syscall         ; make os system call

        ; exit(0)
        mov rax, 60     ; system call 60 is exit
        mov rdi, 0      ; exit code 0
        syscall
