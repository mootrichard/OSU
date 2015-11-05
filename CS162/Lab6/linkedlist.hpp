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