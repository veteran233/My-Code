/*
ID: kookinhard
PROG: money
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int V, N;

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	cin >> V >> N;
	vector<int> mon(V);
	for (int i = 0; i < V; i++)
		cin >> mon[i];
	vector<long long> dp(N + 1);
	dp[0] = 1;
	for (int i = 0; i < V; i++)
		for (int j = mon[i]; j <= N; j++)
			dp[j] += dp[j - mon[i]];
	cout << dp[N] << endl;
	return 0;
}
