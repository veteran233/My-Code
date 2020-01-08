/*
ID: kookinhard
PROG: milk
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	if (N == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> charge(M);
	vector<int> milk(M);

	for (int i = 0; i < M; i++)
		cin >> charge[i] >> milk[i];

	for (int i = 0; i < M - 1; i++)
		for (int j = 0; j < M - 1 - i; j++)
			if (charge[j] > charge[j + 1])
			{
				int temp = charge[j];
				charge[j] = charge[j + 1];
				charge[j + 1] = temp;

				temp = milk[j];
				milk[j] = milk[j + 1];
				milk[j + 1] = temp;
			}

	int i = 0;
	while (N > 0)
		N -= milk[i++];
	N = -N;

	int sum = 0;
	for (int j = 0; j < i - 1; j++)
		sum += milk[j] * charge[j];
	sum += (milk[i - 1] - N) * charge[i - 1];
	cout << sum << endl;
	return 0;
}
