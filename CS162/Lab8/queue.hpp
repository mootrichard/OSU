// Author: Richard Moot
// Date: November 19, 2015
// Description: This Queue class is an abstract data type (ADT) that queues in integers. When a value is removed
//	it is actually set to -1 and then moved out of the queue (nothing is actually destroyed though). Each node is
//	and doubly linked. The structuct is circular so the front and back nodes lead to one another as well.
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{
	public:
		Queue();
		
		void addBack(int incData);
		int getFront();
		void removeFront();

		struct Queuenode {
			Queuenode* next;
			Queuenode* prev;
			int data;
		};
	private:
		Queuenode* front;
		Queuenode* back;
};

#endif // QUEUE_HPP
