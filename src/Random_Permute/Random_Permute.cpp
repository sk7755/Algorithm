#include "Random_Permute.h"
#include <cstdlib>
#include <ctime>
#include <process.h>
#include <algorithm>

void sort_permute(int a[], int n)
{
	init_seed();

	element* p = new element[n];

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

int cmp_element(element& a, element& b)
{
	return a.priority < b.priority;
}

void knuth_shuffle(int a[], int n)
{
	init_seed();
	for (int i = 0; i < n; i++)
	{
		std::swap(a[i], a[uniform(i,n-1)]);
	}
}

void init_seed()
{
	srand(time(NULL));
}

void complicate_init_seed()
{
	unsigned long seed = mix(clock(), time(NULL), _getpid());
	srand(seed);
}

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

int uniform(int a, int b)
{
	int value = rand() | (rand() << 15);
	return value % (b - a + 1) + a;
}