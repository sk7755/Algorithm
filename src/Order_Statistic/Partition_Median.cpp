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