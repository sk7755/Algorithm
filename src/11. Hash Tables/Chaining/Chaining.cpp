#ifndef __CHAINING_CPP__
#define __CHAINING_CPP__

#include "Chaining.h"
#include <iostream>

using namespace std;

template <class T>
Chaining<T>::Chaining(int n, int(*hash)(T, int)) :n(n), hash(hash)
{
	data = new nptr[n];
	sentinel = new nptr[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = new NODE<T>;
		data[i]->next = data[i]->pre = data[i];
		sentinel[i] = data[i];
	}
}

template <class T>
void Chaining<T>::insertion(T key)
{
	int x = hash(key, n);
	nptr pnew = new NODE<T>;
	pnew->key = key;
	pnew->next = data[x];
	pnew->pre = data[x]->pre;
	pnew->pre->next = pnew;
	pnew->next->pre = pnew;
	data[x] = pnew;
}

template <class T>
NODE<T>* Chaining<T>::search(T key)
{
	int x = hash(key, n);
	for (nptr p = data[x]; p != sentinel[x]; p = p->next)
	{
		if (p->key == key)
			return p;
	}

	return nullptr;
}

template <class T>
void Chaining<T>::deletion(nptr p)
{
	if (!p)
		return;

	int x = hash(p->key, n);

	p->next->pre = p->pre;
	p->pre->next = p->next;

	if (data[x] == p)
		data[x] = p->next;
	delete p;
}

template <class T>
void Chaining<T>::print()
{
	for (int i = 0; i < n; i++)
	{
		cout << "SLOT " << i << " : ";
		for (nptr p = data[i]; p != sentinel[i]; p = p->next)
		{
			cout << p->key << ' ';
		}
		cout << endl;
	}
}

template <class T>
Chaining<T>::~Chaining()
{
	for (int i = 0; i < n; i++)
	{
		nptr del = nullptr;
		for (nptr p = data[i]; p != sentinel[i]; p = p->next)
		{
			if (del)
				delete del;
			del = p;
		}
		delete del;
	}
	delete[]data;
	delete[]sentinel;
}

#endif