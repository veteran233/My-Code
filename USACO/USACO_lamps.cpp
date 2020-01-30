/*
ID: kookinhard
PROG: lamps
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, C;
vector<int> ON, OFF;
vector<string> lamp;
vector<vector<int>> num;

bool searchlamp(const string &str, const int &index)
{
	for (int i = 0; i < lamp.size(); i++)
		if (str == lamp[i])
		{
			num[i].push_back(index);
			return 0;
		}
	return 1;
}
string b1(string str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	return str;
}
string b2(string str)
{
	for (int i = 0; i < str.size(); i += 2)
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	return str;
}
string b3(string str)
{
	for (int i = 1; i < str.size(); i += 2)
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	return str;
}
string b4(string str)
{
	for (int i = 0; i < str.size(); i += 3)
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	return str;
}
int dfs(string str, int index = 0)
{
	if (!searchlamp(str, index))
		return 0;
	else
	{
		lamp.push_back(str);
		num.push_back(vector<int>(1, index));
		dfs(b1(str), index + 1);
		dfs(b2(str), index + 1);
		dfs(b3(str), index + 1);
		dfs(b4(str), index + 1);
	}
	return 0;
}
bool meet(int index)
{
	for (int i = 0; i < num[index].size(); i++)
		if (C - num[index][i] >= 0 && (C - num[index][i]) % 2 == 0)
		{
			bool s1 = 1, s2 = 1;
			for (int j = 0; j < ON.size(); j++)
				if (lamp[index][ON[j] - 1] == '0')
					s1 = 0;
			for (int j = 0; j < OFF.size(); j++)
				if (lamp[index][OFF[j] - 1] == '1')
					s2 = 0;
			if (s1 & s2)
				return s1 & s2;
		}
	return 0;
}

int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	cin >> N >> C;

	int user;
	while (cin >> user)
	{
		if (user == -1)
			break;
		ON.push_back(user);
	}
	while (cin >> user)
	{
		if (user == -1)
			break;
		OFF.push_back(user);
	}

	string str;
	for (int i = 0; i < N; i++)
		str.push_back('1');

	dfs(str);

	bool sign = 0;
	if (meet(1))
	{
		cout << lamp[1] << endl;
		sign = 1;
	}
	if (meet(5))
	{
		cout << lamp[5] << endl;
		sign = 1;
	}
	if (meet(3))
	{
		cout << lamp[3] << endl;
		sign = 1;
	}
	if (meet(7))
	{
		cout << lamp[7] << endl;
		sign = 1;
	}
	if (meet(6))
	{
		cout << lamp[6] << endl;
		sign = 1;
	}
	if (meet(2))
	{
		cout << lamp[2] << endl;
		sign = 1;
	}
	if (meet(4))
	{
		cout << lamp[4] << endl;
		sign = 1;
	}
	if (meet(0))
	{
		cout << lamp[0] << endl;
		sign = 1;
	}
	if (!sign)
		cout << "IMPOSSIBLE" << endl;

	return 0;
}
