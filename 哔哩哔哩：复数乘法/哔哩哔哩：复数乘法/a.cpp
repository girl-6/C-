#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Mul(string a,string b)
{
	int a1 = 0;
	int a2 = 0;
	int b1 = 0;
	int b2 = 0;
	int lag = 0;
	int flg1 = 0;
	int flg2 = 0;

	for (int i = 0; i < a.size()-1; i++)
	{
		if (a[i] == '+')
		{
			lag = 1;
			continue;
		}
		if (lag == 0)
		{
			if (a[i] == '-')
				flg1 = -1;
			else
				a1 = a1 * 10 + a[i] - '0';
		}
		else
		{
			if (a[i] == '-')
				flg2 = -1;
			else 
				a2 = a2 * 10 + a[i] - '0';
		}		 
	}
	a1 *= flg1;
	a2 *= flg2;
	flg1 = flg2 = lag = 0;
	for (int i = 0; i < b.size() - 1; i++)
	{
		if (b[i] == '+')
		{
			lag = 1;
			continue;
		}
		if (lag == 0)
		{
			if (b[i] == '-')
				flg1 = -1;
			else
				b1 = b1 * 10 + b[i] - '0';
		}
		else 
		{
			if (b[i] == '-')
				flg2 = -1;
			else
				b2 = b2 * 10 + b[i] - '0';
		}
	}
	b1 *= flg1;
	b2 *= flg2;
	a1 = a1*b1 - a2*b2;
	a2 = a1*b2 + a2*b1;
	string c, d, result;
	while (a1)
	{
		c .push_back( a1 % 10 + '0');
		a1 / 10;
	}
	while (a2)
	{
		d .push_back( a2 % 10 + '0');
		a2 / 10;
	}
	result += c;
	result.push_back('+');
	result += d;
	result.push_back('i');
	return result;
}
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << Mul(a, b) << endl;
	system("pause");
	return 0;
}

