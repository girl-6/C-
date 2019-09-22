#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 18;

int main()
{
	int M, S, T;
	while (cin >> M >> S >> T)
	{
		vector<int> v(maxn, 0);
		for (int i = 1; i <= T; ++i)
		{
			if (M >= 10)
			{
				v[i] = v[i - 1] + 50;
				M -= 10;
			}
			else
			{
				v[i] = v[i - 1];
				M += 4;
			}
		}
		for (int i = 1; i <= T; ++i)
		{
			v[i] = max(v[i], v[i - 1] + 13);
			if (v[i] >= S)
			{
				cout << "Yes " << i << endl;
			}
		}
		if (v[T]<S)
		cout << "No " << v[T] << endl;
	}
	return 0;
}