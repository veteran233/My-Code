/*
ID: kookinhard
PROG: range
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);

	int N;

	cin >> N;

	vector<string> square(N);
	for (int i = 0; i < N; ++i)
		cin >> square[i];

	vector<vector<int>> dp(N, vector<int>(N));
	vector<int> ans(N + 1, 0);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int x = i, y = j;
			for (; x >= 0 && square[x][j] == '1'; --x);
			for (; y >= 0 && square[i][y] == '1'; --y);

			int a = min(i - x, j - y);
			if (i > 0 && j > 0)
				a = min(a, dp[i - 1][j - 1] + 1);

			dp[i][j] = a;
		}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 2; k <= dp[i][j]; ++k)
				++ans[k];

	for (int i = 2; i <= N; ++i)
		if (ans[i])
			cout << i << " " << ans[i] << endl;

	return 0;
}
