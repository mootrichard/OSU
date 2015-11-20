#include "queue.hpp"
#include <iostream>

int main(){
  Queue test;
  int userChoice = 0;
 
 // This is our driver, allows selection process for testing the queue
  while(userChoice != 5){
    std::cout << "\nPlease select a choice from the following:" << std::endl;
    std::cout << "\t1. Enter a number into the queue" << std::endl;
    std::cout << "\t2. Return the number at the front of the queue" << std::endl;
    std::cout << "\t3. Remove number from front of the queue" << std::endl;
    std::cout << "\t4. Unload queue (Warning! This remove all values from the queue)" << std::endl;
    std::cout << "\t5. Exit the program" << std::endl;
    std::cout << "Enter choice here: ";
    std::cin >> userChoice;

      if(userChoice == 1){ // First choice enters numbers into the queue
        int userInt = 0;
        std::cout << "\nPlease enter a positive integer: ";
        std::cin >> userInt;
        if(userInt <= -1){ // User number validiation (don't want a non-postive number entered or it will mess up our queue)
          std::cout << "\nThat is not a valid integer" << std::endl;
        }
        else if(userInt >= 0){ // We are safe, so we can put the number in the queue
          test.addBack(userInt);
          std::cout << "\n" << userInt << " has been added to the queue.\n" << std::endl;
        }
      }
      else if(userChoice == 2){
        if(test.getFront() == -1){ // Checking if the queue is empty
          std::cout << "\nQueue is empty, nothing to return\n" << std::endl;
        }
        else{ // Returning the integer at the front
          std::cout << "\n" << test.getFront() << " is at the front of the queue\n" << std::endl;
        }
      }
      else if(userChoice == 3){ // Removing the front node from the queue
        if(test.getFront() == -1){ // Making sure the queue is not empty
          std::cout << "\nQueue is empty cannot remove anything\n" << std::endl;
        }
        else{ // Letting the user know which integer was removed and removing it
          std::cout << "\n" << test.getFront() << " was removed from the queue\n" << std::endl;
          test.removeFront();
        }
      }
      else if(userChoice == 4){ // This empties the entire queue while logging to the console
        if(test.getFront() != -1){
          while(test.getFront() != -1){
            std::cout << test.getFront() << std::endl;
            test.removeFront();
          }
        }
        else{ // Letting the user know that the queue is empty and cannot be unloaded
          std::cout << "\nQueue is empty\n" << std::endl;
        }
      }
      else if(userChoice == 5){ // Exiting the program
        std::cout << "\nThanks for testing out the queue!\n" << std::endl;
        break;
      }
  }
}