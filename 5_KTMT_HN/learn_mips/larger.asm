# Print the larger

main:
	# get x
	addi $v0, $zero, 5 	# syscall 5: read int
	syscall
	add $t0, $zero, $v0

	# get y
	addi $v0, $zero, 5
	syscall
	add $t1, $zero, $v0

	# $t2 save larger, init is x
	# if x < y, $t2 save y
	add $t2, $zero, $t0

	# compare
	slt $t3, $t0, $t1	# $t3 = (x < y)
	beq $t3, $zero, print_larger
	add $t2, $zero $t1	# When x < y

print_larger:
	addi $v0, $zero, 1
	add $a0, $zero, $t2
	syscall

exit:
	addi $v0, $zero, 10	# syscall 10: exit
	syscall