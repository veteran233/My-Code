/*
ID: kookinhard
PROG: kimbits
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, L;
unsigned I;

void ansprint(int n, int l, unsigned index, vector<vector<unsigned>>&dp)
{
	if (n == 0)
		return;
	else
	{
		unsigned temp = dp[n - 1][l];
		if (temp <= index)
		{
			cout << "1";
			ansprint(n - 1, l - 1, index - temp, dp);
		}
		else
		{
			cout << "0";
			ansprint(n - 1, l, index, dp);
		}
	}
}

int main()
{
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);

	cin >> N >> L >> I;

	vector<vector<unsigned>> dp(N + 1, vector<unsigned>(L + 1, 0));

	for (int i = 0; i <= L; ++i)
		dp[0][i] = 1;

	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= L; ++j)
			if (j - 1 >= 0)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			else
				dp[i][j] = 1;

	ansprint(N, L, I - 1, dp);

	cout << "\n";

	return 0;
}
