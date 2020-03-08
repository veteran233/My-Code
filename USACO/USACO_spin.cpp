/*
ID: kookinhard
PROG: spin
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class wheel
{
public:
	int deg_begin;
	int deg_end;
	int range;
	int speed;
	bool block[360];
	wheel(int speed, int begin, int range)
	{
		this->speed = speed;
		deg_begin = begin;
		this->range = range;
		deg_end = deg_begin + this->range;
		if (deg_end >= 360)
			deg_end -= 360;

		if (deg_begin < deg_end)
			for (int i = 0; i < 360; ++i)
				if (deg_begin <= i && i <= deg_end)
					block[i] = 1;
				else
					block[i] = 0;
		else if (deg_begin == deg_end)
			for (int i = 0; i < 360; ++i)
				block[i] = 1;
		else
			for (int i = 0; i < 360; ++i)
			{
				if (0 <= i && i <= deg_end)
				{
					block[i] = 1;
					continue;
				}
				if (deg_begin <= i && i < 360)
				{
					block[i] = 1;
					continue;
				}
				block[i] = 0;
			}
	}
	void spin()
	{
		if (deg_begin <= deg_end)
			for (int i = deg_begin; i <= deg_end; ++i)
				block[i] = 0;
		else if (deg_begin == deg_end)
			for (int i = 0; i < 360; ++i)
				block[i] = 0;
		else
		{
			for (int i = 0; i <= deg_end; ++i)
				block[i] = 0;
			for (int i = deg_begin; i < 360; ++i)
				block[i] = 0;
		}

		deg_begin += speed;
		deg_end += speed;
		if (deg_begin >= 360)
			deg_begin -= 360;
		if (deg_end >= 360)
			deg_begin -= 360;

		if (deg_begin <= deg_end)
			for (int i = deg_begin; i <= deg_end; ++i)
				block[i] = 1;
		else if (deg_begin == deg_end)
			for (int i = 0; i < 360; ++i)
				block[i] = 1;
		else
		{
			for (int i = 0; i <= deg_end; ++i)
				block[i] = 1;
			for (int i = deg_begin; i < 360; ++i)
				block[i] = 1;
		}
	}
private:
	int pri_deg_begin;
	int pri_deg_end;
};

vector<wheel> whe;

int main()
{
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);

	int speed;
	while (cin >> speed)
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; ++i)
		{
			int begin, range;
			cin >> begin >> range;
			whe.push_back(wheel(speed, begin, range));
		}
	}

	return 0;
}
