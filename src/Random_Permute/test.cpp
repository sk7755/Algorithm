#include <cstdio>
#include "Random_Permute.h"

int main()
{
	int a[10000];
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");

	knuth_shuffle(a, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;

}