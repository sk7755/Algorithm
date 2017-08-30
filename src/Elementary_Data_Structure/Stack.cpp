#include "Stack.h"

Stack::Stack(int size) : Top(-1) , size(size)
{
	data = new int[size];
}

void Stack::push(int key)
{
	if (full())
	{
		printf("push() ERROR : Stack is full\n");
		return;
	}

	data[++Top] = key;
}

int Stack::top()
{
	if (empty())
	{
		printf("top() ERROR : Stack is empty\n");
		return 0;
	}

	return data[Top];
}

void Stack::pop()
{
	if (empty())
	{
		printf("pop() ERROR : Stack is empty\n");
		return;
	}
	Top--;
}

int Stack::empty()
{
	if (Top == -1)
		return 1;
	else
		return 0;
}

int Stack::full()
{
	if (Top == size - 1)
		return 1;
	else
		return 0;
}

Stack::~Stack()
{
	delete[] data;
}