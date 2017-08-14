#include "Order_Statistic.h"

int Linear_Select(int a[], int left, int right, int order)
{
	if (left == right)
		return left;

	int pivot = Partition_Median(a, left, right);
	int k = pivot - left + 1;
	if (order == k)
		return pivot;
	else if (order < k)
		return Linear_Select(a, left, pivot - 1, order);
	else
		return Linear_Select(a, pivot + 1, right, order - k);
}