/*
ID: kookinhard
PROG: fence6
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class segment
{
public:
	int length;
	vector<int> a, b;
};

int N;

int main()
{
	/*freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);*/

	cin >> N;

	vector<segment> seg(N + 1);

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



	return 0;
}
