
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

Mov Bx, 7000
Mov Cx, 0

Jmp Start

Increment:
    Add Bx, 1
    Inc Cx
    Cmp Bx, 7002
    Jge End

Start:
    Mov Dx, [Bx]
    Shr Dx,1
    Jnc Increment
    Add Bx, 1
    Cmp Bx, 7002
    Jl start 
End:
ret




