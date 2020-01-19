/*
ID: kookinhard
PROG: sort3
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sub(int &a, int &b)
{
	int temp = min(a, b);
	if (a > b)
	{
		a = a - b;
		b = 0;
	}
	else
	{
		b = b - a;
		a = 0;
	}
	return temp;
}
int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	int N;
	cin >> N;

	vector<char> num(N);
	int one_two = 0, one_three = 0, two_one = 0, two_three = 0, three_one = 0, three_two = 0;
	int none = 0, ntwo = 0, nthree = 0;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = 0; i < N; i++)
	{
		if (num[i] == '1')
			none++;
		if (num[i] == '2')
			ntwo++;
		if (num[i] == '3')
			nthree++;
	}
	//1:	0~none-1
	//2:	none~none+ntwo-1
	//3:	none+ntwo~none+ntwo+nthree-1
	for (int i = 0; i < none; i++)
	{
		if (num[i] == '2')
			one_two++;
		if (num[i] == '3')
			one_three++;
	}
	for (int i = none; i < none + ntwo; i++)
	{
		if (num[i] == '1')
			two_one++;
		if (num[i] == '3')
			two_three++;
	}
	for (int i = none + ntwo; i < none + ntwo + nthree; i++)
	{
		if (num[i] == '1')
			three_one++;
		if (num[i] == '2')
			three_two++;
	}

	int ans = 0;
	ans += sub(one_two, two_one);
	ans += sub(one_three, three_one);
	ans += sub(two_three, three_two);
	ans += (one_two + one_three + two_one + two_three + three_one + three_two) * 2 / 3;

	cout << ans << endl;

	return 0;
}
