
# include<iostream>
#include <math.h>
using namespace std;

bool IsTriangle(double a, double b, double c)
{
	if (a + b>c&&a + c>b&&b + c>a)
	{
		if (abs(a - b)<c&&abs(a - c)<b&&abs(b - c)<a)
			return true;
	}
	return false;
}
int main()
{
	double a = 0; double b = 0; double c = 0;
	while (cin >> a >> b >> c)
	{
		if (IsTriangle(a, b, c))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}