/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	DynArr *zen = newDynArr(10);

	char temp = *s;
	
	while (temp != '\0') {
		char temp = nextChar(s);
		if( temp == '(' || temp == '{' || temp == '[' ){ // we found an opener and should push it
			pushDynArr(zen, temp);
		}
		if( temp == ')' || temp == '}' || temp == ']' ){
			if(isEmptyDynArr(zen)){
				return 0;
			}
			if(temp == ')' && topDynArr(zen) != '('){ // we found and closed one and should compare it
				return 0;
			}
			if(temp == '}' && topDynArr(zen) != '{'){
				return 0;
			}
			if(temp == ']' && topDynArr(zen) != '['){
				return 0;
			}

			if(temp == ')' && topDynArr(zen) == '('){ // here we are matching the open one with a closed one
				popDynArr(zen);
			}
			if(temp == '}' && topDynArr(zen) == '{'){
				popDynArr(zen);
			}
			if(temp == ']' && topDynArr(zen) == '['){
				popDynArr(zen);
			}
		}
		if(temp == '\0'){
			break;
		}
	}
	if(!isEmptyDynArr(zen)) {return 0;} // need to make sure that we didn't leave an open one
	return 1;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

