	add $t1,$t2,$t3
	addi $t1,$t1,5
	sub $t1,$t2,$3
	lw $t1,4($t2) # $t2 = 0x10010000
	sw $t1,8($t2) #$t2 = 0x10010020
	J label
label: 
exit:
	slt $t1,$t2,$t3
