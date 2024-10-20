.data
a: 	.asciiz "a = "
b: 	.asciiz "b = "
max: 	.asciiz "So lon hon la: "
tong: 	.asciiz "\na + b = "
hieu: 	.asciiz "\na - b = "
tich: 	.asciiz "\na * b = "
thuong: .asciiz "\na / b = "
du: 	.asciiz " du "
Loi: 	.asciiz "\nKhong the chia vi so chia = 0!"
.text
	li $v0, 4
	la $a0, a
	syscall

	li $v0, 5
	syscall
	move $t1, $v0
	
	li $v0, 4
	la $a0, b
	syscall
	li $v0, 5
	syscall
	move $t2, $v0
	li $v0, 4
	la $a0, max
	syscall
	li $v0, 1
	slt $t0, $t1, $t2
	bne $zero, $t0, So2
	move $a0, $t1
	syscall
	j TINH
So2:
	move $a0, $t2
	syscall
TINH:
	li $v0, 4
	la $a0, tong
	syscall
	
	li $v0, 1
	add $a0, $t1, $t2
	syscall
	
	li $v0, 4
	la $a0, hieu
	syscall
	
	li $v0,1
	sub $a0, $t1, $t2
	syscall

	li $v0, 4
	la $a0, tich
	syscall
	
	mult $t1,$t2
	li $v0, 1
	mflo $a0
	syscall

	li $v0,4
	bne $zero, $t2, Thuong
	la $a0, Loi
	syscall
	j EXIT
Thuong:
	la $a0, thuong
	syscall
	div $t1, $t2
	mflo $a0
	li $v0, 1
	syscall

	li $v0, 4
	la $a0, du
	syscall
	li $v0, 1
	mfhi $a0
	syscall
EXIT: