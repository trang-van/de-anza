; CIS 21JA - Assignment 8 
; June 19, 2019

comment !
	THIS PROGRAM:
	Ask the user to enter how many elements the array has. The maxSize is 40.
    Ask the user to enter how many elements in each row in the array.
	Ask the user what type the array is. It could be a byte, word or dword array.
    Ask the user to enter the elements of the array.
    Ask the user for the row index and display the sum of the selected row.
!

INCLUDE irvine32.inc

.data

MAXSIZE EQU 40

numOfElem DWORD ?
rowSize DWORD ?
arrType DWORD ?
rowIndex DWORD ?
sum DWORD ?
twoD_arr DWORD maxSize dup(?)

prompt1 BYTE "Enter how many elements in your array: ", 0
prompt2 BYTE "Enter the row size: ",0
prompt3 BYTE "Enter the type of your array.", 0Ah, 0Dh,
			 "1 for byte", 0Ah, 0Dh, 
			 "2 for word", 0Ah, 0Dh,
			 "4 for doubleword", 0Ah, 0Dh, 0
prompt4 BYTE "Enter an element in your array: ",0
prompt5 BYTE "Enter row number that you want me to sum: ",0
prompt6 BYTE "The sum is: ", 0
errMsg1 BYTE "Maximum size of array is 40. Please enter a smaller number of elements.",0
errMsg2 BYTE "Please enter 1, 2, or 4 only.",0

.code

main proc
	
	;Prompts user to enter how many elements are in array
	READ_NUM_OF_ELEM:
		lea edx, prompt1
		call writeString
		call readInt
		cmp eax, MAXSIZE
		JG THEN01
		mov numOfElem, eax
		JMP NEXT01

	; Size entered is over 40. Prompt Again
	THEN01:
		lea edx, errMsg1
		call writeString
		call crlf
		JMP READ_NUM_OF_ELEM

	; Prompts use for rowSize or number of columns
	NEXT01:
		lea edx, prompt2
		call writeString
		call readInt
		mov rowSize, eax
	
	; Prompt user to make array: byte, word, dword
	CHOOSE_ARR_TYPE:
		lea edx, prompt3
		call writeString
		call readInt
		cmp eax, 1
		JE ENTER_ELEM
		cmp eax, 2
		JE ENTER_ELEM
		cmp eax, 4
		JE ENTER_ELEM

		lea edx, errMsg2
		call writeString
		JMP CHOOSE_ARR_TYPE
	
	; Loops and asks user for elements in array
	ENTER_ELEM:
		mov arrType, eax		
		mov edi, OFFSET twoD_arr
		mov ecx, numOfElem

		CLD

		; Depending on arrType, switches on how to store element
		FILL_ARR:
			lea edx, prompt4
			call writeString
			call readInt

			; C++ Equivalent
			;
			;	switch(arrType){
			;		case 1: store by byte
			;		case 2: store by word
			;		case 4: store by dword
			;	}
			;
			cmp arrType, 1
			JE BYTE_STORE
			cmp arrType, 2
			JE WORD_STORE
			cmp arrType, 4
			JE DWORD_STORE
		
			BYTE_STORE:
				stosb
				JMP OUT01
			WORD_STORE:
				stosw
				JMP OUT01
			DWORD_STORE:
				stosd
				JMP OUT01
			
			OUT01:
		LOOP FILL_ARR
	
	; Prompts user for rowIndex to sum
	; calls the calcRowSum procedure
	FIND_ROW_SUM:
		mov edx, OFFSET prompt5
		call writeString
		call readInt
		mov rowIndex, eax

		sub esp, 4		; save space for sum
		push rowIndex
		push arrType
		push rowSize
		push OFFSET twoD_arr

		call calcRowSum
		pop eax
		
		mov edx, OFFSET prompt6
		call writeString
		call writeDec

	exit 
main endp

;------------------------------------------------------------------------------
calcRowSum PROC
; Recieves: rowIndex, arrType, rowSize, &twoD_arr
; Returns: sum of the indicated rowIndex
;------------------------------------------------------------------------------
	push ebp 
	mov ebp, esp

	push eax
	push ecx
	push edx
	push esi
	push edi

	; Move all parameters to registers
	mov eax, [ebp + 20]		; index
	mov edi, [ebp + 16]		; arrType
	mov ecx, [ebp + 12]		; rowSize	
	mov esi, [ebp + 8]		; & arr

	mul ecx					; b/c eax stores index
	mul edi
	add esi, eax			; rowIndex * numOfCols * type arr
							; moved to ESI to use load string instruction
	
	xor eax, eax			; LOAD TO THIS
	xor edx, edx			; TEMP SUM

	; Different Cases Based on Size
	; C++ Equivalent
	;
	;	switch(arrType){
	;		case 1: dl += al
	;		case 2: dx += ax
	;		case 4: edx += eax
	;	}
	;
	SUM_ROW:
		cmp edi, 1
		JE BYTE_SUM
		cmp edi, 2
		JE WORD_SUM
		cmp edi, 4
		JE DWORD_SUM

		BYTE_SUM:
			lodsb
			add dl, al
			JMP OUT01

		WORD_SUM:
			lodsw
			add dx, ax
			JMP OUT01

		DWORD_SUM:
			lodsd
			add edx, eax
			JMP OUT01

		OUT01:
	Loop SUM_ROW

	mov [ebp + 24], edx
	
	pop edi
	pop esi
	pop edx
	pop ecx
	pop eax
	
	pop ebp
	ret 16		; 4 parameters
calcRowSum ENDP

end main


comment !
	Enter how many elements in your array: 6
	Enter the row size: 2
	Enter the type of your array.
	1 for byte
	2 for word
	4 for doubleword
	1
	Enter an element in your array: 1
	Enter an element in your array: 2
	Enter an element in your array: 3
	Enter an element in your array: 4
	Enter an element in your array: 5
	Enter an element in your array: 6
	Enter row number that you want me to sum: 0
	The sum is: 3


	Enter how many elements in your array: 6
	Enter the row size: 2
	Enter the type of your array.
	1 for byte
	2 for word
	4 for doubleword
	2
	Enter an element in your array: 1
	Enter an element in your array: 2
	Enter an element in your array: 3
	Enter an element in your array: 4
	Enter an element in your array: 5
	Enter an element in your array: 6
	Enter row number that you want me to sum: 1
	The sum is: 7
!
