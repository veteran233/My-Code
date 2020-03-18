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

int distsum(vector<int>&dist)
{
	int ret = 0;
	for (int i = 0; i < N; ++i)
		if (dist[cow_pos[i]] != inf)
			ret += dist[cow_pos[i]];
		else
			return inf;
	return ret;
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

	vector<vector<int>> weight(P + 1, vector<int>(P + 1, inf));

	for (int i = 0; i <= P; ++i)
		weight[i][i] = 0;
	for (int i = 0; i < C; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		weight[a][b] = c;
		weight[b][a] = c;
	}

	int source = 0;
	int mcount = 0;
	while (mcount < P + 1)
	{
		vector<int> dist(P + 1, inf);
		vector<bool> visited(P + 1, 0);

		dist[source] = 0;

		int index = 0;
		int count = 0;
		while (count <= P)
		{
			for (; visited[index]; ++index);
			int i = index;
			for (int j = index + 1; j <= P; ++j)
				if (!visited[j] && dist[i] > dist[j])
					i = j;
			visited[i] = 1;
			for (int j = 0; j <= P; ++j)
				if (dist[j] > dist[i] + weight[i][j])
					dist[j] = dist[i] + weight[i][j];
			++count;
		}
		ans = min(ans, distsum(dist));
		source = ++mcount;
	}

	cout << ans << endl;

	return 0;
}
