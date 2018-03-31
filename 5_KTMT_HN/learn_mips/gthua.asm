# Tinh giai thua n!

        .text
main:
        # read n
        addi $v0, $zero, 5
        syscall
        add $a0, $zero, $v0

        jal gthua

        # print n!
        add $a0, $zero, $v0
        addi $v0, $zero, 1
        syscall

        # exit
        addi $v0, $zero, 10
        syscall

gthua:
        # base case
        slti $t0, $a0, 2
        beq $t0, $zero, gthua_recursive
        addi $v0, $zero, 1
        jr $ra
gthua_recursive:
        # save to stack
        addi $sp, $sp, -8
        sw $ra, 4($sp)
        sw $a0, 0($sp)

        # (n - 1)! save in $t1
        addi $a0, $a0, -1
        jal gthua
        add $t1, $zero, $v0

        # n! = (n - 1)! x n
        lw $t0, 0($sp)
        mult $t1, $t0
        mflo $v0

        # restore from stack
        lw $ra, 4($sp)
        lw $a0, 0($sp)
        addi $sp, $sp, 8
        jr $ra