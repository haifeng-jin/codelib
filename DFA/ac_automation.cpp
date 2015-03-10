/*
	ac_init();
	//insert strings to it here
	insert(root, st);
	build_ac_automation(root);
*/

const int MAX_CHILD_NUM = 0;
const int MAX_NODE_NUM = 0;

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

