/*
ID: kookinhard
PROG: combo
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;
int cir(int num)
{
	if (num < 1)
		return num + N;
	if (num > N)
		return num - N;
	return num;
}
int main()
{
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	int u1[3];
	int u2[3];
	int a[125], b[125], c[125];
	int d[125], e[125], f[125];
	cin >> N;
	cin >> u1[0] >> u1[1] >> u1[2];
	cin >> u2[0] >> u2[1] >> u2[2];

	if (N <= 5)
	{
		cout << N * N * N << endl;
		return 0;
	}

	int n = 0;
	for (int x = u1[0] - 2; x <= u1[0] + 2; x++)
		for (int y = u1[1] - 2; y <= u1[1] + 2; y++)
			for (int z = u1[2] - 2; z <= u1[2] + 2; z++)
			{
				a[n] = cir(x);
				b[n] = cir(y);
				c[n] = cir(z);
				n++;
			}

	n = 0;
	for (int x = u2[0] - 2; x <= u2[0] + 2; x++)
		for (int y = u2[1] - 2; y <= u2[1] + 2; y++)
			for (int z = u2[2] - 2; z <= u2[2] + 2; z++)
			{
				d[n] = cir(x);
				e[n] = cir(y);
				f[n] = cir(z);
				n++;
			}
	n = 0;
	for (int i = 0; i < 125; i++)
		for (int j = 0; j < 125; j++)
			if (a[i] == d[j] && b[i] == e[j] && c[i] == f[j])
				n++;

	cout << 250 - n << endl;
	return 0;
}
