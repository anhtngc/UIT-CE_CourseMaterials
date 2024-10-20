	.data
prompt: .asciiz "Enter one number: "

	.text
main:   jal getInt
        move $s0, $v0
        jal showInt   # G?i th? t?c showInt v?i giá tr? ?ã nh?p + 1
        j exit

getInt: li $v0, 4
        la $a0, prompt
        syscall

        li $v0, 5
        syscall
        jr $ra

showInt: addi $a0, $s0, 1  # T?ng giá tr? c?a s? ?ã nh?p lên 1
         li $v0, 1         # S? d?ng syscall ?? in giá tr? ra màn hình
         syscall
         jr $ra            # Tr? v? n?i g?i th? t?c

exit:
