/*
ID: kookinhard
PROG: transform
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void Spin90(char Array[10][10], int N)
{
	char TempArray[10][10];

	//copy
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			TempArray[i][j] = Array[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Array[j][N - i - 1] = TempArray[i][j];
}
void Reflect(char Array[10][10], int N)
{
	char TempArray[10][10];

	//copy
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			TempArray[i][j] = Array[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Array[i][N - j - 1] = TempArray[i][j];
}
int Pattern(char a[10][10], char b[10][10], int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j] != b[i][j])
				return 1;
	return 0;
}
int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	char Array[10][10];
	char Temp[10][10];
	char Temp2[10][10];
	char after_Array[10][10];
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> Array[i][j];
			Temp[i][j] = Array[i][j];
			Temp2[i][j] = Array[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> after_Array[i][j];

	Spin90(Array, N);
	if (!Pattern(Array, after_Array, N))
	{
		cout << 1 << endl;
		return 0;
	}

	Spin90(Array, N);
	if (!Pattern(Array, after_Array, N))
	{
		cout << 2 << endl;
		return 0;
	}

	Spin90(Array, N);
	if (!Pattern(Array, after_Array, N))
	{
		cout << 3 << endl;
		return 0;
	}

	Reflect(Temp, N);
	if (!Pattern(Temp, after_Array, N))
	{
		cout << 4 << endl;
		return 0;
	}

	Spin90(Temp, N);
	if (!Pattern(Temp, after_Array, N))
	{
		cout << 5 << endl;
		return 0;
	}

	Spin90(Temp, N);
	if (!Pattern(Temp, after_Array, N))
	{
		cout << 5 << endl;
		return 0;
	}

	Spin90(Temp, N);
	if (!Pattern(Temp, after_Array, N))
	{
		cout << 5 << endl;
		return 0;
	}

	if (!Pattern(Temp2, after_Array, N))
		cout << 6 << endl;
	else
		cout << 7 << endl;
	return 0;
}
