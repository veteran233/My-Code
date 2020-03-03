/*
ID: kookinhard
PROG: stamps
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N;
vector<int> stamp;
int ans = 0;

int main()
{
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	fin >> K >> N;

	int user_in;
	while (fin >> user_in)
		stamp.push_back(user_in);

	if (*min_element(stamp.begin(), stamp.end()) != 1)
	{
		fout << 0 << endl;
		return 0;
	}

	const int smax = *max_element(stamp.begin(), stamp.end());
	vector<int> dp(2 * smax);
	dp[0] = 0;

	for (int i = 1; i < smax; ++i)
	{
		vector<int> index;
		for (int j = 0; j < N; ++j)
			if (i - stamp[j] >= 0)
				index.push_back(i - stamp[j]);

		int smin = dp[index[0]];

		for (int i = 0; i < index.size(); ++i)
			if (smin > dp[index[i]])
				smin = dp[index[i]];

		dp[i] = smin + 1;
		++ans;
	}

	for (int i = 0; i < smax; ++i)
		if (dp[i] > K)
		{
			fout << ans - smax + i << endl;
			return 0;
		}

	while (1)
	{
		for (int i = smax; i < 2 * smax; i++)
		{
			int smin = dp[i - stamp[0]];
			for (int j = 0; j < N; ++j)
				if (smin > dp[i - stamp[j]])
					smin = dp[i - stamp[j]];

			dp[i] = smin + 1;
			if (dp[i] > K)
			{
				fout << ans << endl;
				return 0;
			}
			++ans;
		}
		reverse(dp.begin(), dp.begin() + smax);
		reverse(dp.begin() + smax, dp.end());
		reverse(dp.begin(), dp.end());
	}

	return 0;
}
