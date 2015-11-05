#include "linkedlist.hpp"

int main (){
  Stack thisStack;

  thisStack.addNode(1);
  thisStack.addNode(2);
  thisStack.addNode(3);
  thisStack.addNode(4);
  thisStack.addNode(5);

  std::cout << thisStack.remove() << std::endl;

  Queue thisQueue;

  thisQueue.addNode(1);
  thisQueue.addNode(2);
  thisQueue.addNode(3);
  thisQueue.addNode(4);
  thisQueue.addNode(5);

}