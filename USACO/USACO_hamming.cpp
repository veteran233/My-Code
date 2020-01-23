/*
ID: kookinhard
PROG: hamming
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

short N, B, D;

int hd(short a, short b)
{
	int i = 0;
	short c = a xor b;
	while (c != 0)
	{
		if (c & 1)
			i++;
		c >>= 1;
	}
	return i;
}

int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	cin >> N >> B >> D;

	vector<bool> num(pow(2, B), 0);

	num[0] = 1;

	for (int i = 0; i < num.size(); i++)
		if (hd(0, i) >= D)
			num[i] = 1;

	for (int i = 1; i < num.size(); i++)
		if (num[i])
			for (int j = i + 1; j < num.size(); j++)
				if (num[j])
					if (hd(i, j) < D)
						num[j] = 0;

	int temp = 1;
	for (int i = 0; i < num.size(); i++)
	{
		if (temp > N)
			break;
		if (num[i])
		{
			if (temp == N)
				printf("%d\n", i);
			else if (temp % 10 == 0 && temp != 0)
				printf("%d\n", i);
			else
				printf("%d ", i);
			temp++;
		}
	}

	return 0;
}
