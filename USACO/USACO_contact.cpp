/*
ID: kookinhard
PROG: contact
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int A, B, N;
string record;
vector<string> pattern;
vector<vector<string*>> point;
vector<int> pat_count;
vector<int> num;

deque<int> prefix(const string &a)
{
	if (a.size() == 1)
		return deque<int>(1, -1);
	deque<int> ret((int)a.size());
	ret[0] = 0;
	int i = 0;
	int j = 1;
	while (j < a.size())
	{
		if (a[i] == a[j])
			ret[j++] = ++i;
		else
		{
			ret[j++] = 0;
			i = 0;
		}
	}
	ret.pop_back();
	ret.push_front(-1);
	return ret;
}
int kmp(const string &a)
{
	deque<int> p = prefix(a);
	int ret = 0;
	int i = 0;
	while (i < record.size())
	{
		int j = 0;
		while (j < a.size() && i < record.size())
		{
			if (a[j] == record[i])
			{
				++i;
				++j;
			}
			else
			{
				j = p[j];
				if (j == -1)
				{
					j = 0;
					++i;
				}
			}
		}
		if (j == a.size())
		{
			++ret;
			i = i - j + 1;
		}
	}
	return ret;
}
void dfs(int level = 0, string str = "")
{
	if (level > B)
		return;
	else
	{
		if (str.size() >= A)
			pattern.push_back(str);
		str.push_back('0');
		dfs(level + 1, str);

		*(--str.end()) = '1';
		dfs(level + 1, str);
	}
}
//bool cmp(int &a, int &b)
//{
//	if (pat_count[a] > pat_count[b])
//		return 1;
//	else
//		return 0;
//}
//void ansprint(int index)
//{
//	fout << pat_count[index] << endl;
//	for (int i=0;i<)
//}

int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	fin >> A >> B >> N;

	string str_temp;
	while (fin >> str_temp)
		record.append(str_temp);

	dfs();

	vector<bool> visited((int)pattern.size(), 0);

	for (int i = 0; i < pattern.size(); ++i)
		pat_count.push_back(kmp(pattern[i]));

	//sort(num.begin(), num.end(), cmp);

	int vis = 0;
	int index = 0;
	while (vis < pattern.size())
	{
		for (; visited[index]; ++index);
		int pmax = index;
		for (int i = index; i < pattern.size(); ++i)
			if (!visited[i] && pat_count[pmax] < pat_count[i])
				pmax = i;

		point.push_back(vector<string*>(1, &pattern[pmax]));
		num.push_back(pat_count[pmax]);
		visited[pmax] = 1;
		++vis;
		for (int i = pmax + 1; i < pattern.size(); ++i)
			if (!visited[i] && pat_count[pmax] == pat_count[i])
			{
				point[(int)point.size() - 1].push_back(&pattern[i]);
				visited[i] = 1;
				++vis;
			}
	}

	if (point.size() < N)
		for (int i = 0; i < point.size() && num[i] > 0; ++i)
		{
			fout << num[i] << endl;
			for (int j = 1; j <= point[i].size(); ++j)
			{
				fout << *point[i][j - 1];
				if (j % 6 != 0 && j != point[i].size())
					fout << " ";
				else if (j != point[i].size())
					fout << "\n";
			}
			fout << "\n";
		}
	else
		for (int i = 0; i < N && num[i] > 0; ++i)
		{
			fout << num[i] << endl;
			for (int j = 1; j <= point[i].size(); ++j)
			{
				fout << *point[i][j - 1];
				if (j % 6 != 0 && j != point[i].size())
					fout << " ";
				else if (j != point[i].size())
					fout << "\n";
			}
			fout << "\n";
		}

	return 0;
}
