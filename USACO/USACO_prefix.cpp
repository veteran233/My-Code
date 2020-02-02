/*
ID: kookinhard
PROG: prefix
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> P;
string S;

int patten(const int first, const int end)
{
	bool ret = 0;
	for (int i = 0; i < P.size(); i++)
	{
		if (first + (int)P[i].size() != end)
			continue;
		bool sign = 0;
		for (int j = 0; j < P[i].size(); j++)
			if (P[i][j] != S[first + j])
				sign = 1;
		if (!sign)
			ret = 1;
	}
	return ret;
}

int main()
{
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	string user;
	while (fin >> user)
	{
		if (user == ".")
			break;
		P.push_back(user);
	}
	while (fin >> user)
		S += user;

	int pmax = 0;
	for (int i = 0; i < P.size(); i++)
		if (pmax < P[i].size())
			pmax = P[i].size();

	vector<bool> dp(S.size() + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= S.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] && patten(j, i))
			{
				dp[i] = 1;
				break;
			}
			if (i - j > pmax)
				break;
		}
	}

	int i = S.size();
	for (; dp[i] == 0; i--);
	fout << i << endl;

	return 0;
}
