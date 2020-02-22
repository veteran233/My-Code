#include <iostream>

using namespace std;

const int inf = 0x3f3f3f3f;
const int max_vertex = 20;
int weight[max_vertex][max_vertex];
int dist[max_vertex];
bool visited[max_vertex];

void setweight(int a, int b, int w)
{
	weight[a][b] = w;
	weight[b][a] = w;
}
int searchmin()
{
	int i = 0;
	for (; visited[i]; i++);
	for (int j = i + 1; j < max_vertex; j++)
		if (!visited[j] && dist[i] > dist[j])
			i = j;
	return i;
}
int main()
{
	for (int i = 0; i < max_vertex; i++)
		for (int j = 0; j < max_vertex; j++)
			weight[i][j] = inf;
	for (int i = 0; i < max_vertex; i++)
		weight[i][i] = 0;
	setweight(0, 1, 1);
	setweight(0, 2, 3);
	setweight(2, 3, 5);
	setweight(1, 3, 3);
	setweight(2, 5, 2);
	setweight(3, 5, 2);
	setweight(5, 6, 8);
	setweight(2, 4, 6);
	setweight(4, 5, 9);

	for (int i = 0; i < max_vertex; i++)
	{
		dist[i] = inf;
		visited[i] = 0;
	}

	int source = 0;
	int numvisited = 0;
	dist[source] = 0;

	while (numvisited < max_vertex)
	{
		int i = searchmin();
		visited[i] = 1;
		for (int j = 0; j < max_vertex; j++)
			if (dist[j] > dist[i] + weight[i][j])
				dist[j] = dist[i] + weight[i][j];
		numvisited++;
	}

	//cout dist[n] : the minimum distance from source to index n

	return 0;
}
