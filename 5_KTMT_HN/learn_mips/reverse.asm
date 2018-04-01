# Nghich dao chuoi "1234" -> "4321"
#	$a0 str
#	$a1 from
#	$a2 to
reverse:
	# $t0 save A , init &str[from]
	add $t0, $a0, $a1
	# $t1 save B, init &str[to]
	add $t1, $a0, $a2
reverse_loop:
	# check A < B
	slt $t2, $t0, $t1
	beq $t2, $zero, reverse_exit

	# swap *A and *B
	lb $t3, 0($t0)
	lb $t4, 0($t1)
	sb $t4, 0($t0)
	sb $t3, 0($t1)

	addi $t0, $t0, 1	# A += 1
	addi $t1, $t1, -1	# B -= 1
	j reverse_loop
reverse_exit:
	jr $ra