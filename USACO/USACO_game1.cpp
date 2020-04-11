/*
ID: kookinhard
PROG: game1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);

	int N;

	cin >> N;

	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	vector<int> sum(N + 1);

	sum[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> dp[i][i];
		sum[i] = sum[i - 1] + dp[i][i];
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N - k; ++i)
			dp[i][i + k] = sum[i + k] - sum[i - 1] - min(dp[i + 1][i + k], dp[i][i + k - 1]);

	cout << dp[1][N] << " " << sum[N] - dp[1][N] << endl;

	return 0;
}
