/*
ID: kookinhard
PROG: agrinet
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;
int index = 0;

int main()
{
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);

	int N;

	cin >> N;

	vector<vector<int>> weight(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> weight[i][j];

	vector<int> dist(N, inf);
	vector<bool> visited(N, 0);
	int cost = 0;
	int num = 0;

	int source = 0;
	visited[source] = 1;
	num++;

	while (num < N)
	{
		for (int i = 0; i < N; i++)
			if (dist[i] > weight[source][i])
				dist[i] = weight[source][i];

		int temp = index;
		for (; visited[temp]; temp++);
		index = temp;

		for (int i = temp + 1; i < N; i++)
			if (!visited[i] && dist[i] < dist[temp])
				temp = i;

		source = temp;
		visited[source] = 1;
		cost += dist[source];

		num++;
	}

	cout << cost << endl;

	return 0;
}
