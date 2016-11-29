;实验10
assume cs:code
code segment
    start:
        mov dh,8
        mov dl,3
        mov cl,2
        mov ax,data
        mov ds,ax
        mov si,0
        call show_str

        mov ax,4c00h
        int 21h
show_str:
        mov ax,0b800h
        mov es,ax
        
        ;计算开始写入显存的偏移地址
        ;160*dh+2*dl
        mov bx,0
        mov al,dh
        mov ah,160
        mul ah
        add bx,al
        ;
        mov al,dl
        mov ah,2
        mul ah
        add bx,al
        s:
            mov cx,ds:[si]
            mov es:[bx],cx
            mov es:[bx+1],al
            add bx,2
            inc si
            inc cx
            loop s
         ret
         ; = POP ip
code ends

data segment
    db 'Wel come to masm!',0
data ends
db 510-($-$$) dup (0)
db 055h,0aah
end start
