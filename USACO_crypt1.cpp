/*
ID: kookinhard
PROG: crypt1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int change(char i)
{
	return i - '0';
}
void itochar(int a, char temp[])
{
	int i = 1, n = 10;
	while (a / n != 0)
	{
		i++;
		n *= 10;
	}
	for (int j = 0; j < i; j++)
	{
		temp[j] = a % 10 + '0';
		a /= 10;
	}
	for (int m = 0; m < i / 2; m++)
	{
		char t = temp[m];
		temp[m] = temp[i - 1 - m];
		temp[i - 1 - m] = t;
	}
}
bool judge(vector<char> cNum, const char ctemp[])
{
	for (int i = 0; ctemp[i] != '\0'; i++)
		for (int j = 0; j < cNum.size(); j++)
			if (ctemp[i] == cNum[j])
				break;
			else
				if (j < cNum.size() - 1)
					continue;
				else
					return 0;
	return 1;
}
int nsize(const char a[])
{
	int i = 0;
	for (; a[i] != '\0'; i++);
	return i;
}
int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int N;
	cin >> N;
	vector<char> cNum(N);
	for (int i = 0; i < cNum.size(); i++)
		cin >> cNum[i];

	int n_three;
	int n_two1, n_two2;

	int i = 0;
	for (int x = 0; x < cNum.size(); x++)
		for (int y = 0; y < cNum.size(); y++)
			for (int z = 0; z < cNum.size(); z++)
				for (int b = 0; b < cNum.size(); b++)
					for (int w = 0; w < cNum.size(); w++)
					{
						char ctemp1[6] = { '\0' };
						char ctemp2[6] = { '\0' };
						char ctemp3[6] = { '\0' };

						n_three = change(cNum[x]) * 100 + change(cNum[y]) * 10 + change(cNum[z]);
						n_two1 = change(cNum[w]);
						n_two2 = change(cNum[b]);

						itochar(n_three*n_two1, ctemp1);
						itochar(n_three*n_two2, ctemp2);
						if (nsize(ctemp1) != 3 || nsize(ctemp2) != 3)
							continue;
						if (!judge(cNum, ctemp1))
							continue;
						if (!judge(cNum, ctemp2))
							continue;

						itochar(n_three*(n_two1 * 10 + n_two2), ctemp3);
						if (nsize(ctemp3) != 4 || !judge(cNum, ctemp3))
							continue;

						i++;
					}
	cout << i << endl;
	return 0;
}
