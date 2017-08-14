/*

Select

Select K th smallest element in int array

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n^2) Worst Case

<ETC>
1.	Select a[right] Pivot by Partition
2.	In test, this algorithm is fastest even if array size is 10,000,000
	Because,I think, alike quick_sort coefficient is small 

*/

#include "Order_Statistic.h"

int Select(int a[], int left, int right, int order)
{
	if (left == right)
		return left;

	int pivot = Partition(a, left, right);
	int k = pivot - left + 1;
	if (order == k)
		return pivot;
	else if (order < k)
		return Select(a, left, pivot - 1, order);
	else
		return Select(a, pivot + 1, right, order - k);
}