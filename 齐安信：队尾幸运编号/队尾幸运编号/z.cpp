#include <iostream>
using namespace std;

int Num(int n)
{
	int ret = n;
	int num = n / 5;
	n = n - n / 5 + n % 5;
	while (n % 5 != 0)
	{
		num += n / 5;
		ret -= num;
		if (n>5)
			n=ret+n%5;
		else
		{
			n = n % 5 + ret;
		}
	}
	num += n / 5;
	return num;
}
int main()
{
    int n;
	while (cin >> n)
	{
		if (n % 5 == 0)
			cout << n / 5 << endl;
		else
			cout << Num(n) << endl;
	}
	system("pause");
	return 0;
}


