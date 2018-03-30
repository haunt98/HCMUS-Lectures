# Check if string is palindrome, example "abcba"

	.data
str:
	.space 1024

str_yes_palindrome:
	.asciiz "Yes palindrome\n"

str_no_palindrome:
	.asciiz "No palindrome\n"

	.text
main:
	# Read string
	addi $v0, $zero, 8	# syscall read string
	la $a0, str		# buffer
	addi $a1, $zero, 1024	# length (include '\0')
	syscall

	# get A, str[0]
	la $t1, str

	# get B, str[len -1]
	la $t2, str
len_loop:
	lb $t3, 0($t2)		# load byte
	beq $t3, $zero, exit_len_loop
	addi $t2, $t2, 1
	j len_loop
exit_len_loop:
	addi $t2, $t2, -1	# skip '\0'
        lb $t3, 0($t2)
        bne $t3, 10, palin_loop # 10 is '\n'
        addi $t2, $t2, -1       # skip '\n'

	# get *A, *B
palin_loop:
	slt $t3, $t1, $t2	# $t3 = A < B
	beq $t3, $zero, yes_palin
	lb $t4, 0($t1)		# *A
	lb $t5, 0($t2)		# *B

        # skip if *A is space, punctuation
skip_a:
        beq $t4, 32, incre_a    # 32 is SPACE
        beq $t4, 33, incre_a    # 33 is '!'
        beq $t4, 34, incre_a    # 34 is '"'
        beq $t4, 39, incre_a    # 39 is '''
        beq $t4, 40, incre_a
        beq $t4, 40, incre_a
        beq $t4, 44, incre_a    # 44 is ','
        beq $t4, 45, incre_a
        beq $t4, 46, incre_a    # 46 is '.'
        beq $t4, 47, incre_a
        beq $t4, 58, incre_a    # 58 is ':'
        beq $t4, 59, incre_a    # 59 is ';'
        beq $t4, 63, incre_a    # 63 is '?'
        beq $t4, 91, incre_a
        beq $t4, 92, incre_a
        beq $t4, 93, incre_a
        beq $t4, 95, incre_a
        j skip_b
incre_a:
        addi $t1, $t1, 1        # A += 1
	slt $t3, $t1, $t2	# $t3 = A < B
	beq $t3, $zero, yes_palin
        lb $t4, 0($t1)          # get *A
        j skip_a

skip_b:
        beq $t5, 32, incre_b    # 32 is SPACE
        beq $t5, 33, incre_b    # 33 is '!'
        beq $t5, 34, incre_b    # 34 is '"'
        beq $t5, 39, incre_b    # 39 is '''
        beq $t5, 40, incre_b
        beq $t5, 40, incre_b
        beq $t5, 44, incre_b    # 44 is ','
        beq $t5, 45, incre_b
        beq $t5, 46, incre_b    # 46 is '.'
        beq $t5, 47, incre_b
        beq $t5, 58, incre_b    # 58 is ':'
        beq $t5, 59, incre_b    # 59 is ';'
        beq $t5, 63, incre_b    # 63 is '?'
        beq $t5, 91, incre_b
        beq $t5, 92, incre_b
        beq $t5, 93, incre_b
        beq $t5, 95, incre_b
        j lower_a
incre_b:
        addi $t2, $t2, -1       # B -= 1
	slt $t3, $t1, $t2       # $t3 = A < B
	beq $t3, $zero, yes_palin
        lb $t5, 0($t2)          # get *B
        j skip_b


lower_a:
        slt $t3, $t4, 65        # 65 is 'A'
        bne $t3, $zero, lower_b
        slt $t3, $t4, 91        # 90 is 'Z'
        beq $t3, $zero, lower_b
        addi $t4, $t4, 32       # A -> a, plus 32

lower_b:
        slt $t3, $t5, 65        # 65 is 'A'
        bne $t3, $zero, compare
        slt $t3, $t5, 91        # 90 is 'Z'
        beq $t3, $zero, compare
        addi $t5, $t5, 32       # B -> b, plus 32

compare:
	bne $t4, $t5, no_palin
        addi $t1, $t1, 1        # A += 1
	addi $t2, $t2, -1       # B -= 1
	j palin_loop

yes_palin:
	addi $v0, $zero, 4	# syscall print string
	la $a0, str_yes_palindrome
	syscall
	j exit
no_palin:
	addi $v0, $zero, 4
	la $a0, str_no_palindrome
	syscall
	j exit
exit:
	addi $v0, $zero, 10	# syscall exit
	syscall
