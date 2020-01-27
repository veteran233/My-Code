/*
ID: kookinhard
PROG: subset
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;

int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	cin >> N;

	if (N * (N + 1) % 4 != 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int sum = N * (N + 1) / 4;
	vector<vector<long long>> f(N + 1, vector<long long>(sum + 1));
	f[1][1] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= sum; j++)
		{
			if (j - i >= 0)
				f[i][j] = f[i - 1][j] + f[i - 1][j - i];
			else
				f[i][j] = f[i - 1][j];
		}

	cout << f[N][sum] << endl;

	return 0;
}
