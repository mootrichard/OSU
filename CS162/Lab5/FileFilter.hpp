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