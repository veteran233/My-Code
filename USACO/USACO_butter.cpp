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
int inf = 0x3f3f3f3f;
vector<int> cowpos;
vector<vector<int>> weight;
vector<vector<int>> neighbor;
vector<int> dist;
vector<int> ans;

bool cmp(int &a, int &b)
{
	return dist[a] > dist[b];
}

int main()
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);

	cin >> N >> P >> C;

	cowpos.resize(N);
	ans.resize(P + 1, 0);
	weight.resize(P + 1);
	neighbor.resize(P + 1);
	for (int i = 0; i < P + 1; ++i)
		weight[i].resize(P + 1, inf);

	for (int i = 0; i < N; ++i)
		cin >> cowpos[i];

	for (int i = 0; i < C; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		weight[a][b] = c;
		weight[b][a] = c;
		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	for (int cow = 0; cow < N; cow++)
	{
		vector<bool> visited(P + 1, 0);
		vector<bool> joined(P + 1, 0);
		vector<int> join;

		dist.assign(P + 1, inf);

		join.push_back(cowpos[cow]);
		joined[cowpos[cow]] = 1;
		dist[cowpos[cow]] = 0;

		for (int numvisited = 0; numvisited < P; ++numvisited)
		{
			int i = *join.begin();

			visited[i] = 1;
			pop_heap(join.begin(), join.end(), cmp);
			join.pop_back();

			for (int j = 0; j < (int)neighbor[i].size(); ++j)
				if (dist[neighbor[i][j]] > dist[i] + weight[i][neighbor[i][j]])
				{
					dist[neighbor[i][j]] = dist[i] + weight[i][neighbor[i][j]];
					vector<int>::iterator it = find(join.begin(), join.end(), neighbor[i][j]);
					if (it != join.end())
						push_heap(join.begin(), it + 1, cmp);
				}

			for (int j = 0; j < (int)neighbor[i].size(); ++j)
				if (!joined[neighbor[i][j]])
				{
					join.push_back(neighbor[i][j]);
					push_heap(join.begin(), join.end(), cmp);

					joined[neighbor[i][j]] = 1;
				}
		}

		for (int i = 0; i < P + 1; ++i)
			ans[i] = ans[i] + dist[i] >= inf ? inf : ans[i] + dist[i];
	}

	cout << *min_element(ans.begin(), ans.end()) << endl;

	return 0;
}
