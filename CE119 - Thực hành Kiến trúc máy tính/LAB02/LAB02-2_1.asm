.data
.text
main:
	addi $s0, $0, 1		# i = 1
	addi $s1, $0, 2		# j = 2
	addi $t0, $0, 3		# g = 3
	addi $t1, $0, 4	# h = 4
	bne $s0, $s1, ELSE
IF:
	add $s2, $t0, $t1
	j EXIT
ELSE:
	sub $s2, $t0, $t1
EXIT: