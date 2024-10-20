	.data
Output1: .asciiz "Nhap vao so nguyen n: "
Output2: .asciiz "Day n so Fibonacci dau tien la: "
Space: .asciiz " "
f:.word 0		#khai báo m?ng f
	.text
main:
	li $v0, 4	#Xu?t thông tin c?a Output1
	la $a0, Output1
	syscall
	
	li $v0, 5	#nh?p s? nguyên n
	syscall
	move $t0, $v0
	
	li $v0, 4	#Xu?t thông tin c?a Output2
	la $a0, Output2
	syscall
	
	li $t4, 1
	
	sw $t4, f+0	#f[0] = 1
	sw $t4, f+4	#f[1] = 1
	
	li $t1, 1
	
	la $s0, f 	#L?u ??a ch? d vào $s0
	
loop:
	bgt $t1, $t0, end	#So sánh f[i] != 0 th?c hi?n continue
	lw $t5, ($s0)
	bne $t5, 0, continue
	lw $t6, -4($s0)		#giá tr? f[i - 1]
	lw $t7, -8($s0)		#giá tr? f[i - 2]
	add $t5, $t6, $t7	#$t5 = f[i - 1] + f[i - 2]
	sw $t5, ($s0) 		#l?u $t5 vào f[i]
continue:
	li $v0, 1	#xu?t f[i]
	lw $a0, ($s0)
	syscall
	
	li $v0, 4
	la $a0, Space
	syscall
	
	addi $t1, $t1, 1	#t?ng ??m
	addi $s0, $s0, 4	#t?ng ??a ch? f
	
	j loop		#nh?y v? vòng l?p
end:
	li $v0, 10
	syscall