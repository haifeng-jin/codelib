typedef long long LL;
#define maxn 10000
const int S = 20;

LL multi_mod(LL a, LL b, LL c) {  //返回(a*b) mod c,a,b,c<2^63
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

LL pow_mod(LL x, LL n, LL mod) {  //返回x^n mod c ,非递归版
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

bool check(LL a, LL n, LL x, LL t) {  //以a为基，n-1=x*2^t，检验n是不是合数
  LL ret = pow_mod(a, x, n), last = ret;
  for (int i = 1; i <= t; i++) {
    ret = multi_mod(ret, ret, n);
    if (ret == 1 && last != 1 && last != n - 1) return 1;
    last = ret;
  }
  if (ret != 1) return 1;
  return 0;
}

bool Miller_Rabin(LL n) {
  LL x = n - 1, t = 0;
  while ((x & 1) == 0) x >>= 1, t++;
  bool flag = 1;
  if (t >= 1 && (x & 1) == 1) {
    for (int k = 0; k < S; k++) {
      LL a = rand() % (n - 1) + 1;
      if (check(a, n, x, t)) {
        flag = 1;
        break;
      }
      flag = 0;
    }
  }
  if (!flag || n == 2) return 0;
  return 1;
}
