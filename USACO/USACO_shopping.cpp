/*
ID: kookinhard
PROG: shopping
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class cla_offer
{
public:
	vector<int> code;
	vector<int> num;
	void setoffer(int c, int n)
	{
		code.push_back(c);
		num.push_back(n);
	}
	int price;
};
class cla_item
{
public:
	int code;
	int num;
	int price;
};

vector<cla_offer> offer;
vector<cla_item> item;

int main()
{
	/*freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);*/

	int user_in;

	cin >> user_in;

	offer.resize(user_in);

	for (int i = 0; i < user_in; ++i)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; ++j)
		{
			int code, num;
			cin >> code >> num;
			offer[i].setoffer(code, num);
		}
		cin >> offer[i].price;
	}

	cin >> user_in;

	item.resize(user_in);

	for (int i = 0; i < user_in; ++i)
		cin >> item[i].code >> item[i].num >> item[i].price;

	return 0;
}
