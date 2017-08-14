/*

Partition

Choose a[right] Pivot and partition based pivot

<Input>
1.	int array

<Output>
2.	partitioned int array based pivot

<TIme Complexity>
1.	O(n)

<ETC>

*/


#include "Order_Statistic.h"

int Partition(int a[], int left, int right)
{
	int j = left;
	for (int i = left; i < right; i++)
	{
		if (a[i] < a[right])
			swap(a[i], a[j++]);
	}
	swap(a[right], a[j]);
	return j;
}