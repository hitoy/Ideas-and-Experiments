;CMOS RAD读取时间
assume cs:code,ds:data,ss:stack
data segment
    db '2000-01-01 00:00:00'
data ends

stack segment
    db 160 dup(0)
stack ends

code segment
    start:
        ;data segment
        mov ax,data
        mov ds,ax
        ;stack segment
        mov ax,stack
        mov ss,ax
        mov sp,160
        mov bp,160
        ;读取数据
        mov cx,6
        ;port 987420
        ;year
        mov ax,9
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[2],ax
        pop ax
        pop ax
        ;month
        mov ax,8
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[5],ax
        pop ax
        pop ax
        ;day
        mov ax,7
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[8],ax
        ;hours
        mov ax,4
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[11],ax
        pop ax
        pop ax
        ;munites
        mov ax,2
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[14],ax
        pop ax
        pop ax
        ;second
        mov ax,0
        push ax
        call read
        push ax
        call bcd2ascii
        mov ds:[17],ax
        pop ax
        pop ax
        ;clear stack
        mov sp,16
        mov bp,sp
        ;
        mov ax,4c00h
        int 21h

     read:
         push bp
         mov bp,sp
         mov al,[bp+4]
         out 070h,al
         in al,071h
         mov ah,00
         pop bp
         ret
           
     bcd2ascii:
         push bp
         mov bp,sp
         mov al,[bp+4]
         mov ah,al
         mov cl,4
         shr al,cl
         add al,030h

         and ah,00001111B
         add ah,030h
         pop bp
         ret
code ends
end start
