const int MAX_DIGIT = 20;

long long n;
int f[MAX_DIGIT];
long long memoize[MAX_DIGIT][...];

int to_digits(long long a)
{
	int ret = 0;
	while (a > 0)
	{
		f[ret++] = a % 10;
		a /= 10;
	}
	return ret;
}

long long dfs(int digit, bool less, ...)
{
	if (digit < 0)
	{
		return ...;
	}
	if (less && memoize[digit][...] != -1)
	{
		return memoize[digit][...];
	}
	int limit = less ? 9 : f[digit];
	long long ret = 0;
	for (int i = 0; i <= limit; i++)
	{
		ret += dfs(digit - 1, less || i < f[digit], ...);
	}
	if (less)
	{
		memoize[digit][...] = ret;
	}
	return ret;
}

long long work(long long n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		//return 1;
	}
	int len = to_digits(n);
	memset(memoize, -1, sizeof(memoize));
	return dfs(len - 1, false, ...);
}
