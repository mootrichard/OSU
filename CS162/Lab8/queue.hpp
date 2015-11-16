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
