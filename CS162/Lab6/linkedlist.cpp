#include "linkedlist.hpp"
  
    Stack::Stack(){
      top = NULL;
    }
    
    void Stack::addNode(int value){
      Stacknode *newOne = new Stacknode;
      newOne->next = top;
      newOne->number = value;
      top = newOne;
      std::cout << value << " added to a Stacknode" << std::endl;
    }
    
    int Stack::remove(){
      if(top == NULL){
        std::cout << "No more nodes found. Error ";
        return 0;
      }
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

    void Queue::addNode(int value){
      Queuenode *newOne = new Queuenode;
      newOne->number = value;
      if(front == NULL){
        front = newOne;
        back = newOne;
      }
      newOne->next = back;
      back = newOne;

      std::cout << value << " added to a Queuenode" << std::endl;
    }
    
    int Queue::remove(){
      if(front == NULL){
        std::cout << "No more nodes found. Error ";
        return 0;
      }
      Queuenode* removeNode = front;
      int returnNum = front->number;
      front = front->next;
      delete removeNode;
      return returnNum;
    }
