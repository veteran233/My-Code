/*
ID: kookinhard
PROG: msquare
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

class way
{
public:
	way() {}
	way(short temp[2][4])
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 4; ++j)
				way_i[i][j] = temp[i][j];
	}
	short way_i[2][4];
	string str;
};

short init[2][4];
short goal[2][4];
bool visited[9][9][9][9][9][9][9][9];
deque<way> queue;
//set<int> s;
string ansstr;
int ans = 0x3f3f3f3f;

way A(way init_t)
{
	for (int i = 0; i < 4; ++i)
		swap(init_t.way_i[0][i], init_t.way_i[1][i]);
	init_t.str.push_back('A');
	return init_t;
}
way B(way init_t)
{
	reverse(init_t.way_i[0], init_t.way_i[0] + 3);
	reverse(init_t.way_i[0], init_t.way_i[0] + 4);
	reverse(init_t.way_i[1], init_t.way_i[1] + 3);
	reverse(init_t.way_i[1], init_t.way_i[1] + 4);
	init_t.str.push_back('B');
	return init_t;
}
way C(way init_t)
{
	int a, b, c, d;
	a = init_t.way_i[0][1];
	b = init_t.way_i[0][2];
	c = init_t.way_i[1][1];
	d = init_t.way_i[1][2];
	init_t.way_i[0][1] = c;
	init_t.way_i[0][2] = a;
	init_t.way_i[1][1] = d;
	init_t.way_i[1][2] = b;
	init_t.str.push_back('C');
	return init_t;
}
int vectoint(const way &test)
{
	return test.way_i[0][0] * 10000000 + test.way_i[0][1] * 1000000 + test.way_i[0][2] * 100000 + test.way_i[0][3] * 10000 + test.way_i[1][3] * 1000 + test.way_i[1][2] * 100 + test.way_i[1][1] * 10 + test.way_i[1][0];
}
bool martex(short a[2][4], short b[2][4])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] != b[i][j])
				return 0;
	return 1;
}
void bfs()
{
	while (!queue.empty())
	{
		way test = *queue.begin();
		queue.pop_front();

		if (martex(test.way_i, goal))
		{
			ans = min(ans, (int)test.str.size());
			if (ansstr != "")
				ansstr = min(ansstr, test.str);
			else
				ansstr = test.str;
		}

		//s.insert(vectoint(test));
		visited[test.way_i[0][0]][test.way_i[0][1]][test.way_i[0][2]][test.way_i[0][3]][test.way_i[1][3]][test.way_i[1][2]][test.way_i[1][1]][test.way_i[1][0]] = 1;
		way wA = A(test);
		way wB = B(test);
		way wC = C(test);

		//if (s.find(vectoint(wA)) == s.end() && (int)wA.str.size() < ans)
		if (!visited[wA.way_i[0][0]][wA.way_i[0][1]][wA.way_i[0][2]][wA.way_i[0][3]][wA.way_i[1][3]][wA.way_i[1][2]][wA.way_i[1][1]][wA.way_i[1][0]] && (int)wA.str.size() < ans)
			queue.push_back(A(test));
		//if (s.find(vectoint(wB)) == s.end() && (int)wB.str.size() < ans)
		if (!visited[wB.way_i[0][0]][wB.way_i[0][1]][wB.way_i[0][2]][wB.way_i[0][3]][wB.way_i[1][3]][wB.way_i[1][2]][wB.way_i[1][1]][wB.way_i[1][0]] && (int)wB.str.size() < ans)
			queue.push_back(B(test));
		//if (s.find(vectoint(wC)) == s.end() && (int)wC.str.size() < ans)
		if (!visited[wC.way_i[0][0]][wC.way_i[0][1]][wC.way_i[0][2]][wC.way_i[0][3]][wC.way_i[1][3]][wC.way_i[1][2]][wC.way_i[1][1]][wC.way_i[1][0]] && (int)wC.str.size() < ans)
			queue.push_back(C(test));
	}
}

int main()
{
	/*freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);*/

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 4; ++i)
		init[0][i] = i + 1;
	for (int i = 3; i >= 0; --i)
		init[1][i] = 8 - i;

	for (int i = 0; i < 4; ++i)
		cin >> goal[0][i];
	for (int i = 3; i >= 0; --i)
		cin >> goal[1][i];

	queue.push_back(way(init));
	bfs();

	cout << ans << endl;
	cout << ansstr << endl;

	return 0;
}
