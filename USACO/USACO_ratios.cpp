/*
ID: kookinhard
PROG: ratios
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int goal_x, goal_y, goal_z;
int x1, yy1, z1;
int x2, y2, z2;
int x3, y3, z3;
int u1 = 0, u2 = 0, u3 = 0, goal_unit = 0;
vector<vector<int>> ans;

bool cmp()
{
	if (goal_unit == 0)
		return 0;
	if (u1 * x1 + u2 * x2 + u3 * x3 == goal_unit * goal_x)
		if (u1 * yy1 + u2 * y2 + u3 * y3 == goal_unit * goal_y)
			if (u1 * z1 + u2 * z2 + u3 * z3 == goal_unit * goal_z)
				return 1;
	return 0;
}

int main()
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);

	cin >> goal_x >> goal_y >> goal_z;
	cin >> x1 >> yy1 >> z1;
	cin >> x2 >> y2 >> z2;
	cin >> x3 >> y3 >> z3;

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			for (int k = 0; k < 100; ++k)
				for (int n = 0; n < 100; ++n)
				{
					u1 = i;
					u2 = j;
					u3 = k;
					goal_unit = n;
					if (cmp())
					{
						ans.push_back(vector<int>());
						ans[(int)ans.size() - 1].push_back(u1);
						ans[(int)ans.size() - 1].push_back(u2);
						ans[(int)ans.size() - 1].push_back(u3);
						ans[(int)ans.size() - 1].push_back(goal_unit);
					}
				}

	if (ans.empty())
	{
		cout << "NONE" << endl;
		return 0;
	}

	int index = 0;
	for (int i = 0; i < (int)ans.size(); ++i)
		if (ans[index][0] + ans[index][1] + ans[index][2] > ans[i][0] + ans[i][1] + ans[i][2])
			index = i;

	cout << ans[index][0] << " " << ans[index][1] << " " << ans[index][2] << " " << ans[index][3] << endl;

	return 0;
}
