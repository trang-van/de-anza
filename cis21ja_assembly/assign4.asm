; May 4, 2019
; CIS 21JA - Assignment 4

comment !

	The programs uses loops and pointers to execute the following:

    1. Prompt the user to enter 10 numbers.
    2. Save those numbers in a 32-bit integer array.
    3. Print the array with the same order it was entered.
    3. Calculate the sum of the numbers and display it.
    4. Calculate the mean of the array and display it.
    5. Rotate the members in the array forward one position for 
       9 times. Last Rotation will display the array in reverse order.
    6. Print the array after each rotation.
	
!

include irvine32.inc

.data
userPrompt BYTE 'Please enter a number: ', 0
sumStr BYTE 'The sum is: ', 0
meanStr BYTE 'The mean is: ', 0
arrStr BYTE 'The original array: ', 0
space BYTE ' ', 0
rotateStr BYTE 'After a rotation: ', 0
numArr DWORD 10 dup(?)					; Array of 10 uninitialized elements 

.code

main proc 

	; Prompt user for 10 numbers and saves into numArr
	mov esi, OFFSET numArr
	sub eax, eax
	mov ecx, 10
	InitializeArray:
		mov edx, OFFSET userPrompt
		call writeString
		call readDec
		mov [esi],eax
		add esi, TYPE numArr
	loop InitializeArray

	; Calculate sum of array

	mov edx, OFFSET sumStr
	call writeString
	mov esi, OFFSET numArr
	mov ecx, 10
	sub eax,eax					; Set sum to 0

	CalcSum:
		add eax, [esi]
		add esi, TYPE numArr
	loop CalcSum
	
	; Displays the sum of numArr
	call writeDec		
	call crlf

	; Calculate mean of numArr by using sum and dividing by numArr's length
	mov edx, OFFSET meanStr
	call writeString

	sub edx, edx				; Zero out EDX
	mov ebx, LENGTHOF numArr
	div ebx

	; Display quotient (in eax) and remainder (in edx)
	call writeDec	
	
	mov eax, ' '				; Quotient in EAX
	call writeChar

	mov eax, edx				; Remainder in EDX
	call writeDec

	mov eax, '/'
	call writeChar

	mov eax, ebx				; Length of array
	call writeDec
	call crlf

	; Print values of array
	mov edx, OFFSET arrStr
	call writeString
	mov esi, OFFSET numArr
	mov ecx, 10
	PrintNumArr:
		mov eax, [esi]
		call writeDec
		mov al, ' '
		call writeChar
		add esi, type numArr
	loop PrintNumArr
	call crlf

	; Rotate numArr forward. Elements are shifting to the right.
	; Program prints numArr after each rotation.

	mov ecx, lengthof numArr - 1							; Rotations = 9

	mov esi, OFFSET numArr + (lengthof numArr * type numArr)-type numArr
		; ptr to last element (@ 36 bytes)
	mov edi, OFFSET numArr + (lengthof numArr * type numArr)-(type numArr*2) 
		; ptr to second to last element (@ 32 bytes)

	RotateOuter:
		mov ebx, ecx			; Store ecx temporarily
		mov ebp, [esi]			; Store last element in array

		RotateInner:
			mov eax, [edi]		; Move second to last elem to register
			mov [esi], eax		; Set last elem to value of 2nd to last elem

			sub edi, type numArr		; Shift both pointers by 4 bytes
			sub esi, type numArr
		loop RotateInner

		mov [esi], ebp
		
		mov edx, OFFSET rotateStr
		call writeString
		mov esi, OFFSET numArr
		mov ecx, lengthof numArr
		PrintArray:
			mov eax, [esi]
			call writeDec
			mov al, ' '
			call writeChar
			add esi, TYPE numArr
		loop PrintArray

		call crlf
		
		mov esi, OFFSET numArr + (LENGTHOF numArr * TYPE numArr) -TYPE numArr
			; Reset ptr for the next rotation
		mov edi, OFFSET numArr+(LENGTHOF numArr*TYPE numArr)-(TYPE numArr*2)
			; Reset ptr for the next rotation

		mov ecx, ebx			
	loop RotateOuter

exit
main endp
end main

comment !
	---------------SAMPLE RUN--------------------
	Please enter a number: 2
	Please enter a number: 3
	Please enter a number: 4
	Please enter a number: 5
	Please enter a number: 6
	Please enter a number: 7
	Please enter a number: 8
	Please enter a number: 9
	Please enter a number: 0
	Please enter a number: 10
	The sum is: 54
	The mean is: 5 4/10
	The original array: 2 3 4 5 6 7 8 9 0 10
	After a rotation: 10 2 3 4 5 6 7 8 9 0
	After a rotation: 10 0 2 3 4 5 6 7 8 9
	After a rotation: 10 0 9 2 3 4 5 6 7 8
	After a rotation: 10 0 9 8 2 3 4 5 6 7
	After a rotation: 10 0 9 8 7 2 3 4 5 6
	After a rotation: 10 0 9 8 7 6 2 3 4 5
	After a rotation: 10 0 9 8 7 6 5 2 3 4
	After a rotation: 10 0 9 8 7 6 5 4 2 3
	After a rotation: 10 0 9 8 7 6 5 4 3 2

	Press any key to close this window . . .

	---------------------------------------------
!