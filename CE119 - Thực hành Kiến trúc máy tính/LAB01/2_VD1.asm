	.data		#khai b�o v�ng nh? data
var1: 	.word	23	#khai b�o bi?n ki?u word: var1 = 23
	.text		#khai b�o v�ng nh? text
__start:
	lw	$t0, var1	#$t0 l?u gi� tr? var1
	li	$t1, 5		#$t1 = 5
	sw	$t1, var1	#var1 l?u gi� tr? t1

