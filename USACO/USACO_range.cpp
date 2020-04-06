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
vector<unsigned short> numsquare;
vector<vector<bool>> visited;

bool garea(const int &a, const int &b, const unsigned short &p)
{
	if (a + p >= N || b + p >= N)
		return 0;

	for (int i = 0; i <= p; ++i)
		for (int j = 0; j <= p; ++j)
			if (square[a + i][b + j] != '1')
				return 0;

	return 1;
}

int main()
{
	/*freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);*/

	cin >> N;

	square.resize(N);
	numsquare.resize(N);
	ans.resize(N + 1, 0);
	visited.resize(N);
	for (int i = 0; i < N; ++i)
		visited[i].resize(N, 0);

	for (int i = 0; i < N; ++i)
		numsquare[i] = i * i;

	for (int i = 0; i < N; ++i)
		cin >> square[i];

	queue<node> que, t_que;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (square[i][j] == '1')
				que.push(node(i, j));

	for (int k = N - 1; k >= 1; --k)
	{
		while (!que.empty())
		{
			node t = que.front();
			que.pop();

			if (!visited[t.a][t.b] && garea(t.a, t.b, k))
			{
				for (int i = 0; i <= k; ++i)
					for (int j = 0; j <= k; ++j)
						visited[t.a + i][t.b + j] = 1;

				++ans[k + 1];

				for (int i = k; i >= 2; --i)
					ans[i] += numsquare[k - i + 2];
			}
			else if (!visited[t.a][t.b])
				t_que.push(node(t.a, t.b));
		}

		que = t_que;
		t_que = queue<node>();
	}

	for (int i = 0; i < N + 1; ++i)
		if (ans[i] != 0)
			cout << i << " " << ans[i] << endl;

	return 0;
}
