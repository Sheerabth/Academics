
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV ax, 15
MOV bx, 10
MOV cx, 20

CMP ax ,bx
JGE lable1

JMP lable2
    
    lable1:
        
        CMP ax, cx
        JGE a
        JMP c
    
    lable2:
        CMP bx, cx
        JGE b
        JMP c
        
a:
    MOV dx, ax
    JMP last

b:
    MOV dx, bx
    JMP last
    
c:
    MOV dx, cx
    JMP last
    
last:
        

end:
             
ret




