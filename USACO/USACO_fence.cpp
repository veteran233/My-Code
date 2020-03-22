/*
ID: kookinhard
PROG: fence
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int F;
int pos = 0;
vector<vector<bool>> connect(501, vector<bool>(501, 0));
vector<vector<int>> neighbor(501);
vector<int> tour(501, 0);

void find_euler_tour(const int &index)
{
	if ((int)neighbor[index].size() == 0)
		tour[pos++] = index;
	else
	{
		for (int i = 0; i < (int)neighbor[index].size(); ++i)
		{
			if (connect[index][neighbor[index][i]])
			{
				connect[index][neighbor[index][i]] = 0;
				connect[neighbor[index][i]][index] = 0;

				find_euler_tour(neighbor[index][i]);
				i = -1;
			}

		}
		tour[pos++] = index;
	}
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
		connect[a][b] = 1;
		connect[b][a] = 1;

		neighbor[a].push_back(b);
		neighbor[b].push_back(a);
	}

	int index = 0;
	for (; (int)neighbor[index].size() % 2 == 0; ++index);
	if (index == 501)
	{
		index = 0;
		for (; (int)neighbor[index].size() == 0; ++index);
	}

	find_euler_tour(index);

	for (int i = 500; i >= 0; --i)
		if (tour[i])
			cout << tour[i] << endl;

	return 0;
}
