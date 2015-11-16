#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{
	public:
		Queue();
		
		void addBack(int incData);
		int getFront();
		void removeFront();

		struct QueueNode {
			QueueNode* next;
			QueueNode* prev;
			int data;
		};
	private:
		QueueNode* front;
		QueueNode* back;
};

#endif // QUEUE_HPP
