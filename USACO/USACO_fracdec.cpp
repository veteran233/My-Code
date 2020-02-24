/*
ID: kookinhard
PROG: fracdec
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, D;

int main()
{
	/*freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);*/

	cin >> N >> D;

	cout << N / D << ".";

	for (int i = 0; i < 100; i++)
	{
		N = N % D * 10;
		cout << N / D;
	}

	return 0;
}
