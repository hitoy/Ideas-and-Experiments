assume cs:code

code segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    start:
        ;设置栈相关
        mov ax,cs
        add ax,32
        mov sp,32
        ;设置
        mov ax,0
        mov bx,0
        mov cx,8
        s:
        mov ax,cs:[bx]
        add bx,2
        push  ax
        loop s
        
        mov ax,4c00h
        int 21h
code ends
end start
