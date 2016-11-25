;loop 指令 当cx≠0时，跳转标号，short跳转
;9.3
;补全指令，利用loop指令，实现在内存2000H中查找第一个值为0的字节，找到后，将它的偏移地址存放到dx中
;注意 loop会自动给cx-1
; cx = cx -1
; if (cx≠ 0) jmp

assume cs:code

code segment
    start:
    mov ax,2000h
    mov ds,ax
    mov bx,0
    s:
    mov cl,[bx]
    mov ch,0
    ;
    inc cx
    ;
    inc bx
    loop s

    ok:
    dec bx
    mov dx,bx
    mov ax,4c00h
    int 21h
code ends
end start
