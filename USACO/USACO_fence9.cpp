/*
ID: kookinhard
PROG: fence9
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, m, p;
int ans = 0;

int f1(const int &x)
{
	int r = m * x;
	if (r%n == 0)
		return r / n - 1;
	else
		return r / n;
}
int f2(const int &x)
{
	int r = m * (p - x);
	if (r % (p - n) == 0)
		return r / (p - n) - 1;
	else
		return r / (p - n);
}
int f22(const int &x)
{
	int r = m * (p - x);
	return r / (p - n);
}
int main()
{
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);

	cin >> n >> m >> p;

	if (n < p)
	{
		for (int x = 1; x <= n; ++x)
			ans += f1(x);
		for (int x = n + 1; x < p; ++x)
			ans += f2(x);
	}
	else if (n == p)
	{
		for (int x = 1; x < p; ++x)
			ans += f1(x);
	}
	else
	{
		for (int x = 1; x <= p; ++x)
			ans += f1(x);
		for (int x = p + 1; x < n; ++x)
			ans += f1(x) - f22(x);
	}

	cout << ans << endl;

	return 0;
}
