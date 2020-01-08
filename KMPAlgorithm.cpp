#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> GetNext(char T[])
{
	vector<int> next(strlen(T), 0);
	int i = 0, j = 1;
	int p = 0;
	while (T[j] != '\0')
	{
		if (T[i] == T[j])
		{
			next[j] = ++p;
			j++;
			i++;
		}
		else
		{
			p = 0;
			i = 0;
			j++;
		}
	}
	for (int i = strlen(T) - 1; i > 0; i--)
		next[i] = next[i - 1];
	next[0] = -1;

	return next;
}
int KMP(char T[], char S[])
{
	vector<int> Next = GetNext(T);
	int i = 0, j = 0;
	while (S[i] != '\0')
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Next[j];
			if (j == -1)
			{
				j = 0;
				i++;
			}
		}
		if (T[j] == '\0') return (i - j + 1);
	}
	return 0;
}
int main()
{
	char T[6] = "ababc";
	char S[18] = "bcacbbabccacababc";

	cout << "matching complete: " << KMP(T, S) << endl;

	return 0;
}
