org 100h     

mov ah, 1
int 21h
sub al, '0'
mov ah, 0
push ax  

mov ah, 1
int 21h
sub al, '0'
mov ah, 0
push ax 

pop bx
pop ax
mov cl, 10
mul cl
add bx, ax

call endl

mov cx, bx
mov bx, 0  

label:
    xor ax, ax
    call fibo
    push cx
    push bx
    call print_number     
    pop bx
    pop cx
    inc bx
    loop label
ret

fibo proc 
    cmp bl, 2
    jg do_calculation
    add ax, 1
    cmp bl, 0
    jnz not_eq
    mov ax, 0
    not_eq:
    ret
fibo endp

do_calculation proc
    dec bl
    call fibo
    inc bl
    
    sub bl, 2
    call fibo
    add bl, 2
    ret
do_calculation endp

print_number proc
    xor cx, cx
    mov bx, 10
    
.a: xor dx, dx
    div bx
    push dx
    inc cx
    test ax, ax
    jnz .a
.b:
    pop dx
    mov ah, 2
    add dx, 48
    int 21h
    loop .b
    
    mov ah, 2
    mov dx,' '    
    int 21h
    ret
print_number endp

endl proc 
    mov ah,2
    mov dl,0Ah
    int 21h
    mov ah,2
    mov dl,0Dh
    int 21h
    ret
endl endp
    




