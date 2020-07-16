/*
ID: kookinhard
PROG: stall4
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	const int source = 0, sink = N + M + 1;

	vector<vector<int>> capacity(N + M + 2, vector<int>(N + M + 2, 0));
	vector<vector<bool>> isneighbor(N + M + 2, vector<bool>(N + M + 2, 0));
	int totalflow = 0;

	for (int i = 1; i <= N; ++i)
	{
		capacity[source][i] = 1;
		isneighbor[source][i] = 1;
		isneighbor[i][source] = 1;
	}
	for (int i = N + 1; i <= N + M; ++i)
	{
		capacity[i][sink] = 1;
		isneighbor[i][sink] = 1;
		isneighbor[sink][i] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		int a;
		cin >> a;

		while (a--)
		{
			int b;
			cin >> b;

			capacity[i][b + N] = 1;
			isneighbor[i][b + N] = 1;
			isneighbor[b + N][i] = 1;
		}
	}

	while (1)
	{
		vector<int> prevnode(N + M + 2, -1);
		vector<int> flow(N + M + 2, 0);
		vector<bool> visited(N + M + 2, 0);

		flow[source] = 0x3f3f3f3f;

		int maxflow = 0;
		int maxloc = -1;
		while (1)
		{
			maxflow = 0;
			maxloc = -1;

			for (int i = 0; i <= N + M + 1; ++i)
				if (flow[i] > maxflow && !visited[i])
				{
					maxflow = flow[i];
					maxloc = i;
				}

			if (maxloc == -1 || maxloc == sink)
				break;

			visited[maxloc] = 1;

			for (int i = 0; i <= N + M + 1; ++i)
				if (isneighbor[i][maxloc])
					if (flow[i] < min(maxflow, capacity[maxloc][i]))
					{
						prevnode[i] = maxloc;
						flow[i] = min(maxflow, capacity[maxloc][i]);
					}
		}

		if (maxloc == -1)
			break;

		totalflow += flow[sink];

		int curnode = sink;
		while (curnode != source)
		{
			int nextnode = prevnode[curnode];
			capacity[nextnode][curnode] -= flow[sink];
			capacity[curnode][nextnode] += flow[sink];
			curnode = nextnode;
		}
	}

	cout << totalflow << endl;

	return 0;
}
