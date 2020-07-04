/*
ID: kookinhard
PROG: nuggets
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool dp[1000];

bool check(vector<int>&num)
{
	for (int i = 0; i < (int)num.size(); ++i)
		if (num[i] % 2)
			return 1;
	return 0;
}
int main()
{
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);

	int N;
	cin >> N;

	vector<int> num(N);

	for (int i = 0; i < N; ++i)
		cin >> num[i];

	int ans = 0;
	if (check(num))
	{
		int nmax = *max_element(num.begin(), num.end());

		dp[0] = 1;
		for (int i = 0; i <= 2000000000; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i - num[j] >= 0 && dp[(i - num[j]) % 1000])
				{
					dp[i % 1000] = 1;
					break;
				}
				if (j == N - 1)
				{
					if (i != 0)
						dp[i % 1000] = 0;
					ans = i;
				}
			}
			if (ans < i - nmax)
				break;
		}
	}

	cout << ans << endl;

	return 0;
}
