/*

Test execution time of order statistics algorithms

*/

#include <cstdio>
#include "Order_Statistic.h"
#include <ctime>
#include <Windows.h>
#include <algorithm>

enum { size = 50000000, LEFT = -10000000, RIGHT = 9000000 };

void assign(int b[], int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

int main()
{
	int b[size];
	int a[size];
	DWORD start, end;

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		b[i] = ((rand() << 15) | rand()) % (RIGHT - LEFT + 1) + LEFT;
	}

	/*
	start = GetTickCount();
	printf("%d %d\n", order_max(a, size), order_min(a, size));
	end = GetTickCount();
	printf("each method (max,min) : %lf sec\n", (end - start) / (double)1000);

	start = GetTickCount();
	PAIR ret = order_max_min(a, size);
	printf("%d %d\n", ret.first, ret.second);
	end = GetTickCount();
	printf("pair method (max,min) : %lf sec\n", (end - start) / (double)1000);

	start = GetTickCount();
	printf("%d %d\n", a[select(a, 0,size-1,size)], a[select(a,0,size-1,1)]);
	end = GetTickCount();
	printf("Select method (max,min): %lf sec\n", (end - start) / (double)1000);
	*/
	int k = size * 2 / 3;

	assign(b, a, size);
	start = GetTickCount();
	printf("%d\n", a[Select(a, 0, size - 1, k)]);
	end = GetTickCount();
	printf("Select method (Kth order): %lf sec\n", (end - start) / (double)1000);
	
	assign(b, a, size);
	start = GetTickCount();
	printf("%d\n", a[Randomized_Select(a, 0, size - 1, k)]);
	end = GetTickCount();
	printf("Randomized Select method (Kth order): %lf sec\n", (end - start) / (double)1000);
	
	assign(b, a, size);
	start = GetTickCount();
	printf("%d\n", a[Linear_Select(a, 0, size - 1, k)]);
	end = GetTickCount();
	printf("Linear Select method (Kth order): %lf sec\n", (end - start) / (double)1000);
	
	return 0;
}