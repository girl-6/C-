#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int a[4] = { 0 };
	for (int i = 0; i<4; i++)
	{
		cin >> a[i];
	}
	int A = (a[0] + a[2]) / 2;
	int C = (a[3] - a[1]) / 2;
	int B1 = (a[2] - a[0]) / 2;
	int B2 = (a[1] + a[3]) / 2;
	if (B1 != B2)
		cout << "NO";
	else
		cout << A << " " << B1 << " " << C;
	system("pause");
	return 0;
}