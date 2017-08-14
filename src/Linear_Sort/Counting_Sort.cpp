#include "Linear_Sort.h"

/*

counting sort (int array)

<Input>
1. array adress
2. array size
3. lower bound of source array
4. upper bound of source array

<output>
1. sorted int array

<specific>
1. stable
2. not in place
3. O(k+n) Time Complexity	(k = right - left + 1)
4. O(k) Space Complexity

*/

void counting_sort(int a[], int n, int left, int right)
{
	int *c = (int*)malloc(sizeof(int)*(right - left + 1));
	int *b = (int*)malloc(sizeof(int)*n);
	int c_n = right - left + 1;
	for (int i = 0; i < c_n; i++)
		c[i] = 0;

	for (int i = 0; i < n; i++)
		c[a[i] - left]++;

	for (int i = 1; i < c_n; i++)
		c[i] += c[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		b[--c[a[i] - left]] = a[i];
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];
	free(c);
	free(b);
}