#define MAX_INTERVAL 100001

struct Node
{
	int        l, r;
	long long nsum, inc;
	Node    *pleft, *pright;
};

int	node_cnt;
Node    tree[MAX_INTERVAL * 3];

void buildtree(Node *proot, int s, int e)
{
	proot->l = s;
	proot->r = e;
	proot->inc = 0;
	proot->nsum = 0;
	if (s == e)
	{
		proot->pleft = proot->pright = NULL;
		return;
	}
	node_cnt++;
	proot->pleft = tree + node_cnt;
	node_cnt++;
	proot->pright = tree + node_cnt;
	buildtree(proot->pleft, s, (s + e) / 2);
	buildtree(proot->pright, (s + e) / 2 + 1, e);
}

void insert(Node *proot, int s, int e, long long increase)
{
	if (s > proot->r || e < proot->l)
		return;
	s = max(s, proot->l);
	e = min(e, proot->r);
	if (s == proot->l && e == proot->r)
	{
		proot->inc += increase;
		return;
	}
	proot->nsum += (e - s + 1) * increase;
	insert(proot->pleft, s, e, increase);
	insert(proot->pright, s, e, increase);
}

long long query(Node *proot, int s, int e)
{
	if (s > proot->r || e < proot->l)
		return 0;
	s = max(s, proot->l);
	e = min(e, proot->r);
	if (proot->l == s && proot->r == e)
		return proot->nsum + proot->inc * (proot->r - proot->l + 1);
	long long inc_value = proot->inc * (e - s + 1);
	return query(proot->pleft, s, e) + query(proot->pright, s, e) + inc_value;
}


