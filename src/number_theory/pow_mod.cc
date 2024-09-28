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
