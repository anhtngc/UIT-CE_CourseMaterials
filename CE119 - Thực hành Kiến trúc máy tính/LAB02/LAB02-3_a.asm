.data
kt: 		.byte
nhap: 		.asciiz "Nhap ki tu: "
truoc: 		.asciiz "\nKi tu lien truoc: "
sau: 		.asciiz "\nKi tu lien sau: "
So: 		.asciiz "\nKi tu nhap vao la chu so"
Thuong: 	.asciiz "\nKi tu nhap vao la chu thuong"
Hoa: 		.asciiz "\nKi tu nhap vao la chu hoa"
Loi: 		.asciiz "\nInvalid Type"
.text
	li $v0, 4
	la $a0, nhap
	syscall
	
	li $v0, 12
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, truoc
	syscall

	addi $a0, $t0, -1
	li $v0, 11
	syscall
	li $v0, 4
	la $a0, sau
	syscall
	addi $a0, $t0, 1
	li $v0, 11
	syscall
	li $t1, 48
	slt $t1, $t0, $t1
	bne $t1, $zero, Invalid
	li $t1, 58
	slt $t1, $t0, $t1
	beq $t1, $zero, ChuHoa
	li $v0, 4
	la $a0, So
	syscall
	j EXIT
ChuHoa:	
	li $t1, 65
	slt $t1, $t0, $t1
	bne $t1, $zero, Invalid
	li $t1, 91
	slt $t1, $t0, $t1
	beq $t1, $zero, ChuThuong
	li $v0, 4
	la $a0, Hoa
	syscall
	j EXIT
ChuThuong:
	li $t1, 97
	slt $t1, $t0, $t1
	bne $t1, $zero, Invalid
	li $t1,123
	slt $t1, $t0, $t1
	beq $t1, $zero, Invalid
	li $v0,4
	la $a0, Thuong
	syscall
	j EXIT
Invalid:
	li $v0, 4
	la $a0, Loi
	syscall
EXIT: