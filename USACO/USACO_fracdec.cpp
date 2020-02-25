/*
ID: kookinhard
PROG: fracdec
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>

using namespace std;

vector<int> num;
vector<bool> exist(100001, 0);
vector<int> nex(100001);
int a;

int ncha(int x)
{
	if (x == 0)
		return 1;
	int ret = 0;
	while (x != 0)
	{
		x /= 10;
		ret++;
	}
	return ret;
}
bool Div(int N, int D)
{
	for (int i = 0;; i++)
	{
		if (exist[N%D])
		{
			a = nex[N%D];
			break;
		}
		if (N%D != 0)
		{
			num.push_back(N%D);
			exist[N%D] = 1;
			nex[N%D] = i;
		}
		else
			return 0;
		N = N % D * 10;
	}
	return 1;
}
int main()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	int N, D;
	fin >> N >> D;

	bool sign = Div(N, D);
	int n = ncha(N / D) + 1;

	fout << N / D << ".";

	for (int i = 0;; i++)
	{
		if (i == a && sign)
		{
			fout << "(";
			n++;
			if (n % 76 == 0)
				fout << "\n";
		}
		if (sign && i >= num.size())
			break;

		N = N % D * 10;
		fout << N / D;
		n++;
		if (n % 76 == 0)
			fout << "\n";

		if (N == 0 || i >= num.size() - 1)
			break;
	}

	if (sign)
		fout << ")" << endl;
	else
		fout << "\n";

	return 0;
}
