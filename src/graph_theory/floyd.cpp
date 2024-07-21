int dist[MAX_NODE_NUM][MAX_NODE_NUM];
int node_num;

void init()
{
	memset(dist, -1, sizeof(dist));
}

void floyd()
{
	for (int i = 0; i < node_num; i++)
	{
		for (int j = 0; j < node_num; j++)
		{
			if (dist[j][i] == -1)
				continue;
			for (int k = 0; k < node_num; k++)
			{
				if (dist[i][k] == -1)
					continue;
				if (dist[j][k] == -1 || dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
}
