/*Copyright 2015 Richard Moot*/
#include <iostream>

class Stack {
  public:
    Stack();
    ~Stack();
    void addNode(int value);
    int remove();

  protected:
    typedef struct Stacknode {
      int number
      Stacknode* next
    };

  private:
    Stacknode *top;
};

class Queue {
  public:
    Queue();
    ~Queue();
    void addNode(int value);
    int remove();

  protected:
    typedef struct Queuenode {
      int number
      Queuenode* next
      Queuenode* prev
    };

  private:
    Queuenode *front;
    Queuenode *back;
};