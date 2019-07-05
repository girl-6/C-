// write your code here cpp
#include <iostream>
#include <algorithm>
using namespace std;

void AfatB(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pow(3, i) >= n)
		{
			cout << i << endl;
			break;
		}
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		AfatB(n);
	}
	system("pause");
	return 0;
}