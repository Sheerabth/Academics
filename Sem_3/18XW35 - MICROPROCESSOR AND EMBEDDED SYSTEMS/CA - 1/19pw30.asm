
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

include emu8086.inc

org 100h

; add your code here

;PRINT 'Enter the Sentence: '

;MOV Dx, 20
;CALL GET_STRING

MOV SI, 0


; checking for the first letter
MOV AL, [TEST_STRING]
CMP AL, 'a'
JL LOOP_1
SUB AL, 32 
MOV [TEST_STRING], AL    
JMP LOOP_1

; Lable for changing the letter from uppercase to lowercase
SUB_32:

    MOV AL, [TEST_STRING+SI+1]
    SUB AL, 32
    MOV [TEST_STRING+SI+1], AL

; Loop for iterating thru each letter
LOOP_1:
    INC SI
    MOV AL, [TEST_STRING+SI]
    CMP AL, 0
    JE END_LOOP  ; Ending the loop if it is a null character
    CMP AL, ' '  ; Checking if a letter is space  
    JE IF_LOWER 
    JMP END_IF:
    
    IF_LOWER:    ; Condition for checking if the letter is lowercase
        MOV AL, [TEST_STRING+SI+1]
        CMP AL, 'a'
        JGE IF  
    
    JMP END_IF
    IF:           ; Jumping if the char is space and lowercase
        JMP SUB_32          
    END_IF:
    
    JMP LOOP_1

END_LOOP:

; Printing the final string
PRINT 'Final sentence is: '
LEA SI, TEST_STRING
CALL PRINT_STRING


ret

TEST_STRING DB 'capitalize this test sentence', 0

DEFINE_GET_STRING
DEFINE_PRINT_STRING

END



