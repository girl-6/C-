#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string iToS(int n)     //整型转字符串
{
	string s;
	int a = n % 10;
	s.push_back(a + '0');
	n /= 10;
	while (n)
	{
		a = n % 10;
		s.push_back(a + '0');
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;

}

string getFile(string s, int n)    //获取文件名，同时将行数放在字符串中
{
	string s1;
	int i = 0;
	int pos = s.find('\\', i);
	while (pos<s.size())     //找到最后一个\，记录此时i
	{
		i = pos + 1;
		pos = s.find('\\', i);
	}
	for (i; i < s.size(); i++)      //用s1记录文件名
		s1.push_back(s[i]);
	if (s1.size()>16)       //如果文件名字符大于16则只取后16位
		s1 = s1.substr(s1.size() - 16, 16);
	s1.push_back(' ');
	string s2 = iToS(n);
	s1 += s2;
	return s1;
}

int main()
{
	string s;
	int n;
	map<string, int> m;
	int k = 0;
	while (cin >> s >> n)     //循环输入
	{
		string s1 = getFile(s, n);    //将输入转成一个字符串
		auto ret = m.insert(make_pair(s1, 1));    //所有数据插入map中
		if (!ret.second)         //如果字符串已经存在则计数加一
			ret.first->second += 1;
		if (m.size()>8)    //如果map的有效个数大于8，则删除最后一个插入的数据并跳出循环
		{
			m.erase(s1);  
			break;
		}
	}
	for (auto &e : m)     //输出map中数据
		cout << e.first << " " << e.second << " ";
	system("pause");
	return 0;
}