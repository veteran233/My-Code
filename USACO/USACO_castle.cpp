/*
ID: kookinhard
PROG: castle
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

short M, N;
short temp = 0;
bool visited[50][50];
short zone[50][50];
short wallsum[50][50];
int aftermax = 0;
short x, y;
char z;

class room
{
public:
	//0:n 1:s 2:w 3:e
	bool wall[4] = { 0,0,0,0 };
};
int dfs(vector<short>&Max, room r[50][50], short a, short b)
{
	if (visited[a][b])
		return 0;
	else
	{
		visited[a][b] = 1;
		Max[temp]++;
		zone[a][b] = temp;
		if (!r[a][b].wall[0])
			dfs(Max, r, a - 1, b);
		if (!r[a][b].wall[1])
			dfs(Max, r, a + 1, b);
		if (!r[a][b].wall[2])
			dfs(Max, r, a, b - 1);
		if (!r[a][b].wall[3])
			dfs(Max, r, a, b + 1);
	}
	return 0;
}
void wallsumtowall(room r[50][50])
{
	for (int a = 0; a < N; a++)
		for (int b = 0; b < M; b++)
			for (int i = 8; i > 0; i /= 2)
				if (wallsum[a][b] >= i)
				{
					wallsum[a][b] -= i;
					if (i == 8)
						r[a][b].wall[1] = 1;
					if (i == 4)
						r[a][b].wall[3] = 1;
					if (i == 2)
						r[a][b].wall[0] = 1;
					if (i == 1)
						r[a][b].wall[2] = 1;
				}
}
short around(vector<short>&Max, short a, short b)
{
	short sign = 0;

	if (a - 1 >= 0)if (zone[a][b] != zone[a - 1][b] && aftermax < Max[zone[a][b]] + Max[zone[a - 1][b]])
	{
		aftermax = Max[zone[a][b]] + Max[zone[a - 1][b]];
		sign = 1;
	}
	if (b + 1 < M)if (zone[a][b] != zone[a][b + 1] && aftermax < Max[zone[a][b]] + Max[zone[a][b + 1]])
	{
		aftermax = Max[zone[a][b]] + Max[zone[a][b + 1]];
		sign = 2;
	}

	return sign;
}
void search(vector<short>&Max)
{
	for (int j = 0; j < M; j++)
		for (int i = N - 1; i >= 0; i--)
		{
			short sign = around(Max, i, j);
			if (sign)
			{
				x = i + 1;
				y = j + 1;
				if (sign == 1)
					z = 'N';
				else if (sign == 2)
					z = 'E';
			}
		}
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	//column,row
	cin >> M >> N;

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			visited[i][j] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> wallsum[i][j];

	room r[50][50];
	wallsumtowall(r);

	vector<short> Max;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j])
			{
				Max.push_back(0);
				dfs(Max, r, i, j);
				temp++;
			}

	cout << temp << endl;
	cout << *max_element(Max.begin(), Max.end()) << endl;

	search(Max);

	cout << aftermax << endl;
	cout << x << " " << y << " " << z << endl;

	return 0;
}
