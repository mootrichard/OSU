// Author: Richard Moot
// Date: Novmeber 5, 2015
// Description: These are two classes for implementing a linked list Stack and a linked
//   list Queue. The stack is a FILO order, so the element at the top is the one that is
//   removed. The Queue is a FIFO order, so the element in the front is always removed.
//   Our Queus is also a doubly linked list, while the Stack is single linked list.

#include <iostream>

class Stack {
  public:
    Stack();
    void addNode(int value);
    int remove();

  protected:
    struct Stacknode {
      int number;
      Stacknode* next;
    };

  private:
    Stacknode *top;
};

class Queue {
  public:
    Queue();
    void addNode(int value);
    int remove();

  protected:
    struct Queuenode {
      int number;
      Queuenode* next;
      Queuenode* prev;
    };

  private:
    Queuenode *front;
    Queuenode *back;
};