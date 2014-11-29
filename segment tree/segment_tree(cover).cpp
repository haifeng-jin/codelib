#define MAX_INTERVAL 0

struct Node
{
	int l, r;
	long long h;
	Node *pleft, *pright;
	long long value;
}tree[MAX_INTERVAL *4];

int discrete[MAX_INTERVAL *2], node_cnt, discrete_num;

void buildtree(Node *proot, int s, int e)
{
	proot->l = s;
	proot->r = e;
	proot->h = 0;
	proot->value = 0;
	if (s == e)
	{
		proot->pleft = proot->pright = NULL;
		return;
	}
	node_cnt++;
	proot->pleft = tree + node_cnt;
	node_cnt++;
	proot->pright = tree + node_cnt;
	int mid = (s + e) / 2;
	buildtree(proot->pleft, s, mid);
	buildtree(proot->pright, mid + 1, e);
}

void add(Node *proot, int start, int end, long long h)
{
	if (start > proot->r || end < proot->l)
		return;
	start = max(start, proot->l);
	end = min(end, proot->r);
	if (start == proot->l && end == proot->r)
	{
		proot->h = h;
		proot->value = h * (discrete[proot->r + 1] - discrete[proot->l]);
		return;
	}
	if (proot->h != -1 && proot->r != proot->l)
	{
		add(proot->pleft, proot->pleft->l, proot->pleft->r, proot->h);
		add(proot->pright, proot->pright->l, proot->pright->r, proot->h);
		proot->h = -1;
	}
	add(proot->pleft, start, end, h);
	add(proot->pright, start, end, h);
	proot->value = proot->pleft->value + proot->pright->value;
}
