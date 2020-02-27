/*
ID: kookinhard
PROG: inflate
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);

	int M, N;
	cin >> M >> N;

	vector<int> point(N);
	vector<int> cost(N);
	for (int i = 0; i < N; i++)
		cin >> point[i] >> cost[i];

	vector<int> dp(M + 1, 0);
	for (int i = 0; i < N; i++)
		for (int j = cost[i]; j <= M; j++)
			dp[j] = max(dp[j], dp[j - cost[i]] + point[i]);

	cout << dp[M] << endl;

	return 0;
}
