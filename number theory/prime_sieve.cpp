bool is_prime[MAX_N];
int prime[MAX_N];
int prime_num;

void getprime(int n)
{
	int i, j;
	int s, e = (int)(sqrt(0.0 + n) + 1);
	prime_num = 0;
	memset(is_prime, 1, sizeof(is_prime));
	prime[prime_num++] = 2;
	is_prime[0] = is_prime[1] = 0;
	for (i = 4; i < n; i += 2) 
		is_prime[i] = 0;
	for (i = 3; i < e; i += 2)
		if (is_prime[i])
		{
			prime[prime_num++] = i;
			for (s = i * 2, j = i * i; j < n; j += s)
				is_prime[j] = 0;
		}
	for ( ; i < n; i += 2)
		if (is_prime[i])
			prime[prime_num++] = i;
}
