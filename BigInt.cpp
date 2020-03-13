#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class BigInt
{
public:
	void In()
	{
		/*char temp = getchar();
		while (temp != '\n')
		{
			this->n.push_back(temp);
			temp = getchar();
		}*/
		cin >> this->n;
	}
	void Print()const
	{
		for (int i = 0; i < this->n.size(); i++)
			printf("%c", this->n[i]);
		printf("\n");
	}

	inline BigInt operator + (const BigInt&a)
	{
		return add(this, a);
	}
	inline BigInt operator - (BigInt&a)
	{
		return sub(this, &a);
	}
	inline BigInt operator *(BigInt&a)
	{
		return mul(this, a);
	}

private:
	string n;
	BigInt add(BigInt *a, BigInt b)const
	{
		BigInt sum;
		BigInt ta;
		ta.n = a->n;

		reverse(a->n.begin(), a->n.end());
		reverse(b.n.begin(), b.n.end());

		int max = a->n.size() > b.n.size() ? a->n.size() : b.n.size();

		if (a->n.size() > b.n.size())
			for (int i = b.n.size(); i < a->n.size(); i++)
				b.n.push_back('0');
		else
			for (int i = a->n.size(); i < b.n.size(); i++)
				a->n.push_back('0');

		bool sign = 0;

		int i = 0;
		while (i < max)
		{
			if (!sign && a->n[i] + b.n[i] - '0' <= '9')
			{
				sum.n.push_back(a->n[i] + b.n[i] - '0');
				i++;
				continue;
			}
			if (sign && a->n[i] + b.n[i] + sum.n[i] - '0' - '0' <= '9')
			{
				sum.n[i] = a->n[i] + b.n[i] + sum.n[i] - '0' - '0';
				sign = !sign;
				i++;
				continue;
			}
			if (!sign && a->n[i] + b.n[i] - '0' > '9')
			{
				sum.n.push_back(a->n[i] + b.n[i] - '0' - 10);
				sum.n.push_back('1');
				sign = !sign;
				i++;
				continue;
			}
			if (sign && a->n[i] + b.n[i] + sum.n[i] - '0' - '0' > '9')
			{
				sum.n[i] = a->n[i] + b.n[i] + sum.n[i] - '0' - '0' - 10;
				sum.n.push_back('1');
				i++;
				continue;
			}
		}
		reverse(sum.n.begin(), sum.n.end());
		a->n = ta.n;
		return sum;
	}
	BigInt sub(BigInt *a, BigInt *b)const
	{
		BigInt sum;
		BigInt ta, tb;
		ta.n = a->n;
		tb.n = b->n;
		bool sign = 0;
		bool oper = 0;

		if (a->n == b->n)
		{
			sum.n.push_back('0');
			return sum;
		}

		reverse(a->n.begin(), a->n.end());
		reverse(b->n.begin(), b->n.end());

		if (b->n.size() > a->n.size())
		{
			BigInt *temp = a;
			a = b;
			b = temp;
			oper = 1;
		}
		else if (b->n.size() == a->n.size())
			for (int i = 0; i < a->n.size(); i++)
				if (b->n[i] > a->n[i])
				{
					BigInt *temp = a;
					a = b;
					b = temp;
					oper = 1;
					break;
				}

		for (int i = b->n.size(); i < a->n.size(); i++)
			b->n.push_back('0');

		int i = 0;
		while (i < a->n.size())
		{
			if (!sign && a->n[i] - b->n[i] >= 0)
			{
				sum.n.push_back(a->n[i] - b->n[i] + '0');
				i++;
				continue;
			}
			if (sign && a->n[i] - b->n[i] - 1 >= 0)
			{
				sum.n.push_back(a->n[i] - b->n[i] - 1 + '0');
				sign = !sign;
				i++;
				continue;
			}
			if (!sign && a->n[i] - b->n[i] < 0)
			{
				sum.n.push_back(a->n[i] - b->n[i] + 10 + '0');
				sign = !sign;
				i++;
				continue;
			}
			if (sign && a->n[i] - b->n[i] - 1 < 0)
			{
				sum.n.push_back(a->n[i] - b->n[i] - 1 + 10 + '0');
				i++;
				continue;
			}
		}
		if (oper)
		{
			sum.n.push_back('-');
			a->n = tb.n;
			b->n = ta.n;
		}
		else
		{
			a->n = ta.n;
			b->n = tb.n;
		}

		reverse(sum.n.begin(), sum.n.end());
		return sum;
	}
	BigInt mul(BigInt *a, BigInt b)
	{

	}
};
int main()
{
	BigInt a, b, c;
	while (1)
	{
		a.In();
		b.In();
		c = a - b;
		c.Print();
	}

	return 0;
}
