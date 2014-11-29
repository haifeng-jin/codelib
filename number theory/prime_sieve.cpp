bool is_prime[MAX_N];
int prime[MAX_N];

int getprime(int n)
{
	int i, j, k = 0;
	int s, e = (int)(sqrt(0.0 + n) + 1);
	memset(is_prime, 1, sizeof(is_prime));
	prime[k++] = 2;
	is_prime[0] = is_prime[1] = 0;
	for (i = 4; i < n; i += 2) 
		is_prime[i] = 0;
	for (i = 3; i < e; i += 2)
		if (is_prime[i])
		{
			prime[k++] = i;
			for (s = i * 2, j = i * i; j < n; j += s)
				is_prime[j] = 0;
		}
	for ( ; i < n; i += 2)
		if (is_prime[i])
			prime[k++] = i;
	return k;
}
