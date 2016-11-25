;9.1
;要使jmp执行后，CS:IP指向程序的第一条指令，填写data中的数据
assume cs:code,ds:data

data segment
db 000
data ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov bx,0
    jmp word ptr [bx+1]

code ends
end start
; 知识点: jmp short 标号： 段内短转移 -128-127偏移
; jmp near ptr 标号：段内近转移，-32768-32767
; jmp far ptr 标号：段内远转移,
; jmp 16位reg 段内转移
; jmp word ptr 段内转移
; jmp dword ptr 段间转移 高位段地址，地位偏移地址
