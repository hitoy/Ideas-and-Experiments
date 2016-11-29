section text vstart=0x07c0

BOOTSEG     equ 0x07c0  
DISPLAYSEG  equ 0xb800 

_start:
        ;参数
        ;mov dh,8
        ;mov dl,3
        ;mov cl,0
        ;初始化数据地址
        mov ax,BOOTSEG
        mov ds,ax
        mov ax,DISPLAYSEG
        mov es,ax

        call show_str
        mov ax,4c00h
        int 21h
show_str:
        ;计算开始写入显存的偏移地址
        ;160*dh+2*dl
        ;mov al,dh
        ;mov ah,160
        ;mul ah
        ;add di,ax
        ;
        ;mov al,dl
        ;mov ah,2
        ;mul ah
        ;add di,ax

        mov cx,16
        mov si,data
        s:
           mov     al, [si]  
    mov     [es:di], al  
    inc   si  
    inc     di  
    mov byte    [es:di], 0x07  
    inc     di  
        loop s
        ret
data  db 'Welcome to masm!',0
times 510-($-$$) db 0
db 0x55,0xaa
