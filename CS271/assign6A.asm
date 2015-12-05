TITLE Assignment Six-A Read/Write Values (assign6A.asm)

;// Author: Richard Moot
;// Description: This program gets a number from the user between MAX and MIN, and generates a MAX number of
;//		random integers. It then stores them in an array, prints out the unsorted array, calculates the median of the
;//		array, and then print out the sorted array.

INCLUDE Irvine32.INC

.const
MAX_SIZE = 15
LOW_DIGIT = 48
HIGH_DIGIT = 57
PLUS_SIGN = 43
MINUS_SIGN = 45

frameStart	MACRO
	PUSH 	ebp
	MOV  	ebp, esp
	PUSHAD
ENDM

frameEnd	MACRO
	POPAD
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
	MOV		ecx, MAX_SIZE
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
spaces		BYTE	" , ",0

userReq		BYTE	15 DUP(?)
entryLim	DWORD	10
nextNum		DWORD	0
numArray	DWORD	10 DUP(?)

.code
main PROC
	CALL	Clrscr

	PUSH	OFFSET intro1
	PUSH	OFFSET intro2
	CALL	intro

	PUSH	entryLim
	PUSH	OFFSET error1
	PUSH	OFFSET numArray
	PUSH	OFFSET userReq
	PUSH	OFFSET request1
	CALL	readVal

	PUSH	OFFSET sumDisp
	PUSH	OFFSET arrayList
	PUSH	OFFSET spaces
	PUSH	LENGTHOF numArray
	PUSH	OFFSET numArray
	CALL	readArray

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

;//PUSH	entryLim			+24
;//PUSH	OFFSET error1		+20
;//PUSH	OFFSET numArray		+16
;//PUSH	OFFSET userReq		+12
;//PUSH	OFFSET request1		+8

readVal	PROC
	frameStart
	JMP			readValStart
	
readValError:
	myWriteString	[ebp+24]

;// Prompting and requesting for user input
readValStart:
	MOV			ebx, [ebp+24]
	CMP			ebx, 0
	JE			readValEnd
	getString	[ebp+8], [ebp+12] ;// [prompt], [user input]
	CMP			eax, 9
	JGE			readValError
	MOV			ecx, eax
	MOV			esi, [ebp+12]
	MOV			edi, [ebp+16]
	MOV			ebx, 10
	XOR			edx, edx
	CLD

stringLoop:
	;// Here we start going through the string character by character
	LODSB
	CMP			al, LOW_DIGIT			;// Checking if it is below 0
	JL			readValError
	CMP			al, HIGH_DIGIT			;// Checking if number is above 9
	JG			readValError
	SUB			al, 48					;// Converting from ASCII to digit
	MOVZX		eax, al					;// Extending out through whole register to read as DWORD
	ADD			eax, edx				;// Adding in values (starts at 0) before MUL by 10
	MUL			ebx						;// Multiplying by 10 to move values to left as we progress
	MOV			edx, eax				;// Saving value into edx to add in on next iteration
	LOOP		stringLoop

	MOV			eax, edx
	XOR			edx, edx
	DIV			ebx
	PUSH		eax
	PUSH		edi
	CALL		storeValue
	MOV			ebx, [ebp+24]
	DEC			ebx
	MOV			[ebp+24], ebx

	ADD			edi,4

	PUSH		ebx
	PUSH		[ebp+20]
	PUSH		edi
	PUSH		[ebp+12]
	PUSH		[ebp+8]
	CALL		readVal

readValEnd:
	
	frameEnd
	RET 20
readVal	ENDP

storeValue PROC
	frameStart

	MOV			edi, [ebp+8]
	MOV			eax, [ebp+12]
	MOV			[edi], eax

	frameEnd
	RET 8
storeValue ENDP

readArray PROC
	frameStart

	CALL	Crlf
	myWriteString	[ebp+20]

	XOR		ebx,ebx

	MOV		ecx, [ebp+12]
	MOV		edi, [ebp+8]
loopWriteArr:
	MOV		eax, [edi]
	CALL	WriteDec
	ADD		ebx, eax
	CMP		ecx, 1
	JE		readArrayDone
	myWriteString [ebp+16]
	ADD		edi,4
	LOOP	loopWriteArr

readArrayDone:
	myWriteString[ebp + 24]
	MOV		eax, ebx
	CALL	WriteDec

	frameEnd
	RET
readArray ENDP

farewell PROC
	frameStart
	CALL	Crlf
	myWriteString	[ebp + 8]
	frameEnd
	RET		4
farewell ENDP

END main