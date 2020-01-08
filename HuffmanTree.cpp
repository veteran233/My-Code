#include <iostream>
using namespace std;

const int len = 5;

struct Tree
{
	Tree *LC = NULL, *RC = NULL, *PR = NULL;
	int weight = -1;
};
void Select(Tree T[], int &f, int &s)
{
	for (int i = 0; i < 2 * len - 1; i++)		//initialize
		if (T[i].PR == NULL && T[i].weight != -1)
			f = i, s = i;

	for (int i = 0; i < 2 * len - 1; i++)		//search first
		if (T[i].PR == NULL && T[i].weight != -1 && T[i].weight < T[f].weight)
			f = i;

	if (f == s)
		s++;
	for (int i = 0; i < 2 * len - 1; i++)		//search second
		if (T[i].PR == NULL && T[i].weight != -1 && T[i].weight != T[f].weight && T[i].weight < T[s].weight)
			s = i;
}
void CreateHuffmanTree(Tree T[], int w[])
{
	for (int i = 0; i < len; i++)	//initialize weight
		T[i].weight = w[i];
	int f, s;
	for (int i = len; i < 2 * len - 1; i++)
	{
		Select(T, f, s);
		T[i].LC = &T[f];
		T[i].RC = &T[s];

		T[f].PR = &T[i];
		T[s].PR = &T[i];

		T[i].weight = T[f].weight + T[s].weight;
	}
}
int PreOrder(Tree *p)
{
	if (p == NULL) return 0;
	else
	{
		cout << p->weight << " ";
		PreOrder(p->LC);
		PreOrder(p->RC);
	}
	return 0;
}
int main()
{
	int w[len] = { 2,3,4,5,6 };
	Tree T[2 * len - 1];
	CreateHuffmanTree(T, w);
	Tree *p = NULL;
	for (int i = 0; i < 2 * len - 1; i++)
		if (T[i].PR == NULL)
			p = &T[i];
	PreOrder(p);
	return 0;
}
