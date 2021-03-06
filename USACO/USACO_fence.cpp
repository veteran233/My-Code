/*
ID: kookinhard
PROG: fence
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int F;
int pos = 0;
vector<vector<int>> connect(501, vector<int>(501, 0));
vector<vector<int>> neighbor(501);
vector<int> tour(1025, 0);

void find_euler_tour(const int index)
{
	for (int i = 0; i < (int)neighbor[index].size(); ++i)
	{
		if (connect[index][neighbor[index][i]])
		{
			--connect[index][neighbor[index][i]];
			--connect[neighbor[index][i]][index];

			find_euler_tour(neighbor[index][i]);
		}
	}
	tour[pos++] = index;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	cin >> F;

	for (int i = 0; i < F; ++i)
	{
		int a, b;
		cin >> a >> b;
		++connect[a][b];
		++connect[b][a];

		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	for (int i = 0; i < 501; ++i)
		if ((bool)neighbor[i].size())
			sort(neighbor[i].begin(), neighbor[i].end());

	int index = 0;
	while (index < 501)
	{
		if ((int)neighbor[index].size() % 2 != 0)
			break;
		++index;
	}
	if (index == 501)
		for (index = 0; (int)neighbor[index].size() == 0; ++index);

	find_euler_tour(index);

	for (int i = 1024; i >= 0; --i)
		if (tour[i])
			cout << tour[i] << endl;

	return 0;
}
