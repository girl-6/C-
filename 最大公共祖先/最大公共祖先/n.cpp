class LCA {
public:
	int getLCA(int a, int b) {
		if (a == b || a == b / 2)
			return a;
		if (b == a / 2)
			return b;
		while (a != b)
		{
			if (a>b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};
