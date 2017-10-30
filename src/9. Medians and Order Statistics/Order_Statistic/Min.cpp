#include "Order_Statistic.h"

int Min(int a[], int n)
{
	int min = a[0];

	for (int i = 1; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
	}

	return min;
}