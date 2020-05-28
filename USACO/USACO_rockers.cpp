/*
ID: kookinhard
PROG: rockers
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, T, M, dp[21][21], num[21];

int main()
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);

	cin >> N >> T >> M;

	for (int i = 1; i <= N; ++i)
		cin >> num[i];

	for (int i = 1; i <= N; ++i)
		for (int j = M; j >= 1; --j)
			for (int k = T; k >= num[i]; --k)
				dp[j][k] = max(dp[j][k], max(dp[j - 1][T], dp[j][k - num[i]]) + 1);

	cout << dp[M][T] << endl;

	return 0;
}
