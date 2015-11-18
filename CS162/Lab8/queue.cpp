#include "queue.hpp"

Queue::Queue(){
  Queuenode* newNode = new Queuenode;
  newNode->data = -1;
  newNode->next = newNode;
  newNode->prev = newNode;
  back = newNode;
  front = newNode;
}

void Queue::addBack(int incData){
  Queuenode* newNode = new Queuenode;
  newNode->data = incData;
  if(back->data == -1){
    newNode->next = newNode;
    newNode->prev = newNode;
    front = newNode;
    back = newNode;
    return;
  }
  newNode->next = front;
  back->next = newNode;
  newNode->prev = back;
  back = newNode;
}

int Queue::getFront(){
  if(back->data == -1){
    return -1;
  }
  return front->data;
}

void Queue::removeFront(){
  front->data = -1;
  front = front->next;
}