
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV al, 1
MOV Bl, 2
mov cl, 3

a db 3 dup(0)
LEA SI, a
mov a[0], al
mov a[1], bl
mov a[2], cl


lable1:
    mov dl, [si]
ret     




