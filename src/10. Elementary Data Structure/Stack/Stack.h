//Stack class which have integer data
//CLRS 10.1 Stacks and queues ( p232 )
//written by Jeong Jae Hoon 2017-08-27

#ifndef __STACK_H__
#define __STACK_H__

#include <cstdio>

class Stack
{
private:
	int* data;
	int size;
	int Top;

public:
	//Constructor of Stack Class
	//Input:	size ( size of stack )
	Stack(int size);

	//Push the key
	//Input:	key ( which you want to push )
	//Time:		O(1)
	void push(int key);

	//Return top of stack
	//Output:	top of stack
	//Time:		O(1)
	int top();

	//Pop the key
	//Time:		O(1)
	void pop();

	//Let you know whether stack is empty or not
	//Output:	1 (if stack is empty)
	//			0 (if stack is not empty)
	//Time:		O(1)
	int empty();

	//Let you know whether stack is full or not
	//Output:	1 (if stack is full)
	//			0 (if stack is not full)
	//Time:		O(1)
	int full();

	//Destructor of Stack Class
	~Stack();

};

#endif