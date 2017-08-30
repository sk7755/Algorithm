//Queue class which have integer data
//CLRS 10.1 Stacks and queues ( p232 )
//written by Jeong Jae Hoon 2017-08-27

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdio>

class Queue
{
private:
	int* data;
	int size;
	int front, rear;

public:
	//Constructor of queue class
	//Input:	size (size of queue)
	Queue(int size);

	//Return top of queue
	//Output:	top of queue
	//Time:		O(1)
	int top();

	//Push the key in queue
	//Input:	key (which you want to push)
	//Time:		O(1)
	void push(int key);

	//Pop the key in queue
	//Time:		O(1)
	void pop();

	//Let you know whether the queue is empty or not
	//Output:	1 (if queue is empty)
	//			0 (if queue is not empty)
	//Time:		O(1)
	int empty();

	//Let you know whether the queue is full or not
	//Output:	1 (if queue is full)
	//			0 (if queue is not full)
	//Time:		O(1)
	int full();

	//Destructor of queue class
	~Queue();
};

#endif