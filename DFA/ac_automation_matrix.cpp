/*
	ac_init();
	//insert strings to it here
	insert(root, st);
	build_ac_automation(root);
	Matrix matrix;
	extract_matrix(matrix);
*/

const int MAX_CHILD_NUM = 0;
const int MAX_NODE_NUM = 0;
const int MAX_MATRIX_SIZE = 0;
const int MOD = 0;


int matrix_size;
int node_cnt;

struct node
{
	node *fail;
	node *next[MAX_CHILD_NUM];
	int count; //how many words are matched when reach this node(the sum of its fail nodes' count)
}trie[MAX_NODE_NUM], *root = trie;

void ac_init()
{
	memset(trie, 0, sizeof(trie));
	node_cnt = 1;
}

int get_id(char ch)
{
	return ch - 'a';
}

void insert(node *root, char *str)
{
	node *p = root;
	int index;
	for (int i = 0; str[i]; i++)
	{
		index = get_id(str[i]);
		if (p->next[index] == NULL)
		{
			p->next[index] = trie + node_cnt;
			node_cnt++;
		}
		p = p->next[index];
	}
	p->count++;
}

void build_ac_automation(node *root)
{
	queue<node*> q;
	int i;
	root->fail = NULL;
	q.push(root);
	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();
		node *p = NULL;
		for (i = 0; i < MAX_CHILD_NUM; i++)
		{
			p = temp->fail;
			while (p != NULL && p->next[i] == NULL)
				p = p->fail;
			if (temp->next[i] != NULL)
			{
				if (p == NULL)
					temp->next[i]->fail = root;
				else
				{
					temp->next[i]->fail = p->next[i];
					temp->next[i]->count += p->next[i]->count;
				}
				q.push(temp->next[i]);
			}else
			{
				if (p == NULL)
					temp->next[i] = root;
				else
					temp->next[i] = p->next[i];
			}
		}
	}
}

int query(node *root, char* str)
{
	int cnt = 0, index;
	node *p = root;
	for (int i = 0; str[i]; i++)
	{
		index = get_id(str[i]);
		p = p->next[index];
		p = (p == NULL) ? root : p;
		node *temp = p;
		if (temp->count > 0)
			cnt += temp->count;
		//the following "while" marks count as -1 to prevent from matching again
		while (temp != root && temp->count != -1)
		{
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return cnt;
}

struct Matrix
{
	int order;
	int num[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	Matrix()
	{}

	Matrix(int ord)
	{
		order = ord;
	}

	void init()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				num[i][j] = 0;
			}
		}
	}
	void output()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				printf("%d ", num[i][j]);
			}
			puts("");
		}
	}
};

Matrix operator*(Matrix ma, Matrix mb)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	int i, j, k;
	for (i = 0; i < ord; i++)
	{
		for (k = 0; k < ord; k++)
		{
			if (ma.num[i][k] == 0)
				continue;
			for (j = 0; j < ord; j++)
			{
				long long temp = ma.num[i][k] * (long long)mb.num[k][j];
				temp %= MOD;
				numc.num[i][j] += temp;
				numc.num[i][j] %= MOD;
			}
		}
	}
	return numc;
}

Matrix matrix_power(Matrix ma, int x)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	for (int i = 0; i < ord; i++)
	{
		numc.num[i][i] = 1;
	}
	for (; x; x >>= 1)
	{
		if (x & 1)
		{
			numc = numc * ma;
		}
		ma = ma * ma;
	}
	return numc;
}

void extract_matrix(Matrix &matrix)
{
	matrix.order = node_cnt;
	matrix.init();
	for (int i = 0; i < node_cnt; i++)
	{
		for (int j = 0; j < MAX_CHILD_NUM; j++)
		{
			if (trie[i].next[j] == NULL)
				continue;
			int temp = trie[i].next[j] - trie;
			if (trie[temp].count == 0)
			{
				matrix.num[i][temp] += 1;
			}
		}
	}
}

