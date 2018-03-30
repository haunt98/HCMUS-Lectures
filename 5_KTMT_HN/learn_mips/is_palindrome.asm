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
	addi $t2, $t2, -2	# skip \n and \0

	# compare *A, *B
palin_loop:
	slt $t3, $t1, $t2	# $t3 = A < B
	beq $t3, $zero, yes_palin
	lb $t4, 0($t1)		# *A
	lb $t5, 0($t2)		# *B
	bne $t4, $t5, no_palin
	addi $t1, $t1, 1
	addi $t2, $t2, -1
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