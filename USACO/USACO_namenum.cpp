/*
ID: kookinhard
PROG: namenum
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
const char AlphaBet[25] = "ABCDEFGHIJKLMNOPRSTUVWXY";
const unsigned short NumAB[24] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9 };
template<typename Type>void exchange(Type&&a, Type&&b)
{
	Type temp = a;
	a = b;
	b = temp;
}
unsigned short Transform(char Alpha)
{
	for (int i = 0; AlphaBet[i] != '\0'; i++)
		if (Alpha == AlphaBet[i])
			return NumAB[i];
	return 0;
}
int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	long long user;
	cin >> user;
	ifstream file("dict.txt");
	string read_file;
	vector<long long> Num(5000, 0);
	char A[5000][13] = { '\0' };
	unsigned short j = 0;
	while (getline(file, read_file))
	{
		for (unsigned short i = 0; read_file[i] != '\0'; i++)
		{
			int len = read_file.length();
			A[j][i] = read_file[i];
			Num[j] += pow(10, len - 1 - i)*Transform(read_file[i]);
		}
		j++;
	}
	bool sign = 0;
	for (unsigned short i = 0; i < j; i++)
	{
		if (user == Num[i])
		{
			sign = 1;
			for (int tt = 0; A[i][tt] != '\0'; tt++)
				cout << A[i][tt];
			cout << "\n";
		}
	}
	if (!sign)
		cout << "NONE" << endl;
	return 0;
}
