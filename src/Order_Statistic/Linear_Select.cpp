/*

Linear Select

Select K th smallest element in int array

<Input>
1.	int array
2.	left array index
3.	right array index
4.	K order

<Output>
1.	K th smallest element index

<Time Complexity>
1.	O(n) Worst case

<ETC>
1.	But Actually Excution Time is too long even if size is over 10,000,000
	Because, I think, It has a large coefficient

*/


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