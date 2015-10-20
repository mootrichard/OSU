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
      size--;
      if(size == 0){
        return incArray[0];
      }
      else{
        return incArray[size] + sumOfArray(incArray, size);
      }
    }
};

std::string userString = "";

int testArray[10] = {10,11,12,13,14,15,16,17,18,19};
int N = 10;

int main() {
  std::cout << "Please enter a string: ";
  std::getline(std::cin, userString);
  std::cout << "\n";
  std::string *stringPointer = &userString;
  recursive::stringRev(stringPointer);

  std::cout << recursive::sumOfArray(testArray, N) << std::endl;
}