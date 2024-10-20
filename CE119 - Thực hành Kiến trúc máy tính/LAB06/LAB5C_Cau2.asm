.data
promptN: .asciiz "Nhap mot so N lon hon 3: "
promptNum: .asciiz "Nhap so thu "
maxStr: .asciiz "\nSo lon nhat la: "
minStr: .asciiz "\nSo nho nhat la: "
error: .asciiz "So nhap vao phai lon hon 3. Vui long thu lai.\n"
space: .asciiz " "
.text
.globl main
main:
    #Nhap N
    inputN:
        li $v0, 4
        la $a0, promptN
        syscall

        li $v0, 5
        syscall
        move $t0, $v0  

        #Kiem tra so nhap vao co lon hon 3 khong
        li $t5, 3
        ble $t0, $t5, error_inputN
        j continue

    error_inputN:
        #In ra thong bao loi va nhap lai
        li $v0, 4
        la $a0, error
        syscall
        j inputN

    continue:
        #Khoi tao gia tri lon nhat và nho nhat
        li $t1, 0x00000000 
        li $t2, 0x7FFFFFFF  

        #Nhap N so
        li $t3, 1  
        while:
            bgt $t3, $t0, print_result  #Neu $t3 > $t0 thi in ket qua

            #In ra prompt
            li $v0, 4
            la $a0, promptNum
            syscall
            li $v0, 1
            move $a0, $t3
            syscall
            li $v0, 4
            la $a0, space
            syscall

            #Nhap so
            li $v0, 5
            syscall
            move $t4, $v0  #Luu so vao $t4

            #Cap nhat gia tri lon nhat và nho nhat
            bgt $t4, $t1, update_max
            blt $t4, $t2, update_min
            j next

        update_max:
            move $t1, $t4
            j next

        update_min:
            move $t2, $t4

        next:
            #Tang $t3 len 1 và tiep tuc vòng lap
            addi $t3, $t3, 1
            j while

    print_result:
        #In ra so lon nhat
        li $v0, 4
        la $a0, maxStr
        syscall
        li $v0, 1
        move $a0, $t1
        syscall

        #In ra so nho nhat
        li $v0, 4
        la $a0, minStr
        syscall
        li $v0, 1
        move $a0, $t2
        syscall

    exit:
        li $v0, 10
        syscall
