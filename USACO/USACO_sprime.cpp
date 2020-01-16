/*
ID: kookinhard
PROG: sprime
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int N;

int prime(int n)
{
	if (n == 2 || n == 3)
		return 1;
	if (n == 1)
		return 0;
	if (n % 6 != 1 && n % 6 != 5)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int d(int n)
{
	int i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return i;
}
int sp(int n)
{
	if (d(n) > N)
		return 0;
	if (prime(n))
		for (int i = 1; i <= 9; i++)
		{
			if (!sp(n * 10 + i))
			{
				cout << n << endl;
				return 1;
			}
		}
	return 1;
}

int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	cin >> N;

	for (int i = 1; i <= 9; i++)
		sp(i);

	return 0;
}
