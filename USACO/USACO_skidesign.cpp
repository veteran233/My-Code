/*
ID: kookinhard
PROG: skidesign
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	int N, hill[1000];
	int ans = 2147483647;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hill[i];

	sort(hill, hill + N);

	for (int i = hill[0]; i < hill[N - 1]; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (hill[j] > i + 17)
				sum += (hill[j] - i - 17)*(hill[j] - i - 17);
			if (hill[j] < i)
				sum += (i - hill[j])*(i - hill[j]);
		}
		ans = min(sum, ans);
	}
	cout << ans << endl;
	return 0;
}
