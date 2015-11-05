#include "linkedlist.hpp"
  
    Stack::Stack(){
      top = NULL;
    }
    
    void Stack::addNode(int value){
      Stacknode *newOne = new Stacknode;
      newOne->next = top;
      newOne->number = value;
      top = newOne;
      std::cout << top->number << " added to a Stacknode" << std::endl;
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
        newOne->prev = NULL;
        newOne->next = NULL;
        front = newOne;
      }
      else{
        back->next = newOne;
        newOne->prev = back;
      }
      back = newOne;

      std::cout << back->number << " added to a Queuenode" << std::endl;
    }
    
    int Queue::remove(){
      int returnNum;
      if(front == NULL){
        std::cout << "No more nodes found. Error ";
        return 0;
      }
      if(front == back){
        back = NULL;
      }
      if(front->next == NULL){
        //last node
        returnNum = front->number;
        delete front;
        front = NULL;
        back = NULL;
        return returnNum;
      }

      returnNum = front->number;

      front = front->next;
      if(front->prev){
        delete front->prev;
      }
      front->prev = NULL;
      return returnNum;
    }
