#include <iostream>
#include <algorithm>

using namespace std;

class point
{
public:
	point(double a, double b);
	point();
	double x;
	double y;
};
point::point(double a, double b)
{
	x = a;
	y = b;
}
point::point() {}

point Vector(const point &p1, const point &p2)
{
	return point(p1.x - p2.x, p1.y - p2.y);
}
double Array(const point v1, const point v2)
{
	return v1.x * v2.y - v2.x * v1.y;
}
bool IsRectSeparate(const point &p1, const point &p2, const point &p3, const point &p4)
{
	return (
		max(p1.x, p2.x) < min(p3.x, p4.x) ||
		max(p3.x, p4.x) < min(p1.x, p2.x) ||
		max(p1.y, p2.y) < min(p3.y, p4.y) ||
		max(p3.y, p4.y) < min(p1.y, p2.y)
		);
}
bool IsLineSegmentSeparate(const point &p1, const point &p2, const point &p3, const point &p4)
{
	if (IsRectSeparate(p1, p2, p3, p4))
		return 1;

	if (
		Array(Vector(p1, p2), Vector(p1, p3))*Array(Vector(p1, p2), Vector(p1, p4)) > 0 ||
		Array(Vector(p3, p4), Vector(p3, p1))*Array(Vector(p3, p4), Vector(p3, p2)) > 0
		)
		return 1;
	else
		return 0;
}
int main()
{
	return 0;
}
