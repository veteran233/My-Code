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
		num.resize(5, -1);
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
	int code;
	int num;
	int price;
	bool operator<(cla_item&t)
	{
		return this->code < t.code;
	}
};

int inf = 0x3f3f3f3f;
vector<cla_offer> offer;
vector<cla_item> item;
int dp[6][6][6][6][6];
vector<int> codetransform(1000, -1);

bool isminus(int index, int j)
{
	for (int i = 0; i < (int)offer[j].num.size(); ++i)
		if (index - offer[j].num[i] < 0)
			return 0;
	return 1;
}

int main()
{
	/*freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);*/

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

	item.resize(user_in);

	for (int i = 0; i < user_in; ++i)
	{
		cin >> item[i].code >> item[i].num >> item[i].price;
		item[i].code = codetransform[item[i].code];
	}
	sort(item.begin(), item.end());

	memset(dp, inf, sizeof(dp));
	dp[0][0][0][0][0] = 0;



	return 0;
}
