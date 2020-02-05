/*
ID: kookinhard
PROG: nocows
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main()
{
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	cin >> N >> K;

	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= K; i++)
		dp[1][i] = 1;
	for (int i = 3; i <= N; i += 2)
		for (int j = 2; j <= K; j++)
			for (int k = 1; k <= i - 1; k += 2)
				dp[i][j] = (dp[i][j] + dp[i - 1 - k][j - 1] * dp[k][j - 1]) % 9901;

	if (dp[N][K] - dp[N][K - 1] >= 0)
		cout << dp[N][K] - dp[N][K - 1] << endl;
	else
		cout << dp[N][K] + 9901 - dp[N][K - 1] << endl;

	return 0;
}
