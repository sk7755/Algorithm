#include "Queue.h"

Queue::Queue(int size) : size(size)
{
	front = 0, rear = 0;
	data = new int[size+1];
}

int Queue::top()
{
	if (empty())
	{
		printf("top() ERROR : Queue is empty\n");
		return 0;
	}

	return data[front];
}

void Queue::push(int key)
{
	if (full())
	{
		printf("push(int key) ERROR: Queue is full\n");
		return;
	}
	data[rear] = key;

	rear++;
	if (rear == size+1)
		rear = 0;
}

void Queue::pop()
{
	if (empty())
	{
		printf("pop() ERROR: Queue is empty\n");
		return;
	}
	front++;
	
	if (front == size+1)
		front = 0;
}

int Queue::empty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int Queue::full()
{
	if ((rear + 1) % (size + 1) == front)
		return 1;
	else
		return 0;
}

Queue::~Queue()
{
	delete[]data;
}