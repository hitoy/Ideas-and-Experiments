;监测点14.2
assume cs:code

code segment
start:
    mov ax,10
    mov dx,ax
    shl ax,1
    mov cl,3
    shl dx,cl
    add ax,dx
code ends
end start
