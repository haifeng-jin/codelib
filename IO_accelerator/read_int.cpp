inline int read_int()
{
    int num = 0;
    int sign = 1;
    bool skip = false;
    int c = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '-')
        {
            sign = -1;
            skip = true;
        }
        else if(c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
            skip = true;
        }
        else if(skip)
	{
		break;
	}
    }
    return num * sign;
}

