#include "queue.hpp"

Queue::Queue(){
  front = back;
  back = front;
}

void Queue::addBack(int incData){
  Queuenode* newNode = new Queuenode;
  newNode->data = incData;
  if(front == back){
    newNode->next = newNode;
    newNode->prev = newNode;
    front = newNode;
    back = newNode;
    return;
  }
  newNode->next = back->next;
  newNode->prev = back;
  back = newNode;
}

int Queue::getFront(){
  if(front == back){
    return -1;
  }
  return front->data;
}

void Queue::removeFront(){

}