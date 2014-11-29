#define MAX_STING_NUM 0
#define MAX_LEN 0
#define MAX_TRIE_NUM 0

struct Node
{
	Node* next[26];
}trie[MAX_STING_NUM * MAX_LEN * 2];

int convert(char ch)
{
	return ch - 'A';
}

void add(char *st, Node* node)
{
	if (st[0] == 0)
		return;
	int index = convert(st[0]);
	if (node->next[index] == 0)
	{	
		node->next[index] = trie + node_cnt++;
	}
	add(st + 1, node->next[index]);
}

