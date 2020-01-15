/*
ID: kookinhard
PROG: numtri
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned short R;

int dp(vector<short>&num, vector<unsigned>&ans)
{
	ans[0] = num[0];
	ans[1] = num[1] + num[0];
	ans[2] = num[2] + num[0];
	for (int n = 2; n < R; n++)
		for (int i = (1 + n)*n / 2; i < (2 + n)*(1 + n) / 2; i++)
		{
			if (i == (1 + n)*n / 2)
				ans[i] = ans[n*(n - 1) / 2] + num[i];
			else if (i == (2 + n)*(1 + n) / 2 - 1)
				ans[i] = ans[(1 + n)*n / 2 - 1] + num[i];
			else
				ans[i] = max(ans[i - n] + num[i], ans[i - n - 1] + num[i]);
		}

	return 0;
}
int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	cin >> R;

	vector<short> num((1 + R)*R / 2, 0);
	vector<unsigned> ans((1 + R)*R / 2, 0);

	for (int i = 0; i < num.size(); i++)
		cin >> num[i];
	dp(num, ans);
	cout << *max_element(ans.end() - R, ans.end()) << endl;
	return 0;
}
