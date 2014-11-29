template<typename T>
class queue
{
	T data[MAX_Q_LEN];
	int head, tail;

public:
	queue()
	{
		head = tail = 0;
	}

	bool empty()
	{
		return head == tail;
	}

	void pop()
	{
		head++;
		if (head >= MAX_Q_LEN)
			head = 0;
	}

	void push(T a)
	{
		data[tail++] = a;
		if (tail >= MAX_Q_LEN)
			tail = 0;
	}

	T front()
	{
		return data[head];
	}
};

