// write your code here cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void YinZi(int n, vector <int> &v)
{
	for (int i = 2; i<= sqrt(n); i++)
	{
		while (n%i == 0)
		{
			v.push_back(i);
			n /= i;
		}
	}
	if (n>1)
		v.push_back(n);
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector <int> v;
		YinZi(n, v);
		cout << n << " = ";
		for (int i = 0; i<v.size() - 1; i++)
			cout << v[i] << " * ";
		cout << v[v.size() - 1] << endl;
	}
	system("pause");
	return 0;
}
