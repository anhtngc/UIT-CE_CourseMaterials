		.data
string1: 	.asciiz "Chao ban! Ban la sinh vien nam thu may?\n"
string2:	.asciiz "Hihi, minh la sinh vien nam thu nhat ^~^\n"
string:		.asciiz ""
		.text
main:		li	$v0, 4
		la	$a0, string1
		syscall
		la	$a0, string2
		syscall
		
		li 	$v0, 8
		la	$a0, string
		li	$a1, 100
		syscall
		li	$v0, 4
		syscall
		
		li	$v0, 5
		syscall
		add	$t0, $v0, $zero
		li	$v0, 5
		syscall
		add	$t1, $v0, $zero
		add	$a0, $t1, $t0
		li	$v0, 1
		syscall