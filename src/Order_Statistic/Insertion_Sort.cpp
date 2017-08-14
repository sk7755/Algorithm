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


#include "Order_Statistic.h"

void Insertion_Sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > key)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = key;
	}
}