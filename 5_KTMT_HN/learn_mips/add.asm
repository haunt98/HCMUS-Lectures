# Add 2 int
#	input: $t0, $t1
#	output: $t2

main:
	# get 1st int
	addi $v0, $zero, 5 	# syscall 5: read int
	syscall
	add $t0, $zero, $v0

	# get 2nd int
	addi $v0, $zero, 5
	syscall
	add $t1, $zero, $v0

	# print sum
	add $a0, $t0, $t1	# use $s0 cause syscall use it
	addi $v0, $zero, 1	# syscall 1: print int
	syscall
