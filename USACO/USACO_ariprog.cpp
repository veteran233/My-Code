/*
ID: kookinhard
PROG: ariprog
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	int N, M;
	cin >> N >> M;
	int Max = M * M * 2;

	bool ap[125001];

	for (int i = 0; i < 125001; i++)
		ap[i] = 1;
	for (int i = 0; i <= M; i++)
		for (int j = i; j <= M; j++)
			ap[i * i + j * j] = 0;

	bool sign = 0;
	for (int b = 1; b < Max; b++)
	{
		if ((N - 1)*b > Max)
			break;
		for (int a = 0; a < Max; a++)
		{
			if (a + (N - 1)*b > Max)
				break;
			int n = 0;
			for (; n < N; n++)
			{
				if (!ap[a + n * b])
					continue;
				else
					break;
			}

			if (n == N)
			{
				printf("%d %d\n", a, b);
				sign = 1;
			}
		}
	}

	if (!sign)
		printf("NONE\n");
	return 0;
}
