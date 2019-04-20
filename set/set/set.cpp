#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <set>
#include<iostream>
using namespace std;

void TestSet()
{
	// 用数组array中的元素构造set    
	int array[] = { 1, 3, 5, 7, 9, 2, 5, 5, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(0));
	cout << s.size() << endl;

	// 正向打印set中的元素，从打印结果中可以看出：set可去重    
	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	//使用迭代器打印set中的元素
	s.insert(11);
	s.insert(21);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto it1 = find(s.begin(), s.end(), 4); // O(N)
	auto it2 = s.find(7); // O(logN)
	if (it2 != s.end())
	{
		s.erase(it2);
	}
	cout << s.erase(5) << endl;     //删除了set中仅有的1个，故输出1
	cout << s.erase(5) << endl;     //set中已经没有5，故输出0
	//s.clear();        //清空set中的元素
	cout << s.count(3) << endl;     //返回值是1或0
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestMultiset() {
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// 注意：multiset在底层实际存储的是<int, int>的键值对    
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)         
		cout << e << " ";     
	cout << endl;
	// 测试multiset中是否可以存储值相同的元素     
	s.insert(5);
	cout << s.count(5) << endl;     //此时结果为2，说明有重复
	// 删除所有值为5的元素     
	cout<<s.erase(5)<<endl;   //此时结果为2 
	for (auto& e : s)         
		cout << e << " ";     
	cout << endl;
}

int main()
{
	//TestSet();
	TestMultiset();
	system("pause");
	return 0;
}