#include <iostream>
using namespace std;

unsigned short visited_arcnode = 0;
const unsigned short nodenum = 6;
const unsigned short arcnum = 9;
const unsigned short deg = 2 * arcnum;
bool visited[nodenum];

class ArcNode
{
public:
	unsigned short index;
	ArcNode *Next = NULL;
};
template <typename VertexType>class VertexNode
{
public:
	VertexType data;
	ArcNode *Arc;
};
template <typename Type>void SetArcIndex
(
	VertexNode<Type> &Node,
	ArcNode arcNode[],
	unsigned short index[],
	unsigned short len
)
{
	Node.Arc = &arcNode[visited_arcnode];
	for (unsigned short i = visited_arcnode; visited_arcnode < i + len;)
	{
		arcNode[visited_arcnode].index = index[visited_arcnode - i];
		if (++visited_arcnode < i + len)
			arcNode[visited_arcnode - 1].Next = &arcNode[visited_arcnode];
	}
}
template <typename Type>void SetNodeData(VertexNode<Type> Node[], Type data[])
{
	for (unsigned short i = 0; i < nodenum; i++)
		Node[i].data = data[i];
}
template <typename Type>void DFS(VertexNode<Type> Node[], VertexNode<Type> *head, unsigned short head_index)
{
	cout << head->data << "\t";
	visited[head_index] = 1;
	ArcNode *near = head->Arc;
	while (near != NULL)
	{
		if (!visited[near->index])
			DFS(Node, &Node[near->index], near->index);
		near = near->Next;
	}
}
int main()
{
	typedef int Type;
	VertexNode<Type> VNode[nodenum];
	ArcNode ANode[deg];

	cout << "index\t";
	for (int i = 0; i < nodenum; i++)
	{
		cout << i << "\t";
		VNode[i].data = rand() / 100;
	}
	cout << "\ndata\t";
	for (int i = 0; i < nodenum; i++)
		cout << VNode[i].data << "\t";

	unsigned short a0[] = { 1,2,5 };
	unsigned short a1[] = { 0,4 };
	unsigned short a2[] = { 0,3,5 };
	unsigned short a3[] = { 2,4,5 };
	unsigned short a4[] = { 1,3,5 };
	unsigned short a5[] = { 0,2,3,4 };

	SetArcIndex(VNode[0], ANode, a0, 3);
	SetArcIndex(VNode[1], ANode, a1, 2);
	SetArcIndex(VNode[2], ANode, a2, 3);
	SetArcIndex(VNode[3], ANode, a3, 3);
	SetArcIndex(VNode[4], ANode, a4, 3);
	SetArcIndex(VNode[5], ANode, a5, 4);

	cout << "\n\n";
	DFS(VNode, &VNode[0], 0);

	return 0;
}
