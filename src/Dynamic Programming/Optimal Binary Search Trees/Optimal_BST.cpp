#include <iostream>

using namespace std;

inline double MIN(double a, double b)
{
	return a < b ? a : b;
}

void optimal_BST(int n,double* p, double* q, double** dp, int** path)
{
	double *w = new double[n + 1];

	w[0] = 0;
	for (int i = 1; i <= n; i++)
		w[i] = w[i - 1] + p[i] + q[i];

	for (int i = 1; i <= n+1; i++)
		dp[i][i - 1] = q[i - 1];

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = p[i] + (q[i - 1] + q[i])*2;
		path[i][i] = i;
	}

	for (int l = 1; l < n; l++)
	{
		for (int i = 1; i+l <= n; i++)
		{
			int j = i + l;
			double tmp = w[j] - w[i - 1] + q[i - 1];
			dp[i][j] = dp[i][path[i][j - 1] -1] + dp[path[i][j - 1] +1][j];
			path[i][j] = path[i][j-1];
			for (int k = path[i][j-1] + 1; k <= path[i+1][j]; k++)
			{
				if (dp[i][j] > dp[i][k - 1] + dp[k + 1][j])
				{
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j];
					path[i][j] = k;
				}
			}
			dp[i][j] += tmp;
		}
	}

	delete[] w;
}

void print_BST(int** path, int i,int j)
{
	if (i > j)
		return;

	cout << '(';
	print_BST(path,i,path[i][j]-1);
	cout << path[i][j];
	print_BST(path, path[i][j] + 1, j);
	cout << ')';
}

int main()
{
	int n;

	cin >> n;

	double *p = new double[n+1];
	double *q = new double[n+1];
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 0; i <= n; i++)
		cin >> q[i];

	double** dp = new double*[n + 2];
	int** path = new int*[n + 2];
	for (int i = 0; i <= n+1; i++)
	{
		dp[i] = new double[n + 2];
		path[i] = new int[n + 2];
	}
	optimal_BST(n, p, q, dp, path);

	cout << "Minimum Expectation Cost : " << dp[1][n] << endl;
	cout << "Optimal Binary Search Tree" << endl;
	print_BST(path, 1, n);

	for (int i = 0; i <= n + 1; i++)
	{
		delete[] dp[i];
		delete[] path[i];
	}
	delete[] dp;
	delete[] path;
	delete[] p;
	delete[] q;

	return 0;
}