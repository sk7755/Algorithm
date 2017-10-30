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