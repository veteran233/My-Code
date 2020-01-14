/*
ID: kookinhard
PROG: milk3
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool state[21][21][21];
int A, B, C;
vector<int> ans;

int dfs(int nA, int nB, int nC)
{
	if (state[nA][nB][nC])
		return 0;
	else
	{
		state[nA][nB][nC] = 1;

		if (nA >= B - nB)
			dfs(nA - B + nB, B, nC);
		else
			dfs(0, nB + nA, nC);
		if (nA >= C - nC)
			dfs(nA - C + nC, nB, C);
		else
			dfs(0, nB, nC + nA);

		if (nB >= A - nA)
			dfs(A, nB - A + nA, nC);
		else
			dfs(nA + nB, 0, nC);
		if (nB >= C - nC)
			dfs(nA, nB - C + nC, C);
		else
			dfs(nA, 0, nC + nB);

		if (nC >= A - nA)
			dfs(A, nB, nC - A + nA);
		else
			dfs(nA + nC, nB, 0);
		if (nC >= B - nB)
			dfs(nA, B, nC - B + nB);
		else
			dfs(nA, nB + nC, 0);


		if (nA == 0)
			ans.push_back(nC);
	}
	return 0;
}
int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				state[i][j][k] = 0;

	cin >> A >> B >> C;
	dfs(0, 0, C);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
		if (i != ans.size() - 1)
			printf(" ");
	}

	printf("\n");
	return 0;
}
