/*
ID: kookinhard
PROG: pprime
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

int A, B;

int prime(int n)
{
	if (n % 6 != 1 && n % 6 != 5)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
void num2()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
	{
		int num = 10 * d1 + d1;
		if (num < A)continue;
		if (num > B)return;
		if (prime(num))
			cout << num << endl;
	}
}
void num3()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
		{
			int num = 100 * d1 + 10 * d2 + d1;
			if (num < A)continue;
			if (num > B)return;
			if (prime(num))
				cout << num << endl;
		}
}
void num4()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
		{
			int num = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
			if (num < A)continue;
			if (num > B)return;
			if (prime(num))
				cout << num << endl;
		}
}
void num5()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
			{
				int num = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
				if (num < A)continue;
				if (num > B)return;
				if (prime(num))
					cout << num << endl;
			}
}
void num6()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
			{
				int num = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 10 * d2 + d1;
				if (num < A)continue;
				if (num > B)return;
				if (prime(num))
					cout << num << endl;
			}
}
void num7()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
				for (int d4 = 0; d4 <= 9; d4++)
				{
					int num = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					if (num < A)continue;
					if (num > B)return;
					if (prime(num))
						cout << num << endl;
				}
}
void num8()
{
	for (int d1 = 1; d1 <= 9; d1 += 2)
		for (int d2 = 0; d2 <= 9; d2++)
			for (int d3 = 0; d3 <= 9; d3++)
				for (int d4 = 0; d4 <= 9; d4++)
				{
					int num = 10000000 * d1 + 1000000 * d2 + 100000 * d3 + 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					if (num < A)continue;
					if (num > B)return;
					if (prime(num))
						cout << num << endl;
				}
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	cin >> A >> B;

	for (int i = A; i <= 9; i++)
		if (prime(i))
			cout << i << endl;

	num2();
	num3();
	num4();
	num5();
	num6();
	num7();
	num8();

	return 0;
}
