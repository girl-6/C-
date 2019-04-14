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
	for (const string&s : str)    //pair_insert不存在就插入，若已存在则修改second的值
	{
		pair<map<string, int>::iterator, bool>ret = countmap.insert(make_pair(s, 1));
		if (ret.second == false)
			ret.first->second++;
	}
	/*for (const string& s :str)     //find找到即已存在则修改second值，不存在则插入
	{
		map<string, int>::iterator it = countmap.find(s);
		if (it != countmap.end())
			it->second++;
		else
			countmap.insert(make_pair(s, 1));
	}
	for (const string& s : str)       //先插入若存在就修改
	{
		countmap[s]++;
	}*/
	
		/*auto cit = countmap.begin();    //迭代器遍历
		while (cit != countmap.end())
		{
			cout << cit->first << ":" << cit->second << endl;
			++cit;
		}*/
	for (auto& e : countmap)    //范围for遍历
	{
		cout << e.first <<":"<<e.second << endl;
	}
}


		//map的运用——前K个高频单词
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//1. operator[]  2.find insert 2.insert
		map<string, int> countmap;    //map已完成数量统计和首字母排序
		for (const string& s : words)
			countmap[s]++;
		multimap<int, string, greater<int>>sortmap;     //multimap按value排序
		for (const auto&kv : countmap)
			sortmap.insert(make_pair(kv.second, kv.first));
		vector<string>v;
		multimap<int, string>::iterator it = sortmap.begin();
		while (it != sortmap.end() && k--)   //将前k个存入vector中
		{
			v.push_back(it->second);
			++it;
		}
		return v;  //输出vector
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