# 'a' -> 'A'

        .text
main:
        # read char
        addi $v0, $zero, 12
        syscall

        # function
        add $a0, $zero, $v0     # $v0 contains char read
        jal toupper

        # print char
        add $a0, $zero, $v0
        addi $v0, $zero, 11
        syscall

        # exit
        addi $v0, $zero, 10
        syscall

toupper:
        addi $v0, $a0, -32
        jr $ra