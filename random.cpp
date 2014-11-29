double random_double()
{
	return rand() * 1.0 / RAND_MAX;
}

int random_int(int bound)
{
	return (int) (random_double() * (bound - 1) + 0.5);
}

void init_random()
{
	srand(time(NULL));
}

