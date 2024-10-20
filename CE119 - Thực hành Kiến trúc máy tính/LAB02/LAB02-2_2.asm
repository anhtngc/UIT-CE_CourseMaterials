.data
.text
main:
	li 	$s2,0		# int sum = 0	
	addi	$s1, $s0, 5	# N = 5
	addi	$s0, $0, 1	# i = 1
loop:
	bgt $s0, $s1, endloop	# i > n, endloop
	add $s2, $s2, $s0	# i <= n, sum += i
	addi $s0, $s0, 1	# i += 1
	j loop
endloop:
EXIT:

	