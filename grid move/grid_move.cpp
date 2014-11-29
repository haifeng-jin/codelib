struct Point
{
	int x, y;
	Point()
	{}
	Point(int x, int y):x(x), y(y)
	{}
	Point operator + (const Point &a)
	{
		return Point(x + a.x, y + a.y);
	}
};

Point dir[4] = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
bool vis[MAX_X][MAX_Y];
int row_num, col_num;
char dir_name[] = "DRUL";
int grid[MAX_X][MAX_Y];

void visit(Point a)
{
	vis[a.x][a.y] = true;
}

bool out(Point a)
{
	return a.x < 0 || a.y < 0 || a.x >= row_num || a.y >= col_num;
}

bool visited(Point a)
{
	return vis[a.x][a.y];
}
