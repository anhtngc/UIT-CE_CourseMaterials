	.data
prompt: .asciiz "Enter one number: "

	.text
main:   jal getInt
        move $s0, $v0
        jal showInt   # G?i th? t?c showInt v?i gi� tr? ?� nh?p + 1
        j exit

getInt: li $v0, 4
        la $a0, prompt
        syscall

        li $v0, 5
        syscall
        jr $ra

showInt: addi $a0, $s0, 1  # T?ng gi� tr? c?a s? ?� nh?p l�n 1
         li $v0, 1         # S? d?ng syscall ?? in gi� tr? ra m�n h�nh
         syscall
         jr $ra            # Tr? v? n?i g?i th? t?c

exit:
