/*
ID: kookinhard
PROG: wormhole
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;
int X[12], Y[12];
int Next[12] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
int ans = 0;
void JudgeCycle()
{
	bool sign = 0;
	for (int i = 0; i < N; i++)
	{
		int x = X[i];
		int y = Y[i];
		int visited[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
		while (1)
		{
			int i = 0;
			for (; i < N; i++)
				if (X[i] > x && Y[i] == y)
				{
					x = X[i];
					break;
				}
			if (i == N)break;
			if (visited[i] == 0)
			{
				visited[i] = 1;
				x = X[Next[i]];
				y = Y[Next[i]];
			}
			else
			{
				ans++;
				sign = 1;
			}
			if (sign)break;
		}
		if (sign)break;
	}
}
int create(int start)
{
	while (Next[start] != -1 && start < N)
		start++;
	if (start == N)
		return 1;
	for (int step = 1; start + step < N; step++)
	{
		if (Next[start + step] == -1)
		{
			Next[start] = start + step;
			Next[start + step] = start;
		}
		else
			continue;
		if (create(start + 1))
			JudgeCycle();
		Next[start + step] = -1;
	}
	Next[start] = -1;
	return 0;
}
int main()
{
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> X[i] >> Y[i];
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (X[j] > X[j + 1])
			{
				int temp = X[j];
				X[j] = X[j + 1];
				X[j + 1] = temp;

				temp = Y[j];
				Y[j] = Y[j + 1];
				Y[j + 1] = temp;
			}
	create(0);
	cout << ans << endl;
	return 0;
}
