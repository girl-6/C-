#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
 

	/* find（key） + iterator  insert(make_pair()) 
	原理：find（key）可返回查找key 后迭代器的位置，insert可插入迭代器的参考位置
故先用find查找map 内含key的键值对, 若找到就直接修改该位置的value值，若没有找到则需要在这个参考位置用insert 插入新的键值对（make_pair()）*/
void Test1()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto&e : strs)     //遍历查找
	{
		map<string, int>::iterator it = countmap.find(e);
		if (it != countmap.end())     //在map内找到了，就直接修改value值
			it->second++;
		else                         //在map内没找到，则在相对位置insert插入键值对
			countmap.insert(make_pair(e, 1));   
	}
	map<string, int>::iterator cit = countmap.begin();  //遍历打印
	while (cit != countmap.end())
	{
		cout<< cit->first << ":" << cit->second << endl;
		++cit;
	}
}

	/*pair <iterator,bool> insert（make_pair()）
	原理：此函数会主动判断插入key值是否成功，并将结果放在bool中
所以我们不需要用find 进行判断，直接用bool的结果进行操作，若bool==true 则表明插入成功，若bool ==false 则表明已插入过一次只需修改value值即可*/
void Test2()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		pair<map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e,1));    //bool==true则插入成功
		if (ret.second == false)       //如果含key 的键值对已经存在，则只修改value 的值
			ret.first->second++;
	}
	map<string, int>::iterator cit = countmap.begin();        //遍历打印
	while (cit != countmap.end())      
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}

	/*operator[]
	原理：m[key] 会直接返回key 对应的value值
所以若key对应的value 值已经存在则被修改，若未存在就会自动插入*/
void Test3()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto&e : strs)
	{
		countmap[e]++;        //遍历查找value是否都存在
	}
	map<string, int>::iterator cit = countmap.begin();       //遍历打印
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}