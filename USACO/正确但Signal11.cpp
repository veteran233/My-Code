/*
ID: kookinhard
PROG: maze1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

struct str_node
{
	short row;
	short column;
	bool isexit = 0;
	bool northwall = 0;
	bool southwall = 0;
	bool westwall = 0;
	bool eastwall = 0;
};

short W, H;
vector<short> ans;
deque<str_node> que;

void around(str_node &node, const vector<string>&wall, const short &row, const short &column)
{
	if (wall[row - 1][column] == '-')
		node.northwall = 1;
	if (wall[row + 1][column] == '-')
		node.southwall = 1;
	if (wall[row][column - 1] == '|')
		node.westwall = 1;
	if (wall[row][column + 1] == '|')
		node.eastwall = 1;
}
void bfs(vector<vector<str_node>>&node, vector<vector<bool>>&visited, vector<vector<short>>&time)
{
	while (que.size() != 0)
	{
		if (que[0].isexit)
		{
			que.clear();
			break;
		}

		if (!que[0].northwall)
		{
			if (!visited[que[0].row - 1][que[0].column])
			{
				visited[que[0].row - 1][que[0].column] = 1;
				que.push_back(node[que[0].row - 1][que[0].column]);
				time[que[0].row - 1][que[0].column] = time[que[0].row][que[0].column] + 1;
			}
		}
		if (!que[0].southwall)
		{
			if (!visited[que[0].row + 1][que[0].column])
			{
				visited[que[0].row + 1][que[0].column] = 1;
				que.push_back(node[que[0].row + 1][que[0].column]);
				time[que[0].row + 1][que[0].column] = time[que[0].row][que[0].column] + 1;
			}
		}
		if (!que[0].westwall)
		{
			if (!visited[que[0].row][que[0].column - 1])
			{
				visited[que[0].row][que[0].column - 1] = 1;
				que.push_back(node[que[0].row][que[0].column - 1]);
				time[que[0].row][que[0].column - 1] = time[que[0].row][que[0].column] + 1;
			}
		}
		if (!que[0].eastwall)
		{
			if (!visited[que[0].row][que[0].column + 1])
			{
				visited[que[0].row][que[0].column + 1] = 1;
				que.push_back(node[que[0].row][que[0].column + 1]);
				time[que[0].row][que[0].column + 1] = time[que[0].row][que[0].column] + 1;
			}
		}

		que.pop_front();
	}
}

int main()
{
	fstream fin("maze1.in");
	fstream fout("maze1.out");

	fin >> W >> H;
	vector<string> wall(2 * H + 1);
	vector<vector<str_node>> node(H, vector<str_node>(W));
	vector<short> x, y;

	getline(fin, wall[0]);
	for (int i = 0; i < 2 * H + 1; i++)
		getline(fin, wall[i]);

	for (int i = 1; i < 2 * W + 1; i += 2)
	{
		if (wall[0][i] == ' ')
		{
			node[0][(i - 1) / 2].isexit = 1;
			x.push_back(0);
			y.push_back((i - 1) / 2);
		}
		if (wall[2 * H][i] == ' ')
		{
			node[H - 1][(i - 1) / 2].isexit = 1;
			x.push_back(H - 1);
			y.push_back((i - 1) / 2);
		}
	}
	for (int i = 1; i < 2 * H + 1; i += 2)
	{
		if (wall[i][0] == ' ')
		{
			node[(i - 1) / 2][0].isexit = 1;
			x.push_back((i - 1) / 2);
			y.push_back(0);
		}
		if (wall[i][2 * W] == ' ')
		{
			node[(i - 1) / 2][W - 1].isexit = 1;
			x.push_back((i - 1) / 2);
			y.push_back(W - 1);
		}
	}

	for (int i = 1; i < 2 * H + 1; i += 2)
		for (int j = 1; j < 2 * W + 1; j += 2)
		{
			node[(i - 1) / 2][(j - 1) / 2].row = (i - 1) / 2;
			node[(i - 1) / 2][(j - 1) / 2].column = (j - 1) / 2;
			around(node[(i - 1) / 2][(j - 1) / 2], wall, i, j);
		}
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			vector<vector<bool>> visited(H, vector<bool>(W, 0));
			vector<vector<short>> time(H, vector<short>(W, 32767));

			visited[i][j] = 1;
			time[i][j] = 1;
			que.push_back(node[i][j]);

			bfs(node, visited, time);

			ans.push_back(min(time[x[0]][y[0]], time[x[1]][y[1]]));
		}

	fout << *max_element(ans.begin(), ans.end()) << endl;

	return 0;
}
