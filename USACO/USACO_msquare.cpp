/*
ID: kookinhard
PROG: msquare
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <algorithm>
#include <string.h>
#include <deque>

using namespace std;

class square
{
public:
	square() {}
	square(bool sign)
	{
		for (int i = 0; i < 8; ++i)
			num[i] = i + 1;
	}
	short num[8];
	string str;
};

bool visited[40320];
short goal[8];
deque<square> squ;
int anscount = 0x3f3f3f3f;
string ansstr;

void A(square &temp)
{
	reverse(temp.num, temp.num + 8);
	temp.str.push_back('A');
}
void B(square &temp)
{
	reverse(temp.num, temp.num + 3);
	reverse(temp.num, temp.num + 4);
	reverse(temp.num + 5, temp.num + 8);
	reverse(temp.num + 4, temp.num + 8);
	temp.str.push_back('B');
}
void C(square &temp)
{
	static short a, b, c, d;

	a = temp.num[1];
	b = temp.num[2];
	c = temp.num[5];
	d = temp.num[6];
	temp.num[1] = d;
	temp.num[2] = a;
	temp.num[5] = b;
	temp.num[6] = c;
	temp.str.push_back('C');
}
int cantor(const square &temp)
{
	static const short fact[8] = { 5040,720,120,24,6,2,1,1 };
	static short a[8];
	static int ret;
	static bool used[8];
	static short count;

	ret = 0;
	memset(used, 0, sizeof(used));

	for (int i = 0; i < 8; ++i)
	{
		count = 0;
		for (int j = 0; j < 8; ++j)
			if (!used[j] && temp.num[i] > temp.num[j])
				++count;

		used[i] = 1;
		a[i] = count;
		ret += a[i] * fact[i];
	}

	return ret;
}
bool equality(const square &temp)
{
	for (int i = 0; i < 8; ++i)
		if (temp.num[i] != goal[i])
			return 0;
	return 1;
}
void bfs()
{
	static square temp;
	while (!squ.empty())
	{
		temp = *squ.begin();

		squ.pop_front();

		if (equality(temp))
		{
			if (!ansstr.empty())
				ansstr = min(ansstr, temp.str);
			else
				ansstr = temp.str;
			anscount = (int)ansstr.size();
		}

		square a = temp, b = temp, c = temp;
		A(a); B(b); C(c);

		if (!visited[cantor(a)])
		{
			visited[cantor(a)] = 1;
			if (anscount > (int)a.str.size())
				squ.push_back(a);
		}
		if (!visited[cantor(b)])
		{
			visited[cantor(b)] = 1;
			if (anscount > (int)b.str.size())
				squ.push_back(b);
		}
		if (!visited[cantor(c)])
		{
			visited[cantor(c)] = 1;
			if (anscount > (int)c.str.size())
				squ.push_back(c);
		}
	}
}

int main()
{
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 8; ++i)
		fin >> goal[i];

	squ.push_back(square(0));
	visited[cantor(*squ.begin()->num)] = 1;
	bfs();

	fout << anscount << endl;

	int i = 0;
	while (i < (int)ansstr.size())
	{
		fout << ansstr[i];
		++i;
		if (i % 60 == 0 && i != (int)ansstr.size())
			fout << "\n";
	}

	fout << "\n";

	return 0;
}
