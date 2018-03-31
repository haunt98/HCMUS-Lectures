# Compute fibonaci
# $t0, $t1, ... between call is reset

        .data
msg_debug:
        .asciiz "DEBUG\n"

        .text
main:
        # get n
        addi $v0, $zero, 5      # syscall read int
        syscall
        add $a0, $zero, $v0

        jal fibo

        # print fibo(n)
        add $a0, $zero, $v0
        addi $v0, $zero, 1
        syscall

        # exit
        addi $v0, $zero, 10
        syscall

fibo:
        # base case
        slti $t0, $a0, 2        # $t0 = n < 2
        beq $t0, $zero, fibo_recursive
        addi $v0, $zero, 1
        jr $ra
fibo_recursive:
        # save to stack
        addi $sp, $sp, -16
        sw $ra, 12($sp)
        sw $a0, 8($sp)

        # $t1 to save fibo(n - 1)
        lw $t0, 8($sp)
        addi $a0, $t0, -1
        jal fibo
        add $t1, $zero, $v0
        sw $t1, 4($sp)          # $t1 will lose in next call

        # $t2 to save fibo(n - 2)
        lw $t0, 8($sp)
        addi $a0, $t0, -2
        jal fibo
        add $t2, $zero, $v0
        lw $t1, 4($sp)

        # fibo(n) = fibo(n - 1) + fibo(n - 2)
        add $v0, $t1, $t2

        # restore from stack
        lw $ra, 12($sp)
        lw $a0, 8($sp)
        addi $sp, $sp, 16
        jr $ra