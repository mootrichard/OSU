TITLE Assignment Six-A Read/Write Values (assign6A.asm)

;// Author: Richard Moot
;// Description: This program takes in 10 integers from a user as strings, validates that they are valid integers, converts them to intergers
;//		from strings, then displays all of the integers to the user. It will also display the sum and average of all the value that were entered.

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
request1  	BYTE 	". Please enter an unsigned number: ", 0
error1 		BYTE 	"ERROR: You did not enter an unsigned number or your number was too big.",10,0
arrayList	BYTE 	"You entered the following numbers:",10,0
sumDisp		BYTE 	"The sum of these numbers is: ",0
avgList		BYTE 	"The average is: ",0
signOff		BYTE	"Thanks for playing!",10,0
spaces		BYTE	" , ",0
subPrompt	BYTE	09," Current total: ",0

userReq		BYTE	15 DUP(?)
outputs		BYTE	15 DUP(?)
line		DWORD	1
entryLim	DWORD	10
subTotal	DWORD	0
numArray	DWORD	10 DUP(?)

.code
main PROC
	CALL	Clrscr

	PUSH	OFFSET intro1
	PUSH	OFFSET intro2
	CALL	intro

	PUSH	subTotal
	PUSH	OFFSET	subPrompt
	PUSH	line
	PUSH	entryLim
	PUSH	OFFSET error1
	PUSH	OFFSET numArray
	PUSH	OFFSET userReq
	PUSH	OFFSET request1
	CALL	readVal

	CALL	Crlf

	PUSH	OFFSET outputs
	PUSH	OFFSET arrayList
	PUSH	OFFSET spaces
	PUSH	LENGTHOF numArray
	PUSH	OFFSET numArray
	CALL	writeVal

	CALL	Crlf

	PUSH	OFFSET numArray
	PUSH	OFFSET avgList
	PUSH	OFFSET sumDisp
	PUSH	subTotal
	CALL	writeAvg

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

;//PUSH	sumTotal			+36
;//PUSH	OFFSET	subTotal	+32
;//PUSH	line				+28
;//PUSH	entryLim			+24
;//PUSH	OFFSET error1		+20
;//PUSH	OFFSET numArray		+16
;//PUSH	OFFSET userReq		+12
;//PUSH	OFFSET request1		+8

;// 
;// 
;// 
;// 
;// 
;// 
;// 
;// 

readVal	PROC
	frameStart
	JMP			readValStart
	
readValError:
	myWriteString	[ebp+20]

;// Prompting and requesting for user input
readValStart:
	MOV			ebx, [ebp+24]
	CMP			ebx, 0
	JE			readValEnd
	MOV			eax, [ebp+28]		;// Writing line number
	CALL		WriteDec
	getString	[ebp+8], [ebp+12]	;// [prompt], [user input]
	CMP			eax, 10				;// Verifying length of digit isn't too big
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

	myWriteString [ebp+32]
	PUSH		eax
	ADD			[ebp+36], eax
	MOV			eax, [ebp+36]
	MOV			[ebp+36], eax
	CALL		WriteDec
	CALL		Crlf
	POP			eax

	PUSH		eax
	PUSH		edi
	CALL		storeValue

	MOV			ebx, [ebp+24]
	DEC			ebx
	MOV			[ebp+24], ebx

	ADD			edi,4
	MOV			eax, [ebp+28]
	INC			eax
	MOV			[ebp+28], eax

	PUSH		[ebp+36]
	PUSH		[ebp+32]
	PUSH		eax
	PUSH		ebx
	PUSH		[ebp+20]
	PUSH		edi
	PUSH		[ebp+12]
	PUSH		[ebp+8]
	CALL		readVal

readValEnd:
	
	frameEnd
	RET 32
readVal	ENDP

;// ebp+8 == next integer
storeValue PROC
	frameStart

	MOV		edi, [ebp+8]
	MOV		eax, [ebp+12]
	MOV		[edi], eax

	frameEnd
	RET 8
storeValue ENDP

;// PUSH	OFFSET avgList		+32
;// PUSH	OFFSET outputs		+28
;// PUSH	OFFSET sumDisp		+24
;// PUSH	OFFSET arrayList	+20
;// PUSH	OFFSET spaces		+16
;// PUSH	LENGTHOF numArray	+12
;// PUSH	OFFSET numArray		+8

;// 
;// 
;// 
;// 
;// 
;// 
;// 
;// 

writeVal PROC
	frameStart

	MOV		ebx, [ebp+12]	;// Checking if this is our first call, printing declaration of values entered
	CMP		ebx, 10
	JL		writeValStart

	;// Prompting the display of their values
	myWriteString	[ebp+20]

writeValStart:
	XOR		ebx, ebx		;// Clearing out registers to be used
	XOR		edi, edi

	MOV		ecx, [ebp+12]	;// Placing our array size into ecx to control for hitting out base case
	MOV		esi, [ebp+8]	;// Placing our next integer to be parsed into a string

	PUSH	[ebp+24]		;// Inputting temp string used for writing integer to
	PUSH	[esi]			;// Pushing next integer to be displayed
	CALL	intToString		;// Calling procedure that converts the digit to a string and displays it
	CMP		ecx, 1			;// Seeing if we are at our last integer, skipping putting a space with a comma
	JE		readArrayDone
	myWriteString	[ebp+16]
	ADD		esi,4			;// Incrementing our array to point at the next integer

	MOV		ecx, [ebp+12]	;// Decrementing our limit in order to move towards the base case
	DEC		ecx
	
	PUSH	[ebp+24]	;// PUSH	OFFSET outputs		+24
	PUSH	[ebp+20]	;// PUSH	OFFSET arrayList	+20
	PUSH	[ebp+16]	;// PUSH	OFFSET spaces		+16
	PUSH	ecx			;// PUSH	LENGTHOF numArray	+12
	PUSH	esi			;// PUSH	OFFSET numArray		+8
	CALL	writeVal

readArrayDone:

	frameEnd
	RET	20
writeVal ENDP

;// 
;// 
;// 
;// 
;// 
;// 
;// 
;// 

;//PUSH	OFFSET numArray
;//PUSH	OFFSET avgList
;//PUSH	OFFSET sumDisp
;//PUSH	subTotal

writeAvg	PROC
	frameStart

	myWriteString	[ebp + 12]

	XOR		eax, eax
	XOR		ebx, ebx
	XOR		edx, edx
	MOV		ecx, 10

	MOV		edi, [ebp+20]
findSum:
	ADD		eax, [edi]
	ADD		edi, 4
	LOOP	findSum

	CALL	WriteDec

	CALL	Crlf

	myWriteString	[ebp+16]

	MOV		ebx, 10
	DIV		ebx

	CALL	WriteDec

	frameEnd
	RET		8
writeAvg	ENDP

intToString	PROC
	frameStart
	XOR		ecx,ecx
	MOV		eax, [ebp+8]
	MOV		edi, [ebp+12]

findDigitEnd:
	XOR		edx, edx
	MOV		ebx, 10d
	DIV		ebx
	CMP		eax, 0
	JE		endOfDigits
	INC		ecx
	JMP		findDigitEnd

endOfDigits:		;// We found how many digits are in the number!
	INC		ecx
	ADD		edi, ecx
	STD
	XOR		eax, eax
	MOV		al,0
	STOSB
	MOV		eax, [ebp+8]
buildDigitString:
	XOR		edx, edx
	DIV		ebx
	ADD		edx, LOW_DIGIT
	PUSH	eax
	MOV		al, dl
	STOSB
	POP		eax
	LOOP	buildDigitString

	myWriteString	[ebp+12]

	frameEnd
	RET		8
intToString	ENDP

farewell PROC
	frameStart
	CALL	Crlf
	CALL	Crlf
	myWriteString	[ebp + 8]
	frameEnd
	RET		4
farewell ENDP

END main