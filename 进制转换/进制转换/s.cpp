#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int w, n;
	cin >> w >> n;
	vector<char> v;
	string s = "0123456789ABCDEF";
	bool flag = false;
	if (w < 0)
	{
		w = 0 - w;
		flag = true;
	}
	do
	{
		int b = w % n;
		v.push_back(s[b]);
		w = w / n;
	} while (w > 0);
	reverse(v.begin(), v.end());
	if (flag)
		cout << "-";
	for (const auto&e : v)
	{
		cout << e;
	}
	system("pause");
	return 0;
}