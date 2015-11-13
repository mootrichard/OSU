TITLE Assignment Four Composite Number Calculator (assign4.asm)

;// Author: Richard Moot
;// Description: This program calculates a specified number of composite numbers ranging between 1 and 400
;//   It validates user input to make sure that the number is between 1 and 400. It will print out the specified
;//	  number of composite numbers 10 per line spaced out evenly

INCLUDE Irvine32.INC

.const
LOW_LIMIT = 1
UP_LIMIT = 400

.data
greeting	BYTE "Composite Numbers Programmed by Richard Moot", 0
instruct1	BYTE "Enter the number of composite numbers you would like to see.", 0
instruct2	BYTE "I'll accept requests for up to 400 composites.", 0
userReq		BYTE "Enter the number of composites to display [1 .. 400]: ", 0
outOfRange	BYTE "Out of range. Try again.", 0
sayBye		BYTE "Results certified by Richard Moot. Have a great day!", 0
ecAttempt	BYTE "**EC Attempt: Numbers are aligned",0

userNum			DWORD ?
checkCompNum	DWORD 4
nextCompNum		DWORD 4
loopLimit		DWORD ?

.code
main PROC
CALL Clrscr

CALL intro
CALL getUserData
CALL showComposites
CALL farewell

exit
main ENDP

;// Providing greeting and instructions about the program to the user.
;// Receives: none
;// Returns: none
;// Preconditions: none
;// Registers Changed: edx
intro PROC
	MOV edx, OFFSET greeting
	CALL WriteString
	CALL Crlf
	CALL Crlf
	MOV edx, OFFSET ecAttempt ;// Declaring extra credit attempt
	CALL WriteString
	CALL Crlf
	CALL Crlf
	MOV edx, OFFSET instruct1 ;// Explaining program instructions
	CALL WriteString
	CALL Crlf
	MOV edx, OFFSET instruct2 ;// Declaring input limits to the user
	CALL WriteString
	CALL Crlf
	CALL Crlf
	RET
intro ENDP

;// Obtains input data from user, calls other procedure to accomplish validation, then stores data
;// Receives: none
;// Returns: Valid input number from the user
;// Preconditions:  none
;// Registers changed : edx
getUserData PROC
		MOV edx, OFFSET userReq ;// Intructing user to provide input numer
		CALL WriteString
		XOR eax, eax
		CALL ReadInt
		CALL validate ;// Verifying user input data
		MOV userNum, eax;// User input is correct, pushing it into the userName 
	RET
getUserData ENDP

;// Validates user input to ensure a valid entry has been selected
;// Receives: User input number being attempted
;// Returns: Error warning to console if input is invalid, otherwise the valid input number
;// Preconditions:  User input number
;// Registers changed : eax, edx
validate PROC
	JMP checkHere ;// No need to warn user on first execution, skipping warning
	dataWrong: ;// Warning the user has an invalida input, sending them back to get a correct input
		MOV edx, OFFSET outOfRange
		CALL WriteString
		CALL Crlf
		CALL getUserData
	checkHere: ;// Verifying their input is too high or too low
		CMP eax, LOW_LIMIT
		JL dataWrong
		CMP eax, UP_LIMIT
		JG dataWrong
	RET
validate ENDP

;// Prints composite numbers, 10 per line up to user defined limit
;// Receives: Next composite number
;// Returns: Composite numbers up to the user defined limit
;// Preconditions: Valid user input number
;// Registers changed : eax, ecx
showComposites PROC
	MOV eax, userNum
	MOV loopLimit, eax
	MOV ecx, userNum ;// Setting our main loop limiter to let us jump out once we have reached our user specified number of composites
	loopAll:
		PUSH ecx ;// Moving out counter for safe keeping on the stack
		MOV ecx, 10 ;// Setting counter so we print 10 per line
		loopTen:
			CALL checkComp ;// Checking for the next composite number
			MOV eax, nextCompNum ;// Writing the next composite to the console
			CALL WriteDec
			MOV al, TAB ;// Inserting a tab to align the columns
			CALL WriteChar
			DEC loopLimit ;// Decrementing our main loop limit so that we can prematurely jump out mid line if we are almost done
			CMP loopLimit,0
			JE stopPrint
			LOOP loopTen ;// Continuing for 10 composites per line
		POP ecx ;// Getting our main limit off the stack
		LOOP loopAll
	stopPrint:
		POP ecx ;// Popping our limit back off the stack to be safe since we are done and don't want to leave anything on the stack
	RET
showComposites ENDP

;// Checks for what the next composite number is
;// Receives: none
;// Returns: The next composite number that is being searched for
;// Preconditions: Valid input number between 1 and 400
;// Registers changed : eax, ebx, edx
checkComp PROC
	skipPrime:
	XOR edx, edx ;// Clearing out edx for division
	MOV eax, checkCompNum ;// This is our number that we are checking is a composite
	MOV ebx, 2 ;// First trying to divide by 2
	DIV ebx
	CMP edx, 0 ;// If we find a composite we are done and can move on
	JE haveComp
	INC EBX ;// Looks like we didn't find a composite so we should increase the divisor and keep trying
	keepChecking:
		XOR edx, edx
		XOR eax, eax
		CMP ebx, checkCompNum ;// Seeing if our divisor is the same as our number we are checking, cause then we have a prime
		JE noComp
		MOV eax, checkCompNum ;// Checking if the next divisor will evenly divide into our number
		DIV ebx
		CMP edx, 0
		JE havecomp
		ADD ebx, 2 ;// We don't see to have a composite yet (incrementing by 2 from here to keep numbers odd)
		JMP keepChecking
	havecomp:
		MOV eax,checkCompNum ;// Found a composite number storing it so it could be printed
		MOV nextCompNum, eax
		INC checkCompNum ;// Incrementing our check number so next time we don't just print the last found composite
		JMP timeToGo ;// Exiting out of the procedure from there
	noComp:
		INC checkCompNum ;// Found a prime, better move onto the next number
		JMP skipPrime
	timeToGo:
	RET
checkComp ENDP

;// Says farewell to the user
;// Receives: none
;// Returns: none
;// Preconditions:  none
;// Registers changed : edx
farewell PROC
	CALL Crlf
	MOV edx, OFFSET sayBye
	CALL WriteString
	CALL Crlf
	RET
farewell ENDP

END main