;将data段每个单词的都一个字母改成大写字母
;分析，改成大写字母，把ASIIC码第5位改为0，其它位不变
;用and
assume cs:code,ds:data
data segment
    db '1. file         '
    db '2. edit         '
    db '3. search       '
    db '4. view         '
    db '5. options      '
    db '6. help         '
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov cx,6
    mov bx,3
    
    uppercase:
    mov al,[bx]
    and al,11011111B
    mov [bx],al
    add bx,16
    loop uppercase

    mov ax,4c00h
    int 21h
code ends
end start
