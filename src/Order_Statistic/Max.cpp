#include "Order_Statistic.h"

/*

Find Max Element

<Input>
1.	int array
2.	size of array

<Output>
1.	Largest element in array

<Time Complexity>
1.	O(n)

<ETC>

*/


int Max(int a[], int n)
{
	int max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}

	return max;
}