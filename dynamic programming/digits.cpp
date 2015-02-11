
const int MAX_DIGIT = 20;

long long n;
int f[MAX_DIGIT];
long long memoize[MAX_DIGIT][20*20*9];
int pivot;

int to_digits(long long a)
{
	int ret = 0;
	while (a > 0)
	{
		f[++ret] = a % 10;
		a /= 10;
	}
	return ret;
}

long long dfs(int digit, bool less, int weight)
{
	if (digit <= 0)
	{
		return weight == 0;
	}
	if (less && memoize[digit][weight] != -1)
	{
		return memoize[digit][weight];
	}
	int limit = less ? 9 : f[digit];
	long long ret = 0;
	for (int i = 0; i <= limit; i++)
	{
		int new_weight = weight + (digit - pivot) * i;
		if (new_weight < 0)
		{
			continue;
		}
		ret += dfs(digit - 1, less || i < f[digit], new_weight);
	}
	memoize[digit][weight] = ret;
	return ret;
}

long long work(long long n)
{
	if (n < 0)
	{
		return 0;
	}
	int len = to_digits(n);
	return dfs(len, false, 0);
}
