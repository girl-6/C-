#include <iostream>
using namespace std;

int GYS(int a, int b)
{
	int c = 0;
	while (c=a%b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n;
	cin >> m;
	int temp = GYS(n, m);
	cout << (m*n / temp) << endl;
	return 0;
}