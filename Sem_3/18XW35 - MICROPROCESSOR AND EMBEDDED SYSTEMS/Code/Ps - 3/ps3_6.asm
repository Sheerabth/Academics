
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

Mov Al, 0
Mov Bx, 1200
Mov Cx,0  
Mov DX,1250

jmp Start

Increment:
    Inc Cx
    INC BX
    JMP Continue

Start:   
    CMP Al,[BX]
    JE Increment
    INC BX 
    Continue:
    CMP Dx,Bx
    JG Start  

ret




