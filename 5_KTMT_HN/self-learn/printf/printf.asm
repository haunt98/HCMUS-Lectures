; use printf in C library

        global  main
        extern  printf

        section .data
fmt     db      "%s", 10, 0
msg     db      "printf haha", 0

        section .text
main:
        mov     rdi, fmt
        mov     rsi, msg
        call    printf
        ret
