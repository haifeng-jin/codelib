#define MAX_X 0
#define MAX_Y MAX_X

int matrix[MAX_X][MAX_Y];
bool vis[MAX_X];
int match[MAX_X];
int x_num, y_num;

bool find_match(int a)
{
	for (int i = 0; i < y_num; i++)
		if (matrix[a][i] &&!vis[i])
		{
			vis[i] = true;
			if (match[i] == -1|| find_match(match[i]))
			{
				match[i] = a;
				return true;
			}
		}
	return false;
}

int max_match()
{
	memset(match, -1, sizeof(match));
	for (int i = 0; i < x_num; i++)
	{
		memset(vis, 0, sizeof(vis));
		find_match(i);
	}
	int ans = 0;
	for (int i = 0; i < x_num; i++)
		if (match[i] != -1)
			ans++;
	return ans;
}

void init_match(int x, int y)
{
	x_num = x;
	y_num = y;
}
