	.data
Output1: .asciiz "Nhap n: "
Output2: .asciiz "n! = "
	.text
main:
	la $a0, Output1		#Xu?t thông tin c?a Output1
	addi $v0, $0, 4
	syscall
	
	addi $v0, $0, 5		#nh?p n
	syscall
	
	addi $s0, $v0, 0	#l?u giá tr? n vào $s0
	
	addi $s1, $0, 1		#kh?i t?o $s1 = 1 (bi?n giai th?a)
	
	addi $t1, $0, 1		#kh?i t?o $t1 = 1 (bi?n ??m)
loop:
	mult $s1, $t1	#s1 * t1
	mflo $s1		#l?u giá tr? vào $s1
	addi $t1, $t1, 1	#t?ng bi?n ??m t1
	ble $t1, $s0, loop	#t1 <= n, th?c hi?n loop
	
	la $a0, Output2		#In ra thông báo k?t qu?
	addi $v0, $0, 4
	syscall
	
	addi $a0, $s1, 0	
	addi $v0, $0, 1
	syscall