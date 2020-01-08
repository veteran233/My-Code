/*
ID: kookinhard
PROG: barn1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	int M, S, C;
	cin >> M >> S >> C;

	vector<unsigned short> Cow(C);
	vector<unsigned short> Length;
	vector<short> Empty;

	for (int i = 0; i < C; i++)
		cin >> Cow[i];

	if (M >= C)
	{
		cout << C << endl;
		return 0;
	}

	for (int i = 0; i < Cow.size() - 1; i++)
		for (int j = 0; j < Cow.size() - 1 - i; j++)
			if (Cow[j] > Cow[j + 1])
			{
				short temp = Cow[j];
				Cow[j] = Cow[j + 1];
				Cow[j + 1] = temp;
			}

	int index = 0;
	while (index < C)
	{
		const unsigned short start = Cow[index];
		unsigned short i = Cow[index];

		while (index < C && Cow[index] == i)
		{
			i++;
			index++;
		}

		Length.push_back(i - start);
		if (index < C)
			Empty.push_back(Cow[index] - i);
	}

	if (Length.size() == 0)
	{
		cout << C << endl;
		return 0;
	}

	for (int i = 0; i < Empty.size() - 1; i++)
		for (int j = 0; j < Empty.size() - 1 - i; j++)
			if (Empty[j] > Empty[j + 1])
			{
				short temp = Empty[j];
				Empty[j] = Empty[j + 1];
				Empty[j + 1] = temp;
			}

	int sum = 0;
	for (int i = 0; i < Length.size(); i++)
		sum += Length[i];

	for (int i = 0; i < Length.size() - M; i++)
		sum += Empty[i];
	cout << sum << endl;
	return 0;
}
