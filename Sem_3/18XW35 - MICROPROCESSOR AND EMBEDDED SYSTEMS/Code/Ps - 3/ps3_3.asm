
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

Mov Ah, 10
Mov Al, 5
Mov Bl, Al
Mov Al, Ah
Mov Ah, Bl


ret




