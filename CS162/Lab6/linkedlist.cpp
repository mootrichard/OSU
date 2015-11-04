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
    }
    
    int Stack::remove(){

    }

    // typedef struct Stacknode {
    //   int data 
    //   Stacknode* next
    // };

  
    Queue::Queue(){

    }
    
    Queue::~Queue(){

    }
    
    void Queue::addNode(int value){

    }
    
    int Queue::remove(){

    }

    // typedef struct Queuenode {
    //   int data 
    //   Queuenode* next
    //   Queuenode* prev
    // };
