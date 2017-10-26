#ifndef __RANDOM_PERMUTE_H__
#define __RANDOM_PERMUTE_H__

template <class T>
struct element
{
	T key;
	int priority;
};

template <class T>
void sort_permute(T a[], int n);

template <class T>
int cmp_element(element<T>& a, element<T>& b);

template <class T>
void knuth_shuffle(T a[], int n);

template <class T>
void init_seed();

template <class T>
void complicate_init_seed();

template <class T>
unsigned long mix(unsigned long a, unsigned long b, unsigned long c);

template <class T>
int uniform(int a, int b);

#include "Random_Permute.h"

#endif