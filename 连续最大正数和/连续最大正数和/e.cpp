#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n = 0;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	int sum = v[0];
	int s2 = 0;
	int s1 = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] < 0)
		{
			s2 = s1 = v[i];
		}
		else
			s2 = s1 + v[i];
		if (s2>s1)
			s1 = s2;
		else
		{
			sum = s1;
			s1 = 0;
		}
		sum = sum > s2 ? sum : s2;
	}
	cout << sum;
	system("pause");
	return 0;
}