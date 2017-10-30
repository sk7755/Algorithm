#include "Linear_Sort.h"

void Radix_Sort(int a[], int n)
{
	int c[19] = { 0, };
	int* b[2];

	for (int i = 0; i < 2; i++)
		b[i] = (int*)malloc(sizeof(int)*n);
	int up = 0, down = 1;

	for (int i = 0; i < n; i++)
		b[up][i] = a[i];


	for (int i = 1; i <= 1000000000; i *= 10)
	{
		for (int j = 0; j < 19; j++)
			c[j] = 0;

		for (int j = 0; j < n; j++)
		{
			int d = b[up][j] / i % 10;
			c[d + 9]++;
		}

		for (int j = 1; j < 19; j++)
			c[j] += c[j - 1];

		for (int j = n - 1; j >= 0; j--)
		{
			int d = (long long)b[up][j] / i % 10;
			b[down][--c[d + 9]] = b[up][j];
		}

		up ^= 1, down ^= 1;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[up][i];

	free(b[0]);
	free(b[1]);
}