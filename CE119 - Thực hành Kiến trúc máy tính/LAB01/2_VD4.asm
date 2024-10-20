		.data
string1: 	.asciiz "Print this.\n"		#khai báo m?ng string
		.text
main:		li 	$v0,4			#truy?n tham s? 4 vào v0
		la	$a0, string1		#in chu?i kí t? mà ??a ch? ???c l?u trong a0
		syscall

