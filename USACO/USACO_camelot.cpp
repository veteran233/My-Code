/*
ID: kookinhard
PROG: camelot
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int column, row;
int inf = 0x3f3f3f3f;
int cost[26][30];
int kingdist[26][30];
int kingcost[26][30];
int knightcost[26][30][2];

int knightmove(int a, int b, bool sign)
{
	int ret = 0;

	if (a + 1 < column)
	{
		if (b + 2 < row)
		{
			if (knightcost[a + 1][b + 2][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a + 1][b + 2][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
		if (b - 2 >= 0)
		{
			if (knightcost[a + 1][b - 2][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a + 1][b - 2][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
	}
	if (a - 1 >= 0)
	{
		if (b + 2 < row)
		{
			if (knightcost[a - 1][b + 2][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a - 1][b + 2][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
		if (b - 2 >= 0)
		{
			if (knightcost[a - 1][b - 2][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a - 1][b - 2][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
	}
	if (a + 2 < column)
	{
		if (b + 1 < row)
		{
			if (knightcost[a + 2][b + 1][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a + 2][b + 1][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
		if (b - 1 >= 0)
		{
			if (knightcost[a + 2][b - 1][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a + 2][b - 1][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
	}
	if (a - 2 >= 0)
	{
		if (b + 1 < row)
		{
			if (knightcost[a - 2][b + 1][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a - 2][b + 1][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
		if (b - 1 >= 0)
		{
			if (knightcost[a - 2][b - 1][sign] > knightcost[a][b][sign] + 1)
			{
				knightcost[a - 2][b - 1][sign] = knightcost[a][b][sign] + 1;
				++ret;
			}
		}
	}

	if (!sign && knightcost[a][b][1] > kingdist[a][b] + knightcost[a][b][0])
	{
		knightcost[a][b][1] = kingdist[a][b] + knightcost[a][b][0];
		++ret;
	}
	return ret;
}

int main()
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	cin >> row >> column;

	char user_c;
	int user_r;
	cin >> user_c >> user_r;

	for (int i = 0; i < column; ++i)
		for (int j = 0; j < row; ++j)
			kingdist[i][j] = max(abs(i - user_c + 'A'), abs(j - user_r + 1));

	memset(cost, 0, sizeof(cost));
	memcpy(kingcost, kingdist, sizeof(kingcost));

	while (cin >> user_c)
	{
		cin >> user_r;

		memset(knightcost, inf, sizeof(knightcost));
		knightcost[user_c - 'A'][user_r - 1][0] = 0;

		int k = 0;
		while (1)
		{
			int temp = 0;
			for (int i = 0; i < column; ++i)
				for (int j = 0; j < row; ++j)
				{
					if (knightcost[i][j][0] == k)
						temp += knightmove(i, j, 0);
					if (knightcost[i][j][1] == k)
						temp += knightmove(i, j, 1);
				}
			if (temp == 0)
				break;
			else
				++k;
		}

		for (int i = 0; i < column; ++i)
			for (int j = 0; j < row; ++j)
				if (kingcost[i][j] > knightcost[i][j][1] - knightcost[i][j][0])
					kingcost[i][j] = knightcost[i][j][1] - knightcost[i][j][0];

		for (int i = 0; i < column; ++i)
			for (int j = 0; j < row; ++j)
				if (knightcost[i][j][0] != inf)
					cost[i][j] += knightcost[i][j][0];
				else
					cost[i][j] = inf;
	}

	int ans = cost[0][0] + kingcost[0][0];
	for (int i = 0; i < column; ++i)
		for (int j = 0; j < row; ++j)
			if (ans > cost[i][j] + kingcost[i][j])
				ans = cost[i][j] + kingcost[i][j];

	cout << ans << endl;

	return 0;
}
