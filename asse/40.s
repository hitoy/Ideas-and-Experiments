assume cs:code

code segment
start:
    mov al,01001000b
    shl al,1
    ;shift left
    ;逻辑左移
    ;如果移动位数大于1，则必须放到cl中
    shr al,1
    ;逻辑右移动
    ;shl shr都是把最后一位植入到CF标志中
code ends
end start
