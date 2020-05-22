/*
ID: kookinhard
PROG: fence9
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

double n, m, p;
int ans = 0;

double f1(const double &x)
{
	int r = (int)(m / n * x);
	if ((double)(n / m * r) == x)
		return r - 1;
	else
		return r;
}
double f2(const double &x)
{
	int r = (int)(m * (n - x) / (p - n) + m);
	if ((double)((m - r) / m * (p - n) + n) == x)
		return r - 1;
	else
		return r;
}
int main()
{
	/*freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);*/

	cin >> n >> m >> p;

	if (n < p)
	{
		for (double x = 1; x <= n; ++x)
			ans += (int)f1(x);
		for (double x = n + 1; x < p; ++x)
			ans += (int)f2(x);
	}
	else if (n == p)
	{
		for (double x = 1; x < p; ++x)
			ans += (int)f1(x);
	}
	else
	{
		for (double x = 1; x <= p; ++x)
			ans += (int)f1(x);
		for (double x = p + 1; x < n; ++x)
			ans += (int)f1(x) - (int)f2(x);
	}

	cout << ans << endl;

	return 0;
}
