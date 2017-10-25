#ifndef __RANDOM_PERMUTE_H__
#define __RANDOM_PERMUTE_H__

struct element
{
	int key;
	int priority;
};

void sort_permute(int a[], int n);
int cmp_element(element& a, element& b);
void knuth_shuffle(int a[], int n);
void init_seed();
void complicate_init_seed();
unsigned long mix(unsigned long a, unsigned long b, unsigned long c);
int uniform(int a, int b);

#endif