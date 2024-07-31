#define MAX_LEN 0

struct Node
{
	Node *pleft;
	Node *pright;
	long long l, r;
	long long sum;
} tree[MAX_LEN * 3];

int len;
long long sum;
int ncount;

void build_tree(Node *proot, int l, int r)
{
	int mid = (l + r) / 2;
	proot->l = l;
	proot->r = r;
	proot->sum = 0;
	if (l == r)
		return;
	ncount++;
	proot->pleft = tree + ncount;
	ncount++;
	proot->pright = tree + ncount;
	build_tree(proot->pleft, l, mid);
	build_tree(proot->pright, mid + 1, r);
}

long long query(Node *proot, long long l, long long r)
{
	if (l > proot->r || r < proot->l)
	{
		return 0;
	}
	l = max(proot->l, l);
	r = min(proot->r, r);
	if (l == proot->l && r == proot->r)
	{
		D(puts("***"));
		return proot->sum;
	}
	return (query(proot->pleft, l, r) + query(proot->pright, l, r)) % MOD;
}

void update(Node *proot, long long pos, long long a)
{
	if (pos > proot->r || pos < proot->l)
	{
		return;
	}
	proot->sum += a;
	proot->sum %= MOD;
	if (proot->l == proot->r)
	{
		return;
	}
	update(proot->pleft, pos, a);
	update(proot->pright, pos, a);
}

