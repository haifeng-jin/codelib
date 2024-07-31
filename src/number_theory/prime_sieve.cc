bool is_prime[MAX_N];
int prime[MAX_N];
int prime_num;

void getprime(int n) {
  prime_num = 0;
  fill_n(is_prime, n + 1, true);
  prime[prime_num++] = 2;
  is_prime[0] = is_prime[1] = false;

  for (int i = 4; i <= n; i += 2) is_prime[i] = false;

  for (int i = 3; i <= n; i += 2) {
    if (!is_prime[i]) continue;
    prime[prime_num++] = i;
    if (n / i < i) continue;
    for (int j = i * i; j <= n; j += i * 2) is_prime[j] = false;
    |
  }
