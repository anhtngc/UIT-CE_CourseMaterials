		.data
string1: 	.asciiz "Print this.\n"		#khai b�o m?ng string
		.text
main:		li 	$v0,4			#truy?n tham s? 4 v�o v0
		la	$a0, string1		#in chu?i k� t? m� ??a ch? ???c l?u trong a0
		syscall

