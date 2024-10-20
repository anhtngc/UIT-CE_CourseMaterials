.data
prompt: .asciiz "Nhap mot so lon hon 50: "
error: .asciiz "So nhap vao phai lon hon 50. Vui long thu lai."
space: .asciiz " "
.text
.globl main
main:
    #In ra thong bao nhap
    li $v0, 4
    la $a0, prompt
    syscall

    #Nhap so bat ki
    li $v0, 5
    syscall
    move $t0, $v0  #Luu so do vao $t0

    #Kiem tra so vua nhap co lon hon 50 khong
    li $t5, 50
    ble $t0, $t5, error_exit

    #Kiem tra va in so nguyen to
    li $t1, 2  
    while:
        blt $t1, $t0, check_prime  #Neu $t1 < $t0 thi den kiem tra so nguyen to
        j exit

    check_prime:
        move $t2, $t1  
        li $t3, 2 
        sqrt:
            mul $t4, $t3, $t3  #$t4 = $t3 * $t3
            ble $t4, $t2, divide  #Neu $t4 <= $t2 thi tiep tuc chia
            j print_prime

        divide:
            rem $t4, $t2, $t3  #$t4 = $t2 mod $t3
            beqz $t4, not_prime  #Neu $t4 == 0 thì khong phai so nguyen to
            addi $t3, $t3, 1  #Tang $t3 len 1
            j sqrt

    print_prime:
        #In ra so nguyen to
        li $v0, 1
        move $a0, $t1
        syscall

        #In ra dau cach
        li $v0, 4
        la $a0, space
        syscall

        #Tiep tuc vong lap
        j not_prime

    not_prime:
        #Tang $t1 len 1 và tiep tuc vong lap
        addi $t1, $t1, 1
        j while

exit:
    li $v0, 10
    syscall

error_exit:
    #In ra thong bao loi và ket thuc chuong trinh
    li $v0, 4
    la $a0, error
    syscall
    j exit
