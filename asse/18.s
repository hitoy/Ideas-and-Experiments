assumen cs:code,ds:data,ss:stack,es:table
;《汇编语言（第三版）》王爽 实验7

;16位CPU，一次最多只能操作2字节,16位，一个字，半个双字
data segment
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995'

    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1184300,2759000,3753000,4649000,5837000


    dw 3,7,9,13,28,38,120,220,476,778,1001,1442,2258,2783,4037,5635,8226
    dw 11542,14430,15257,17800
data ends
    dd 0,0,0,0
stack segment
    
stack ends


table segment
    db 21 dup("year summ ne ?? ")
table ends

code segment
    start:
    ;初始化段
    mov ax,data
    mov ds,ax

    mov ax,table
    mov es,ax

    mov ax,stack
    mov ss,ax
    mov sp,10h
    ;初始化copy个数
    mov cx,21
    ;初始化偏移量
    mov bx,0
    mov si,0

   s0:
        push cs
        mov cx,3
        s:
            mov ax,ds:[bx+si]
            mov es:[si],ax
            mov ax,ds:[bx+si]
            mov es:[si],ax
    


code ends
end start
