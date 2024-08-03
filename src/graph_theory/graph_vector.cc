#include "common_header.h"
#define MAX_NODE_NUM 16

int node_num, edge_num;
long long dist[MAX_NODE_NUM];
vector<pair<int, int> > edge(MAX_NODE_NUM);

// edge[u].push_back(make_pair(v, w));
