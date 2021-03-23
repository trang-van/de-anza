; May 26,2019
; CIS 21JA-Assignment 6

comment !
	Finding Prime Numbers:
		A prime number is an integer that's divisible only by 1 & by itself.
		This program prompts the user to input a number and then
		returns all prime numbers that are greater than 2 (lowest prime #)
		but less than the prompted number.
!

include irvine32.inc

.data

num1 DWORD ?		; Used to store the user's number
primeCt DWORD 0		; Counter-Used to count number of primes
userPrompt BYTE "Please enter a number:", 0
displayStr BYTE "Primes found until the given number:", 0Ah, 0Dh

.code
;-------------------------------------------------------------------------
main proc
; Description:
;	Prompts the user for a number. Pushes prime numbers onto the stack. 
;	Calls printPrimes at the end to display prime numbers.
;-------------------------------------------------------------------------

	mov edx, OFFSET userPrompt
	call writeString

	call readDec
	mov num1, eax			; Stores user's number to num1

	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	; WHILE01 loop starts from user number & checks if it's a prime number
	; If the current number is prime, that number is pushed onto the stack
	; Otherwise, the current number is decremented and loops again.
	;
	; C++ EQUIVALENT:
	; while (n >= 2){
	;	if (isPrime(n)){
	;		push n;
	;		primeCt++;
	;	} else {
	;		n--;
	;	}
	;}			
	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	mov ebx, num1			; Set loop counter to user number
	WHILE01:
		call isPrime		
		cmp edi, 1			
		JNE ELSE01			
		push ebx			
		inc primeCt			
	
		ELSE01:				
			dec ebx		
			cmp ebx, 2		
			JAE WHILE01		
	
	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	; Print prime numbers by popping from the stack. Uses primeCt to set 
	; counter for loop. 
	;
	; C++ EQUIVALENT:
	;	for (int i = primeCt; i != 0; i--)
	;	{
	;		pop ebx;
	;		cout << ebx << ' ';
	;	}
	;	cout << endl;
	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	mov edx, OFFSET displayStr
	call writeString

	mov ecx, primeCt
	Print:
		pop ebx				; Pop the prime number off the stack
		mov eax, ebx
		call writeDec

		mov al, ' '
		call writeChar
	Loop Print
	call crlf

exit 
main endp

;-------------------------------------------------------------------------
isPrime PROC
; Recieves: EBX, the current number being checked from WHILE01 in main
; Returns:	EDI set to 0 (false) if current number is NOT prime OR
;					   1 (true) if current number is prime
;-------------------------------------------------------------------------

	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	; WHILE02 clears out EDX and moves the current number to be the
	; dividend. Divides by each loop iteration until divisor is 1 (which
	; means the number is prime). Otherwise, the loop divides EAX by ECX
	; and checks the remainder. Sets the return value for the procedure.
	; while(i!=1){
	;		i --
	;		if (i == 1){return true}
	;		else {
	;			if (n % i == 0) {return false}}}
	;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	mov ecx, ebx			; Set loop counter to current number
	WHILE02:
		xor edx, edx		; Clears EDX for the remainder
		mov eax, ebx		; Sets the dividend to current number
		dec ecx				; Sets the divisor
		cmp ecx, 1			
		JNE ELSE02			
							
		mov edi, 1			; Only other divisor is 1, set true
		JMP OUT02			; Break out of loop once number is prime
							
		ELSE02:				
			div ecx			
			cmp edx, 0 		
			JNE WHILE02		
			mov edi, 0		; Another number divides into current number
							; Set false
	OUT02:					
		ret
isPrime ENDP

end main


comment !
----------------- SAMPLE RUN --------------------
Please enter a number:44
Primes found until the given number:
2 3 5 7 11 13 17 19 23 29 31 37 41 43
-------------------------------------------------

!