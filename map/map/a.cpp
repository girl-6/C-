#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
//#include <stdio.h>
#include<string>
#include<iostream>
#include<map>
#include <functional>
#include<vector>
using namespace std;

void test_map()
{
	string str[] = { "zaq", "asd", "zaq", "asd", "zaq", "rty" };
	map<string, int>countmap;
	for (const string&s : str)    //pair_insert�����ھͲ��룬���Ѵ������޸�second��ֵ
	{
		pair<map<string, int>::iterator, bool>ret = countmap.insert(make_pair(s, 1));
		if (ret.second == false)
			ret.first->second++;
	}
	/*for (const string& s :str)     //find�ҵ����Ѵ������޸�secondֵ�������������
	{
		map<string, int>::iterator it = countmap.find(s);
		if (it != countmap.end())
			it->second++;
		else
			countmap.insert(make_pair(s, 1));
	}
	for (const string& s : str)       //�Ȳ��������ھ��޸�
	{
		countmap[s]++;
	}*/
	
		/*auto cit = countmap.begin();    //����������
		while (cit != countmap.end())
		{
			cout << cit->first << ":" << cit->second << endl;
			++cit;
		}*/
	for (auto& e : countmap)    //��Χfor����
	{
		cout << e.first <<":"<<e.second << endl;
	}
}


		//map�����á���ǰK����Ƶ����
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//1. operator[]  2.find insert 2.insert
		map<string, int> countmap;    //map���������ͳ�ƺ�����ĸ����
		for (const string& s : words)
			countmap[s]++;
		multimap<int, string, greater<int>>sortmap;     //multimap��value����
		for (const auto&kv : countmap)
			sortmap.insert(make_pair(kv.second, kv.first));
		vector<string>v;
		multimap<int, string>::iterator it = sortmap.begin();
		while (it != sortmap.end() && k--)   //��ǰk������vector��
		{
			v.push_back(it->second);
			++it;
		}
		return v;  //���vector
	}
};

void test_solution()
{
	Solution s;
	vector<string> words;
	words.push_back("i");
	words.push_back("love");
	words.push_back("a");
	words.push_back("i");
	words.push_back("love");
	words.push_back("c");
	words.push_back("b");
	vector<string>a=s.topKFrequent(words, 2);
	for (auto& s : a)
		cout << s << " ";
	cout << endl;
}


int main()
{
	//test_map();
	test_solution();
	system("pause");
	return 0;
}