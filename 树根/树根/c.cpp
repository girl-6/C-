// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int SGen(int m)
{
	int a = m % 10;
	int sum = a;
	m /= 10;
	while (m)
	{
		a = m % 10;
		sum += a;
		m /= 10;
	}
	if (sum<10)
		return sum;
	else
		return SGen(sum);
}

int main()
{
	string s;
	while (cin >> s)
	{
		int n = 0;
		for (int i = 0; i<s.size(); i++)
			n += s[i] - '0';
		while (n>9)
		{
			n = SGen(n);
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}