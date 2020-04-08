/*
ID: kookinhard
PROG: range
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class node
{
public:
	int a;
	int b;
	node(int x, int y)
	{
		a = x;
		b = y;
	}
};

int N;
vector<string> square;
vector<unsigned short> ans;


bool garea(const int &a, const int &b, const unsigned short &p)
{
	if (a + p >= N || b + p >= N)
		return 0;

	for (int i = 0; i <= p; ++i)
		if (square[a + p][b + i] != '1')
			return 0;

	for (int i = 0; i <= p; ++i)
		if (square[a + i][b + p] != '1')
			return 0;

	return 1;
}

int main()
{
	/*freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);*/

	cin >> N;

	square.resize(N);
	ans.resize(N + 1, 0);

	for (int i = 0; i < N; ++i)
		cin >> square[i];

	queue<node> que, t_que;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (square[i][j] == '1')
				que.push(node(i, j));

	while (!que.empty())
	{
		node t = que.front();
		que.pop();

		for (int i = 1; i < N; ++i)
		{
			if (garea(t.a, t.b, i))
				++ans[i + 1];
			else
				break;
		}
	}

	for (int i = 0; i < N + 1; ++i)
		if (ans[i] != 0)
			cout << i << " " << ans[i] << endl;

	return 0;
}
