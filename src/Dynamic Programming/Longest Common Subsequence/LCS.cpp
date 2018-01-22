#include <iostream>

using namespace std;

enum {UP,LEFT, UPLEFT};

void LCS(char str1[], char str2[],int** dp, int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	}
}
int main()
{
	int n, m;
	char* str1;
	char* str2;

	cin >> n >> m;

	str1 = new char[n+1];
	str2 = new char[m+1];


	cin >> str1+1 >> str2+1;

	int** dp;
	dp = new int*[n+1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[m+1];

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= m; i++)
		dp[0][i] = 0;

	LCS(str1, str2, dp, n, m);

	cout << "Length : " << dp[n][m] << endl;
	cout << "Longest Common Sequence : ";
	int i = n, j = m;

	char* stack = new char[m + n];
	int top = -1;
	while (i && j )
	{
		if (str1[i] == str2[j])
		{
			stack[++top] = str1[i];
			i--, j--;
		}
		else if (dp[i-1][j] == dp[i][j])
			i--;

		else
			j--;
	}
	while (top >= 0)
		cout << stack[top--];
	cout << endl;

	delete[] stack;
	delete[] str1;
	delete[] str2;

	for (int i = 0; i <= n; i++)
		delete[] dp[i];

	return 0;
}