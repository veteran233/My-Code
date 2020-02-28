/*
ID: kookinhard
PROG: humble
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int K, N;

int main()
{
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);

	cin >> K >> N;

	vector<int> prime(K);
	set<int> si;

	for (int i = 0; i < K; ++i)
	{
		cin >> prime[i];
		si.insert(prime[i]);
	}

	for (int i = 0; i != K; ++i)
	{
		set<int>::iterator it = si.begin();
		while (1)
		{
			int t = (*it)*prime[i];
			if (t < 0)
				break;
			if (si.size() > N)
			{
				si.erase(--si.end());
				if (t > *(--si.end()))
					break;
			}
			si.insert(t);
			++it;
		}
	}

	cout << *(--si.end()) << endl;

	return 0;
}
