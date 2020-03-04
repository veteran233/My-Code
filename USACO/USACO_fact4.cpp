/*
ID: kookinhard
PROG: fact4
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

void removezero(long long &a)
{
	while (a % 10 == 0)
		a /= 10;
}

int main()
{
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);

	cin >> N;

	long long ans = 1;

	for (int i = 1; i <= N; ++i)
	{
		ans *= i;
		ans %= 1000000;
		removezero(ans);
	}

	cout << ans % 10 << endl;

	return 0;
}
