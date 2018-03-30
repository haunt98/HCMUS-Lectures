# Calc A x B (B >= 0)

main:
	# get A, save in $t0
 	addi $v0, $zero, 5	# syscall read int
 	syscall
 	add $t0, $zero, $v0

 	# get B, save in $t1
 	addi $v0, $zero, 5
 	syscall
 	add $t1, $zero, $v0

 	# mult save in $t2
 	add $t2, $zero, $zero

 	# i save in $t3, init 0
 	add $t3, $zero, $zero

loop:
	slt $t4, $t3, $t1	# $t4 = i < B
	beq $t4, $zero, exit
	add $t2, $t2, $t0	# mult += A
 	addi $t3, $t3, 1	# i += 1
 	j loop

exit:
 	# print A x B
 	addi $v0, $zero, 1	# syscall print int
 	add $a0, $zero, $t2
 	syscall

 	addi $v0, $zero, 10	# syscall exit
 	syscall