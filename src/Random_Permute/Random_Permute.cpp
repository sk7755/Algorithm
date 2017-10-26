#ifndef __RANDOM_PERMUTE_CPP__
#define __RANDOM_PERMUTE_CPP__

#include "Random_Permute.h"
#include <cstdlib>
#include <ctime>
#include <process.h>
#include <algorithm>

template <class T>
void sort_permute(T a[], int n)
{
	init_seed();

	element<T>* p = new element<T>[n];

	int limit = n*n*n;
	if (n > 1000)
		limit = 1000000000;

	for (int i = 0; i < n; i++)
	{
		p[i].priority = uniform(1, limit);
		p[i].key = a[i];
	}
	
	std::sort(p, p + n, cmp_element);

	for (int i = 0; i < n; i++)
		a[i] = p[i].key;

	delete[] p;

}

template <class T>
int cmp_element(element<T>& a, element<T>& b)
{
	return a.priority < b.priority;
}

template <class T>
void knuth_shuffle(T a[], int n)
{
	init_seed();
	for (int i = 0; i < n; i++)
	{
		std::swap(a[i], a[uniform(i,n-1)]);
	}
}

template <class T>
void init_seed()
{
	srand(time(NULL));
}

template <class T>
void complicate_init_seed()
{
	unsigned long seed = mix(clock(), time(NULL), _getpid());
	srand(seed);
}

template <class T>
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
	a = a - b;  a = a - c;  a = a ^ (c >> 13);
	b = b - c;  b = b - a;  b = b ^ (a << 8);
	c = c - a;  c = c - b;  c = c ^ (b >> 13);
	a = a - b;  a = a - c;  a = a ^ (c >> 12);
	b = b - c;  b = b - a;  b = b ^ (a << 16);
	c = c - a;  c = c - b;  c = c ^ (b >> 5);
	a = a - b;  a = a - c;  a = a ^ (c >> 3);
	b = b - c;  b = b - a;  b = b ^ (a << 10);
	c = c - a;  c = c - b;  c = c ^ (b >> 15);
	return c;
}

template <class T>
int uniform(int a, int b)
{
	int value = rand() | (rand() << 15);
	return value % (b - a + 1) + a;
}

#endif