	move 	$a0, $s0
	move 	$a1, $s1
	move 	$a2, $s2
	move 	$a3, $s3
	jal 	proc_example
	
# L?y gi� tr? c?a (a + b) - (c + d) t? $v0
	move 	$a0, $v0
	li	$v0, 1
	syscall

# L?y gi� tr? c?a (a - b) + (c - d) t? $v1
	move 	$a0, $v1
	li	$v0, 1
	syscall

# K?t th�c ch??ng tr�nh
	li $v0, 10
	syscall

proc_example:
	addi	$sp, $sp, -4
	sw	$s0, 0($sp)
	
	add 	$t0, $a0, $a1
	add 	$t1, $a2, $a3
	sub 	$s0, $t0, $t1
	
	move 	$v0, $s0

# T�nh gi� tr? c?a (a - b) + (c - d)
	add 	$t2, $a0, $a1
	add 	$t3, $a2, $a3
	sub 	$s1, $t2, $t3

# Move gi� tr? c?a (a + b) - (c + d) v�o $v0
	move 	$v0, $s0

# Return gi� tr? c?a (a - b) + (c - d) th�ng qua $v1
	move 	$v1, $s1

	lw	$s0, 0($sp)
	addi	$sp, $sp, 4
	
	jr	$ra
