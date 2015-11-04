// Author: Richard Moot
// Description: These are functions that utilize polymorphism in order to re-define their copy functions
// for different purposes. There is a Copy function, an Uppercase function, and an Encryption function.
// Date: October 29, 2015


#ifndef FILE_FILTER_HPP
#define FILE_FILTER_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

class FileFilter{
	public:	
		void doFilter(std::ifstream &in, std::ofstream &out);
		virtual char transform(char ch) = 0;
};

class Copy: public FileFilter {
	public:
		char transform(char ch);
};

class UpperCase: public FileFilter {
	public:
		char transform(char ch);
};

class Encrypt: public FileFilter{
	private:
		int cypher;
	public:
		Encrypt();
		char transform(char ch);
};

#endif // FILE_FILTER_HPP