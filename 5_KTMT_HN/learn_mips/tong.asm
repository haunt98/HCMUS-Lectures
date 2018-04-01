# Tinh tong tu 1...n

main:

	addi $v0, $zero, 5	# syscall read int
	syscall
	add $a0 ,$zero, $v0	# $a0 = n
	jal tong
	add $a0, $zero, $v0	# $a0 = 1 + 2 + ... + n
	add $v0, $zero, 1	# syscall print int
	syscall
	addi $v0, $zero, 10	# syscall exit
	syscall

# Ham tinh 1 + 2 + ... + n
# 	$a0 n
tong:
	add $v0, $zero, $zero	# $v0 = 0
	addi $t0, $zero, 1	# $t0 = 1
	addi $t1, $a0, 1	# $t1 = n + 1
tong_loop:
	slt $t2, $t0, $t1
	beq $t2, $zero, tong_exit	# neu $t0 >= n + 1
	add $v0, $v0, $t0	# $v0 += $t0
	addi $t0, $t0, 1	# $t0 += 1
	j tong_loop
tong_exit:
	jr $ra