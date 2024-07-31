#define MAX_NODE_NUM 105
#define INF 0x3f3f3f3f

int node_num, edge_num;
long long dist[MAX_NODE_NUM];
vector<pair<int, int> > edge[MAX_NODE_NUM];
int push_cnt[MAX_NODE_NUM];
bool in_queue[MAX_NODE_NUM];

bool relax(int &dist, int length)
{
	if (dist > length)
	{
		dist = length;
		return true;
	}
	return false;
}

int SPFA(int origin, int destination)
{
	fill(dist, dist + node_num, INF);
	fill(push_cnt, push_cnt + node_num, 0);
	fill(in_queue, in_queue + node_num, 0);
	queue<int> q;
	q.push(origin);
	in_queue[origin] = true;
	dist[origin] = 0;
	bool unbound = false;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_queue[u] = false;
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i].first;
			int w = edge[u][i].second;
			if (relax(dist[v], dist[u] + w) && !in_queue[v]) 
			{
				q.push(i->v);
				in_queue[i->v] = true;
				push_cnt[i->v]++;
				if (push_cnt[i->v] > node_num)
				{
					return -1;		//negative ring;
				}
			}
		}
	}
	return dist[destination];
}

