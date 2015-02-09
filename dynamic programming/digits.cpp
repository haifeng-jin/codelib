#include <cstdio>
#include <cstring>
using namespace std;

#define D(x) x

const int MAX_DIGIT = 35;

int n, m;
int f[MAX_DIGIT];
int memoize[MAX_DIGIT][2][2][2][13];

void to_digits(int a)
{
	for (int i = 0; i < MAX_DIGIT; i++)
	{
		f[i] = a % 10;
		a /= 10;
	}
}

int dfs(int digit, bool less, bool contain, bool one, int remain)
{
	if (digit == -1)
	{
		return contain && !remain;
	}
	if (memoize[digit][less][contain][one][remain] != -1)
	{
		return memoize[digit][less][contain][one][remain];
	}
	int limit = less ? 9 : f[digit];
	int ret = 0;
	for (int i = 0; i <= limit; i++)
	{
		int new_remain = (remain * 10 + i) % 13;
		if (i == 3  && one)
		{
			ret += dfs(digit - 1, less || i < f[digit], true, false, new_remain);
			continue;
		}
		if (i == 1)
		{
			ret += dfs(digit - 1, less || i < f[digit], contain, true, new_remain);
			continue;
		}
		ret += dfs(digit - 1, less || i < f[digit], contain, false, new_remain);
	}
	memoize[digit][less][contain][one][remain] = ret;
	return ret;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		to_digits(n);
		memset(memoize, -1, sizeof(memoize));
		int ans = dfs(32, false, false, false, 0);
		printf("%d\n", ans);
	}
	return 0;
}

