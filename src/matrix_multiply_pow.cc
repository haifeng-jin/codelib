#define MAX_MATRIX_SIZE 101
#define MOD 100000

struct Matrix
{
	int order;
	int num[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	Matrix()
	{}

	Matrix(int ord)
	{
		order = ord;
	}

	void init()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				num[i][j] = 0;
			}
		}
	}
	void output()
	{
		for (int i = 0; i < order; i++)
		{
			for (int j = 0; j < order; j++)
			{
				printf("%d ", num[i][j]);
			}
			puts("");
		}
	}
};

Matrix operator*(Matrix ma, Matrix mb)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	int i, j, k;
	for (i = 0; i < ord; i++)
	{
		for (k = 0; k < ord; k++)
		{
			if (ma.num[i][k] == 0)
				continue;
			for (j = 0; j < ord; j++)
			{
				long long temp = ma.num[i][k] * (long long)mb.num[k][j];
				temp %= MOD;
				numc.num[i][j] += temp;
				numc.num[i][j] %= MOD;
			}
		}
	}
	return numc;
}

Matrix matrix_power(Matrix ma, int x)
{
	int ord = ma.order;
	Matrix numc(ord);
	numc.init();
	for (int i = 0; i < ord; i++)
	{
		numc.num[i][i] = 1;
	}
	for (; x; x >>= 1)
	{
		if (x & 1)
		{
			numc = numc * ma;
		}
		ma = ma * ma;
	}
	return numc;
}
