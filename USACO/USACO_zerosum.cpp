/*
ID: kookinhard
PROG: zerosum
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string str;

void zero()
{
	vector<int> num;
	vector<char> c;
	int n = 1;
	int j = 0;
	while (n <= N)
	{
		int temp = n;
		while (j < N - 1 && str[j] == ' ')
		{
			j++;
			n++;
			temp = temp * 10 + n;
		}
		num.push_back(temp);
		if (j < N - 1 && str[j] != ' ')
			c.push_back(str[j]);
		j++;
		n++;
	}

	int temp = num[0];
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] == '+')
			temp += num[i + 1];
		else
			temp -= num[i + 1];
	}
	if (temp == 0)
	{
		for (int i = 0; i < str.size(); i++)
			cout << i + 1 << str[i];
		cout << str.size() + 1 << endl;
	}
}
int dfs()
{
	if (str.size() >= N - 1)
		return 0;
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:str.push_back(' '); break;
		case 1:str.push_back('+'); break;
		case 2:str.push_back('-'); break;
		}
		if (!dfs())
		{
			zero();
		}
		str.pop_back();
	}
	return 1;
}

int main()
{
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	cin >> N;

	dfs();

	return 0;
}
