; use printf in C library

        extern  printf

        section .data
fmt     db      "%s", 10, 0     ; 10 is "\n", 0 is "\0"
msg     db      "printf haha", 0

        section .text
        global  main
main:
        push    rbp     ; set up stack frame

        mov     rdi, fmt
        mov     rsi, msg
        mov     rax, 0
        call    printf

        pop     rbp     ; restore stack
        mov     rax, 0  ; no error, return value
        ret
