/*
ID: kookinhard
PROG: ttwo
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char area[10][10];

struct obj
{
	int r;
	int c;
	int dire = 0;
	bool same(obj &a)
	{
		if (this->c == a.c && this->r == a.r)
			return 1;
		else
			return 0;
	}
	void move()
	{
		//1:N 2:E 3:S 4:W
		switch (this->dire)
		{
		case 0:r--; break;
		case 1:c++; break;
		case 2:r++; break;
		case 3:c--; break;
		}
	}
	bool movepossible()
	{
		switch (this->dire)
		{
		case 0:if (r - 1 < 0 || area[r - 1][c] == '*')return 0; break;
		case 1:if (c + 1 > 9 || area[r][c + 1] == '*')return 0; break;
		case 2:if (r + 1 > 9 || area[r + 1][c] == '*')return 0; break;
		case 3:if (c - 1 < 0 || area[r][c - 1] == '*')return 0; break;
		}
		return 1;
	}
};

int main()
{
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	obj farmer, cow;
	int time = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> area[i][j];
			if (area[i][j] == 'F')
			{
				farmer.r = i;
				farmer.c = j;
			}
			if (area[i][j] == 'C')
			{
				cow.r = i;
				cow.c = j;
			}
		}

	while (!farmer.same(cow))
	{
		if (farmer.movepossible())
			farmer.move();
		else
			farmer.dire = (farmer.dire + 1) % 4;

		if (cow.movepossible())
			cow.move();
		else
			cow.dire = (cow.dire + 1) % 4;

		time++;
		if (time >= 65536)
			break;
	}

	if (time == 65536)
		cout << 0 << endl;
	else
		cout << time << endl;

	return 0;
}
