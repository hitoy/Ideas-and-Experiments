assume cs:code

code segment
    mov ax,1
    mov cx,10
    s:
    add ax,1
    loop s
 mov ax,4c00H
    int 21H
code ends
end
