	.data
array: .space 200
s1: .asciiz "\nNhap so luong phan tu: "
s2: .asciiz "\nNhap cac phan tu: "
s3: .asciiz " "
s4: .asciiz "\nMAX: "
s5: .asciiz "\nMIN: "
s6: .asciiz "\nSUM = "
s7: .asciiz "\nPhan tu thu: "
s8: .asciiz "INVALID."
.text
	li $v0, 4
	la $a0, s1
	syscall

	li $v0, 5
	syscall
	move $a1, $v0 # a1 : so luong phan tu

	la $s1, array #load add array len $s1
	sll $t0, $a1, 2
	add $t1, $s1, $t0 #Gioi han

	add $t0, $0, $s1
loop:
	slt $t2, $t0, $t1
	beq $t2, $0, MIN_MAX
	li $v0, 5
	syscall
	sw $v0, ($t0)
	addi $t0, $t0, 4
	j loop

MIN_MAX: 
	lw $s2, ($s1) #MAX
	lw $s3, ($s1) #MIN
	add $t0, $0, $s1
	addi $t0, $t0, 4

loop_2:
	slt $t2, $t0, $t1
	beq $t2, $0, print
	lw $t3, ($t0)
	slt $t4, $t3, $s3
	bne $t4, $0, MIN
	sgt $t4, $t3, $s2
	bne $t4, $0, MAX
	add $t0, $t0, 4
	j loop_2

MIN:
	add $s3, $0, $t3
	add $t0, $t0, 4
	j loop_2
	
MAX:
	add $s2, $0, $t3
	add $t0, $t0, 4
	j loop_2

print:
	li $v0, 4
	la $a0, s4
	syscall
	li $v0, 1
	la $a0, ($s2)
	syscall
	li $v0, 4
	la $a0, s5
	syscall
	li $v0, 1
	la $a0, ($s3)
	syscall

#Tong
	add $s0, $0, $0
	add $t0, $0, $s1
loop_3:
	slt $t2, $t0, $t1
	beq $t2, $0, print_sum
	lw $t3, ($t0)
	add $s0, $s0, $t3
	addi $t0, $t0, 4
	j loop_3

print_sum:
	li $v0, 4
	la $a0, s6
	syscall
	li $v0, 1
	la $a0, ($s0)
	syscall

#Nhap vao chi so va in ra
	li $v0, 4
	la $a0, s7
	syscall
	li $v0, 5
	syscall
	move $s0, $v0

	sge $t2, $s0, 0
	slt $t3, $s0, $a1
	bne $t2, $t3, invalid

	sll $t2, $s0, 2
	add $t3, $s1, $t2
	lw $t2, ($t3)
	li $v0, 1
	la $a0, ($t2)
	syscall
	j exit

invalid:
	li $v0, 4
	la $a0, s8
	syscall 

exit:
