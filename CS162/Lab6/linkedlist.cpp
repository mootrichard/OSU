#include "linkedlist.hpp"
  
    Stack::Stack(){
      top = NULL;
    }
    
    Stack::~Stack(){

    }
    
    void Stack::addNode(int value){
      Stacknode *newOne = new Stacknode;
      newOne->next = top;
      newOne->number = value;
      top = newOne;
      std::cout << value << " added to a Stacknode" << std::endl;
    }
    
    int Stack::remove(){
      Stacknode* removeNode = top;
      int returnNum = top->number;
      top = top->next;
      delete removeNode;
      return returnNum;
    }

  
    Queue::Queue(){
      front = NULL;
      back = NULL;
    }
    
    Queue::~Queue(){

    }
    
    void Queue::addNode(int value){
      Queuenode *newOne = new Queuenode;
      newOne->next = front;
      newOne->number = value;
      front = newOne;
      std::cout << value << " added to a Queuenode" << std::endl;
    }
    
    int Queue::remove(){
      return 0;
    }
