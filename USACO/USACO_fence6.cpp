/*
ID: kookinhard
PROG: fence6
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class segment
{
public:
	int length;
	vector<int> a, b;
};

int N;
int ans = 0x3f3f3f3f;
vector<segment> seg;

void dfs(const short &s, short index, short before, vector<bool> visitable, bool e, int &sum)
{
	sum += seg[index].length;

	if (index != s)
		if (!e)
			for (int i = 0; i < (int)seg[before].a.size(); ++i)
				visitable[seg[before].a[i]] = 0;
		else
			for (int i = 0; i < (int)seg[before].b.size(); ++i)
				visitable[seg[before].b[i]] = 0;


	for (int i = 0; i < (int)seg[s].b.size(); ++i)
	{
		if (index == seg[s].b[i])
		{
			ans = min(ans, sum);
			return;
		}
	}

	bool sign = 1;
	for (int i = 0; i < (int)seg[index].a.size(); ++i)
	{
		if (visitable[seg[index].a[i]])
		{
			sign = 0;
			dfs(s, seg[index].a[i], index, visitable, 0, sum);
			sum -= seg[seg[index].a[i]].length;
		}
	}
	if (sign)
	{
		for (int i = 0; i < (int)seg[index].b.size(); ++i)
		{
			if (visitable[seg[index].b[i]])
			{
				dfs(s, seg[index].b[i], index, visitable, 1, sum);
				sum -= seg[seg[index].b[i]].length;
			}
		}
	}
	return;
}
int main()
{
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);

	cin >> N;

	seg.resize(N + 1);

	for (int i = 0; i < N; ++i)
	{
		int s;
		cin >> s;
		cin >> seg[s].length;
		int c, d;
		cin >> c >> d;

		for (int j = 0; j < c; ++j)
		{
			int t;
			cin >> t;
			seg[s].a.push_back(t);
		}
		for (int j = 0; j < d; ++j)
		{
			int t;
			cin >> t;
			seg[s].b.push_back(t);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		vector<bool> visitable(N + 1, 1);
		visitable[i] = 0;
		int sum = 0;
		dfs(i, i, 0, visitable, 0, sum);
	}

	cout << ans << endl;

	return 0;
}
