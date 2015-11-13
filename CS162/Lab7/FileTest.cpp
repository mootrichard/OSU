// Author: Richard Moot
// Date: 11-12-2015
// Description: This FileTest class is designed to demonstrate the use
//   of reading files and sorting and searching them. I did not have time to 
//   implement the binary search algorithm in this class though.

#include "FileTest.hpp"

// Basic constructor for creating our files with.
FileTest::FileTest(){
    std::ifstream fileIn;
    std::ofstream fileOut;
}

// Used for opening our designated files
void FileTest::openFile(){
  std::cout << "Enter input filename: ";
  std::cin >> fileInName;

  fileIn.open(fileInName.c_str());
}

// Creates an output for for us
void FileTest::createFile(){
  std::cout << "Enter output filename: ";
  std::cin >> fileOutName;

  fileOut.open(fileOutName.c_str());
}

// Returns the position of the zero found in the file
int FileTest::searchValue(){
  openFile();
  int position = -1;
  int i = 0;
  while(true){
    if(fileIn.eof()){
      fileIn.close();
      break;
    }
    i++;
    if(fileIn.get() == '0'){
      position = i;
    }
  }
  if(position == -1){
    std::cout << "[NOT FOUND] returning -1! ";
  }
  return position;
}

// Sorts the file into an output file from greatest to least using bubble sort
void FileTest::sortValue(){
  openFile();
  std::vector<char> v;
  char c;
  while(fileIn.get(c)){
    if(fileIn.eof()){
      break;
    }
    v.push_back(c);
  }
  for (unsigned int i = 1; i != v.size(); ++i){
    for (unsigned int j = 0; j != v.size() - i; ++j){
      if(v.at(j+1) > v.at(j)){
        std::swap(v.at(j+1), v.at(j));
      }
    }
  }
  createFile();
  for(std::vector<char>::iterator it = v.begin(); it != v.end(); ++it){
    fileOut.put(*it);
  }
  fileOut.close();
  return;
}