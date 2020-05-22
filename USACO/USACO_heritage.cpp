/*
ID: kookinhard
PROG: heritage
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class point
{
public:
	point* left = NULL;
	point* right = NULL;
	char code;
};

string inorder, preorder;
vector<point> ans(30);
int level = 1;
int index = -1;

int tree(int a, int b, int pivot)
{
	index = -1;
	for (int i = a; i < pivot; ++i)
		if (preorder[level] == inorder[i])
		{
			index = i;
			++level;
			break;
		}
	if (index != -1)
	{
		ans[pivot].left = &ans[index];
		ans[index].code = inorder[index];
		tree(a, pivot, index);
	}

	index = -1;
	for (int i = pivot + 1; i < b; ++i)
		if (preorder[level] == inorder[i])
		{
			index = i;
			++level;
			break;
		}
	if (index != -1)
	{
		ans[pivot].right = &ans[index];
		ans[index].code = inorder[index];
		tree(pivot + 1, b, index);
	}
	return 0;
}
int postorder(const point *t)
{
	if (t == NULL)
		return 0;
	else
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->code;
	}
	return 0;
}

int main()
{
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);

	cin >> inorder >> preorder;

	int pivot;
	for (int i = 0; i < (int)inorder.size(); ++i)
		if (inorder[i] == preorder[0])
		{
			pivot = i;
			ans[pivot].code = inorder[pivot];
			break;
		}

	tree(0, (int)inorder.size(), pivot);
	postorder(&ans[pivot]);
	cout << "\n";

	return 0;
}
