#include <iostream>
#include <string>

namespace recursive {

    void stringRev(std::string *incoming) {
      if (incoming->size() == 1) {
        std::cout << incoming->at(0) << std::endl;
      } 
      else {
        std::cout << incoming->at(incoming->length() - 1);
        incoming->resize(incoming->length() - 1);
        stringRev(incoming);
      }
    }

    int sumOfArray(int incArray[], unsigned int size) {
      if(size == 0){
        return incArray[0];
      }
      else{
        return incArray[size-1] + sumOfArray(incArray, size-1);
      }
    }

    int triNumber(unsigned int userNum){
      if (userNum == 0){
        return userNum;
      }
      else{
        return userNum + triNumber(userNum -1);
      }
    }
}

int main() {
    unsigned int userChoice = 0;

    std::cout << "\n" << "Hi! Welcome to Recursive Functions!" << "\n";

    while(userChoice != 4){
      std::cout << std::endl;
      std::cout << "Please select which function you would like to use:" << "\n\n";
      std::cout << "Enter 1 for String Reversal" << "\n";
      std::cout << "Enter 2 for Sum Array" << "\n";
      std::cout << "Enter 3 for Triangle Number" << "\n";
      std::cout << "Enter 4 to exit the program" << "\n";
      std::cout << "Enter selection here: ";
      std::cin >> userChoice;

      if(userChoice == 1){
      	  std::cin.ignore();
          std::string userString;
          std::cout << "Please enter a string: ";
          getline(std::cin, userString);
          std::string *stringPointer = &userString;
          std::cout << std::endl;
          recursive::stringRev(stringPointer);
        }
        else if (userChoice == 2){
          unsigned int size = 0;
          std::cout << "Please enter the size of your array of integers: ";
          std::cin >> size;
          int *pointerArray = new int[size];
          for (unsigned int i = 0;i < size; i++){
            std::cout << "Enter integer " << i << ": ";
            std::cin >> pointerArray[i];
          }
          std::cout << "The sum of your array is: " << recursive::sumOfArray(pointerArray, size) << std::endl;
          delete[] pointerArray;
        }
        else if (userChoice == 3){
          unsigned int userNum = 0;
          std::cout << "Enter how many rows you want in your triangle: ";
          std::cin >> userNum;
          std::cout << "Your triangle contains: " <<recursive::triNumber(userNum) << std::endl;
        }
        else{
          std::cout << "Thanks for using the recursive functions, hope you had fun! :)" << std::endl;
        }
      }
}