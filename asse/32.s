;call 指令
;把IP或CS和IP push到栈中，并跳转到标号
;call = push ip,jmp word ptr
;不能实现短跳转
; call 标号

assume cs:code

code segment
start:
    mov ax,0
    call s
    inc ax
    s:pop ax

code ends
end start
