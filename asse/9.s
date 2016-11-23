assume cs:code,ds:data
    data segment
        db 'unIx'
        db 'foRk'
    data ends
    code segment
    start:
        mov al,ds:[0]
        mov bl,ds:[1]
        mov ax,4c00h
        int 21h
    code ends
end start
