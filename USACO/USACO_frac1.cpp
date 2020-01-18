/*
ID: kookinhard
PROG: frac1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

short N;
vector<short> a;
vector<short> b;

short gcd(short a, short b)
{
	if (a < b)
		swap(a, b);
	return b == 0 ? a : gcd(b, a%b);
}
bool frac(short i, short j)
{
	return a[i] * b[j] < a[j] * b[i] ? 1 : 0;
}
int main()
{
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	cin >> N;

	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
		{
			if (gcd(i, j) == 1)
			{
				a.push_back(i);
				b.push_back(j);
			}
		}

	vector<short> st;

	for (int i = 0; i < a.size(); i++)
		st.push_back(i);

	sort(st.begin(), st.end(), frac);

	cout << "0/1" << endl;
	for (int i = 0; i < st.size(); i++)
		cout << a[st[i]] << '/' << b[st[i]] << endl;
	cout << "1/1" << endl;

	return 0;
}
