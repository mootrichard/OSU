TITLE Assignment Four Composite Number Calculator (assign4.asm)

;// Author: Richard Moot
;// Description: This program gets a number from the user between MAX and MIN, and generates a MAX number of
;//		random integers. It then stores them in an array, prints out the unsorted array, calculates the median of the
;//		array, and then print out the sorted array.

INCLUDE Irvine32.INC

.const
MIN = 10
MAX = 200
LO = 100
HI = 999

.data
intro1 		BYTE 	"Sorting Random Integers",09,09,"Created by Richard Moot",0
intro2 		BYTE 	"This program generates random numbers in the range [10..999],", 0
intro3 		BYTE 	"displays the original list, sorts the list, and calculates the median value. ",10,"Finally, it displays the list in sorted descending order.",10,0
request1  	BYTE 	"How many numbers should be generated? [10..200]: ", 0
error1 		BYTE 	"Invalid input. Try again.",10,0
error2    	BYTE 	"Cannot allocate enough contiguous memory. Please free some memory and rerun the application The program will now exit.",0
arrayL1		BYTE 	"The unsorted random numbers:",10,0
arrayL2		BYTE 	"The sorted list:",0
median1		BYTE 	"The median is: ",0
spaces		BYTE	09,0

userReq			DWORD ?
checkCompNum	DWORD 4
nextCompNum		DWORD 4
loopLimit		DWORD ?
numArray		DWORD 200 DUP(?)

.code
main PROC
CALL Clrscr

CALL Randomize

PUSH OFFSET intro1
PUSH OFFSET intro2
PUSH OFFSET intro3
CALL intro

PUSH OFFSET request1
PUSH OFFSET error1
PUSH OFFSET userReq
CALL getUserData

PUSH OFFSET numArray
PUSH userReq
CALL generateNumbers

PUSH OFFSET spaces
PUSH OFFSET arrayL1
PUSH OFFSET numArray
PUSH userReq
CALL displayArray

PUSH OFFSET numArray
PUSH userReq
CALL sortArray

CALL farewell

exit
main ENDP

;// Providing greeting and instructions about the program to the user.
;// Receives: intro1, intro2, intro3
;// Returns: none
;// Preconditions: All greeting paramenters passed in as offset in the order they appear
;// Registers Changed: edx, ebp
intro PROC
	
	PUSH 	ebp
	MOV  	ebp, esp
	
	;// Writing intro1
	MOV edx, [ebp+16]
	CALL WriteString
	CALL Crlf
	;// Writing intro2
	MOV edx, [ebp+12]
	CALL WriteString
	CALL Crlf
	;// Writing intro3
	MOV edx, [ebp+8]
	CALL WriteString
	CALL Crlf

	POP ebp

	RET 12
intro ENDP

;// Obtains input data from user, validates that the data is in the specified range, then stores the data
;// Receives: request1, error1, userReq
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : edx, ebp, ebx
getUserData PROC

	PUSH 	ebp
	MOV  	ebp, esp

requestParams:
	;// Requesting user input
	MOV		edx, [ebp+16]
	CALL	WriteString

readParams:
	CALL	ReadInt
	CMP		eax, MAX
	JG		validateParams
	CMP		eax, MIN
	JL		validateParams

	MOV ebx, [ebp + 8]

	;// Request storage
	MOV	[ebx], eax
	JMP doneParams

validateParams:
	;// Notifying of error
	MOV		edx, [ebp+12]
	CALL	WriteString
	JMP		requestParams
	
doneParams:
	POP		ebp
	RET	12
getUserData ENDP

;// Generates the request amount of random numbers in the array
;// Receives: numArray, userReq
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : edx, ebp, ebx, eax, ecx
generateNumbers PROC
	PUSH 	ebp
	MOV  	ebp, esp

	MOV		eax, (HI - LO) + 1

	MOV		edi, [ebp + 12]
	MOV		ecx, [ebp + 8]
	XOR		edx, edx

fillArray:

	CALL	RandomRange
	ADD		eax, LO
	MOV		[edi],eax
	ADD		edi, 4
	LOOP	fillArray

	POP		ebp
	RET 8
generateNumbers ENDP

;// Display values inside of the array
;// Receives: numArray, userReq
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : edx, ebp, ebx, eax, ecx
displayArray PROC
	PUSH 	ebp
	MOV  	ebp, esp

	;// Displaying which type of array it is to console
	MOV		edx, [ebp+16]
	CALL	WriteString

	;// Number of numbers to display [userReq]
	MOV		ecx, [ebp+8]
	;// Setting our array reference
	MOV		esi, [ebp+12]
	MOV		ebx,0
;// Our loop for displaying 10 numbers per line
disArrLoop:
	;// Writing out the next number in the array
	MOV		eax, [esi]
	CALL	WriteDec
	;// Tab spacing between numbers
	MOV		edx, [ebp+20]
	CALL	WriteString
	;// Incrementing to next array value
	ADD		esi, 4
	;// Checking if we have written 10 numbers
	CMP		ebx, 10
	JNE		needTenNums
	;// Resetting to start a new row
	MOV		ebx, 0
	INC		ebx
	CALL	Crlf
needTenNums:
	LOOP	disArrLoop
	CALL	Crlf
	CALL	Crlf

	POP		ebp
	RET 20
displayArray ENDP

sortArray PROC
	PUSH 	ebp
	MOV  	ebp, esp

	;// 
	;MOV		eax, [ebp+8]
	;MOV		

	POP		ebp
	RET
sortArray ENDP


farewell PROC
	PUSH 	ebp
	MOV  	ebp, esp

	POP		ebp
	RET
farewell ENDP

END main