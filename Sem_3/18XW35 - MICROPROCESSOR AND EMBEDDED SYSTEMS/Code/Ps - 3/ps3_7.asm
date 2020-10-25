
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

Mov Ax, 1
Mov Bx, 2
Mov Cx, 3
Mov Dx, 4
Mov SI, 5
Mov DI, 6

Start:
    Cmp Ax, Bx
    JG Bx_Cx 
    Mov Bp, Ax
    Mov Ax, Bx
    Mov Bx, Bp
    JMP Start
Bx_Cx:
    Cmp Bx, Cx
    JG Cx_Dx 
    Mov Bp, Bx
    Mov Bx, Cx
    Mov Cx, Bp
    JMP Start
Cx_Dx:
    Cmp Cx, Dx
    JG Dx_SI
    Mov Bp, Cx
    Mov cx, Dx
    Mov Dx, Bp
    JMP Start
Dx_SI:
    Cmp Dx, SI
    JG SI_DI
    Mov Bp, Dx
    Mov Dx, SI
    Mov SI, Bp
    JMP Start
SI_DI:
    Cmp SI, DI
    JG End 
    Mov Bp,SI
    Mov SI, DI
    Mov DI, Bp        
    JMP Start
End:    
ret


