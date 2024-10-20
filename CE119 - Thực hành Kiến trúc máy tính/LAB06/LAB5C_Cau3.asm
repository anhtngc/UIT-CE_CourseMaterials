.data
a: .word 0
b: .word 0
c: .word 0
no_solution: .asciiz "Phuong trình vo nghiem"
input: .asciiz "Nhap lan luot cac he so a, b, c \n"
input_prompt: .asciiz " "
output_prompt: .asciiz "Nghiem cua phuong trinh la: "
.text
main:
	li $v0, 4
    	la $a0, input
    	syscall
    #Nhap he so a tu ban phim
    li $v0, 4
    la $a0, input_prompt
    syscall
    li $v0, 5
    syscall
    sw $v0, a

    #Nhap he so b tu ban phim
    li $v0, 4
    la $a0, input_prompt
    syscall
    li $v0, 5
    syscall
    sw $v0, b

    #Nhap he so c tu ban phim
    li $v0, 4
    la $a0, input_prompt
    syscall
    li $v0, 5
    syscall
    sw $v0, c

    #Tinh delta = b^2 - 4ac
    lw $t0, a
    lw $t1, b
    lw $t2, c
    mul $t3, $t1, $t1
    mul $t4, $t0, $t2
    li $t5, 4
    mul $t4, $t4, $t5
    sub $t6, $t3, $t4

    #Kiem tra delta
    bltz $t6, delta_negative
    beqz $t6, delta_zero
    j delta_positive

delta_negative:
    #In ra thong bao phuong trinh vo nghiem
    li $v0, 4
    la $a0, no_solution
    syscall
    j end

delta_zero:
    #Tinh va in ra nghiem kep x = -b / (2a)
    negu $t1, $t1
    li $t7, 2
    mul $t0, $t0, $t7
    div $t1, $t0
    mflo $t1
    li $v0, 4
    la $a0, output_prompt
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    j end

delta_positive:
    #Tinh va in ra hai nghiem phan biet x1, x2
    srl $t6, $t6, 1
    negu $t1, $t1
    li $t7, 2
    mul $t0, $t0, $t7
    add $t8, $t1, $t6
    div $t8, $t0
    mflo $t8
    sub $t9, $t1, $t6
    div $t9, $t0
    mflo $t9
    li $v0, 4
    la $a0, output_prompt
    syscall
    li $v0, 1
    move $a0, $t8
    syscall
    move $a0, $t9
    syscall
    j end

end:
    #Ket thuc chuong trinh
    li $v0, 10
    syscall
