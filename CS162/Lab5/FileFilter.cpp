// Author: Richard Moot
// Description: These are functions that utilize polymorphism in order to re-define their copy functions
// for different purposes. There is a Copy function, an Uppercase function, and an Encryption function.
// Date: October 29, 2015

#include "FileFilter.hpp"

void FileFilter::doFilter(std::ifstream &in, std::ofstream &out){
	char c; // for storing our current char we want to write to file
	while(true){
		c = in.get();
		if(in.eof()) break; // terminate once we hit the end of file
		out << transform(c); // writing char to output file
	}
}

// regular copy function, just returns what is read
char Copy::transform(char ch){
	return ch;
}

// converts lowercase letter to an uppercase letter
char UpperCase::transform(char ch){
	return std::toupper(ch);
}

// constructor that requests the shift input from the user
Encrypt::Encrypt(){
	std::cout << "\n Indicate your encryption number (between 1 and 20): ";
	std::cin >> cypher;
}

// This is our encryptor that uses the current cypher shift to move the letters on output
char Encrypt::transform(char ch){
	if(std::isalpha(ch)){ // want to be sure we have a letter before transforming
		if(std::islower(ch)){ // if its lowercase, we have differt limits
			if((ch + cypher) > 122){
				return (ch + cypher - 26);
			}
			else if (std::isupper(ch)){ // same goes for the upper case
				if((ch + cypher) > 90){
					return (ch + cypher - 26);
				}
			}
			else{
				return ch + cypher; // we're safe, just return the shifted char
			}
		}
	}
	return ch; // we don't have a char, better just return it
}

