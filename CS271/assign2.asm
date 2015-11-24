TITLE Assignment Two Fibonacci Numbers(assign2.asm)

;// Author: Richard Moot
;// Description: This is program designed to greet a user, get a number, and display an amount of Fibonacci terms
;//				 up the the designated user input (between 1 and 46).
;//				 Also attempting EC with having the numbers aligned to columns (didn't know how to account for terms above 36 though)
;// Date : 10/17/2015

INCLUDE Irvine32.inc

UP_LIMIT	EQU 46
LOW_LIMIT	EQU 1

.data
	greet1		BYTE "Welcome to Fibonacci numbers!",0
	greet2		BYTE "My name is Richard Moot, please enter your name? :",0
	userName	BYTE 32 DUP(0)
	sayHello1	BYTE "Hello ",0
	sayHello2	BYTE "!", 0
	sayGoodbye	BYTE "Farewell, ",0
	instruct	BYTE "This program will display an amount of Fibonacci number(s) selected (between 1 and 46)",0
	requestNum	BYTE "Please enter your number: ",0
	wrongNum	BYTE "You did not enter a number between 1 and 46",0
	fiveSpace	BYTE "     ",0
	extraCredit	BYTE "**EC: Displaying numbers in alinged columns (atleast up to 36)",0

	userNum		DWORD 0
	startNum	DWORD 1
	loopNeed	DWORD 0

.code
main PROC
CALL Clrscr

;// Introduction | Get User's name & Greet the User
intro:
	MOV edx, OFFSET greet1 ;// Saying hello the the user and asking for thier name
	CALL WriteString
	CALL Crlf
	MOV edx, OFFSET extraCredit ;// Delaring my extra credit attempt
	CALL WriteString
	CALL Crlf
	MOV edx, OFFSET greet2
	CALL WriteString
	MOV edx, OFFSET userName
	MOV ecx, SIZEOF userName - 1 ;// Getting the user's name
	CALL ReadString
	CALL Crlf

	MOV edx, OFFSET sayHello1 ;//Using the User's name to greet them
	CALL WriteString
	MOV edx, OFFSET userName
	CALL WriteString
	MOV edx, OFFSET sayHello2
	CALL WriteString
	CALL Crlf

;// User Instructions | Explain the program and what is expected from the user
instructions:
	MOV edx, OFFSET instruct ;// Providing instruction and requesting the user's number
	CALL WriteString
	CALL Crlf

;// Get User Data | Prompt User for number of Fibonacci terms to be displayed
getData:
	MOV edx, OFFSET requestNum ;// Getting the number of terms that the user wants displayed
	CALL WriteString
	CALL ReadInt
	MOV userNum, eax
testInput:
	CMP userNum, UP_LIMIT ;// Verifying the input is below 46
	JG inputError
	CMP userNum, LOW_LIMIT ;// Verifying the input is above 0
	JL inputError
	JMP skipLoop ;// Looks like everything is valid, lets see if we can skip something
inputError:
	MOV edx, OFFSET wrongNum
	CALL WriteString
	CALL Crlf
	JMP getData

;// Checking to see if we can skip looping
skipLoop:
	CMP userNum, 1 ;// Only want one number, skipping looping numbers
	JE onlyOne
	CMP userNum, 2 ;// Only want two numbers, skipping looping the numbers
	JE onlyTwo

;// Calculate & Display all Fibonacci terms up to userInput

init:
	MOV	ebx, 1 ;// Initial Fibonacci numbers
	MOV	edx, 0
outterLoop:
	MOV ecx, 5 ;// We'll be displaying 5 terms per line, setting loop counter accordingly
insideLoop:
	MOV	eax, ebx
	ADD	eax, edx
	MOV	ebx, edx
	MOV	edx, eax
	CALL WriteDec ;// Writing our next Fibonacci number
	MOV	al, TAB ;// Using TAB to align numbers to a column (only works for values below 37, after which numbers are out of alignment)
	CALL WriteChar
	SUB userNum, 1 ;// Decrementing the user number so we know when to prematurely exit in order to print the right number terms
	CMP userNum, 0 ;// This will let us exit the loop should be below 5 more terms needing to be displayed
	JE farewell
	LOOP insideLoop
	CALL Crlf

outsideLoop:
	JMP outterLoop ;// Jumping back into the loop cause we're not done yet

;// Farewell
onlyOne:
	MOV eax, 1
	CALL WriteDec ;// Looks like we got off easy, only need to show 1 term
	JMP farewell

onlyTwo:
	MOV eax, 1
	CALL WriteDec 
	MOV	al, TAB
	CALL WriteChar
	MOV eax, 1
	CALL WriteDec ;// Looks like we got off easy, only need to show 2 terms
	JMP farewell

farewell:
	CALL Crlf
	MOV edx, OFFSET sayGoodbye ;// Saying farewell
	CALL WriteString
	MOV edx, OFFSET userName ;// Using user's name in farewell
	CALL WriteString
	CALL Crlf
exit
main ENDP

END main