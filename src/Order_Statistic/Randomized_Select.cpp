/*

Randomized Select

Select K th smallest element in int array

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n) Expected Running Time (Average Case)

<ETC>
1.	Select Random Pivot by Partition_Random

*/

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