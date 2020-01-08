/*
ID: kookinhard
PROG: palsquare
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
char num_change(int &&a)
{
	switch (a)
	{
	case 10:return 'A';
	case 11:return 'B';
	case 12:return 'C';
	case 13:return 'D';
	case 14:return 'E';
	case 15:return 'F';
	case 16:return 'G';
	case 17:return 'H';
	case 18:return 'I';
	case 19:return 'J';
	default:return '0' + a;
	}
}
string change(int base, int n)
{
	string temp;
	while (n != 0)
	{
		temp += num_change(n%base);
		n = n / base;
	}
	reverseorder(temp);
	return temp;
}
int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int N[300];
	string N2[300];
	int base;

	cin >> base;

	for (int i = 0; i < 300; i++)
	{
		N[i] = i + 1;
		N2[i] = change(base, N[i] * N[i]);
	}

	for (int i = 0; i < 300; i++)
	{
		bool sign = 0;
		for (int j = 0; j < N2[i].length() / 2; j++)
			if (N2[i][j] != N2[i][N2[i].length() - 1 - j])
			{
				sign = 1;
				break;
			}

		if (!sign)
			cout << change(base, i + 1) << " " << N2[i] << endl;
	}
	return 0;
}
