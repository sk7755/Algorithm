#include "Order_Statistic.h"

int Partition_Random(int a[], int left, int right)
{
	int pivot = ((rand() << 15) | rand()) % (right - left + 1) + left;
	swap(a[pivot], a[right]);

	return Partition(a, left, right);
}
