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

class cla_queue
{
public:
	cla_queue(int i)
	{
		d = i;
	}
	int index;
	int d;

	bool operator <(const cla_queue&a)const
	{
		return this->d < a.d;
	}
	bool operator >(const cla_queue&a)const
	{
		return this->d > a.d;
	}
};

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
	int nv = 0;
	while (nv < P + 1)
	{
		//vector<bool> visited(P + 1, 0);
		vector<int> truedist(P + 1, inf);

		vector<cla_queue> dist(P + 1, cla_queue(inf));
		for (int i = 0; i <= P; ++i)
			dist[i].index = i;

		dist[source].d = 0;

		make_heap(dist.begin(), dist.end(), less<cla_queue>());

		int numvisited = 0;
		while (numvisited < P + 1)
		{
			int i = dist[0].index;

			for (int j = 0; j <= P; ++j)
				if (truedist[j] > truedist[i] + weight[i][j])
				{
					truedist[j] = truedist[i] + weight[i][j];
					dist[j].d = dist[i].d + weight[i][j];
				}

			pop_heap(dist.begin(), dist.end(), less<cla_queue>());
			++numvisited;
		}
		ans = min(ans, distsum(truedist));
		++source;
		++nv;
	}

	cout << ans << endl;

	return 0;
}
