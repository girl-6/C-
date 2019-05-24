#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include<map>
#include<vector>
using namespace std;

//应用map
//int main()
//{
//	int i = 0;
//	vector<int> v;
//	while (cin>>i)
//	{
//		v.push_back(i);
//	}
//	map<int, int> m;
//	for (const auto&e : v)
//		m[e]++;
//	for (const auto &e : m)
//	{
//		if (e.second >=(v.size() / 2))
//			cout<<e.first;
//	}
//	system("pause");
//	return 0;
//}

//排序后，输出最中间的数
//#include<algorithm>
//int main()
//{
//	int i = 0;
//	vector<int> v;
//	while (cin >> i)    //用/0 停止输入
//	{
//		v.push_back(i);
//	}
//	sort(v.begin(), v.end());
//	cout << v[v.size() / 2-1];
//	system("pause");
//	return 0;
//}

//count计数
int main()
{
	int i = 0;
	vector<int> v;
	while (cin >> i)
		v.push_back(i);
	int count = 1;
	int temp = v[0];
	for (int a = 0; a < v.size(); a++)
	{
		if (temp == v[a])
			count++;
		else
			count--;
		if (count == 0)
		{
			temp = v[a];
			count++;
		}
	}
	cout << temp;
	system("pause");
	return 0;
}