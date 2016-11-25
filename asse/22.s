;jcxz 当cx=0时，跳转 jcxz 标号
;9.2
;补全编程，利用jcxz,实现在内存2000H段中查找第一个值为0的字节，找到后，将它的偏移地址存在dx中

assume cs:code


code segment
    start:
    mov ax,2000H
    mov ds,ax
    mov bx,0
    s:
    ;四条指令
    mov ch,0
    mov cl,ds:[bx]
    jcxz ok
    inc bx
    ;
    jmp short s

    ok:
    mov dx,bx
    mov ax,4c00h
    int 21h

code ends
end start
