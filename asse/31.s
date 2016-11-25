;10.1补全程序，实现从内存1000:0000处开始指令
assume cs:code 

stack segment
    db 16 dup (0)
stack ends

code segment
start:
    mov ax,stack
    mov ss,ax
    mov sp,16
    ;mov ax,___
    mov ax,1000h
    push ax
    ;mov ax,_
    mov ax,0
    push ax
    retf
code ends
end start
