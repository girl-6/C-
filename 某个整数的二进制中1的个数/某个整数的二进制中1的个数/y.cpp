#include <iostream>
using namespace std;

int findNumberOf1(int num)
{
	int count = 0;
	while (num)
	{
		if (num & 1)
			count++;
		num = num >> 1;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = findNumberOf1(n);
		cout << count << endl;
	}
	system("pause");
	return 0;
}