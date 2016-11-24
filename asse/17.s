;可以用来寻址的寄存器
;bx,bp,si,di
;bx和bp不能同时出现
;si和di不能同时出现
;bp的默认段地址是ss
;bx的默认段地址是ds

;寄存器可以分为普通寄存器reg和段寄存器sreg
;reg: ax,bx,cx,dx,al,ah,bl,bh,cl,ch,dl,dh,sp,bp,si,di
;sreg: cs,ds,es,ss
;div reg
;div 指令
;32位被除数 DXAX存放被除数，除数为16位 div reg/[reg] 结果 AX存放商，DX存放余数
;16位被除数 AX存放被除数，除数为8位     div reg/[reg] 结果AL存放商，AH存放余数

assume cs:code,ds:data

data segment
    dd 100001
    dw 100
    dw 0
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov ax,ds:[0]
    mov dx,ds:[2]
    div word ptr ds:[4]
    mov ds:[6],ax
    mov ax,4c00h
    int 21h
code ends

end start
