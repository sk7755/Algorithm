#include "Priority_Queue.h"

template <class T>
Priority_Queue<T>::Priority_Queue(int size, int(*cmp)(T&, T&)) : heap_size(0), cmp(cmp)
{
	heap = new T*[size + 1];
}

template <class T>
int Priority_Queue<T>::size() const
{
	return heap_size;
}

template <class T>
int Priority_Queue<T>::empty() const
{
	return heap_size == 0 ? 1 : 0;
}

template <class T>
void Priority_Queue<T>::max_heapify(int idx)
{
	int largest = idx;
	do
	{
		exchange(heap[idx], heap[largest]);
		idx = largest;
		int left = 2 * idx, right = 2 * idx + 1;

		if (left <= heap_size && cmp(*heap[left], *heap[largest]))
			largest = left;
		if (right <= heap_size && cmp(*heap[right], *heap[largest]))
			largest = right;
	} while (largest != idx);
}

template <class T>
T Priority_Queue<T>::top() const
{
	if (!empty())
		return *heap[1];
	else
		return NULL;
}

template <class T>
void Priority_Queue<T>::pop()
{
	if (empty())
		return;

	T* del = heap[1];
	heap[1] = heap[heap_size];
	heap_size--;

	if (!empty())
		max_heapify(1);

	delete del;
}

template <class T>
void Priority_Queue<T>::push(T& key)
{
	heap[++heap_size] = new T;
	*heap[heap_size] = key;
	int idx = heap_size;

	while (idx > 1 && cmp(*heap[idx], *heap[idx / 2]))
	{
		exchange(heap[idx], heap[idx / 2]);
		idx /= 2;
	}
}

template <class T>
Priority_Queue<T>::~Priority_Queue()
{
	delete[] heap;
}