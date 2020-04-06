/*
ID: kookinhard
PROG: range
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> square;
vector<vector<unsigned short>> scount;
vector<unsigned short> ans;

int garea(const int &a, const int &b, const unsigned short &p)
{
	if (a + p >= N || b + p >= N)
		return 2;

	for (int i = 0; i <= p; ++i)
		if (square[a + i][b + p] != '1')
			return 0;

	for (int i = 0; i <= p; ++i)
		if (square[a + p][b + i] != '1')
			return 0;

	return 1;
}

int main()
{
	/*freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);*/

	cin >> N;

	square.resize(N);
	scount.resize(N);
	ans.resize(N*N + 1, 0);
	for (int i = 0; i < N; ++i)
		scount[i].resize(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> square[i];

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (square[i][j] == '1' && scount[i][j] == k + 1)
				{
					int temp = garea(i, j, scount[i][j]);

					if (temp == 1)
					{
						++scount[i][j];
						++ans[scount[i][j]];
					}
					else if (temp == 2)
						break;
				}

	for (int i = 0; i < N*N + 1; ++i)
		if (ans[i] != 0)
			cout << i << " " << ans[i] << endl;

	return 0;
}
