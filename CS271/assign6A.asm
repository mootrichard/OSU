TITLE Assignment Six-A Read/Write Values (assign6A.asm)

;// Author: Richard Moot
;// Date:	12-6-2015
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
displayString	MACRO	buffer
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
	displayString	promptUser
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
extra1		BYTE	"**EC: ReadVal and WriteVal procedures are recursive",0
extra2		BYTE	"**EC: Numbers each line of user input and display a running subtotal of the user's numbers.", 0

userReq		BYTE	15 DUP(?)
outputs		BYTE	15 DUP(?)
line		DWORD	1
entryLim	DWORD	10
subTotal	DWORD	0
numArray	DWORD	10 DUP(?)

.code
main PROC
	CALL	Clrscr

	PUSH	OFFSET extra2
	PUSH	OFFSET extra1
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

	PUSH	OFFSET outputs
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
;// Receives: intro1, intro2, extra1, extra2
;// Returns: none
;// Preconditions: All greeting paramenters passed in as offset in the order they appear
;// Registers Changed: edx, ebp
intro PROC
	frameStart

	;// Writing intro1
	displayString	[ebp+12]
	CALL Crlf
	;// Writing intro2
	displayString	[ebp+8]
	CALL Crlf
	displayString	[ebp+16]
	CALL Crlf
	displayString	[ebp+20]
	CALL Crlf
	CALL Crlf

	frameEnd

	RET 16
intro ENDP

;//PUSH	subTotal			+36
;//PUSH	OFFSET	subPrompt	+32
;//PUSH	line				+28
;//PUSH	entryLim			+24
;//PUSH	OFFSET error1		+20
;//PUSH	OFFSET numArray		+16
;//PUSH	OFFSET userReq		+12
;//PUSH	OFFSET request1		+8

;// Obtains input integer from user in form of string validates that string is a valid intger, converts from string to integer, then stores it in an array
;// Receives: request1, userReq, numArray, error1, entryLim, line, subPrompt, subTotal
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : eax, ebx, ecx, edx, ebp, edi, esi

readVal	PROC
	frameStart
	JMP			readValStart	;// Skipping over error message
	
readValError:
	displayString	[ebp+20]	;// User entered a wrong number, displaying an error message

;// Prompting and requesting for user input
readValStart:
	MOV			ebx, [ebp+24]		;// Checking our entryLim to see if we have hit our base case
	CMP			ebx, 0
	JE			readValEnd			;// Hit our base case, moving to end of procedure
	MOV			eax, [ebp+28]		;// Writing line number
	CALL		WriteDec
	getString	[ebp+8], [ebp+12]	;// [prompt], [user input]
	CMP			eax, 10				;// Verifying length of digit isn't too big by checking number of characters in string
	JGE			readValError
	MOV			ecx, eax			;// Setting string length for when we parse it into integers
	MOV			esi, [ebp+12]		;// Setup the user input to be parsed
	MOV			edi, [ebp+16]		;// Place destination array location in EDI for when we write out the parsed integer
	MOV			ebx, 10				;// Setup for multiplying values by 10 to create our integer
	XOR			edx, edx			;// Clearing out edx for our final division used to get the final number
	CLD								;// Set flag to forward, since we will parse the string from the beginning

stringLoop:
	;// Here we start going through the string character by character
	LODSB
	CMP			al, LOW_DIGIT			;// Checking if it is below 0, if so go back to warn it is invalid
	JL			readValError
	CMP			al, HIGH_DIGIT			;// Checking if number is above 9, if so go back to warn it is invalid
	JG			readValError
	SUB			al, 48					;// Converting from ASCII to digit
	MOVZX		eax, al					;// Extending out through whole register to read as DWORD
	ADD			eax, edx				;// Adding in values (starts at 0) before MUL by 10
	MUL			ebx						;// Multiplying by 10 to move values to left as we progress
	MOV			edx, eax				;// Saving value into edx to add in on next iteration
	LOOP		stringLoop

	MOV			eax, edx				;// Putting our value in to divide by 10 to get to our target number
	XOR			edx, edx
	DIV			ebx

	displayString [ebp+32]				;// Writing out message prompting the sub-total
	PUSH		eax						;// Saving eax for later just to be safe
	ADD			[ebp+36], eax			;// Adding our value to subTotal so that we could keep track of the running sub-total
	MOV			eax, [ebp+36]			
	MOV			[ebp+36], eax			;//	Moving running sub-total out to memory
	CALL		WriteDec				;// Writing current sub-total out to the console
	CALL		Crlf
	POP			eax						;// Returning eax back from the stack

	PUSH		eax						;// Setting value to be store in the numArray
	PUSH		edi
	CALL		storeValue				;// Storing value in numArray

	MOV			ebx, [ebp+24]			;// Decrementing entryLim in order to make sure we hit our base case
	DEC			ebx
	MOV			[ebp+24], ebx

	ADD			edi,4					;// Moving numArray to next position for the next number
	MOV			eax, [ebp+28]			;// Incrementing our line number for the next entry
	INC			eax
	MOV			[ebp+28], eax

	PUSH		[ebp+36]				;// Pushing values out for the next call to readVal since it is recursive
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

;// Integer value into numArray
;// Receives: userReq, numArray
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : edi, eax

storeValue PROC
	frameStart

	MOV		edi, [ebp+8]		;// Putting next array address into so we can store our integer there
	MOV		eax, [ebp+12]		;// Putting our integer in so we can store it
	MOV		[edi], eax			;// Storing our integer in the array

	frameEnd
	RET 8
storeValue ENDP

;// PUSH	OFFSET outputs
;// PUSH	OFFSET arrayList
;// PUSH	OFFSET spaces
;// PUSH	LENGTHOF numArray
;// PUSH	OFFSET numArray

;// Reads integer values that are stored in the array and converts them from integers back into string and writes them out to the console
;// Receives: numArray, LENGTHOF numArray, spaces, arrayList, outputs
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : eax, ebx, ecx, edx, ebp, edi, esi

writeVal PROC
	frameStart

	MOV		ebx, [ebp+12]	;// Checking if this is our first call, printing declaration of values entered
	CMP		ebx, 10
	JL		writeValStart

	;// Prompting the display of their values
	displayString	[ebp+20]

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
	displayString	[ebp+16]
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

;//PUSH	OFFSET outputs		+24
;//PUSH	OFFSET numArray		+20
;//PUSH	OFFSET avgList		+16
;//PUSH	OFFSET sumDisp		+12
;//PUSH	subTotal			+8

;// Calculates the sum and average of the user input values and writes them out to the console
;// Receives: subTotal, sumDisp, avgList, numArray, outputs
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : eax, ebx, ecx, edx, ebp, edi

writeAvg	PROC
	frameStart

	displayString	[ebp + 12]		;// Writing out or preamble to the actual values

	XOR		eax, eax				;//	Making sure that our registers are cleared out
	XOR		ebx, ebx
	XOR		edx, edx
	MOV		ecx, 10					;// Setting loop counter for all values in the array

	MOV		edi, [ebp+20]			;// Passing in our array of integers we want to sum up
findSum:
	ADD		eax, [edi]				;// Adding current value in
	ADD		edi, 4					;// Incrementing to next value in array
	LOOP	findSum					;// Loop through whole array

	PUSH	[ebp+24]
	PUSH	eax
	CALL	intToString				;// Writing out our sum
	CALL	Crlf					

	displayString	[ebp+16]		;// Writing out preamble to our average of the array values

	MOV		ebx, 10					;// Getting the average (rounded down)
	DIV		ebx

	PUSH	[ebp+24]
	PUSH	eax
	CALL	intToString				;// Writing out our average

	frameEnd
	RET		8
writeAvg	ENDP

;// Converts integer values into a string and writes them out to console 
;// Receives: numArray, outputs
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : eax, ebx, ecx, edx, ebp, edi

intToString	PROC
	frameStart
	XOR		ecx,ecx				;// Clearing out ecx so we can use it to find out how many digits we have
	MOV		eax, [ebp+8]		;// Inputting next integer we want to convert 
	MOV		edi, [ebp+12]		;// Input temp string for our output

findDigitEnd:
	XOR		edx, edx			;// We are going to keep dividing our value by 10 and increment ecx to find out how long our digit is
	MOV		ebx, 10d
	DIV		ebx
	CMP		eax, 0
	JE		endOfDigits			;// We found our last digit (less 1) so we can jump out
	INC		ecx
	JMP		findDigitEnd		;// Haven't found the last digit, better keep going

endOfDigits:					;// We found how many digits are in the number!
	INC		ecx					;// Incrementing to account for our last digit (and to place null terminator)
	ADD		edi, ecx			;// Setting it to end of string for how many digits we have
	STD
	XOR		eax, eax
	MOV		al,0				;// Null terminating our string since we are writing it backwards
	STOSB
	MOV		eax, [ebp+8]		;// Moving our string in so that we could start writing it in
buildDigitString:
	XOR		edx, edx			
	DIV		ebx					;// Dividing by 10 so we can actually just take the remainder to find our next digit
	ADD		edx, LOW_DIGIT		;// Adding 48 to set to our ASCII range
	PUSH	eax					;// Saving our value since we need to write in the BYTE to use STOSB
	MOV		al, dl				;// Writing in our digit to al so we could write it to our output string
	STOSB
	POP		eax					;// Restoring our digit so we can get the next digit
	LOOP	buildDigitString

	displayString	[ebp+12]	;// Writing out our constructed digit string

	frameEnd
	RET		8
intToString	ENDP

;// Thanks the user for using our program
;// Receives: signOff
;// Returns: none
;// Preconditions:  Paramaters need to be pass in the order listed above
;// Registers changed : edx

farewell PROC
	frameStart
	CALL	Crlf
	CALL	Crlf
	displayString	[ebp + 8]
	frameEnd
	RET		4
farewell ENDP

END main