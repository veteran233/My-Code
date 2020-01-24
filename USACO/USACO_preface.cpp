/*
ID: kookinhard
PROG: preface
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string ans;

string com(char a, int b)
{
	string str;
	for (int i = 0; i < b; i++)
		str.push_back(a);
	return str;
}
string fn1(int n)
{
	if (n == 0)
		return "";
	if (n == 4)
		return "IV";
	if (n == 9)
		return "IX";
	if ((n -= 5) >= 0)
		return "V" + com('I', n);
	else
		return com('I', 5 + n);
}
string fn2(int n)
{
	if (n == 0)
		return "";
	if (n == 4)
		return "XL";
	if (n == 9)
		return "XC";
	if ((n -= 5) >= 0)
		return "L" + com('X', n);
	else
		return com('X', 5 + n);
}
string fn3(int n)
{
	if (n == 0)
		return "";
	if (n == 4)
		return "CD";
	if (n == 9)
		return "CM";
	if ((n -= 5) >= 0)
		return "D" + com('C', n);
	else
		return com('C', 5 + n);
}
string fn4(int n)
{
	if (n == 0)
		return "";
	if (n == 1)
		return "M";
	if (n == 2)
		return "MM";
	if (n == 3)
		return "MMM";
}
void romannum(int x)
{
	for (int n4 = 0; n4 <= 9; n4++)
		for (int n3 = 0; n3 <= 9; n3++)
			for (int n2 = 0; n2 <= 9; n2++)
				for (int n1 = 0; n1 <= 9; n1++)
				{
					int n = 1000 * n4 + 100 * n3 + 10 * n2 + n1;
					if (n > x)
						return;
					else
					{
						ans.append(fn4(n4));
						ans.append(fn3(n3));
						ans.append(fn2(n2));
						ans.append(fn1(n1));
					}
				}
}

int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	int N;
	bool sign[7] = { 0,0,0,0,0,0,0 };//I V X L C D M
	char r[7] = { 'I','V','X','L','C','D','M' };
	int n[7] = { 0,0,0,0,0,0,0 };

	cin >> N;

	romannum(N);

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] == 'I')
		{
			sign[0] = 1;
			n[0]++;
			continue;
		}
		if (ans[i] == 'V')
		{
			sign[1] = 1;
			n[1]++;
			continue;
		}
		if (ans[i] == 'X')
		{
			sign[2] = 1;
			n[2]++;
			continue;
		}
		if (ans[i] == 'L')
		{
			sign[3] = 1;
			n[3]++;
			continue;

		}
		if (ans[i] == 'C')
		{
			sign[4] = 1;
			n[4]++;
			continue;
		}
		if (ans[i] == 'D')
		{
			sign[5] = 1;
			n[5]++;
			continue;
		}
		if (ans[i] == 'M')
		{
			sign[6] = 1;
			n[6]++;
			continue;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (sign[i])
			cout << r[i] << " " << n[i] << endl;
	}

	return 0;
}
