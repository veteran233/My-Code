/*
ID: kookinhard
PROG: camelot
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class cla_node
{
public:
	int c;
	int r;
	cla_node() {}
	cla_node(int a, int b)
	{
		c = a;
		r = b;
	}
};

int column, row;
vector<vector<cla_node>> node;
cla_node king;
vector<cla_node> knight;

void bfs(int c, int r, vector<vector<bool>>&joined, vector<vector<int>>&dist)
{
	queue<cla_node> que;
	que.push(node[c][r]);
	joined[c][r] = 1;
	dist[c][r] = 0;

	static int loop = 1;

	while (!que.empty())
	{
		cla_node temp_node = que.front();
		que.pop();

		if (temp_node.c + 1 < column && temp_node.r + 2 < row)
			if (!joined[temp_node.c + 1][temp_node.r + 2])
			{
				que.push(node[temp_node.c + 1][temp_node.r + 2]);
				joined[temp_node.c + 1][temp_node.r + 2] = 1;
				dist[temp_node.c + 1][temp_node.r + 2] = loop;
			}

		if (temp_node.c + 1 < column && temp_node.r - 2 >= 0)
			if (!joined[temp_node.c + 1][temp_node.r - 2])
			{
				que.push(node[temp_node.c + 1][temp_node.r - 2]);
				joined[temp_node.c + 1][temp_node.r - 2] = 1;
				dist[temp_node.c + 1][temp_node.r - 2] = loop;
			}

		if (temp_node.c - 1 >= 0 && temp_node.r + 2 < row)
			if (!joined[temp_node.c - 1][temp_node.r + 2])
			{
				que.push(node[temp_node.c - 1][temp_node.r + 2]);
				joined[temp_node.c - 1][temp_node.r + 2] = 1;
				dist[temp_node.c - 1][temp_node.r + 2] = loop;
			}

		if (temp_node.c - 1 >= 0 && temp_node.r - 2 >= 0)
			if (!joined[temp_node.c - 1][temp_node.r - 2])
			{
				que.push(node[temp_node.c - 1][temp_node.r - 2]);
				joined[temp_node.c - 1][temp_node.r - 2] = 1;
				dist[temp_node.c - 1][temp_node.r - 2] = loop;
			}

		if (temp_node.c + 2 < column && temp_node.r + 1 < row)
			if (!joined[temp_node.c + 2][temp_node.r + 1])
			{
				que.push(node[temp_node.c + 2][temp_node.r + 1]);
				joined[temp_node.c + 2][temp_node.r + 1] = 1;
				dist[temp_node.c + 2][temp_node.r + 1] = loop;
			}

		if (temp_node.c + 2 < column && temp_node.r - 1 >= 0)
			if (!joined[temp_node.c + 2][temp_node.r - 1])
			{
				que.push(node[temp_node.c + 2][temp_node.r - 1]);
				joined[temp_node.c + 2][temp_node.r - 1] = 1;
				dist[temp_node.c + 2][temp_node.r - 1] = loop;
			}

		if (temp_node.c - 2 >= 0 && temp_node.r + 1 < row)
			if (!joined[temp_node.c - 2][temp_node.r + 1])
			{
				que.push(node[temp_node.c - 2][temp_node.r + 1]);
				joined[temp_node.c - 2][temp_node.r + 1] = 1;
				dist[temp_node.c - 2][temp_node.r + 1] = loop;
			}

		if (temp_node.c - 2 >= 0 && temp_node.r - 1 >= 0)
			if (!joined[temp_node.c - 2][temp_node.r - 1])
			{
				que.push(node[temp_node.c - 2][temp_node.r - 1]);
				joined[temp_node.c - 2][temp_node.r - 1] = 1;
				dist[temp_node.c - 2][temp_node.r - 1] = loop;
			}

		++loop;
	}
}

int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	cin >> column >> row;

	node.resize(column);
	for (int i = 0; i < column; ++i)
		node[i].resize(row);

	for (int i = 0; i < column; ++i)
		for (int j = 0; j < row; ++j)
		{
			node[i][j].c = i;
			node[i][j].r = j;
		}

	char user_a, user_b;
	cin >> user_a >> user_b;

	king.c = user_a - 'A';
	king.r = user_b - '0' - 1;

	while (cin >> user_a)
	{
		cin >> user_b;
		knight.push_back(cla_node(user_a - 'A', user_b - '0' - 1));
	}

	//select a gathering area
	for (int i = 0; i < column; ++i)
		for (int j = 0; j < row; ++j)
		{
			vector<vector<bool>> joined(column, vector<bool>(row, 0));
			vector<vector<int>> dist(column, vector<int>(row));

			bfs(i, j, joined, dist);

			//select a king-gathering area


			for (int m = 0; m < column; ++m)
				for (int n = 0; n < row; ++n)
				{

				}
		}

	return 0;
}
