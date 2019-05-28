#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int n1 = 0, n2 = 1;
	while (N > n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp + n1;
	}
	int min = (N - n1)<(n2 - N) ? N - n1 : n2 - N;
	cout << min;
	system("pause");
	return 0;
}