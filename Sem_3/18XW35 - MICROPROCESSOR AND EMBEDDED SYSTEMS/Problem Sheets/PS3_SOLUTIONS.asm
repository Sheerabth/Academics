
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

include emu8086.inc
org 100h


;QUES 2

;MOV AX,10
;MOV BX,AX
;INC BX
;MUL BX
;MOV BX,2
;DIV BX


;QUES 3

;
;MOV SI, OFFSET A
;LOOP1:
;
;MOV AL, [SI]
;ADD [T], AL
;INC SI
;CMP SI, 11BH
;JNE LOOP1
; 
;ret
;A DB 10 DUP(1)
;T DB 0H


;QUES 4

;A DB 2H, 5H, 1H
;
;MOV AL, A[0]
;CMP AL, A[1]
;
;JGE GT     
;MOV AL, A[1]
;
;GT: 
;MOV BL, A[2]
;
;CMP AL, BL
;JGE MM
;
;MOV AL, A[2]
;
;MM:
;END


;QUES 5

;L1:
;MOV AL, 15
;MOV BL, 2
;DIV BL
;CMP AH, 0
;JNE L2
;PRINT 'EVEN NUMBER'
;JMP END
;
;L2:
;CMP AH, 1
;PRINT 'ODD NUMBER'
;
;END:
;END


;QUES 6

;MOV AX, 5
;SAL AX, 2
;MOV AX, 5
;SAR AX, 2


;QUES 7

;MOV AX, 1234H
;OR AX, 00FFH


;QUES 8

;MOV BX,0FFEFH
;AND BX,0101010101010101


;QUES 9

;MOV AX , NUM      
;ROL AX , 1        ; ROTATE BY 01 shifting bits
; 
;JC  DN             
;  
;PRINT 'POSITIVE'
;JMP EXIT
;  
;DN:    
;  PRINT 'NEGATIVE'
; 
;EXIT:
;ret 
;NUM DW -78


;QUES 10

;NUMS DW 6,7,4,1,8,9
;
;
;MOV BX,0
;MOV AX,[NUMS]
;MOV CX,5
;
;L:
;
;INC BX
;INC BX
;
;CMP AX,[NUMS+BX]
;
;JNC L2:
;
;MOV AX,[NUMS+BX]
;
;L2:
;LOOP L
;
;HLT


;QUES 11

;MOV AL, 3
;MOV BL, AL
;
;FACT:
;DEC BL
;MUL BL
;CMP BL, 1
;JNE FACT
;
;END


;QUES 13

;MOV BX, 0E000H ;source address
;MOV BP, 0B001H ;destination address
;loop_start: 
;    
;MOV AL, [BX]  
;MOV [BP], AX       
;CMP BX, 0E007H  
;JE loop_end     
;INC BX          
;INC BP  
;JMP loop_start:
;
;loop_end:
;END

RET

