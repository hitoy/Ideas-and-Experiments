;nasm写法
start:
    mov ax,data
    mov es,ax
    mov ax,0b800h
    mov ds,ax
   
    ;内存彩色字符空间 0xB8000 - 0xBFFFF,共计2^15 32KB
    ;段地址:0xb800，偏移地址最大值:0x7fff

    ;一屏每行字符80个，25行，一屏共计2000字符
    ;每个字符占用一个字，两个字节，低8位ASCII码，高8位样式，则一屏占用内存4000 Byte ≈ 4KB
    ;由上，32KB的内存空间可以显示8屏的内容

    ;字体样式
    ;0 1 2 3 4 5 6 7
    ;B G R I B G R BL
    ;____  _ _____ _
    ;前景 高亮 背景 闪烁
    ; 绿字  01000000B = 0x40
    ; 绿底红字 00100100B = 0x24
    ; 白底篮子 10001110B = 0x8e

    ;每行空间
    ;由于每一行显示80个字符，显示每个字符占用2个字节，则每一行占用160(0xa0)个字节
    ;空间分布如下:
    ;1. 0x00 ~ 0x9f
    ;2. 0xa0 ~ 0x13f
    ;3. 0x140 ~ 0x1df

    ;上述字符串共有16个字符，水平局中左右各32个字符
    ;垂直局中，在第13行显示即可



    ;清空屏幕上原有的字符
    ;把所有相应内存写为0x00即可
    ;有32KB的空间需要写入，一次写入2B，则需要写入16K次 2**14 = 0100 0000 0000 0000B = 0x04000
    mov cx,0400h
    mov bx,0
    mov dx,41h
    clear:
    mov [ds:bx],dx
    add bx,2
    loop clear
    
    mov byte [ds:0],'a'
    ;获取开始写的偏移量
    ;空空间总个数为12*160+32*2 = 784
    mov bx,784
    mov si,0
    mov cx,010h
    mov dl,0h
    w:
    ;拷贝数据到ax
    ;mov byte al,[es:si]
    mov byte al,'a'
    ;写入显存空间
    mov byte [ds:bx],al
    ;写入样式
    mov byte [ds:bx+1],dl
    add bx,2
    inc si 
    loop w
    jmp $

data: db 'welcome to masm!'
times 510-($-$$) db 0
db 0x55,0xaa
