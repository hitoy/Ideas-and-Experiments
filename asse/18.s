assume cs:code,ds:data,ss:stack,es:table
;《汇编语言（第三版）》王爽 实验7

;16位CPU，一次最多只能操作2字节,16位，一个字，半个双字
;push操作的必须是一个字
data segment
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995'

    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1184300,2759000,3753000,4649000,5837000


    dw 3,7,9,13,28,38,120,220,476,778,1001,1442,2258,2783,4037,5635,8226
    dw 11542,14430,15257,17800
data ends

stack segment
    db 16 dup(0)
stack ends

table segment
    db 21 dup("year summ ne ?? ")
table ends

code segment
    start:
    ;数据段
    mov ax,data
    mov ds,ax
    ;栈段
    mov ax,stack
    mov ss,ax
    mov sp,10h
    ;附加段，table
    mov ax,table
    mov es,ax
    ;初始化copy个数
    mov cx,21
    ;初始化偏移量
    mov bx,0
    mov si,0

    s:
        ;year
        mov ax,ds:[bx]
        mov dx,ds:[bx+2]
        mov es:[bx],ax
        mov es:[bx+2],dx
        mov byte ptr es:[bx+4],' '
       ;summe 
        mov ax,ds:[bx+21*4]
        mov dx,ds:[bx+21*4+2]
        mov es:[bx+5],ax
        mov es:[bx+7],dx
        mov byte ptr es:[bx+9],' '
        ;person count
        push cx
        mov cx, ds:[si+42*4]
        mov es:[bx+10],cx
        mov byte ptr es:[bx+12],' '
        ;average
        div cx
        pop cx
        mov es:[bx+13],ax
        mov byte ptr es:[bx+15],' '
     loop s

    mov ax,4c00h
    int 21h
code ends
end start
