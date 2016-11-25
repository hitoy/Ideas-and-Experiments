;9.1 2
;补全指令，使得jmp执行后，CS:IP指向程序的第一条指令
assume cs:code

data segment
    dd 12345678H
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov bx,0
    ;mov [bx],__
    ;mov [bx+2],__
    ;result
    mov [bx],bx
    mov [bx+2],cs
    jmp dword ptr ds:[0]
code ends
end start
