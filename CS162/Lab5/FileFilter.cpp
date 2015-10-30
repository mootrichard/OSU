#include "FileFilter.hpp"

void FileFilter::doFilter(std::ifstream &in, std::ofstream &out){
	char c;
	while(true){
		c = in.get();
		if(in.eof()) break;
		out << transform(c);
	}
}

char Copy::transform(char ch){
	return ch;
}

char UpperCase::transform(char ch){
	return std::toupper(ch);
}

Encrypt::Encrypt(){
	std::cout << "\n Indicate your encryption number (between 1 and 20): ";
	std::cin >> cypher;
}

char Encrypt::transform(char ch){
	if(std::isalpha(ch)){	
		if(std::islower(ch)){
			if((ch + cypher) > 122){
				return (ch + cypher - 26);
			}
			else if (std::isupper(ch)){
				if((ch + cypher) > 90){
					return (ch + cypher - 26);
				}
			}
			else{
				return ch + cypher;
			}
		}
	}
	return ch;
}

