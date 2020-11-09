
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;QUES 1

;MOV AX, 22H
;MOV SI, 2000H
;MOV [SI], AX      
;INC AX
;INC SI
;MOV [SI], AX


;QUES 2

;MOV AH, 05H
;MOV AL, 06H
;MOV BH, AH
;MOV AH, AL
;MOV AL, BH
;MOV BH, 00


;QUES 3

;MOV AX, 1002H
;MOV BX, 2002H
;MOV SI, 0250H
;ADD AX, BX
;MOV [SI], AX
;ADD SI, 2      ;INCREMENTING SI
;MUL BX
;MOV [SI], AX
;ADD SI, 2
;DIV BX      
;MOV [SI], AX


;QUES 4

;MOV AX, 0AABBH
;MOV SI, 0300H
;
;LOOP1:
;
;MOV [SI], AX 
;ADD SI, 2H
;CMP SI, 0342H 
;JNE LOOP1


;QUES 5

;MOV SI, 2000H
;MOV [SI], 20
;MOV [SI+01H], 10
;MOV [SI+02H], 5
;
;MOV AX, [SI]
;SUB AX, [SI+01H]
;SUB AX, [SI+02H]


;QUES 6

;A DB 1H, 2H, 3H, 4H
;MOV SI, 3700H
;MOV AL, A[0] 
;MOV [SI], AL
;INC SI
;ADD AL, A[1]
;MOV [SI], AL
;INC SI
;ADD AL, A[2]
;MOV [SI], AL
;INC SI
;ADD AL, A[3]
;MOV [SI], AL


ret




