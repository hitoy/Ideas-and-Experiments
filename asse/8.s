assume cs:code,ss:stack,ds:data
data segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
data ends

stack segment
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  
stack ends
    start:
    ;初始化栈段寄存器
    mov ax,stack
    mov ss,ax
    ;初始化栈偏移指针
    mov ax,32
    mov ax,data
    mov ds,ax
code segment


code ends

end start
