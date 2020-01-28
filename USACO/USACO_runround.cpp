/*
ID: kookinhard
PROG: runround
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool r(vector<bool>&visited)
{
	bool sign = 0;
	for (int i = 0; i < visited.size(); i++)
		if (visited[i] != 1)
			sign = 1;
	return sign;
}
int dfs(vector<bool>&visited, vector<short>&num, bool &s, int index = 0)
{
	visited[index] = 1;

	index = index + num[index];
	while (index >= num.size())
		index = index - num.size();

	if (visited[index] && index != 0)
		s = 1;
	else if (!r(visited) && index == 0)
		s = 0;
	else
		dfs(visited, num, s, index);
	return 0;
}

int main()
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	int n;
	cin >> n;

	while (1)
	{
		n++;
		int temp = n;
		bool s = 0;
		vector<short> num;
		vector<bool> d(10, 0);
		while (temp != 0)
		{
			if (d[temp % 10] || temp % 10 == 0)
			{
				s = 1;
				break;
			}
			d[temp % 10] = 1;
			num.push_back(temp % 10);
			temp /= 10;
		}

		if (s == 1)
			continue;

		reverse(num.begin(), num.end());

		vector<bool> visited(num.size(), 0);

		dfs(visited, num, s);

		if (s == 0)
		{
			cout << n << endl;
			break;
		}
	}
	return 0;
}
