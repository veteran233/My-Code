/*
ID: kookinhard
PROG: contact
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

struct pattern
{
	pattern(int a, string str)
	{
		int_count = a;
		str_pattern = str;
	}
	int int_count;
	string str_pattern;
};

int A, B, N;
string record;
vector<pattern> pat;

int pat_transform(string a)
{
	int ret = 0;
	for (int i = a.size() - 1; i >= 0; --i)
		if (a[i] == '1')
			ret += (int)pow(2, (int)a.size() - i - 1);
	return ret;
}
bool cmp1(pattern *a, pattern *b)
{
	if (a->str_pattern.size() < b->str_pattern.size())
		return 1;
	else
		if (a->str_pattern.size() == b->str_pattern.size())
			if (a->str_pattern < b->str_pattern)
				return 1;
			else
				return 0;
		else
			return 0;
}
bool cmp2(pattern &a, pattern &b)
{
	if (a.int_count > b.int_count)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	cin >> A >> B >> N;

	string user_temp;
	while (cin >> user_temp)
		record.append(user_temp);

	vector<int> point(B - A + 1, 0);
	vector<int> len(B - A + 1);
	for (int i = A; i < B + 1; ++i)
		len[i - A] = i;

	vector<vector<bool>> visited;
	vector<vector<int>> pos;
	for (int i = 0; i < B - A + 1; ++i)
	{
		visited.push_back(vector<bool>((int)pow(2, len[i]), 0));
		pos.push_back(vector<int>((int)pow(2, len[i])));

		for (int j = len[i] - 1; j < record.size(); ++j)
		{
			int index = pat_transform(record.substr(j - len[i] + 1, len[i]));
			if (!visited[i][index])
			{
				pat.push_back(pattern(1, record.substr(j - len[i] + 1, len[i])));
				pos[i][index] = (int)pat.size() - 1;
				visited[i][index] = 1;
			}
			else
				++pat[pos[i][index]].int_count;
		}
	}

	sort(pat.begin(), pat.end(), cmp2);

	vector<vector<pattern*>> ans;
	int index = 0;
	int now_count = -1;

	while (ans.size() < N + 1 && index < pat.size())
	{
		if (now_count != pat[index].int_count)
		{
			ans.push_back(vector<pattern*>());
			if (ans.size() == N + 1)
			{
				ans.pop_back();
				break;
			}
			ans[(int)ans.size() - 1].push_back(&pat[index]);
			now_count = pat[index].int_count;
		}
		else
			ans[(int)ans.size() - 1].push_back(&pat[index]);
		index++;
	}

	for (int i = 0; i < ans.size(); ++i)
		sort(ans[i].begin(), ans[i].end(), cmp1);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i][0]->int_count << endl;
		for (int j = 1; j <= ans[i].size(); ++j)
		{
			cout << ans[i][j - 1]->str_pattern;
			if (j % 6 != 0 && j != ans[i].size())
				cout << " ";
			else if (j % 6 == 0 && j != ans[i].size())
				cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}
