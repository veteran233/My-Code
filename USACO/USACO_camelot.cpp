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
	bool isking = 0;
	bool isknight = 0;
};
class cla_king
{
public:
	int c;
	int r;
};

int column, row;
vector<vector<cla_node>> node;
cla_king king;

void bfs(int c, int r)
{
	queue<cla_node> que;
	que.push(node[c][r]);

	while (!que.empty())
	{
		cla_node temp_node = que.front();
		que.pop();


	}
}

int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	cin >> column >> row;

	vector<vector<bool>> visited(column, vector<bool>(row, 0));
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

	node[king.c][king.r].isking = 1;

	while (cin >> user_a)
	{
		cin >> user_b;
		node[user_a - 'A'][user_b - '0' - 1].isknight = 1;
	}

	return 0;
}
