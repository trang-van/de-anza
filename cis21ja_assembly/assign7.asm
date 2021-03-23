Title Assignment 7

COMMENT !
*****************
date: June 02,2019
*****************
!

include irvine32.inc
; ===============================================
.data
  ; Fill your data here
  intArr DWORD 40 dup (?)
  arr_len DWORD 0
  welcomeMsg BYTE "Enter up to 40 unsigned dword integers.", 0
  welcomeMsg2 BYTE "To end the array, enter 0.", 0
  userPrompt BYTE "After each element press enter:", 0
  arrMsg BYTE "Initial array:", 0
  newArrMsg BYTE "Array sorted in descending order:", 0
  errMsg BYTE "Cannot enter zero. Please try again."
;=================================================
.code
main proc
	mov edx, OFFSET welcomeMsg
	call writeString
	mov edx, OFFSET welcomeMsg2
	call writeString
	call crlf

	mov edx, OFFSET userPrompt 
	call writeString
	call crlf

	sub esp, 4
	push OFFSET intArr
	call enter_elem

	pop arr_len

	cmp arr_len, 0
	JE THEN01

	mov edx, OFFSET arrMsg
	call writeString
	call crlf

	push OFFSET intArr
	push arr_len
	call print_arr


	push OFFSET intArr
	push arr_len
	call sort_arr

	mov edx, OFFSET newArrMsg
	call writeString
	call crlf

	push OFFSET intArr
	push arr_len
	call print_arr

	JMP OUT01
	
	; Display Error Message if user enters 0
	THEN01:
		mov edx, OFFSET errMsg
		call writeString
	OUT01:
		exit
main endp

; ================================================
; void enter_elem(arr_addr)
;
; Input:
;   ARR_ADDRESS THROUGH THE STACK
; Output:
;   ARR_LENGTH THROUGH THE STACK
; Operation:
;   Fill the array and count the number of elements
;
enter_elem proc

	push ebp
	mov ebp, esp

	push esi
	push ebx
	push eax

	mov esi, [ebp + 8]
	xor ebx, ebx

	WHILE01:				
		call readDec
		cmp eax, 0
		JNE THEN01
		JMP ELSE01				; if equal to 0, break out of loop
		THEN01:
			cmp ebx, 40
			JNE THEN02
			JMP OUT01
			THEN02:
				mov [esi],eax
				add esi, TYPE intArr
				inc ebx
				JMP WHILE01			
	ELSE01:
		mov arr_len, ebx		;  should have 0 if user enters 0
	OUT01:
		mov [ebp + 12], ebx
		pop eax
		pop ebx
		pop esi

		pop ebp
		ret 4
enter_elem endp

; ================================================
; void print_arr(arr_addr,arr_len)
;
; Input:
;   ARR_ADDRESS and ARR_LEN THROUGH STACK
; Output:
;   ARRAY PRINTED OUT WITH SPACES IN BETWEEN
; Operation:
;  print out the array
;

print_arr proc
  push ebp
  mov ebp, esp

  push esi
  push ecx
  push eax

  mov esi, [ebp + 12]
  mov ecx, [ebp + 8]
  PrintArray:
	mov eax, [esi]
	call writeDec
	mov al, ' '
	call writeChar
	add esi, TYPE intArr
	Loop PrintArray
  call crlf

  pop eax
  pop ecx
  pop esi
  pop ebp

  ret 8
print_arr endp

; ================================================
; void sort_arr(arr_addr,arr_len)
;
; Input:
;   ARR_ADDRESS and ARR_LEN THROUGH STACK
; Output:
;   AN ARRAY SORTED IN DESCENDING ORDER
; Operation:
;   sort the array
;

sort_arr proc
   push ebp
   mov ebp, esp

   push esi 
   push edi
   push ecx
   push ebx
		
   mov ecx, [ebp + 8]
   mov esi, [ebp + 12]		; &first elem  = x
   mov edi, esi				 
   add edi, 4				; &second elem  = y


   ; NESTED FOR LOOPS - C++ Equivalent
   ; for (int i = n; i != 0; i--)
   ;	temp = i
   ;	for (i = temp - 1; i != 0; i--)
   ;		compareAndSwap
   Outer:
	   mov ebx, ecx		; saves current loop
	   dec ecx
	   CompareLoop:
		  push edi		;y
		  push esi		;x
	   
		  call compare_and_swap

		  add esi, 4
		  add edi, 4

		  cmp ecx, 0
		  JE out01
		Loop CompareLoop
	   
	   out01:
	   	 mov ecx, ebx
		 mov esi, [ebp + 12]		; RESET &first elem  = x
		 mov edi, esi				 
		 add edi, 4					; RESET &second elem  = y

	Loop Outer

   pop ebx
   pop ecx
   pop edi
   pop esi

   pop ebp
   ret 8
sort_arr endp

; ===============================================
; void compare_and_swap(x_addr,y_addr)
;
; Input:
;   X_ADDRESS and Y_ADDRESS THROUGH STACK
; Output:
;   EDI, ESI COMPARED WITH EACH OTHER TO SWAP
; Operation:
;  compare and call SWAP ONLY IF Y > X 
;

compare_and_swap proc

   ; FILL YOUR CODE HERE
   ; YOU NEED TO CALL SWAP PROCEDURE 
   push ebp
   mov ebp, esp

   push eax
   push ebx
   push esi
   push edi

   mov eax, [ebp + 8]	;x
   mov ebx, [ebp + 12]  ;y

   mov esi, [eax]
   mov edi, [ebx]

   ; C++ Equivalent - if Y > X {swap}
   cmp edi, esi
   JBE THEN01

   push ebx
   push eax
   call swap
   
   THEN01:
	pop edi
	pop esi
	pop ebx
	pop eax

	pop ebp
	ret 8

compare_and_swap endp

; =================================================
; void swap(x_addr,y_addr)
;
; Input:
;   X_ADDRESS and Y_ADDRESS THROUGH STACK
; Output:
;   ESI, EDI VALUES SWAPPED
; Operation:
;  swap the two inputs
;

swap proc

   ; FILL YOUR CODE HERE
   push ebp
   mov ebp, esp

   push eax
   push ebx
   push edi
   push esi

   mov eax, [ebp + 8]; points to & first elem
   mov ebx, [ebp + 12]; points to & second elem
   
   mov edi, [eax]
   mov esi, [ebx]

   mov [eax], esi
   mov [ebx], edi

   pop esi
   pop edi
   pop ebx
   pop eax
   pop ebp

   ret 8

swap endp

end main

;;;;;;;;;;;;;;;;;;;;SAMPLE RUN;;;;;;;;;;;;;;;;;;;;;;;
comment !
======================RUN 1=======================================

Enter up to 40 unsigned dword integers. To end the array, enter 0.
After each element press enter:
1
4
3
8
99
76
34
5
2
17
0
Initial array:
1 4 3 8 99 76 34 5 2 17
Array sorted in descending order:
99 76 34 17 8 5 4 3 2 1


==========================ZERO CASE================================
Enter up to 40 unsigned dword integers. To end the array, enter 0.
After each element press enter:
0
Cannot enter zero. Please try again.
!