
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX,2
MOV BX,3
ADD AX,BX

MOV BX,DS:0200H
MOV AX,DS:0201H
ADD AX,BX
MOV DS:0203H,AX


DATA1 DB 2H
DATA2 DB 3H 
SUM DB ?

MOV AL,DATA1
MOV BL,DATA2
ADD AL,BL
MOV SUM,AL

MOV AX,2H
MOV BX,3H
MUL BX   

DATA3 DW 1001H
DATA4 DW 1002H
MOV AX,DATA3
MOV BX,DATA4
MUL BX

MOV AX,127
MOV BL,67
DIV BL 
     



ret




