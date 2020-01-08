#include <iostream>
using namespace std;
//bool ju(char Num[10001], int len)
//{
//	for (int i = 0; i < len / 2; i++)
//		if (Num[i] != Num[len - 1 - i])
//			return 1;
//	return 0;
//}
void Print(char Num[10001], int len)
{
	for (int i = 0; i < len; i++)
		cout << Num[i];
	cout << "\n";
}
int compare(char Num[10001], const int len)
{
	//jishu
	int i = len / 2, j = len / 2;
	while (len % 2 == 1 && j < len)
	{
		if (Num[i] > Num[j])
			return 0;
		if (Num[i] < Num[j])
			return 1;
		i--; j++;
	}

	//oushu
	i--;
	while (len % 2 == 0 && j < len)
	{
		if (Num[i] > Num[j])
			return 0;
		if (Num[i] < Num[j])
			return 1;
		i--; j++;
	}
}
void swapnum(char Num[10001], const int len)
{
	int i = len / 2, j = len / 2;
	while (len % 2 == 1 && j < len)//jishu
	{
		Num[j] = Num[i];
		i--; j++;
	}

	i--;
	while (len % 2 == 0 && j < len)
	{
		Num[j] = Num[i];
		i--; j++;
	}
}
int num9(char Num[10001], int len)
{
	int i = len / 2, j = len / 2;
	int ii = len / 2 - 1;
	while (len % 2 == 1 && j < len && Num[i] == '9')//jishu
	{
		Num[i] = '0';
		i--; j++;
	}

	while (len % 2 == 0 && j < len && Num[ii] == '9')//oushu
	{
		Num[ii] = '0';
		ii--; j++;
	}

	if (Num[0] == '0')
		return 0;
	else
	{
		if (len % 2 == 1)Num[i]++;
		else Num[ii]++;
		swapnum(Num, len);
	}
	return 1;
}
int main()
{
	char Num[10001] = { '\0' };
	while (cin >> Num)
	{
		int len = 0;
		for (int i = 0; Num[i] != '\0'; i++)
			len++;
		if (!compare(Num, len))
		{
			swapnum(Num, len);
			Print(Num, len);
		}
		else if (!num9(Num, len))
		{
			cout << 1;
			for (int i = 0; i < len - 1; i++)
				cout << 0;
			cout << 1 << endl;
		}
		else
			Print(Num, len);
	}
	return 0;
}
