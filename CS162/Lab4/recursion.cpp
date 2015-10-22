#include <iostream>
#include <string>

namespace recursive {

    void stringRev(std::string *incoming) {
      if (incoming->length() == 1) {
        std::cout << incoming->at(0) << std::endl;
      } else {
        std::cout << incoming->at(incoming->length() - 1);
        incoming->resize(incoming->length() - 1);
        stringRev(incoming);
      }
    }

    int sumOfArray(int incArray[], int size) {
      if(size == 0){
        return incArray[0];
      }
      else{
        return incArray[size] + sumOfArray(incArray, size-1);
      }
    }
};

std::string userString = "";

int size = 0;

int main() {
  std::cout << "Please enter a string: ";
  std::getline(std::cin, userString);
  std::cout << "\n";
  std::string *stringPointer = &userString;
  recursive::stringRev(stringPointer);
  std::cout << "Please entre the size of your array of integers: ";
  std::cin >> size;

  int *pointerArray = new int[size];
  
  for (unsigned int i = 0;i < size; i++){
    std::cout << "Enter integer " << i << " : ";
    std::cin >> pointerArray[i];
    if(i == size){
        std::cout << std::endl;
    }
  }

  std::cout << recursive::sumOfArray(pointerArray, size) << std::endl;
}