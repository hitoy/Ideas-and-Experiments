;将data中每个单词都改为大写字幕
assume cs:code,ds:data
data segment
db 'ibm             '
db 'dec             '
db 'dos             '
db 'vax             '
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov bx,0
    mov cx,4
    s0:    
        mov dx,cx
        mov cx,3
        mov si,0
    s:
        mov al,[bx+si]
        and al,11011111B
        mov [bx+si],al
        inc si
        loop s
    
    add bx,16
    mov cx,dx
    loop s0

    mov ax,4c00h
    int 21h
    ; char s[0][16] = 'ibm....'
    ; int i,j;
    ;for(i=0;i<4;i++){
    ; for(j=0;j<3j++){
    ;   s[i][j] = s[i][j]&0xDF
    ;}
    ;}
code ends
end start
