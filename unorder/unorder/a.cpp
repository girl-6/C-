#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


//map 接口测试
//int main()
//{
//	unordered_map<string, string> um;
//	um.insert(make_pair(string("sort"), string("排序")));
//	um.insert(make_pair(string("string"), string("字符串")));
//	um.insert(make_pair(string("left"), string("左边")));
//	um.insert(make_pair(string("lost"), string("丢失")));
//	um.insert(make_pair(string("come"), string("过来")));
//
//	cout << um.empty() << endl;//判断是否为空
//	cout << um.size() << endl;//元素的个数
//
//
//	unordered_map<string, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//
//	system("pause");
//	return 0;
//}

//set接口测试
int main()
{
	unordered_set<int> us;
	us.insert(9);
	us.insert(6);
	us.insert(8);
	us.insert(10);
	us.insert(7);
	us.insert(3);
	us.insert(6);
	us.insert(7);
	us.insert(4);

	cout << us.empty() << endl;
	cout << us.size() << endl;

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}


