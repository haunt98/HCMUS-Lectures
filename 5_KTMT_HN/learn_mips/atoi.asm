# String to int

        .data
str:
        .space 1024

        .text
main:
        # read string
        add $v0, $zero, 8       # syscall read string
        la $a0, str             # buffer
        add $a1, $zero, 1024    # length
        syscall

        # call atoi
        jal atoi

        # print result
        add $a0, $zero, $v0
        add $v0, $zero, 1       # syscall print int
        syscall

        # exit
        add $v0, $zero, 10      # syscall exit
        syscall

atoi:
        # store result in $v0
        add $v0, $zero, $zero

        # $t1 is pointer to str, init $a0
        add $t1, $zero, $a0

        # get sign (negative or positive)
        lb $t2, 0($t1)
        addi $t3, $zero, 1
        bne $t2, 45, atoi_sum_loop      # 45 is '-'
        addi $t3, $zero, -1
        addi $t1, $t1, 1        # skip '-'

atoi_sum_loop:
        lb $t2, 0($t1)          # load character in 1 byte
        slt $t4, $t2, 48        # check str[i] >= '0'
        bne $t4, $zero, atoi_exit
        slt $t4, $t2, 58        # check str[i] <= '9'
        beq $t4, $zero, atoi_exit

        # result = result * 10 + str[i] - '0'
        addi $t4, $zero, 10
        mult $v0, $t4           # result * 10
        mflo $v0                # get from LO

        addi $t2, $t2, -48      # str[i] - '0'
        add $v0, $v0, $t2
        addi $t1, $t1, 1
        j atoi_sum_loop

atoi_exit:
        # use sign
        mult $v0, $t3
        mflo $v0

        jr $ra