; CP/M I/O Subroutines

; ASCII characters
CR              EQU     0DH             ; Carriage Return
LF              EQU     0AH             ; Line Feed
SQT             EQU     27H             ; Single Quote

; CP/M BDOS Functions
RCONF           EQU     1               ; Read CON: into A
WCONF           EQU     2               ; Write A to CON:
RBUFF           EQU     10              ; Read a console line

; CP/M Addresses
RBOOT           EQU     0               ; Re-boot CP/M system
BDOS            EQU     5               ; System call entry
TPA             EQU     100H            ; Transient Program Area

                ORG     TPA             ; Assemble program for TPA

START           LXI     SP,STAK         ; Set up user's stack
START1:         CALL    CCRLF           ; Start a new line
                LXI     H,SINON         ; with sign-on message
                CALL    COMSG
START2:         CALL    TWOCR           ; Double space lines
                CALL    SPMSG           ; Prompt for test
                DB      'Waiting for string',CR,LF,0
                CALL    GETYN
                JNZ     START3          ; Got a "NO"
                CALL    SPMSG           ; Got a "YES"
                DB      LF,'YOUR ANSWER WAS "YES!"',0
                JMP     START2
START3:         CALL    SPMSG
                DB      LF,'YOU SAID "NO!"',0
                JMP     START2

SINON:          DB      'Remove Vowels from strings with this tool!',CR,LF,0

; Console character into register A masked to 7 bits
CI:             PUSH    B               ; Save registers
                PUSH    D
                PUSH    H        
                MVI     C,RCONF         ; Read function
                CALL    BDOS
                ANI     7FH             ; Mask to 7 bits
                POP     H               ; Restore registers
                POP     D
                POP     B
                RET

; Character in register A output to console
CO:             PUSH    B               ; Save registers
                PUSH    D
                PUSH    H
                MVI     C,WCONF         ; Select function
                MOV     E,A             ; Character to E
                CALL    BDOS            ; Output by CP/M
                POP     H               ; Restore registers
                POP     D
                POP     B
                RET

; Print two lines by calling CCRLF twice
TWOCR:          CALL    CCRLF

; Carriage Return, Line Feed to console
CCRLF:          MVI     A,CR
                CALL    CO
                MVI     A,LF
                JMP     CO

; Message pointed to by HL out to console
COMSG:          MOV     A,M             ; Get a character
                ORA     A               ; Zero is the terminator
                RZ                      ; Return on zero
                CALL    CO              ; else output the character
                INX     H               ; point to the next one
                JMP     COMSG           ; and continue

; Input console message into buffer
CIMSG:          PUSH    B               ; Save registers
                PUSH    D
                PUSH    H
                LXI     H,INBUF+1       ; Zero character counter
                MVI     M,0
                DCX     H               ; Set maximum line length
                MVI     M,80
                XCHG                    ; INBUF pointer to DE register
                MVI     C,RBUFF         ; Set up Read Buffer function
                CALL    BDOS            ; Input a line
                LXI     H,INBUF+1       ; Get character counter
                MOV     E,M             ; into LSB of DE register pair
                MVI     D,0             ; Zero MSB
                DAD     D               ; Add length to start
                INX     H               ; plus one points to end
                MVI     M,0             ; Insert terminator at end
                POP     H               ; Restore all registers
                POP     D
                POP     B
                RET

; Message pointed to by stack out to console 
SPMSG:          XTHL                    ; Get "return address" to HL
                XRA     A               ; Clear flags and accumulator
                ADD     M               ; Get one message character
                INX     H               ; Point to next
                XTHL                    ; Restore stack for
                RZ                      ; return if done
                CALL    CO              ; else display character
                JMP     SPMSG           ; and do another
                
; Remove the vowels from the $-terminated string at [DE]
DVWL:	        PUSH	D	    ; Keep output pointer on stack
VWLLP:	        LDAX	D	    ; Get current byte
                INX	    D	    ; Advance input pointer
                POP	    B	    ; Store at output pointer
                STAX	B
                CPI	    '$'	    ; Reached the end?
                RZ		        ; If so, stop
                PUSH	B	    ; Put output pointer back on stack
                LXI	    H,VWLS	; Check against each vowel
                ORI	    32 	    ; Make lowercase
                MVI	    B,5	    ; 5 vowels
VCHK:	        CMP	    M	    ; Equal to current vowel?
                JZ	    VWLLP	; Then overwrite with next character
                INX	    H	    ; Check next vowel
                DCR	    B	    ; Any vowels left?
                JNZ	    VCHK
                POP	    B	    ; Not a vowel, advance output pointer
                INX	    B
                PUSH	B
                JMP	    VWLLP
VWLS:	        DB	    'aeiou'	; Vowels
; Get yes or no from console
GETYN:          CALL    SPMSG           ; Prompt for input
                DB      ' Enter a String: ',0
                CALL    CIMSG           ; Get the input line
                CALL    CCRLF           ; Echo carriage return

                LXI	    D,INBUF+2
                CALL	DVWL	; Remove vowels
                LXI	    D,INBUF+2
                MVI	    c,9	    ; Print using CP/M
                JMP	    5

INBUF:          DS      83              ; Line Input Buffer

; Set up stack space
                DS      64              ; 40H locations
STAK:           DB      0               ; Top of stack

                END
