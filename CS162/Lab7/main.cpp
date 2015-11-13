#include "FileTest.hpp"

int main(){
  FileTest newFile;
  std::cout << "The first file input will search for the zero in the give input file you provide." << std::endl;
  std::cout << "The second file input will the given input file you provide and allow you to designate an output file for your sorted numbers to go into." << std::endl;

  std::cout << "Zero is character " << newFile.searchValue() << std::endl;
  newFile.sortValue();
}