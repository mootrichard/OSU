// Author: Richard Moot
// Date: Novmeber 5, 2015
// Description: This is the main file for our Stack/Queue program
#include "linkedlist.hpp"

int main (){
  Stack thisStack;
  Queue thisQueue;

  for(unsigned int i = 0; i < 10; i++){
    thisStack.addNode(i);
  }
  for(unsigned int i = 0; i < 10; i++){
    thisQueue.addNode(i);
  }

  for(unsigned int i = 0; i < 11; i++){
    std::cout << "Removed node withe value " << thisStack.remove() << std::endl;
  }
  for(unsigned int i = 0; i < 11; i++){
    std::cout << "Removed node withe value " << thisQueue.remove() << std::endl;
  }
}