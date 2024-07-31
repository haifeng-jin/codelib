const int MAX_LEN = 0;
// call init_RMQ(f[], n) first.
// then call query(a, b) to quest the RMQ of [a, b].
int power[30];
int st[MAX_LEN * 2][32];
int ln[MAX_LEN * 2];

// returns the index of the first minimum value in [x, y]
void init_RMQ(int f[], int n) {
  int i, j;
  for (power[0] = 1, i = 1; i < 21; i++) {
    power[i] = 2 * power[i - 1];
  }
  for (i = 0; i < n; i++) {
    st[i][0] = i;
  }
  ln[0] = -1;
  for (int i = 1; i <= n; i++) {
    ln[i] = ln[i >> 1] + 1;
  }
  for (j = 1; j < ln[n]; j++) {
    for (i = 0; i < n; i++) {
      if (i + power[j - 1] - 1 >= n) {
        break;
      }
      // for maximum, change ">" to "<"
      // for the last, change "<" or ">" to "<=" or ">="
      if (f[st[i][j - 1]] > f[st[i + power[j - 1]][j - 1]]) {
        st[i][j] = st[i + power[j - 1]][j - 1];
      } else {
        st[i][j] = st[i][j - 1];
      }
    }
  }
}

int query(int f[], int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  int k = ln[y - x + 1];
  // for maximum, change ">" to "<"
  // for the last, change "<" or ">" to "<=" or ">="
  if (f[st[x][k]] > f[st[y - power[k] + 1][k]]) return st[y - power[k] + 1][k];
  return st[x][k];
}

// first use the constructed function
// call function lcp(l, r) to get the longest common prefix of sa[l] and sa[r]
// have access to the member of sa, myrank, height and so on
// height is the LCP of sa[i] and sa[i + 1]
class SuffixArray {
 public:
  char* s;
  int n, sa[MAX_LEN], height[MAX_LEN], myrank[MAX_LEN];
  int tmp[MAX_LEN], top[MAX_LEN];

  SuffixArray() {}

  // the string and the length of the string
  SuffixArray(char* st, int len) {
    s = st;
    n = len + 1;
    make_sa();
    make_lcp();
  }

  void make_sa() {
    // O(N * log N)
    int na = (n < 256 ? 256 : n);
    memset(top, 0, na * sizeof(int));
    for (int i = 0; i < n; i++) top[myrank[i] = s[i] & 0xff]++;
    for (int i = 1; i < na; i++) top[i] += top[i - 1];
    for (int i = 0; i < n; i++) sa[--top[myrank[i]]] = i;
    int x;
    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i++) {
        x = sa[i] - len;
        if (x < 0) x += n;
        tmp[top[myrank[x]]++] = x;
      }
      sa[tmp[top[0] = 0]] = x = 0;
      for (int i = 1; i < n; i++) {
        if (myrank[tmp[i]] != myrank[tmp[i - 1]] ||
            myrank[tmp[i] + len] != myrank[tmp[i - 1] + len])
          top[++x] = i;
        sa[tmp[i]] = x;
      }
      memcpy(myrank, sa, n * sizeof(int));
      memcpy(sa, tmp, n * sizeof(int));
      if (x >= n - 1) break;
    }
  }

  void make_lcp() {
    // O(4 * N)
    int i, j, k;
    for (j = myrank[height[i = k = 0] = 0]; i < n - 1; i++, k++) {
      while (k >= 0 && s[i] != s[sa[j - 1] + k]) {
        height[j - 1] = (k--);
        j = myrank[sa[j] + 1];
      }
    }
    init_RMQ(height, n - 1);
  }

  int lcp(int l, int r) { return height[query(height, l, r - 1)]; }
};
