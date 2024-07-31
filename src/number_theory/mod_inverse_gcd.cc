void gcd_extend(long long a, long long b, long long &g, long long &x,
                long long &y) {
  if (!b) {
    g = a;
    x = 1;
    y = 0;
    return;
  }
  gcd_extend(b, a % b, g, y, x);
  y -= a / b * x;
}

long long get_inverse(long long a) {
  long long g, x, y;
  gcd_extend(a, MOD, g, x, y);
  x = (x % MOD + MOD) % MOD;
  x /= g;
  return x;
}
