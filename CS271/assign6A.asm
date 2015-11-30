TITLE Assignment Six-A Read/Write Values (assign6A.asm)

;// Author: Richard Moot
;// Description: This program gets a number from the user between MAX and MIN, and generates a MAX number of
;//		random integers. It then stores them in an array, prints out the unsorted array, calculates the median of the
;//		array, and then print out the sorted array.

INCLUDE Irvine32.INC

frameStart	MACRO
	PUSH 	ebp
	MOV  	ebp, esp
ENDM

frameEnd	MACRO
	POP		ebp
ENDM

;// From CS 271 Slides for Lecture 26
myWriteString	MACRO	buffer
	PUSH	edx
	MOV		edx, buffer
	CALL	WriteString
	POP		edx
ENDM

;// From CS 271 Slides for Lecture 26
myReadString	MACRO	varName
	PUSH	ecx
	PUSH	edx
	MOV		edx, varName
	MOV		ecx, 11
	CALL	ReadString
	POP		edx
	POP		ecx
ENDM

getString	MACRO	promptUser, stringVarName
	myWriteString	promptUser
	myReadString	stringVarName
ENDM

.data
intro1 		BYTE 	09,"PROGRAMMING ASSIGNMENT 6: Designing low-level I/O procedures",10,09,09,09,"Created by Richard Moot",0
intro2 		BYTE 	10,"Please provide 10 unsigned decimal integers.",10,"Each number needs to be small enough to fit inside a 32-bit register.",10,"After you have finished inputting the raw numbers I will display a list",10,"of the integers, their sum, and their average value.",10, 0
request1  	BYTE 	"Please enter an unsigned number: ", 0
error1 		BYTE 	"ERROR: You did not enter an unsigned number or your number was too big.",10,0
arrayList	BYTE 	"You entered the following numbers:",10,0
sumDisp		BYTE 	"The sum of these numbers is: ",0
avgList		BYTE 	"The average is: ",0
signOff		BYTE	"Thanks for playing!",10,0
spaces		BYTE	09,0

userReq			BYTE	11 DUP(?)
loopLimit		DWORD	?
numArray		DWORD	20 DUP(?)

.code
main PROC
	CALL	Clrscr

	PUSH	OFFSET intro1
	PUSH	OFFSET intro2
	CALL	intro

	PUSH	OFFSET userReq
	PUSH	OFFSET request1
	CALL	readVal

	PUSH	OFFSET signOff
	CALL	farewell

exit
main ENDP

;// Providing greeting and instructions about the program to the user.
;// Receives: intro1, intro2, intro3
;// Returns: none
;// Preconditions: All greeting paramenters passed in as offset in the order they appear
;// Registers Changed: edx, ebp
intro PROC
	frameStart

	;// Writing intro1
	myWriteString	[ebp+12]
	CALL Crlf
	;// Writing intro2
	myWriteString	[ebp+8]
	CALL Crlf

	frameEnd

	RET 8
intro ENDP

readVal	PROC
	frameStart

	getString		[ebp+8], [ebp+12]

	frameEnd
	RET 8
readVal	ENDP

farewell PROC
	frameStart
	CALL	Crlf
	myWriteString	[ebp + 8]
	frameEnd
	RET		4
farewell ENDP

END main