		.data				
array1:		.space 12			#t?o 12 bytes b? nh?
		.text
__start:	la	$t0, array1		#t0 mang ??a ch? array1
		li	$t1,5			#t1 = 5
		sw	$t1, ($t0)		#array1[0] = t1
		li 	$t1,13			#t1 = 13
		sw	$t1, 4($t0)		#...t??ng t?
		li	$t1,-7
		sw	$t1, 8($t0)