assume cs:code,ds:data

data segment
    db 'BaSic'
    db 'iNfOrMaTioN'
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov cx,5
    mov bx,0

    upcase:
    mov al, [bx]
    and al,11011111B
    mov [bx],al
    add bx,1
    loop upcase
    mov cx,11

    lowercase:
    mov al,[bx]
    or al,00100000B
    mov [bx],al
    inc bx
    loop lowercase

    mov ax,4c00h
    int 21h
code ends
end start
;关键点: and和or的位运算
