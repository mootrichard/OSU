#include "linkedlist.hpp"

int main (){
  Stack thisStack;
  Queue thisQueue;

  thisStack.addNode(1);
  thisStack.addNode(2);
  thisStack.addNode(3);
  thisStack.addNode(4);
  thisStack.addNode(5);

  std::cout << thisStack.remove() << std::endl;
  std::cout << thisStack.remove() << std::endl;
  std::cout << thisStack.remove() << std::endl;
  std::cout << thisStack.remove() << std::endl;
  std::cout << thisStack.remove() << std::endl;
  std::cout << thisStack.remove() << std::endl;



  thisQueue.addNode(1);
  thisQueue.addNode(2);
  thisQueue.addNode(3);
  thisQueue.addNode(4);
  thisQueue.addNode(5);
  std::cout << thisQueue.remove() << std::endl;
  std::cout << thisQueue.remove() << std::endl;
}