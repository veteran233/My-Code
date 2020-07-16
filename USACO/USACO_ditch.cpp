/*
ID: kookinhard
PROG: ditch
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int infinity = 0x3f3f3f3f;

int main()
{
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> capacity(M + 1, vector<int>(M + 1, 0));
	vector<vector<bool>> isneighbor(M + 1, vector<bool>(M + 1, 0));

	for (int i = 0; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		capacity[a][b] += c;

		isneighbor[a][b] = 1;
		isneighbor[b][a] = 1;
	}

	const int source = 1, sink = M;
	int totalflow;

	if (source == sink)
	{
		totalflow = infinity;
		return 0;
	}

	totalflow = 0;

	while (1)
	{
		vector<int> prevnode(M + 1, -1);
		vector<int> flow(M + 1, 0);
		vector<bool> visited(M + 1, 0);

		flow[source] = infinity;

		int maxflow = 0;
		int maxloc = -1;

		while (1)
		{
			maxflow = 0;
			maxloc = -1;

			for (int i = 1; i <= M; ++i)
			{
				if (flow[i] > maxflow && !visited[i])
				{
					maxflow = flow[i];
					maxloc = i;
				}
			}

			if (maxloc == -1 || maxloc == sink)
				break;

			visited[maxloc] = 1;

			for (int i = 1; i <= M; ++i)
			{
				if (isneighbor[maxloc][i])
					if (flow[i] < min(maxflow, capacity[maxloc][i]))
					{
						prevnode[i] = maxloc;
						flow[i] = min(maxflow, capacity[maxloc][i]);
					}
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
