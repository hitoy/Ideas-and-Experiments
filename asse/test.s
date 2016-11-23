assume cs:code,ss:stack
stack segment
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
stack ends

code segment
start:
    mov ax,stack
    mov ss,ax
    mov ax,4h
    mov sp,ax

    mov cx,5h
    mov bx,20h
    s:
    push bx
    loop s

    mov ax,4c00h
    int 21h
code ends
end start



