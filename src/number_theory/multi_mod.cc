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
