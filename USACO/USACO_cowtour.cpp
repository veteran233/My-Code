/*
ID: kookinhard
PROG: cowtour
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class point
{
public:
	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double x;
	double y;
	bool visited = 0;
	int area;
};

const double inf = 150000;
int N;
double ans = inf;
vector<point> poi;
vector<vector<double>> dist;
vector<double> pointdiam;

double pdist(point &a, point &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
void dfs(int index, const int area)
{
	poi[index].visited = 1;
	poi[index].area = area;
	for (int i = 0; i < N; i++)
		if (!poi[i].visited && dist[index][i] != inf)
			dfs(i, area);
}

int main()
{
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		poi.push_back(point(x, y));
	}
	for (int i = 0; i < N; i++)
	{
		dist.push_back(vector<double>());
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				dist[i].push_back(0);
				continue;
			}
			if (str[j] == '0')
				dist[i].push_back(inf);
			else
				dist[i].push_back(pdist(poi[i], poi[j]));
		}
	}

	//divide area
	int area = 0;
	for (int i = 0; i < N; i++)
		if (!poi[i].visited)
		{
			dfs(i, area);
			area++;
		}

	//floyd-warshall
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	//point diameter
	for (int i = 0; i < N; i++)
	{
		pointdiam.push_back(0);
		for (int j = 0; j < N; j++)
			if (pointdiam[i] < dist[i][j] && dist[i][j] != inf)
				pointdiam[i] = dist[i][j];
	}

	//area diameter
	vector<double> areadiam(area, 0);
	for (int i = 0; i < N; i++)
		if (areadiam[poi[i].area] < pointdiam[i])
			areadiam[poi[i].area] = pointdiam[i];

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (poi[i].area == poi[j].area)
				continue;
			double m = pdist(poi[i], poi[j]) + pointdiam[i] + pointdiam[j];
			double d = max(max(m, areadiam[poi[i].area]), areadiam[poi[j].area]);
			ans = min(ans, d);
		}

	cout << setiosflags(ios::fixed) << setprecision(6) << ans << endl;

	return 0;
}
