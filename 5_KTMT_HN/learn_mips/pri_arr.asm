        .data
arr:
        .space 1024

        .text
main:
        # $t0 save len
        addi $v0, $zero, 5      # syscall read int
        syscall
        add $t0, $zero, $v0     # $v0 save read
        sll $t0, $t0, 2         # len *= 4

        # check if len > 1024
        slti $t3, $t0, 1024
        beq $t3, $zero, exit

        # INPUT
        # $t1 save pointer of arr
        la $t1, arr
        # $t2 save arr + len
        add $t2, $t1, $t0
loop_get_arr:
        slt $t3, $t1, $t2       # $t3 = p < arr + len
        beq $t3, $zero, loop_get_exit

        # get arr[i]
        addi $v0, $zero, 5
        syscall
        sw $v0, 0($t1)

        addi $t1, $t1, 4        # p += 4
        j loop_get_arr
loop_get_exit:

        # PRINT
        # $t1 save pointer of arr
        la $t1, arr
        # $t2 save arr + len
        add $t2, $t1, $t0
loop_pri_arr:
        slt $t3, $t1, $t2       # $t3 = p < arr + len
        beq $t3, $zero, loop_pri_exit

        # get arr[i]
        addi $v0, $zero, 1      # syscall print int
        lw $a0, 0($t1)          # $a0 is int to print
        syscall

        # print '\n'
        addi $v0, $zero, 11     # syscall print char
        addi $a0, $zero, 10     # 10 is '\n'
        syscall

        addi $t1, $t1, 4        # p += 4
        j loop_pri_arr
loop_pri_exit:

exit:
        addi $v0, $zero, 10
        syscall