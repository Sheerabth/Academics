
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


org 100h

MOV AX,BX
MOV AX,0AAAAh
MOV AX,[BX]
MOV AX,[4]
MOV AX,[BX+SI]
MOV AX,[SI+4]
MOV AX,[BX+SI+4]


ret




