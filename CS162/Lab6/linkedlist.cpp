// Author: Richard Moot
// Date: Novmeber 5, 2015
// Description: These are two classes for implementing a linked list Stack and a linked
//   list Queue. The stack is a FILO order, so the element at the top is the one that is
//   removed. The Queue is a FIFO order, so the element in the front is always removed.

#include "linkedlist.hpp"
    // Our constructor initializes the top pointer to NULL
    Stack::Stack(){
      top = NULL;
    }
    // This is for adding a node onto the top of the Stack
    void Stack::addNode(int value){
      Stacknode *newOne = new Stacknode; // Here is our new node
      newOne->next = top; // Making sure our new node point to the node before it
      newOne->number = value; // Storing our input number
      top = newOne; // Pointing top to the new node we created
      std::cout << top->number << " added to a Stacknode" << std::endl;
    }
    
    // Here is our remove function for taking elements off the top of the stack
    int Stack::remove(){
      if(top == NULL){ // Stack is empty, just returning an error
        std::cout << "No more nodes found. Error ";
        return 0;
      }
      Stacknode* removeNode = top; // We are caching the top node here
      int returnNum = top->number; // Storing the number for returning later
      top = top->next; // Setting top to the next node
      delete removeNode; // Removing the node that was top was previously pointing to
      return returnNum; // Returning the number that was stored in the removed node
    }

    // Our constructor initializes the front and back pointers to NULL
    Queue::Queue(){
      front = NULL;
      back = NULL;
    }

    // Our addNode function for the doulby linked list Queue 
    void Queue::addNode(int value){
      Queuenode *newOne = new Queuenode;
      newOne->number = value;
      if(front == NULL){ // No items in the queue yet, need to set Front and Back
        newOne->prev = NULL;
        newOne->next = NULL;
        front = newOne;
      }
      else{ // Looks like something is in the queue, we can set next and prev now
        back->next = newOne;
        newOne->prev = back;
      }
      back = newOne; // We can now place newOne at the back of the queue

      std::cout << back->number << " added to a Queuenode" << std::endl;
    }
    
    int Queue::remove(){
      int returnNum;
      if(front == NULL){ // Uh oh queue is emtpy, need to warn the user
        std::cout << "No more nodes found. Error ";
        return 0;
      }
      if(front->next == NULL){ // Looks like we are at the last node
        returnNum = front->number; // Caching the last number
        delete front; // Deleting the last node
        front = NULL; // Setting both front and back to NULL to be cautious
        back = NULL;
        return returnNum;
      }

      returnNum = front->number;

      front = front->next;
      if(front->prev){ //Checking to make sure there is a previous node to delete
        delete front->prev;
      }
      front->prev = NULL;
      return returnNum;
    }
