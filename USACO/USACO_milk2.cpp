/*
ID: kookinhard
PROG: milk2
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int N;
struct Time
{
	int start;
	int end;
};
void exchange(int&a, int&b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
vector<Time> Sort(vector<Time>T)
{
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
			if (T[j].start > T[j + 1].start)
			{
				exchange(T[j].start, T[j + 1].start);
				exchange(T[j].end, T[j + 1].end);
			}
	return T;
}
int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	cin >> N;

	vector<Time> T(N);
	for (int i = 0; i < N; i++)
		cin >> T[i].start >> T[i].end;

	T = Sort(T);

	int i = 0;
	int j = 0;
	for (; j < N; i++)
	{
		T[i].start = T[j].start;
		T[i].end = T[j].end;
		while (T[j].start <= T[i].end)
		{
			T[i].end = T[i].end > T[j].end ? T[i].end : T[j].end;
			j++;
			if (j >= N) break;
		}
	}

	int max1 = T[0].end - T[0].start;
	int max2 = 0;
	for (int n = 0; n < i; n++)
		if (max1 < T[n].end - T[n].start)
			max1 = T[n].end - T[n].start;
	for (int n = 0; n < i - 1; n++)
		if (max2 < T[n + 1].start - T[n].end)
			max2 = T[n + 1].start - T[n].end;
	cout << max1 << " " << max2 << endl;
	return 0;
}
