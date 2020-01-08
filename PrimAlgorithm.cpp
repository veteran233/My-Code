#include <iostream>
using namespace std;

template<typename Type>class Tree
{
public:
	Type data;
	short parent;
};

const unsigned short nodenum = 6;
unsigned short arcweight[nodenum][nodenum];
bool visited[nodenum];

void SetArcWeight(const unsigned short weight, const unsigned short index_x, const unsigned short index_y)
{
	arcweight[index_x][index_y] = weight;
	arcweight[index_y][index_x] = weight;
}
template<typename Type>int MST(Tree<Type> Node[], unsigned short index, unsigned short top = 0)
{
	if (top >= nodenum - 1)
		return 0;
	unsigned short min = 65535;
	unsigned short parent;
	visited[index] = 1;
	for (unsigned short i = 0; i < nodenum; i++)
		if (visited[i])
			for (unsigned short j = 0; j < nodenum; j++)
				if (!visited[j] && arcweight[i][j] < min)
				{
					min = arcweight[i][j];
					index = j;
					parent = i;
				}
	Node[index].parent = parent;
	MST(Node, index, ++top);
}
int main()
{
	typedef int Type;
	Tree<Type> Node[nodenum];

	for (unsigned short i = 0; i < nodenum; i++)
		for (unsigned short j = 0; j < nodenum; j++)
			arcweight[i][j] = 65535;

	for (unsigned short i = 0; i < nodenum; i++)
		Node[i].data = rand() / 100;

	SetArcWeight(34, 0, 1);
	SetArcWeight(12, 1, 4);
	SetArcWeight(38, 4, 3);
	SetArcWeight(17, 3, 2);
	SetArcWeight(46, 2, 0);
	SetArcWeight(19, 0, 5);
	SetArcWeight(26, 4, 5);
	SetArcWeight(25, 3, 5);
	SetArcWeight(25, 2, 5);

	Node[0].parent = -1;
	MST(Node, 0);

	cout << "index\tdata\tparent" << endl;
	for (unsigned short i = 0; i < nodenum; i++)
		cout << i << "\t" << Node[i].data << "\t" << Node[i].parent << endl;

	unsigned short cost = 0;
	for (unsigned short i = 0; i < nodenum; i++)
	{
		if (Node[i].parent == -1)
			continue;
		cost += arcweight[i][Node[i].parent];
	}
	cout << "cost: " << cost << endl;
	return 0;
}
