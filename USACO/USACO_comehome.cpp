/*
ID: kookinhard
PROG: comehome
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;
vector<vector<int>> arc(52, vector<int>(52, inf));
int N;
int ans = inf;
char p;

int main()
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char a, b;
		int x, y;
		int t;
		cin >> a >> b >> t;
		if (a == b)
			continue;
		if (a <= 'Z')
			x = a - 65;
		else
			x = a - 97 + 26;
		if (b <= 'Z')
			y = b - 65;
		else
			y = b - 97 + 26;
		arc[x][y] = min(arc[x][y], t);
		arc[y][x] = arc[x][y];
	}
	for (int i = 0; i < 52; i++)
		arc[i][i] = 0;

	for (int source = 0; source < 25; source++)
	{
		vector<int> dist(52, inf);
		vector<bool> visited(52, 0);
		dist[source] = 0;

		int num = 0;
		while (num < 52)
		{
			int i = 0;
			for (; visited[i]; i++);
			for (int j = 0; j < 52; j++)
				if (!visited[j] && dist[j] < dist[i])
					i = j;

			visited[i] = 1;

			for (int j = 0; j < 52; j++)
				if (dist[i] + arc[i][j] < dist[j])
					dist[j] = dist[i] + arc[i][j];
			num++;
		}
		if (ans > dist['Z' - 65])
		{
			p = (char)(source + 65);
			ans = dist['Z' - 65];
		}
	}

	cout << p << " " << ans << endl;

	return 0;
}
