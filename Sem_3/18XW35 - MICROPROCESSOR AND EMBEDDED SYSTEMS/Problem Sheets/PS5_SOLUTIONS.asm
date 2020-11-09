
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

INCLUDE 'EMU8086.INC'


;QUES 7

;CALL GET_STRING ; save value to DS:DI
;    mov  ah, 0Ah
;    int  21h  
;DEFINE_GET_STRING  
;MOV SI,2H       
; counting: 
;    MOv bx,00H 
;    cmp  [si], 'a'
;    je   count1 
;    cmp  [si], 'e'
;    je   count1
;    cmp  [si], 'i'
;    je   count1
;    cmp  [si], 'o'
;    je   count1 
;    cmp  [si], 'u'
;    je   count1
;    cmp bx,00h
;    je count2
;    inc  si   
;    loop counting  
; exit: 
;  .EXIT    
;  
; count1:  
;    MOV bx,01h
;    inc vowel 
;    inc  si 
;    cmp  [si],0Dh      
;    je   exit
;    loop counting 
; count2:
;    cmp [si],20h  ;blank space
;    jne incc 
;    inc  si 
;    cmp  [si],0Dh     
;    je   exit 
;    loop counting
; incc:  
;    inc  consonent 
;    inc  si  
;    cmp  [si],0Dh      
;    je   exit
;    loop counting 
;
;vowel  db ? 
;consonent db ?
;
;END 


;QUES 9

;DECIMAL TO BINARY
;MOV AX,6
;MOV SI,2000H
;MOV BX,2    
;
;LOOP:
;DIV BX
;MOV BYTE PTR [SI],DL  
;MOV AH,00
;INC SI
;CMP AX,1
;JNE LOOP
;MOV [SI],AX
;PRINT 'THE BINARY FORM IS: '
;           
;LOOP2:
;MOV AL,[SI]
;CALL PRINT_NUM
;DEC SI
;CMP SI,2000H
;JGE LOOP2


;DECIMAL TO HEXADECIMAL  - faulty for some values                  
;MOV AX, 193
;MOV SI, 2000H
;MOV BX, 16    
;CMP AX, 15
;JLE LOOP3
;
;
;LOOP:
;    DIV BX
;    MOV BYTE PTR [SI],DL 
;    MOV AH,00
;    INC SI
;    inc cx
;    CMP AL,00  
;    JNE LOOP
;    PRINT 'THE HEXADECIMAL FORM IS: '
;    
;    
;           
;LOOP2:
;    MOV AL,[SI]
;    CMP AL,9
;    JLE LOOP4 
;    ADD AL,55
;    MOV [SI],AL
;    CALL PRINT_STRING
;    JMP LOOP5
;
;LOOP4:
;    CALL PRINT_NUM
;
;LOOP5:
;    DEC SI
;    CMP SI,2000H
;    JGE LOOP2 
;    JMP EXIT
;
;LOOP3:
;    MOV [SI],AL
;    JMP LOOP2
;
;EXIT:
;    MOV DX,0000H
;
;RET
;  
;DEFINE_PRINT_NUM
;DEFINE_PRINT_NUM_UNS
;DEFINE_PRINT_STRING 

ret
;DEFINE_PRINT_NUM
;DEFINE_PRINT_NUM_UNS







