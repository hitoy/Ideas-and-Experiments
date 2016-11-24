;将data段中的每个单词的前4个字母改成大写
assume ds:data,cs:code,ss:stack
data segment
 db '1. display      '
 db '2. brows        '
 db '3. replace      '
 db '4. modify       '
data ends

stack segment
    dd 0,0,0,0
stack ends


code segment
    start:
        mov ax,data
        mov ds,ax
        mov ax,stack
        mov ss,ax
        mov sp,10h
        mov bx,3

        s0:
        push cx
        mov cx,4
        mov si,0
        s:
            mov al,[bx+si]
            and al,0dfh
            mov [bx+si],al
            inc si
        loop s
        pop cx
        add bx,16
        loop s0

code ends

end start
