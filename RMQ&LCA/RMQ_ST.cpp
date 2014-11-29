//call init_RMQ(f[], n) first.
//then call query(a, b) to quest the RMQ of [a, b].
int power[30];
int st[MAX_NODE_NUM * 2][32];
int ln[MAX_NODE_NUM * 2];

//returns the index of the first minimum value in [x, y]
void init_RMQ(int f[], int n)
{
	int i, j;
	for (power[0] = 1, i = 1; i < 21; i++)
	{
		power[i] = 2 * power[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		st[i][0] = i;
	}
	ln[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		ln[i] = ln[i >> 1] + 1;
	}
	for (j = 1; j < ln[n]; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (i + power[j - 1] - 1 >= n)
			{
				break;
			}
			//for maximum, change ">" to "<"
			//for the last, change "<" or ">" to "<=" or ">="
			if (f[st[i][j - 1]] > f[st[i + power[j - 1]][j - 1]])
			{
				st[i][j] = st[i + power[j - 1]][j - 1];
			}
			else
			{
				st[i][j] = st[i][j - 1];
			}
		}
	}
}

int query(int x, int y)
{
	if(x > y)
	{
		swap(x, y);
	}
	int k = ln[y - x + 1];
	//for maximum, change ">" to "<"
	//for the last, change "<" or ">" to "<=" or ">="
	if (depth[st[x][k]] > depth[st[y - power[k] + 1][k]])
		return st[y - power[k] + 1][k];
	return st[x][k];
}
