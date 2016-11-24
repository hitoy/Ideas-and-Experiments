;将data中每个单词都改为大写字幕
assume cs:code,ds:data
data segment
db 'ibm             '
db 'dec             '
db 'dos             '
db 'vax             '
data ends

code segment
//内存中保存局部变量
    start:
        mov ax,data
        mov ds,ax
        mov cx,4
        mov bx,0
    s0:
        mov ds:[40h],cx
        mov cx,3
        mov si,0
    s:
        mov al,ds:[bx+si]
        and al,dfh
        mov ds:[bx+si],al
        inc si
        loop s

        add bx,16
        mov cx,ds:[40h]
        loop s0

    mov ax,4c00h
    int 21h

code ends
end start
