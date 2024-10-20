.model small
.data
    output1 db 10,13, 'Nhap n co hai chu so: $'
    output2 db 10,13, 'Day n so fibonacci dau tien la: 0 1 $'
    num dw ?
    a dw 0h
    b dw 01h
.code
    mov ax,@data
    mov ds,ax
    
    lea dx,output1
    mov ah,09h  ;In chuoi
    int 21h
    
    call nhap_fibonacci
    
    mov cx,num
    sub cx,02h
    
    lea dx,output2
    mov ah,09h
    int 21h
    
    loop1:
        mov ax,a
        add ax,b
        mov a,ax
        mov di,cx
        mov dx,ax
        call xuat_fibonacci
        mov ax,a
        xchg ax,b
        mov a,ax
        mov cx,di
        loop loop1
        
        mov ah, 4ch   
        int 21h
        
xuat_fibonacci proc near
        mov ax,0000h
        mov ax,dx
        mov bx,0010d
        mov cx,0000h
        
    loop_push:
        mov dx,0000h
        div bx
        push dx
        inc cx
        cmp ax,0000h
        jne loop_push
        
    loop_pop:
        pop dx
        add dx,0030h
        mov ah,02h
        int 21h
        loop loop_pop
        
        mov dl,' '
        mov al,02h
        int 21h
        
    ret
    xuat_fibonacci endp
  
nhap_fibonacci proc near
    mov ah,01h
    int 21h
    sub al,30h
    mov bl,al
    mov ah,01h
    int 21h
    sub al,30h
    mov ah,bl
    aad
    mov num,ax
    ret
    nhap_fibonacci endp
    



