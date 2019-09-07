#include <iostream>

using namespace std;

template <class T>

T cmp(T x, T y)
{
	if (x > y)
		return 1;
	else if (x == y)
		return 0;
	else if (x < y)
		return -1;
	else
		return false;
}

int main()
{
	int x = 2, y = 3;
	cout << cmp(x, y) << endl;
	system("pause");
	return 0;
}