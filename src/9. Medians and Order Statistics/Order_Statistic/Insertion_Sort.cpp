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