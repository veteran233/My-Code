/*
ID: kookinhard
PROG: holstein
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

short V, G;
unsigned short ans1 = 65535;
vector<bool> ans2;

unsigned short sum(vector<bool>&visited)
{
	unsigned short n = 0;
	for (int i = 0; i < visited.size(); i++)
		if (visited[i])
			n++;
	return n;
}
bool meet(vector<short>&vit, vector<vector<short>>&feeds, const short n)
{
	bool sign = 0;
	for (int i = 0; i < V; i++)
	{
		vit[i] -= feeds[n][i];
		if (vit[i] > 0)
			sign = 1;
	}
	return sign;
}
int dfs(vector<short>&vit, vector<vector<short>>&feeds, vector<bool>&visited, short n)
{
	for (int i = n; i < G; i++)
	{
		visited[i] = 1;
		if (meet(vit, feeds, i))
			dfs(vit, feeds, visited, i + 1);
		else
		{
			unsigned short temp = sum(visited);
			if (ans1 > temp)
			{
				ans1 = min(ans1, temp);
				ans2 = visited;
			}
		}
		for (int k = 0; k < V; k++)
			vit[k] += feeds[i][k];
		visited[i] = 0;
	}
	return 0;
}

int main()
{
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	cin >> V;
	vector<short> vit(V);
	for (int i = 0; i < V; i++)
		cin >> vit[i];

	cin >> G;
	vector<vector<short>> feeds(G, vector<short>(V));
	for (int i = 0; i < G; i++)
		for (int j = 0; j < V; j++)
			cin >> feeds[i][j];

	vector<bool> visited(G, 0);

	dfs(vit, feeds, visited, 0);

	printf("%d ", ans1);
	short temp = 1;
	for (int i = 0; i < ans2.size(); i++)
	{
		if (ans2[i] && temp < ans1)
		{
			printf("%d ", i + 1);
			temp++;
		}	
		else if (ans2[i] && temp == ans1)
		{
			printf("%d", i + 1);
			temp++;
		}
	}
	printf("\n");

	return 0;
}
