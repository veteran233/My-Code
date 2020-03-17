/*
ID: kookinhard
PROG: butter
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, P, C;
vector<int> cow_pos;
const int inf = 0x3f3f3f3f;
int ans = inf;

int pathsum(int index, vector<vector<int>>&path)
{
	int psum = 0;
	for (int i = 0; i < N; ++i)
		if (path[index][cow_pos[i]] != inf)
			psum += path[index][cow_pos[i]];
		else
			return inf;
	return psum;
}

int main()
{
	/*freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);*/

	cin >> N >> P >> C;
	for (int i = 0; i < N; ++i)
	{
		int user_in;
		cin >> user_in;
		cow_pos.push_back(user_in);
	}

	vector<vector<int>> path(P + 1, vector<int>(P + 1, inf));

	for (int i = 0; i <= P; ++i)
		path[i][i] = 0;
	for (int i = 0; i < C; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a][b] = c;
		path[b][a] = c;
	}

	for (int k = 0; k <= P; ++k)
		for (int i = 0; i <= P; ++i)
			for (int j = 0; j <= P; ++j)
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];

	for (int i = 0; i <= P; ++i)
		ans = min(ans, pathsum(i, path));

	cout << ans << endl;

	return 0;
}
