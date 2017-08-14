#include "Order_Statistic.h"

int Randomized_Select(int a[], int left, int right, int order)
{
	if (left == right)
		return left;

	int pivot = Partition_Random(a, left, right);
	int k = pivot - left + 1;
	if (order == k)
		return pivot;
	else if (order < k)
		return Randomized_Select(a, left, pivot - 1, order);
	else
		return Randomized_Select(a, pivot + 1, right, order - k);
}