/*
ID: kookinhard
PROG: butter
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int N, P, C;
vector<int> cow_pos;
const int inf = 0x3f3f3f3f;
int ans = inf;

int main()
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);

	cin >> N >> P >> C;
	for (int i = 0; i < N; ++i)
	{
		int user_in;
		cin >> user_in;
		cow_pos.push_back(user_in);
	}

	vector<vector<int>> weight(P + 1, vector<int>(P + 1, inf));
	vector<vector<int>> neighbor(P + 1);

	for (int i = 0; i <= P; ++i)
		weight[i][i] = 0;
	for (int i = 0; i < C; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		weight[a][b] = c;
		weight[b][a] = c;
		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	vector<vector<int>> dist(N, vector<int>(P + 1, inf));

	for (int nv = 0; nv < N; ++nv)
	{
		vector<bool> visited(P + 1, 0);
		vector<bool> joined(P + 1, 0);
		list<int> join;

		dist[nv][cow_pos[nv]] = 0;
		join.push_back(cow_pos[nv]);

		for (int numvisited = 0; numvisited < P; ++numvisited)
		{
			int i = *join.begin();

			list<int>::iterator deletejoin = join.begin();
			for (list<int>::iterator j = join.begin(); j != join.end(); ++j)
				if (dist[nv][i] > dist[nv][*j])
				{
					i = *j;
					deletejoin = j;
				}

			visited[i] = 1;
			joined[i] = 1;
			join.erase(deletejoin);

			for (int t = 0; t < neighbor[i].size(); ++t)
				if (!joined[neighbor[i][t]])
				{
					join.push_back(neighbor[i][t]);
					joined[neighbor[i][t]] = 1;
				}

			if (!neighbor[i].empty())
				for (int j = 0; j < (int)neighbor[i].size(); ++j)
					if (dist[nv][neighbor[i][j]] > dist[nv][i] + weight[i][neighbor[i][j]])
						dist[nv][neighbor[i][j]] = dist[nv][i] + weight[i][neighbor[i][j]];
		}
	}

	return 0;
}
