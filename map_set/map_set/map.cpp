#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<string>
#include<iostream>
#include<map>
#include <functional>
#include<vector>
using namespace std;

//键值对
//template<class K, class V>
//struct pair
//{
//	typedef K first_type;
//	typedef V second_type;
//
//	K first;
//	V second;
//	pair()
//		:first(K())
//		, second(V())
//	{}
//
//	pair(const K& a, const V&b)
//		: first(a)
//		, second(b)
//	{}
//};

//make_pair 是函数模板，根据pair的类型直接推出参数类型
//template<class K, class V>
//pair<K, V> make_pair(const K&k, const V&v)
//{
//	return pair<K, V>(k, v);
//}


	//map 的使用--字典
	void test_map()
	{
		map<string, string> m1;
		map<string, string>m2{ { "apple", "苹果" },
		{ "banan", "香蕉" }, { "orange", "橘子" } };
		cout << m2["apple"] << endl;     //苹果
		cout << m2["peach"] << endl;     //空串
		
		//迭代器使用
		map<string, string>::iterator it = m2.begin();
		while (it != m2.end())
		{
			cout << (*it).first << ":" << (*it).second << "  ";
			it++;
		}
		cout << endl;
	}

	//map 的operator[]
void TestMap() {    // 构造一个空的map，此时m中一个元素都没有    
	map<string, string> m;

	/*    operator[]的原理是：      
	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中      
	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器      
	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器      
	operator[]函数后将insert返回值键值对中的value返回    */   
	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，    
	// 即修改与"apple"对应的value""为"苹果"    
	m["apple"] = "苹果";        
	// 将<"apple", "">插入map中，插入失败，将<"apple", "苹果">中的"苹果"返回    
	cout << m["apple"] << endl;    
	cout << m.size() << endl;

	// “banan不在map中，该函数抛异常”    
	//m.at("banan"); 
} 

void TestMap2()
{
	map<string, string> m;

	// 向map中插入元素的方式：将键值对<"peach","桃子">插入map中，用pair直接来构造键值对 
	m.insert(pair<string, string>("peach", "桃子"));

	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对 
	m.insert(make_pair("banan", "香蕉"));  

	// 借用operator[]向map中插入元素   
	m["apple"] = "苹果";

	// key不存在时抛异常    m.at("waterme") = "水蜜桃";  

	//iterator insert中的position 只是参考位置
	m.insert(m.find("banan"), make_pair("waterme", "水蜜桃"));    

	cout << m.size() << endl;    //4

	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列    
	for (const auto& e : m)       
		cout << e.first << "：" << e.second << endl;    
	cout << endl;      //苹果，香蕉，桃子，水蜜桃

	// map中的键值对key一定是唯一的，如果key存在将插入失败    
	auto ret = m.insert(make_pair("peach", "桃色"));    
	if (ret.second)        
		cout << "<peach, 桃色>不在map中, 刚插入" << endl;    
	else        
		cout << "key为peach的元素已经存在  " << ret.first->first << "：" << ret.first->second << endl;

	// 删除key为"apple"的元素    
	m.erase("apple");    

	//count 检测key在map中的个数，只能是1或0
	if (m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被删除" << endl;
	cout << "剩下的水果有 ->" << endl;
	for (auto& e : m)        
	cout << e.first << "：" << e.second << endl;
}


	//测试multimap
void TestMultimap1() 
{
	multimap<string, string> m;
	m.insert(make_pair("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	//尝试插入key相同的值
	m.insert(make_pair("李逵", "铁牛")); 
	cout << m.size() << endl;    //4

	for (auto& e : m)    
		cout << "<" << e.first << "：" << e.second << endl;

	// key为李逵的元素有多少个    
	cout << m.count("李逵") << endl;        //2 
}
void TestMultimap2() 
{
	multimap<int, int> m; 
	for (int i = 0; i < 10; ++i)    
		m.insert(pair<int, int>(i, i));

	for (auto& e : m)    
		cout << e.first << "：" << e.second << endl; 
	cout << endl;

	// 返回m中大于等于5的第一个元素 
	auto it = m.lower_bound(5); 
	cout << it->first << "：" << it->second << endl;

	// 返回m中大于5的第一个元素 
	it = m.upper_bound(5); 
	cout << it->first << "：" << it->second << endl; 
} 

	int main()
	{
		//test_map();
		//TestMap();
		//TestMap2();
		//TestMultimap1();
		TestMultimap2();
		system("pause");
		return 0;
	}