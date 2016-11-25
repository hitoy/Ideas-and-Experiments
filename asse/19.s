assume cs:code
;9.1
code segment
    s:
    mov ax,bx
    mov si,offset s
    mov di,offset s0
    mov ax,[si]
    mov [di],ax
    s0:
        nop
        nop
code ends
end s
