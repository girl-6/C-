#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Grops(int n, vector<int> v)
{
	sort(v.begin(), v.end());
	int i = n;
	long long sum = v[i];
	while (i<(3*n-2))
	{
		i += 2;
		sum += v[i];
	}
	return sum;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int a = 3 * n;
		vector <int> v;
		for (int i = 0; i<a; i++)
		{
			int a_i = 0;
			cin >> a_i;
			v.push_back(a_i);
		}
		cout << Grops(n, v) << endl;
	}
	system("pause");
	return 0;
}


