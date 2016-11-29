assume cs:code
code segment
start:
    mov al,0
    out 070h,al
    in al,71h
code ends
end start
