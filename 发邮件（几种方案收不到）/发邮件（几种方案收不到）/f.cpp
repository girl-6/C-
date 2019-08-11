#include <iostream>
using namespace std;

int main()
{
	long long n[21] = { 0, 0, 1 };
	for (int i = 3; i<21; i++)
		n[i] = (i - 1)*(n[i - 1] + n[i - 2]);   //递归总结规律
	int a = 0;
	while (cin >> a)
		cout << n[a] << endl;
	return 0;
}