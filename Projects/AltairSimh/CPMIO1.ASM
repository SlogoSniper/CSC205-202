; CP/M I/O Subroutines

; ASCII characters
CR              EQU     0DH     ; Carriage Return
LF              EQU     0AH     ; Line Feed
CTRLZ           EQU     1AH     ; Operator interrupt

; CP/M BDOS Functions
RCONF           EQU     1       ; Read CON: into (A)
WCONF           EQU     2       ; Write (A) to CON:

; CP/M BDOS Functions
RBOOT           EQU     0       ; Re-boot CP/M System
BDOS            EQU     5       ; System call entry
TPA             EQU     100H    ; Transient Program Area

                ORG     TPA     ; Assemble program for TPA

START:          LXI     SP,STAK ; Set up user's stack
START1:         CALL    CI      ; Input a console character
                CPI     CTRLZ   ; Operator interupt? 
                JZ      RBOOT   ; If yes, return to CP/M
                CALL    CO      ; If no, echo it and
                JMP     START1  ; loop

; Console character into register A masked to 7 bits
CI:             PUSH    B       ; Save registers
                PUSH    D
                PUSH    H
                MVI     C,RCONF ; READ function
                CALL    BDOS
                ANI     7FH     ; Mask to 7 bits
                POP     H       ; Restore registers
                POP     D
                POP     B
                RET

; Character in register A output to console
CO:             PUSH    B       ; Save registers
                PUSH    D
                PUSH    H
                MVI     C,WCONF ; SELECT function
                MOV     E,A     ; Character to E
                CALL    BDOS    ; Output to CP/M
                POP     H       ; Restore registers
                POP     D
                POP     B
                RET

; Set up stack space
                DS      64      ; 40H locations
STAK:           DB      0       ; Top of stack 

                END
