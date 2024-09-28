#define LL long long

const int MAX_C = 0;
const int MOD = (int)(1e9) + 7;

LL multi_mod(LL a, LL b, LL c) {  // 返回(a*b) mod c,a,b,c<2^63
  a %= c;
  b %= c;
  LL ret = 0;
  while (b) {
    if (b & 1) ret = (ret + a) % c;
    a <<= 1;
    a %= c;
    b >>= 1;
  }
  return ret;
}

LL pow_mod(LL x, LL n, LL mod) {  // 返回x^n mod c ,非递归版
  x %= mod;
  if (n == 1) return x;
  LL ret = 1;
  while (n) {
    if (n & 1) ret = multi_mod(ret, x, mod);
    n >>= 1;
    x = multi_mod(x, x, mod);
  }
  return ret;
}

long long get_inverse(long long a) { return pow_mod(a, MOD - 2, MOD); }

long long factorial[MAX_C];
long long inverse[MAX_C];

void init_comb(int n) {
  factorial[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i;
    factorial[i] %= MOD;
  }
  inverse[n] = get_inverse(factorial[n]);
  for (int i = n - 1; i >= 0; i--) {
    inverse[i] = inverse[i + 1] * (i + 1);
    inverse[i] %= MOD;
  }
}

// choose b from a
long long comb(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = factorial[a] * inverse[a - b];
  ret %= MOD;
  ret *= inverse[b];
  ret %= MOD;
  return ret;
}
