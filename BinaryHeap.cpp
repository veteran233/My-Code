#include <iostream>
#include <vector>
using namespace std;
void exchange(int&a, int&b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
template<typename Type>int Order(Type iArray[], const unsigned short p, const unsigned&len)
{
	if (p <= len - 1)
	{
		Order(iArray, 2 * p + 1, len);
		Order(iArray, 2 * p + 2, len);
		cout << iArray[p] << " ";
	}
	return 0;
}
template<typename Type>int DeleteMin(Type iArray[], unsigned&len)
{
	unsigned short p = 0;
	iArray[p] = 65535;
	exchange(iArray[len - 1], iArray[p]);

	while (2 * p + 2 <= len - 1)
	{
		if (iArray[p] > iArray[2 * p + 1] || iArray[p] > iArray[2 * p + 2])
			if (iArray[2 * p + 1] > iArray[2 * p + 2])
			{
				exchange(iArray[2 * p + 2], iArray[p]);
				p = 2 * p + 2;
			}
			else
			{
				exchange(iArray[2 * p + 1], iArray[p]);
				p = 2 * p + 1;
			}
		else
			break;
	}
	if (2 * p + 1 <= len - 1)
		if (iArray[p] > iArray[2 * p + 1])
			exchange(iArray[2 * p + 1], iArray[p]);
	len--;
	return 0;
}
int main()
{
	typedef int Type;
	Type iArray[4] = { 1,1,1,1 };
	unsigned len = sizeof(iArray) / sizeof(iArray[0]);

	Order(iArray, 0, len);
	DeleteMin(iArray, len);
	cout << "\n";
	Order(iArray, 0, len);

	return 0;
}
