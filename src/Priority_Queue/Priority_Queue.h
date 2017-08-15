#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

/*
This Class is Max Priority Queue
According to your compare function, mean of max can be changed
For example, if your compare function gives higher priority to smaller int element, max means smallest
So in this case, this class constructs Min Priority Queue

***Compare Function Form***

int compare (T a,T b)

return 1 if a has higher priority than b
otherwise, return 0

***CAUSION***

If you want to use this class
Please include two files
1.	Priority_Queue.h
2.	Priority_QUeue.cpp
If you only include Priority_Queue.h, Compiler cause an error LINK2019
*/

template <class T>
class Priority_Queue
{
private:
	int heap_size;
	T **heap;
	int(*cmp)(T&, T&);
public:

	inline void exchange(T*& a, T*& b)
	{
		T* tmp = a;
		a = b;
		b = tmp;
	}

	Priority_Queue(int size, int(*cmp)(T&, T&));
	/*
		Constructor of Priority Queue

		<Input>
		1.	max size of priority_queue
		2.	compare function pointer

		<Output>
		1.	construct Max Priority Queue
	*/


	int size() const;
	/*
		return current size of priority queue

		<Output>
		1.	current size of priority queue
	*/

	int empty() const;
	/*
		return information which priority queue is empty or not

		<Output>
		1.	output 1 if empty, output 0 if not empty
	*/
	void max_heapify(int idx);
	/*
		on assumption heap[k] (k >idx) is satisfy max heap condition ( max heap condition : heap[parent] > heap[left], heap[right] )
		max_heapify function make heap[idx] satisfy the condition

		<Input>
		1.	index that you want to make satisfy the condition

		<Output>
		1.	heap[idx] satisfy the condition
	*/

	T top() const;
	/*
		return top of heap array
		this element is max element in heap

		<Output>
		1.	Max element in heap, If heap is empty, return 0
	*/

	void pop();
	/*
		delete top of heap array
	*/

	void push(T& key);
	/*
		Insert element to heap array

		<Input>
		1.	element which you want to insert
	*/

	~Priority_Queue();
	/*
	Destructor of Priority Queue Class
	*/


};

#endif