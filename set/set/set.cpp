#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <set>
#include<iostream>
using namespace std;

void TestSet()
{
	// ������array�е�Ԫ�ع���set    
	int array[] = { 1, 3, 5, 7, 9, 2, 5, 5, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(0));
	cout << s.size() << endl;

	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��    
	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	//ʹ�õ�������ӡset�е�Ԫ��
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
	cout << s.erase(5) << endl;     //ɾ����set�н��е�1���������1
	cout << s.erase(5) << endl;     //set���Ѿ�û��5�������0
	//s.clear();        //���set�е�Ԫ��
	cout << s.count(3) << endl;     //����ֵ��1��0
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestMultiset() {
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��    
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)         
		cout << e << " ";     
	cout << endl;
	// ����multiset���Ƿ���Դ洢ֵ��ͬ��Ԫ��     
	s.insert(5);
	cout << s.count(5) << endl;     //��ʱ���Ϊ2��˵�����ظ�
	// ɾ������ֵΪ5��Ԫ��     
	cout<<s.erase(5)<<endl;   //��ʱ���Ϊ2 
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