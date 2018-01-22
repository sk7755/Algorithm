#include <iostream>
#include <algorithm>

using namespace std;

struct Jewerly
{
	double w;
	double p;

};

int mycmp(Jewerly &a, Jewerly &b)
{
	return a.p / a.w > b.p / b.w;
}

int main()
{
	int n;
	cin >> n;

	double knapsack;
	cin >> knapsack;

	Jewerly* a = new Jewerly[n];

	for (int i = 0; i < n; i++)
		cin >> a[i].w >> a[i].p;

	sort(a, a + n, mycmp);

	double tmp = knapsack;
	double total = 0;
	for (int i = 0; i < n && tmp > 0; i++)
	{
		if (tmp >= a[i].w)
		{
			total += a[i].p;
			tmp -= a[i].w;
		}
		else
		{
			total += a[i].p / a[i].w * tmp;
			tmp = 0;
		}
	}

	cout << "Fractional Knapsack Problem : " << total << '$' << endl;

	double *dp = new double[(int)knapsack + 1];
	
	for (int i = 0; i <= knapsack; i++)
		dp[i] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = knapsack; j - a[i].w >= 0; j--)
		{
			if (dp[j] < dp[j - (int)a[i].w] + a[i].p)
				dp[j] = dp[j - (int)a[i].w] + a[i].p;
		}
	}
	//If dp[j-(int)a[i].w] == 0
	//It means that dp[j] has small jewlery than value j so that dp[j] covers dp[0 ~ j-1].

	cout << "0-1 Knapsack Problem : " << dp[(int)knapsack] << '$' << endl;

}