; input two 2 integers
; output sum

%include "asm_io.inc"

; initialize data is put in .data
segment .data

prompt1 db "Enter 1st number: ", 0 ; 0 is NULL terminator
prompt2 db "Enter 2nd number: ", 0
outmsg1 db "You entered ", 0
outmsg2 db "and ", 0
outmsg3 db ", sum is ", 0

; uninitialize data is put in .bss
segment .bss    ; block start by symbol

; store input with double word
input1 resd 1
input2 resd 1

; code is put in .text
segment .text
        global _asm_main
_asm_main:
        enter 0,0       ; setup routine
        pusha

        mov eax, prompt1
        call print_string

        call read_int
        mov [input1], eax

        mov eax, prompt2
        call print_string

        call read_int
        mov [input2], eax

        mov eax, [input1]
        add eax, [input2]
        mov ebx, eax

        dump_regs 1     ; print out register value
        dump_mem 2, outmsg1, 1  ; print out memory

; print result
        mov eax, outmsg1
        call print_string

        mov eax, [input1]
        call print_int

        mov eax, outmsg2
        call print_string

        mov eax, [input2]
        call print_int

        mov eax, outmsg3
        call print_string

        mov eax, ebx
        call print_int
        call print_nl   ; new line

        popa
        mov eax, 0      ; return back to C
        leave
        ret
