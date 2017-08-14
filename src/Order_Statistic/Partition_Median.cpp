/*

Partition Median

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

#include "Order_Statistic.h"

int Partition_Median(int a[], int left, int right)
{
	int pivot;
	if (right - left + 1 < 140)
	{
		pivot = Partition(a, left, right);
	}
	else
	{
		int j = left - 1;
		for (int i = left; i + 4 <= right; i += 5)
		{
			Insertion_Sort(a + i, 5);
			swap(a[i + 2], a[++j]);
		}

		pivot = Linear_Select(a, left, j, (j - left + 1) / 2);
	}
	swap(a[pivot], a[right]);

	return Partition(a, left, right);
}