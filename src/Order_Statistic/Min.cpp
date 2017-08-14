#include "Order_Statistic.h"

/*

Find Min Element

<Input>
1.	int array
2.	size of array

<Output>
1.	Smallest element in array

<Time Complexity>
1.	O(n)

<ETC>

*/

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