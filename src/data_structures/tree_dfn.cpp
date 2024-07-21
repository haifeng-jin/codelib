int dfn[MAX_N], dfn2[MAX_N];
int time_count;

void dfs(int u, int father)
{
	dfn[u] = time_count++;
	for (int i = 0; i < (signed)edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != father)
			dfs(v, u);
	}
	dfn2[u] = time_count;	//can be deleted, if dfn2 is not necessary.
}

