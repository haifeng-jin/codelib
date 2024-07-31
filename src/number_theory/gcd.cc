LL gcd(LL a, LL b) {
  if (a == 0) return 1;
  if (a < 0) return gcd(-a, b);
  while (b) {
    LL t = a % b;
    a = b;
    b = t;
  }
  return a;
}
