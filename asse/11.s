assume cs:code,ds:data
data segment
    db 'welcome to masm!'
    db '................'
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov cx,8
    mov di,0
    copy:
        mov ax,[di]
        mov [di+16],ax
        add di,2
        loop copy

        mov ax,4c00h
        int 21h

code ends
end start
;关键点：一次拷贝两个字节
;寻址方式:
;常量寻址 【idata】
;[bx]表示内存地址
;[bx+idata]
;[bx+si]
;[bx+si+idata]
