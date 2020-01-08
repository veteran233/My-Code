#include <iostream>
using namespace std;
int QSort(int a[], const int first, const int end)
{
	int i = first;
	int j = end;

	while (i < j)
	{
		while (a[j] > a[first] && i < j)
			j--;
		while (a[i] < a[first] && i < j)
			i++;
		swap(a[i], a[j]);
	}
	swap(a[first], a[i]);
	if (first < end)
	{
		QSort(a, first, i - 1);
		QSort(a, j + 1, end);
	}
	return 0;
}
int main()
{
	int a[8];
	for (int i = 0; i < 8; i++)
	{
		a[i] = rand();
		cout << a[i] << "\t";
	}

	cout << "\n";

	QSort(a, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << a[i] << "\t";

	return 0;
}
