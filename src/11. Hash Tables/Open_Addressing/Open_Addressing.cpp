#ifndef __OPEN_ADDRESSING_CPP__
#define __OPEN_ADDRESSING_CPP__

#include "Open_Addressing.h"
#include <iostream>

using namespace std;

template <class T>
Open_Addressing<T>::Open_Addressing(int n, int(*hash)(T, int, int)) : n(n), hash(hash)
{
	status = new int[n];
	data = new T*[n];

	for (int i = 0; i < n; i++)
		status[i] = EMPTY;
}

template <class T>
int Open_Addressing<T>::insertion(T key)
{
	for (int i = 0; i < n; i++)
	{
		int x = hash(key, i, n);
		if (status[x] == EMPTY || status[x] == DELETED)
		{
			data[x] = new T(key);
			status[x] = FULL;
			return x;
		}
	}
}

template <class T>
int Open_Addressing<T>::search(T key)
{
	for (int i = 0; i < n; i++)
	{
		int x = hash(key, i, n);
		if (*data[x] == key)
			return x;
		if (status[x] == EMPTY)
			return -1;	//not exist
	}
	return -1;	//full
}

template <class T>
void Open_Addressing<T>::deletion(int slot)
{
	delete data[slot];
	status[slot] = DELETED;
}

template <class T>
void Open_Addressing<T>::print()
{
	for (int i = 0; i < n; i++)
	{
		if(status[i] == FULL)
			cout << "SLOT "<<i<<" : " <<*data[i] << endl;
	}
}

template <class T>
Open_Addressing<T>::~Open_Addressing()
{
	for (int i = 0; i < n; i++)
	{
		if (status[i] == FULL)
		{
			delete data[i];
		}
	}
	delete[] status;
	delete[] data;
}

#endif