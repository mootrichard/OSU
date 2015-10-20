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

    void sumOfArray(int ofArrays[], int sizeOfArray) {

    }
};

std::string userString = "";

int main() {
  std::cout << "Please enter a string: ";
  std::getline(std::cin, userString);
  std::cout << "\n";
  std::string *stringPointer = &userString;
  recursive::stringRev(stringPointer);
}