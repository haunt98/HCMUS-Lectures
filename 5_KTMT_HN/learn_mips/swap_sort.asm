# $s0 -> i, $s1 -> j
# $a0 -> v[], $a1 -> n
sort:		# Save n ($a1) and $ra with stack
			addi $sp, $sp, -16
			sw $ra, 12($sp)
			sw $a1, 8($sp)
			sw $s0, 4($sp)
			sw $s1, 0($sp)
			add $s0, $zero, $zero 		# i = 0

for_i:		slt $t0, $s0, $a1 			# Check i < n
			beq $t0, $zero, for_i_exit	# If i >= n

			addi $s1, $s0, -1		# j = i - 1
for_j:		slt $t1, $s1, 0				# Check j >= 0
			bne $t1, $zero, for_j_exit	# If j < 0
			sll $t2, $s1, 2			# j * 4
			add $t2, $t2, $a0		# &v[j]
			lw $t3, 0($t2)			# v[j]
			lw $t4, 4($t2)			# v[j + 1]
			slt $t1, $t4, $t3		# Check v[j + 1] < v[j]
			beq $t1, $zero, for_j_exit

			# Call swap
			add $a1, $s1, $zero 		# Set j to argument
			jal swap

			addi $s1, $s1, -1		# j -= 1
			j for_j

for_j_exit:	addi $s0, $s0, 1			# i += 1
			j for_i

for_i_exit:	lw $s1, 0($sp)
			lw $s0, 4($sp)
			lw $a1, 8($sp)
			lw $ra, 12($sp)
			addi $sp, $sp, 20
			jr $ra

# $a0 -> v[], $a1 -> k
swap:		sll $t1, $a1, 2				# k * 4
			add $t1, $t1, $a0		# &v[k]
			lw $t0, 0($t1)			# v[k]
			lw $t2, 4($t1)			# v[k + 1]
			sw $t2, 0($t1)
			sw $t0, 4($t1)
			jr $ra
