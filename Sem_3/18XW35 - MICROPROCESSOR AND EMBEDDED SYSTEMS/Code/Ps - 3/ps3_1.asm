
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

Mov [1100h], 10
Mov Bx, [1100h]
Mov Cx, Bx
Mov [1300h],Cx
Mov Dx, [1300h]

ret




