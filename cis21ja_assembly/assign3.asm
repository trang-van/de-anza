; April 29, 2019
; CIS 21JA - Assignment 3
comment !
	This program prompts the user for three numbers. Then, the program
	uses the three numbers to calculate a result using the following 
	formula: (((num1 ^ 3) * num2)+ (5 * (num2 ^ 2))) / num3.

	The program will display the three numbers and the quotient/remainder
	result.

!

include irvine32.inc

.data

userPrompt byte 'Please enter a number:', 0
formula byte '(((num1 ^ 3) * num2)+ (5 * (num2 ^ 2))) / num3 = ', 0
var1 byte 'num1 = ',0
var2 byte 'num2 = ',0
var3 byte 'num3 = ',0
num1 byte ?
num2 byte ?
num3 byte ?
quotient byte ?
remainder byte ?

.code
main proc
	; Ask User for 1st number - Store into num1
	mov edx, offset userPrompt
	call writeString
	call readDec 
	mov num1, al

	; Ask User for 2nd number - Store into num2
	mov edx, offset userPrompt
	call writeString
	call readDec
	mov num2, al

	; Ask User for 3rd number - Store into num3
	mov edx, offset userPrompt
	call writeString
	call readDec 
	mov num3, al 

	; Calculates (num1^3)*num2 and moves result to ECX
	mov al, num1
	mul num1
	mul num1
	mul num2

	mov ecx, eax
	
	; Calculates (5 * (num2 ^ 2)) and adds result stored in ECX

	mov al, num2
	mul num2
	mov bx, ax
	mov al, 5
	mul bx
	add eax, ecx

	; Clears out edx before moving num3 to EBX to use in division
	sub edx, edx
	movzx ebx, num3
	div ebx

	; Retrieve quotient and remainder from EAX and EDX 
	mov quotient, al
	mov remainder, dl

	; Print num1
	mov edx, offset var1
	call writeString
	mov al, num1
	call writeDec
	call crlf

	; Print num2
	mov edx, offset var2
	call writeString
	mov al, num2
	call writeDec
	call crlf

	; Print num3
	mov edx, offset var3
	call writeString
	mov al, num3
	call writeDec
	call crlf

	; Print out Formula and answer
	mov edx, offset formula
	call writeString

	mov al, quotient
	call writeDec

	mov al, ' '
	call writeChar
	mov al, 'R'
	call writeChar
	mov al, ' '
	call writeChar

	mov al, remainder
	call writeDec
	call crlf
	
exit

main endp
end main

comment ?
SAMPLE OUTPUT:

Please enter a number:1
Please enter a number:2
Please enter a number:3
num1 = 1
num2 = 2
num3 = 3
(((num1 ^ 3) * num2)+ (5 * (num2 ^ 2))) / num3 = 7 R 1

?