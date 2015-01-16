struct Point
{
	int x, y;
	int time;
	Point()
	{}
	Point(int x, int y):x(x), y(y)
	{}
	Point(int x, int y, int t): x(x), y(y), time(t)
	{}
	Point operator + (const Point &a)
	{
		return Point(x + a.x, y + a.y);
	}
	bool operator < (const Point &a) const
	{
		return time > a.time;
	}
	bool operator == (const Point &a) const
	{
		return x == a.x && y == a.y;
	}
};

Point dir[4] = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
bool vis[MAX_X][MAX_Y];
int dis[MAX_X][MAX_Y];
int row_num, col_num;
char dir_name[] = "DRUL";
char dir_name2[] = "SENW";
char grid[MAX_X][MAX_Y];
Point start, end;

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

void input()
{
	scanf("%d", &row_num);
	col_num = row_num;
	for (int i = 0; i < row_num; i++)
	{
		scanf("%s", grid[i]);
	}
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			if (grid[i][j] == 'M')
			{
				start = Point(i, j);
				grid[i][j] = '.';
			}
			if (grid[i][j] == 'T')
			{
				end = Point(i, j);
				grid[i][j] = '.';
			}
		}
	}
}

void init()
{
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			vis[i][j] = false;
			dis[i][j] = INF;
		}
	}
}

int bfs()
{
	init();
	priority_queue<Point> pq;
	start.time = 0;
	pq.push(start);
	while (!pq.empty())
	{
		Point u = pq.top();
		pq.pop();
		if (u == end)
		{
			return u.time;
		}
		if (visited(u))
		{
			continue;
		}
		visit(u);
		for (int i = 0; i < 4; i++)
		{
			Point v = u + dir[i];
			if (out(v) || grid[v.x][v.y] != '.')
			{
				continue;
			}
			if (u.time + 1 < dis[v.x][v.y])
			{
				dis[v.x][v.y] = u.time + 1;
				pq.push(Point(v.x, v.y, u.time + 1));
			}
		}
	}
	return -1;
}

