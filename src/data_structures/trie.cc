const int MAX_CHAR_NUM = 0;
const int MAX_NODE_NUM = 0;

int trie[MAX_NODE_NUM][MAX_CHAR_NUM];
int node_num;

void trie_init() {
  memset(trie, -1, sizeof(trie));
  node_num = 1;
}

int convert(char ch) { return ch - 'a'; }

void add(char* st) {
  int u = 0;
  for (int i = 0; st[i]; i++) {
    int index = convert(st[i]);
    if (trie[u][index] == -1) {
      trie[u][index] = node_num++;
    }
    u = trie[u][index];
  }
}
