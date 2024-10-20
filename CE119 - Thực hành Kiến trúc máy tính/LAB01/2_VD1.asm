	.data		#khai báo vùng nh? data
var1: 	.word	23	#khai báo bi?n ki?u word: var1 = 23
	.text		#khai báo vùng nh? text
__start:
	lw	$t0, var1	#$t0 l?u giá tr? var1
	li	$t1, 5		#$t1 = 5
	sw	$t1, var1	#var1 l?u giá tr? t1

