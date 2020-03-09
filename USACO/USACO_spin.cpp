/*
ID: kookinhard
PROG: spin
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> speed(5);
vector<vector<int>> wed_begin(5, vector<int>());
vector<vector<int>> wed_range(5, vector<int>());

int main()
{
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);

	for (int i = 0; i < 5; ++i)
	{
		int sp, num;
		cin >> sp >> num;
		speed[i] = sp;
		for (int j = 0; j < num; ++j)
		{
			int a, b;
			cin >> a >> b;
			wed_begin[i].push_back(a);
			wed_range[i].push_back(b);
		}
	}

	for (int i = 0; i <= 360; i++)
	{
		vector<int> time(360, 0);

		for (int n = 0; n < 5; ++n)
			for (int k = 0; k < wed_begin[n].size(); ++k)
				for (int m = wed_begin[n][k] % 360;; m = (m + 1) % 360)
				{
					++time[m];
					if (m == (wed_begin[n][k] + wed_range[n][k]) % 360)
						break;
				}

		for (int n = 0; n < 360; ++n)
			if (time[n] > 4)
			{
				cout << i << endl;
				return 0;
			}

		for (int n = 0; n < 5; ++n)
			for (int k = 0; k < wed_begin[n].size(); ++k)
				wed_begin[n][k] = (wed_begin[n][k] + speed[n]) % 360;
	}

	cout << "none" << endl;

	return 0;
}
