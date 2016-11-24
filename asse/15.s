;将data中每个单词都改为大写字幕，利用栈保存暂存的数据
assume cs:code,ds:data,ss:stack
data segment
db 'ibm             '
db 'dec             '
db 'dos             '
db 'vax             '
data ends

stack segment
    dw 0,0,0,0,0,0,0,0
stack ends

code segment
    start:
        ;ds初始化
        mov ax,data
        mov ds,ax
        ;ss,sp初始化
        mov ax,stack
        mov ss,ax
        mov sp,10h
        mov bx,0 
        mov cx,4

        s0:
            push cx
            mov si,0
            mov cx,3
            s:
                mov al,[bx+si]
                and al,0dfh
                mov [bx+si],al
                inc si
                loop s
            add bx,16
            pop cx
            loop s0

         mov ax,4c00h
         int 21h

code ends

end start
