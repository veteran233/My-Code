/*
ID: kookinhard
PROG: concom
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int N;

void dfs(const int index, const vector<vector<int>>&arc, vector<int>&node, vector<bool>&visited, vector<vector<int>>&con)
{
	visited[index] = 1;
	for (int i = 1; i <= 100; i++)
		if (arc[index][i])
			node[i] += arc[index][i];
	for (int i = 1; i <= 100; i++)
	{
		if (visited[i] == 0 && node[i] > 50)
		{
			con[index].push_back(i);
			visited[i] = 1;
			for (int j = 1; j <= 100; j++)
				node[j] += arc[i][j];
			i = 0;
		}
	}
}

int main()
{
	ifstream fin("concom.in");
	ofstream fout("concom.out");

	fin >> N;

	int i, j, p;
	vector<vector<int>> arc(101, vector<int>(101, 0));

	while (fin >> i >> j >> p)
		arc[i][j] = p;

	vector<vector<int>> con(101);
	for (int i = 1; i <= 100; i++)
	{
		vector<int> node(101, 0);
		vector<bool> visited(101, 0);
		dfs(i, arc, node, visited, con);
		sort(con[i].begin(), con[i].end());
		for (int j = 0; j < con[i].size(); j++)
			fout << i << " " << con[i][j] << endl;
	}

	return 0;
}
