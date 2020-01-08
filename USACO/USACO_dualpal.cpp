/*
ID: kookinhard
PROG: dualpal
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
void exchange(char &a, char &b)
{
	char t = a;
	a = b;
	b = t;
}
void reverseorder(string &A)
{
	for (int i = 0; i < A.length() / 2; i++)
		exchange(A[i], A[A.length() - 1 - i]);
}
string basechange(const int &base, int num)
{
	string str;
	while (num != 0)
	{
		str += '0' + num % base;
		num /= base;
	}
	reverseorder(str);
	return str;
}
int judge(string str)
{
	const int len = str.length();
	for (int i = 0; i < len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return 1;
	return 0;
}
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int N, S;
	cin >> N >> S;
	S++;
	while (N)
	{
		int sign = 0;
		for (int i = 2; i <= 10; i++)
			if (!judge(basechange(i, S)))
				sign++;
		if (sign >= 2)
		{
			cout << S << endl;
			N--;
		}
		S++;
	}

	return 0;
}
