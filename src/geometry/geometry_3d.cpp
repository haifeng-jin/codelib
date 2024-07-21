#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8
#define MAX_POINT_NUM 0

int double_cmp(double a)
{
	if (zero(a))
		return 0;
	return a > 0 ? 1 : -1;
}

struct Point
{
	double x, y, z;

	Point()
	{}

	Point(double x, double y, double z): x(x), y(y), z(z)
	{}

	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y, z - a.z);
	}

	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y, z + a.z);
	}

	bool operator == (const Point &a) const
	{
		return !double_cmp(x - a.x) && !double_cmp(y - a.y) && !double_cmp(z - a.z);
	}
};

double dot_product(Point a, Point b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double point_dist(Point a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z;
}
