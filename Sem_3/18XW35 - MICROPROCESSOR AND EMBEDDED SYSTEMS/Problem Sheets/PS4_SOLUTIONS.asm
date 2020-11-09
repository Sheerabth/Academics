
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
include emu8086.inc
org 100h


;QUES 1

;MOV AX,0
;MOV DX,10 
;MOV DI,offset arr  
;PRINT "Enter string:" 
;PRINTN
;CALL GET_STRING
;MOV SI,DI
;LOOP1:
;CMP [SI],0
;JZ OUTP:
;CMP [SI],'a'
;JE VOWEL
;CMP [SI],'A'
;JE VOWEL
;CMP [SI],'E'
;JE VOWEL
;CMP [SI],'e'
;JE VOWEL
;CMP [SI],'i'
;JE VOWEL
;CMP [SI],'I'
;JE VOWEL
;CMP [SI],'o'
;JE VOWEL
;CMP [SI],'O'
;JE VOWEL
;CMP [SI],'u'
;JE VOWEL
;CMP [SI],'U'
;JE VOWEL 
;INC SI
;JMP LOOP1
;VOWEL:
;INC AX
;INC SI
;JMP LOOP1
;
;OUTP:
;MOV SI,offset arr 
;PRINTN
;CALL PRINT_STRING
;PRINT "VOWELS - "
;CALL PRINT_NUM
;
;arr db 3 dup(0) 
;
;DEFINE_GET_STRING
;DEFINE_PRINT_STRING    
;DEFINE_PRINT_NUM
;DEFINE_PRINT_NUM_UNS
;
;END    


;QUES 2

;ST DB 'EXERCISE'
;MOV SI, OFFSET ST
;MOV DL, 0
;LOOP1:
;CMP [SI], 'I'
;JNE L1
;INC DL
;
;L1:
;INC SI
;CMP SI, 0108H
;JNE LOOP1
;
;END


;QUES 3

;MOV DI,offset a
;MOV DX,10
;CALL GET_STRING
;LOOP1:
;CMP [DI],0
;JZ OUTP
;CMP [DI],97
;JGE LABEL1
;INC DI
;JMP LOOP1
;LABEL1:
;CMP [DI],122
;JLE CAP
;INC DI
;JMP LOOP1
;CAP:      
;SUB [DI],32
;INC DI
;JMP LOOP1
;OUTP:
;MOV SI,offset a
;PRINTN
;CALL PRINT_STRING
;ret
;
;a db 10 dup(0)
;DEFINE_GET_STRING
;DEFINE_PRINT_STRING 


;QUES 4

;MOV DX, 20H
;PRINT 'ENTER A STRING :'
;MOV DI, 2000H
;CALL GET_STRING
;PRINTN
;
;PRINT 'THE OUTPUT STRING :'
;MOV SI, DI
;CALL PRINT_STRING
;
;;CALL PRINT_STRING
;MOV SI, 4000H
;
;LOOP:
;MOV AL, [DI]
;INC DI
;MOV [SI], AL
;INC SI
;CMP [DI], 00H
;JNE LOOP
;
;
;
;RET 
;DEFINE_GET_STRING
;DEFINE_PRINT_STRING


;QUES 5            

;MOV DI,offset a
;MOV DX,10 
;MOV BX,offset b
;CALL GET_STRING
;LOOP1:
;CMP [DI],0
;JZ OUTP
;MOV AL,[DI]
;MOV B.[BX],AL
;INC DI
;INC BX
;JMP LOOP1
;OUTP:
;ret
;a db 10 dup(0)
;b db 10 dup(0) 
;DEFINE_GET_STRING 


;QUES 6

;MOV DI,offset a
;MOV DX,10
;MOV BX,offset b
;CALL GET_STRING
;LOOP1:
;CMP [DI],0
;JZ STORE
;INC DI
;JMP LOOP1
;STORE:
;CMP DI,offset a
;JL OUTP
;MOV AL,[DI]
;MOV B.[BX],AL
;DEC DI
;INC BX
;JMP STORE
;OUTP:
;ret
;a db 10 dup(0)
;b db 10 dup(0)
;DEFINE_GET_STRING

ret




