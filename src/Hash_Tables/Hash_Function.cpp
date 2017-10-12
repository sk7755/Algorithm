#include "Hash_Function.h"

int division_hash(int key, int m)
{
	int ret = key%m;
	if (ret < 0)
		ret += m;

	return ret;
}
#include <cstdio>
int multiplication_hash(int key, int m)
{
	int p = 0, c = 1;
	while (m)
	{
		m /= 2;
		p++;
		c *= 2;
	}
	if (c > m)
		p--;
	unsigned long long s = 2654435769;
	s *= (unsigned long long)key;
	unsigned long long mask = 0x80000000;
	int ret = 0;
	for (int i = 0; i < p; i++, mask = mask>>1)
	{
		ret = ret * 2;
		if (mask & s)
			ret++;
	}
	return ret;
}

static int flag_universal = 0;

int universal_hash(int key, int m)
{
	static int a;
	static int b;
	if (!flag_universal)
	{
		srand(time(NULL));
		a = 1, b = rand() % m;

		while (!(a%m))
			a = rand() % m;
		flag_universal = 1;
	}
	return division_hash((a*key) % m + b, m);
}

int linear_hash(int key, int i, int m)
{
	return division_hash(key + i,m);
}

int quadratic_hash(int key, int i, int m)
{
	return division_hash(key + i + i*i, m);
}

int double_hash(int key, int i, int m)
{
	int p = m - 2;
	
	return division_hash(division_hash(key, p) * i + key, m);
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) :a;
}