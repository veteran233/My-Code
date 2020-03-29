/*
ID: kookinhard
PROG: shopping
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class cla_offer
{
public:
	vector<int> num;
	cla_offer()
	{
		num.resize(5, 0);
	}
	void setoffer(int c, int n)
	{
		num[c] = n;
	}
	int price;
};
class cla_item
{
public:
	int code = 0x3f3f3f3f;
	int num = 0;
	int price = 0;
	bool operator<(cla_item&t)
	{
		return this->code < t.code;
	}
};

int inf = 0x3f3f3f3f;
vector<cla_offer> offer;
vector<cla_item> item(5);
int dp[6][6][6][6][6];
vector<int> codetransform(1000, -1);

inline bool isminus(int a, int b, int c, int d, int e, int index)
{
	return (a - offer[index].num[0] >= 0) &&
		(b - offer[index].num[1] >= 0) &&
		(c - offer[index].num[2] >= 0) &&
		(d - offer[index].num[3] >= 0) &&
		(e - offer[index].num[4] >= 0);
}

int main()
{
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);

	int user_in;

	cin >> user_in;

	offer.resize(user_in);

	int temp = 0;
	for (int i = 0; i < user_in; ++i)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; ++j)
		{
			int code, num;
			cin >> code >> num;
			if (codetransform[code] == -1)
				codetransform[code] = temp++;
			offer[i].setoffer(codetransform[code], num);
		}
		cin >> offer[i].price;
	}

	cin >> user_in;

	for (int i = 0; i < user_in; ++i)
	{
		cin >> item[i].code >> item[i].num >> item[i].price;
		item[i].code = codetransform[item[i].code];
	}
	sort(item.begin(), item.end());

	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			for (int k = 0; k < 6; ++k)
				for (int l = 0; l < 6; ++l)
					for (int m = 0; m < 6; ++m)
						dp[i][j][k][l][m] = item[0].price*i + item[1].price*j + item[2].price*k + item[3].price*l + item[4].price*m;

	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			for (int k = 0; k < 6; ++k)
				for (int l = 0; l < 6; ++l)
					for (int m = 0; m < 6; ++m)
						for (int n = 0; n < (int)offer.size(); ++n)
							if (isminus(m, l, k, j, i, n))
								dp[m][l][k][j][i] = min(dp[m][l][k][j][i],
									dp[m - offer[n].num[0]][l - offer[n].num[1]][k - offer[n].num[2]][j - offer[n].num[3]][i - offer[n].num[4]] + offer[n].price);

	cout << dp[item[0].num][item[1].num][item[2].num][item[3].num][item[4].num] << endl;

	return 0;
}
