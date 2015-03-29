void gcd_extend(long long a,long long b,long long &g,long long &x,long long &y)
{
	if (!b)
	{
		g = a;
		x = 1;
		y = 0;
		return;
	}
	gcd_extend(b, a % b, g, y, x);
	y -= a / b * x;
}
