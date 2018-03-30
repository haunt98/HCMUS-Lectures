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

        # store result in $t0
        add $t0, $zero, $zero

        # $t1 is pointer to str
        la $t1, str

        # get sign (negative or positive)
        lb $t2, 0($t1)
        addi $t3, $zero, 1
        bne $t2, 45, sum_loop   # 45 is '-'
        addi $t3, $zero, -1
        addi $t1, $t1, 1        # skip '-'

sum_loop:
        lb $t2, 0($t1)          # load character in 1 byte
        slt $t4, $t2, 48        # check str[i] >= '0'
        bne $t4, $zero, exit
        slt $t4, $t2, 58        # check str[i] <= '9'
        beq $t4, $zero, exit

        # result = result * 10 + str[i] - '0'
        addi $t4, $zero, 10
        mult $t0, $t4           # result * 10
        mflo $t0                # get from LO

        addi $t2, $t2, -48      # str[i] - '0'
        add $t0, $t0, $t2
        addi $t1, $t1, 1
        j sum_loop

exit:
        # use sign
        mult $t0, $t3
        mflo $t0

        # print result
        add $v0, $zero, 1       # syscall print int
        add $a0, $zero, $t0
        syscall

        add $v0, $zero, 10      # syscall exit
        syscall
