#include "Linear_Sort.h"
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <Windows.h>

enum{ size = 10000000 , min = -10000000, max = 9000000 };

void random(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = ((rand() << 15) | rand()) % (max - min + 1) + min;
	}
}

void assign(int b[], int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

int main()
{
	int b[size];
	int a[size];
	DWORD start;
	DWORD end;

	printf("RANGE : ( %d ~ %d ), size : %d\n", min, max, size);

	random(b,size);

	assign(b, a, size);
	start = GetTickCount();
	Bucket_Sort(a, size, min, max);
	end = GetTickCount();
	printf("Bucket_Sort : %lf sec\n", (end - start) / (double)1000);

	assign(b,a,size);
	start = GetTickCount();
	Radix_Sort(a, size);
	end = GetTickCount();
	printf("Radix_Sort : %lf sec\n", (end - start) / (double)1000);

	assign(b, a, size);
	start = GetTickCount();
	Counting_Sort(a, size, min, max);
	end = GetTickCount();
	printf("Counting_Sort : %lf sec\n", (end - start) / (double)1000);

	assign(b, a, size);
	start = GetTickCount();
	std::sort(a, a + size);
	end = GetTickCount();
	printf("Library_Sort : %lf sec\n", (end - start) / (double)1000);

	return 0;
}

