/*
        MAXN is the number of factors
        S is the number of seeds for Miller_Rabin
        Call find_divisor(n) to find all the divisors of n.
*/
typedef long long LL;
const int MAXN = 10000;
const int S = 20;

LL prime_factor[MAXN];
int prime_factor_num;
pair<LL, int> unique_factor[MAXN];
int unique_num;
long long divisor[MAXN];
int divisor_num;

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

LL Pollard_rho(LL x, LL c) {
  LL i = 1, x0 = rand() % x, y = x0, k = 2;
  while (1) {
    i++;
    x0 = (multi_mod(x0, x0, x) + c) % x;
    LL d = gcd(y - x0, x);
    if (d != 1 && d != x) {
      return d;
    }
    if (y == x0) return x;
    if (i == k) {
      y = x0;
      k += k;
    }
  }
}

void find_prime_factor(LL n) {  //递归进行质因数分解N
  if (!Miller_Rabin(n)) {
    prime_factor[prime_factor_num++] = n;
    return;
  }
  LL p = n;
  while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
  find_prime_factor(p);
  find_prime_factor(n / p);
}

void dfs(int step, long long product) {
  if (step >= unique_num) {
    divisor[divisor_num++] = product;
    return;
  }
  long long temp = 1;
  for (int i = 0; i <= unique_factor[step].second; i++) {
    dfs(step + 1, product * temp);
    temp *= unique_factor[step].first;
  }
}

void make_unique() {
  unique_num = 0;
  unique_factor[0] = make_pair(prime_factor[0], 1);

  for (int i = 1; i < prime_factor_num; i++) {
    if (prime_factor[i] == unique_factor[unique_num].first) {
      unique_factor[unique_num].second++;
      continue;
    }
    unique_num++;
    unique_factor[unique_num] = make_pair(prime_factor[i], 1);
  }
  unique_num++;
}

void find_divisor(long long n) {
  prime_factor_num = 0;
  find_prime_factor(n);
  sort(prime_factor, prime_factor + prime_factor_num);

  make_unique();
  divisor_num = 0;
  dfs(0, 1);
  sort(divisor, divisor + divisor_num);
}
