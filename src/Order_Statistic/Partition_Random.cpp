#include "Order_Statistic.h"

/*

Partition_Random

Choose Random Pivot and partition based pivot 

<Input>
1.	int array

<Output>
2.	partitioned int array based random pivot

<TIme Complexity>
1.	O(n)

<ETC>
1.	Using rand function in <cstdlib>

*/

int Partition_Random(int a[], int left, int right)
{
	int pivot = ((rand() << 15) | rand()) % (right - left + 1) + left;
	swap(a[pivot], a[right]);

	return Partition(a, left, right);
}
