; May 20,2019
; CIS 21JA - Assignment 5

comment !
		1.Clears the screen, locates the cursor near the 
		   middle of the screen.
		2.Prompts the user for two signed integers.
		3. Displays their sum and difference.
		4. Repeats the same steps three times. 
		   Clears the screen after each loop iteration.
!

include irvine32.inc

.data

num1 SDWORD ?
num2 SDWORD ?
userPrompt byte "Enter an integer: ", 0
sumStr byte "Sum = ", 0
diffStr byte "Difference = ", 0
waitKeyStr byte "Press any key...",0
row BYTE ?						; Value changes and resets depending on proc
COLUMN BYTE 79/2				; Constant value for middle of screen (79/2)

.code 
main proc
	
	mov ecx, 3					; Prompts 3 times
	L1:
		call ClrScr
		mov row, 24/2				; mid
		call Input
		mov num1, eax
		call Input
		mov num2,eax

		call DisplaySum
		call DisplayDifference
		call WaitForKey
	Loop L1
exit
main endp

;-------------------------------------------------------------------------
Locate PROC
; Uses the Gotoxy procedure from Irvine 32 library and locates the middle
; of the screen. Rows increment when other procedures call Locate.
; Recieves: COLUMN, constant value defined for middle of the screen
;			row, which is set at the beginning of ea. iteration 
; Returns: Location of the cursor at ROW: y and COLUMN: x (approx. middle)
; Requires: NOTHING
;-------------------------------------------------------------------------
	mov dh, row  
	mov dl, COLUMN 
	call Gotoxy
	inc row
	ret
Locate ENDP

;-------------------------------------------------------------------------
Input PROC
; Prompts the user to enter 1 signed integer
; Recieves: Address of userPrompt
; Returns:  EAX, the one integer 
; Requires: NOTHING
;-------------------------------------------------------------------------
	call Locate
	mov edx, OFFSET userPrompt
	call WriteString
	call readInt
	ret
Input ENDP

;-------------------------------------------------------------------------
DisplaySum PROC
; Adds num1 and num2 and displays it on the screen
; Recieves: num1, num2, the stored integers inputted by user
; Returns: EAX = sum
; Requires: NOTHING
;-------------------------------------------------------------------------
	call Locate
	mov ebx, num1
	add ebx, num2

	mov edx, OFFSET sumStr
	call WriteString
	mov eax, ebx
	call WriteInt
	ret
DisplaySum ENDP

;-------------------------------------------------------------------------
DisplayDifference PROC
; Subtracts the num2 from num1 and displays the difference to the user
; Recieves: num1, num2, the stored integers inputted by user
; Returns: EAX = difference
; Requires:
;-------------------------------------------------------------------------
	call Locate 
	mov ebx, num1
	sub ebx, num2

	mov edx , OFFSET diffStr
	call WriteString

	mov eax, ebx
	call WriteInt
	ret
DisplayDifference ENDP

;-------------------------------------------------------------------------
WaitForKey PROC
; Waits for user to press any key to continue to the next iteration. 
; Recieves: address of waitKeyStr
; Returns: EAX, Character inputted 
; Requires: NOTHING
;-------------------------------------------------------------------------
	call Locate
	mov edx, OFFSET waitKeyStr
	call WriteString
	call ReadChar
	ret
WaitForKey ENDP

end main


comment @
-------------------------------------SAMPLE RUN-------------------------------











                                        Enter an integer: 12
                                        Enter an integer: 3
                                        Sum = +15
                                        Difference = +9
                                        Press any key...












                                        Enter an integer: -12
                                        Enter an integer: -10
                                        Sum = -22
                                        Difference = -2
                                        Press any key...
										










                                        Enter an integer: 10
                                        Enter an integer: -9
                                        Sum = +1
                                        Difference = +19
                                        Press any key...

										Press any key to close this window . . .
-------------------------------------------------------------------------------
@