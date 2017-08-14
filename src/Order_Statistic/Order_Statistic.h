#ifndef __ORDER_STATISTIC_H__
#define __ORDER_STATISTIC_H__

#include <cstdlib>

struct PAIR
{
	int first, second;
};

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Max(int a[], int n);
int Min(int a[], int n);
PAIR Max_Min(int a[], int n);
int Select(int a[], int left, int right, int order);
int Partition(int a[], int left, int right);
void Insertion_Sort(int a[], int n);
int Linear_Select(int a[], int left, int right, int order);
int Partition_Median(int a[], int left, int right);
int Randomized_Select(int a[], int left, int right, int order);
int Partition_Random(int a[], int left, int right);

#endif