# include <iostream>
#include <string>
#include <set>
using namespace std;

string AtoS(string s2,string s1)   //将输入的字符串转成标准字符串
{
	string s = "";
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i]>='0'&&s2[i]<='9')   //数字1-9 直接放入字符串
			s.push_back(s2[i]);
		else if (s2[i] == '-')   //字符 '-' 忽略
			continue;
		else       //字符A-Z 转成数字
		{
			char b = s1[s2[i] - 'A'];
				s.push_back(b);
		}
	}
	//将字符串分隔成两部分，再写成标准形式
	string ret1 = s.substr(0, 3);
	string ret2 = s.substr(3, 4);
	s = "";
	s += ret1;
	s.push_back('-');   
	s += ret2;
	return s;
}

int main()
{
	string s1 = "22233344455566677778889999";
	int n;
	while (cin >> n)
	{
		set <string> data;   //set 可实现排序和去重
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			string s = AtoS(a, s1);
			data.insert(s);
		}
		for (auto &e : data)
		{
			cout << e << endl;
		}
		cout << endl;
	}
	return 0;
}