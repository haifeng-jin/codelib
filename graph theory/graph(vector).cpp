struct Edge
{
    int v;
    int length;
    Edge()
    {}
    Edge(int v, int length):v(v), length(length)
    {}
};

vector<vector<Edge> > G;

void add_edge(vector<vector<Edge> > &G, int u, int v, int length)
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
