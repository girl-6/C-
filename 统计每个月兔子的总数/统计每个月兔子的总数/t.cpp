#include <iostream>
using namespace std;

int Count(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Count(n - 1) + Count(n - 2);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
	return 0;
}