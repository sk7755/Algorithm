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
/*
Find Max Element

<Input>
1.	int array
2.	size of array

<Output>
1.	Largest element in array

<Time Complexity>
1.	O(n)

<ETC>
*/

int Min(int a[], int n);
/*
Find Min Element

<Input>
1.	int array
2.	size of array

<Output>
1.	Smallest element in array

<Time Complexity>
1.	O(n)

<ETC>
*/

PAIR Max_Min(int a[], int n);
/*
Find Max and Min element simultaneously

<Input>
1.	int array
2.	size of array

<Output>
1.	Pair Struct ( first = max, second = min )

<Time Complexity>
1.	O(n)

<ETC>
1.	This Algorithm is faster than the method which find each
*/

int Select(int a[], int left, int right, int order);
/*
Select K th smallest element in int array

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n^2) Worst Case

<ETC>
1.	Select a[right] Pivot by Partition
2.	In test, this algorithm is fastest even if array size is 10,000,000
Because,I think, alike quick_sort coefficient is small
*/

int Partition(int a[], int left, int right);
/*
Choose a[right] Pivot and partition based pivot

<Input>
1.	int array

<Output>
2.	partitioned int array based pivot

<TIme Complexity>
1.	O(n)

<ETC>
*/

void Insertion_Sort(int a[], int n);
/*
Insertion Sort

<Input>
1. int array
2. size of array

<Output>
1. sorted array

<Time Complexity>
1. O(n) Best Case
2. O(n^2) Worst Case

<ETC>
*/

int Linear_Select(int a[], int left, int right, int order);
/*
Select K th smallest element in int array but worst case time complexity is O(n) 

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n) Worst case

<ETC>
1.	But Actually Excution Time is too long even if size is over 10,000,000
Because, I think, It has a large coefficient
*/

int Partition_Median(int a[], int left, int right);
/*
Choose Median close Pivot and partition based pivot

<Input>
1.	int array

<Output>
2.	partitioned int array based pivot

<TIme Complexity>
1.	O(n)

<ETC>
1.	at least 3n/10 - 6 elements are less than pivot
2.	at least 3n/10 - 6 elements are greater than pivot
3.	proof is on assumption that all elements are distinct
*/

int Randomized_Select(int a[], int left, int right, int order);
/*
Randomized Select K th smallest element in int array

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n) Expected Running Time (Average Case)

<ETC>
1.	Select Random Pivot by Partition_Random
*/

int Partition_Random(int a[], int left, int right);
/*
Choose Random Pivot and partition based pivot

<Input>
1.	int array

<Output>
2.	partitioned int array based random pivot

<TIme Complexity>
1.	O(n)

<ETC>
1.	Using rand function in <cstdlib>
*/

#endif