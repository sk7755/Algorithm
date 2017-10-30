#include "Order_Statistic.h"

PAIR Max_Min(int a[], int n)
{
	PAIR ret;
	if (n % 2)
		ret.first = ret.second = a[0];
	else
	{
		if (a[0] < a[1])
			ret.first = a[1], ret.second = a[0];
		else
			ret.first = a[0], ret.second = a[1];
	}

	for (int i = 2 - n % 2; i < n; i += 2)
	{
		if (a[i] < a[i + 1])
		{
			if (a[i + 1] > ret.first)
				ret.first = a[i + 1];
			if (a[i] < ret.second)
				ret.second = a[i];
		}
		else
		{
			if (a[i] > ret.first)
				ret.first = a[i];
			if (a[i + 1] < ret.second)
				ret.second = a[i + 1];
		}
	}

	return ret;
}