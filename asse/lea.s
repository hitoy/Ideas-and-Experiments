assume cs:code,ds:data
;学习lea指令的使用
;用来确定数据在段内的偏移地址
;offset 是伪指令，在编译时确定
;lea 是硬指令，执行是确定
;只和相应段有关系
code segment
    start:
    mov ax,data
    mov ds,ax
    lea bx,adata
    mov bx,offset bdata
    mov ax,4c00h
    int 21h
code ends

data segment
    adata db 16 dup(0)
    bdata db 16 dup(0)
    cdata db 16 dup(0)
    ddata db 16 dup(0)
    edata db 16 dup(0)
    fdata db 16 dup(0)
    gdata db 16 dup(0)
data ends

end start
