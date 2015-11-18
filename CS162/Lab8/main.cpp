#include "queue.hpp"
#include <iostream>

int main(){
  Queue test;
  test.addBack(5);
  std::cout << test.getFront() << std::endl;
  test.addBack(7);
  test.removeFront();
  std::cout << test.getFront() << std::endl;

  for(int i = 20; i > 0; i--){
    test.addBack(i);
  }
  for(int j = 21; j > 0; j--){
    test.removeFront();
    std::cout << test.getFront() << std::endl;
  }
}