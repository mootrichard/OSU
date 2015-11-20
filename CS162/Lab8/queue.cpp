// Author: Richard Moot
// Date: November 19, 2015
// Description: This Queue class is an abstract data type (ADT) that queues in integers. When a value is removed
//  it is actually set to -1 and then moved out of the queue (nothing is actually destroyed though). Each node is
//  and doubly linked. The structuct is circular so the front and back nodes lead to one another as well.
#include "queue.hpp"

// We are creating the initial emtpy node here
Queue::Queue(){
  Queuenode* newNode = new Queuenode;
  newNode->data = -1;
  newNode->next = newNode;
  newNode->prev = newNode;
  back = newNode;
  front = newNode;
}

// Our function for adding integers into the back of the queue
void Queue::addBack(int incData){
  Queuenode* newNode = new Queuenode;
  newNode->data = incData;
  if(back->data == -1){ // Checking if the queue is empty and we need to change front as well
    newNode->next = newNode;
    newNode->prev = newNode;
    front = newNode;
    back = newNode;
    return;
  }
  newNode->next = front; // Looping it back to the front of the queue
  back->next = newNode; // Setting next of the current back to the new node
  newNode->prev = back; // The new node will point prev to the old back node
  back = newNode; // Set back to the new node now that it is setup
}

int Queue::getFront(){
  if(back->data == -1){ // Makeing sure we don't have an empty queue
    return -1;
  }
  return front->data;
}

void Queue::removeFront(){
  front->data = -1; // Setting to sentinel value in order to empty node
  front = front->next;
}