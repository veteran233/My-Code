#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<vector<int>> dp(N, vector<int>(N));
	vector<vector<int>> sum(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		cin >> dp[i][i];
		sum[i][i] = dp[i][i];
	}
	for (int i = 1; i < N; ++i)
		for (int j = 0; j < N - i; ++j)
		{
			sum[j][j + i] = sum[j][j + i - 1] + sum[j + i][j + i];
		}

	for (int i = 1; i < N; ++i)
		for (int j = 0; j < N - i; ++j)
		{
			dp[j][j + i] = max(sum[j][j] + sum[j + 1][j + i] - dp[j + 1][j + i], sum[j + i][j + i] + sum[j][j + i - 1] - dp[j][j + i - 1]);
		}

	return 0;
}
