int discrete[MAX_D];
int discrete_num;

int get_index(int a)
{
	return lower_bound(discrete, discrete + discrete_num, a) - discrete;
}

void discretization()
{
	sort(discrete, discrete + discrete_num);
	discrete_num = unique(discrete, discrete + discrete_num) - discrete;
}
