TITLE Assignment Three Accumulator Arithmetic (assign3.asm)

;// Author: Richard Moot
;// Description: This program collects negative numbers between -100 and -1. It then calculates the sum
;//   and average of these numbers and displays that to the user. It will validate that a correct integer
;//   has been entered and calculate the sum and average when a positive number is entered.
;// Date : 11/01/2015

INCLUDE Irvine32.inc

.const
LOW_LIMIT	EQU -100
UP_LIMIT	EQU -1

.data
progTitle	BYTE "Welcome to the Accumulator Arithmetic Program created by Richard Moot", 0
askName		BYTE "What is your name? ", 0
userName	BYTE 32 DUP(0)
greetUser	BYTE "Hello, ",0
instrUser1	BYTE "Please enter numbers in [-100,-1].",0
instrUser2	BYTE "Enter a non-negative number when you are finished to see results.", 0
entNumber	BYTE ". Enter number: ",0
reportInc1	BYTE "You entered ",0
reportInc2	BYTE " valid numbers.",0
tellSum		BYTE "The sum of your valid numbers is ",0
tellAvg		BYTE "The rounded average is ",0
byeUser		BYTE "Thank you for playing Integer Accumulator! It's been a pleasure to meet you, ",0
invalidInt	BYTE "That is not valid input",0
ecDesc		BYTE "**EC: Numbers lines during user input",0
noNegs		BYTE "No negative numbers were entered!",0

counter		DWORD 0
sumTotal	SDWORD 0
quotient	SDWORD 0
remainder	SDWORD 0
lineNumber	DWORD 1

.code
main PROC
CALL Clrscr

;// Introduction | Get User's name & Greet the User
intro:
	MOV edx, OFFSET progTitle ;// Delcaring the program title and creator to the user
	CALL WriteString
	CALL Crlf
	MOV edx, OFFSET ecDesc ;// Declaring extra credit attempt
	CALL WriteString
	CALL Crlf
	CALL Crlf
	MOV edx, OFFSET askName ;// Requesting the user's name
	CALL WriteString
	MOV edx, OFFSET userName
	MOV ecx, SIZEOF userName - 1
	CALL ReadString
	CALL Crlf

	;// 
	MOV edx, OFFSET greetUser
	CALL WriteString
	MOV edx, OFFSET userName ;// Greeting the user with their name
	CALL WriteString
	CALL Crlf
	CALL Crlf

;// User Instructions | Explain the program and what is expected from the user
instruct:
	;// Giving the user instructions on how the program works and what to do
	MOV edx, OFFSET instrUser1
	CALL WriteString
	CALL Crlf
	MOV edx, OFFSET instrUser2
	CALL WriteString
	CALL Crlf
	JMP mainloop ;// 

;// Get User Data | Prompt User for numbers requesting to be summed
errorDetect:
	;// An invalid integer was found, notifying the user to pick a different integer (below -100)
	MOV edx, OFFSET invalidInt
	CALL WriteString
	CALL Crlf

mainLoop:	
	MOV eax, lineNumber ;// Numbering each line during user input
	CALL WriteDec
	INC lineNumber ;// Incrementing number for next line input
	XOR eax, eax
	MOV edx, OFFSET entNumber ;// Requsting the user's next input number
	CALL WriteString
	CALL ReadInt
	CMP eax, LOW_LIMIT ;// Validating number against lower limit
	JL errorDetect
	CMP eax, UP_LIMIT ;// Seeing if the number is positive so we can start calculating
	JG doCalcs
	ADD sumTotal, eax ;// Adding value to sumTotal for later calculations
	INC counter ;// Incrementing counter for later calculations
	JMP mainLoop

doCalcs:
	CMP counter, 0 ;// Ensuring we got some number to prevent zero division (program crash)
	JE noNegatives
	MOV eax, sumTotal ;// Performing division to get average
	CDQ
	MOV ebx, counter
	IDIV ebx
	MOV quotient, eax
	
	MOV remainder, edx ;// Checking here to see if we need to round up or down
	XOR ebx, ebx
	SUB ebx, remainder ;// Switching the remainder from negative to positive
	SHL ebx, 1 ;// Doubling the remainder
	CMP ebx, counter ;// Comparing the doubled remainder to the divisor, if its greater it should be decremented
	JG roundDown
	JMP displayResults ;// We didn't need to round down (further from zero) 
roundDown:
	DEC quotient ;// Decrementing the quotient since we had a large enough remainder

displayResults:
	;// Displaying the number of valid integers to the user
	MOV edx, OFFSET reportInc1
	CALL WriteString
	MOV eax, counter
	CALL WriteDec
	MOV edx, OFFSET reportInc2
	CALL WriteString
	CALL Crlf
	;// Displaying the sum of all of the valid integers
	MOV edx, OFFSET tellSum
	CALL WriteString
	MOV eax, sumTotal
	CALL WriteInt
	CALL Crlf
	;// Displaying the average of all of the valid integers
	MOV edx, OFFSET tellAvg
	CALL WriteString
	MOV eax, quotient
	CALL WriteInt
	CALL Crlf
	JMP farewell

;// Farewell
noNegatives:
	MOV edx, OFFSET noNegs ;// Letting them know that no valid integers were entered
	CALL WriteString
	CALL Crlf

farewell:
	;// Saying goodbye to the user and using their name
	MOV edx, OFFSET byeUser
	CALL WriteString
	MOV edx, OFFSET userName
	CALL WriteString
	CALL Crlf
exit
main ENDP

END main