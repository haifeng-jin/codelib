#define MAX_NODE_NUM 105
#define INF 0x3f3f3f3f

struct Edge
{
    int v;
    int length;
    Edge()
    {}
    Edge(int v, int length):v(v), length(length)
    {}
};

int dist[MAX_NODE_NUM];
int node_num, road_num;
bool vis[MAX_NODE_NUM];
int push_cnt[MAX_NODE_NUM];
vector<vector<Edge> > G;
bool in_queue[MAX_NODE_NUM];

void addedge(vector<vector<Edge> > &G, int u, int v, int length)
{
    G[u].push_back(Edge(v, length));
}

void iterate()
{
    for (int i = 0; i < node_num; i++)
    {
        for (vector<Edge>::iterator j = G[i].begin(); j != G[i].end(); j++)
 	{}
    }
}

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
    memset(push_cnt, 0, sizeof(push_cnt));
    memset(in_queue, 0, sizeof(in_queue));
    queue<int> q;
    q.push(origin);
    in_queue[origin] = true;
    dist[origin] = 0;
    bool unbound = false;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
	in_queue[temp] = false;
        for (vector<Edge>::iterator i = G[temp].begin(); i != G[temp].end(); i++)
        {
            if (relax(dist[i->v], dist[temp] + i->length) && !in_queue[i->v]) 
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

