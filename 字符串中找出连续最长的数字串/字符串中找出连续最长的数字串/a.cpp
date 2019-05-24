#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string s1,s2;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			s2 += s[i];    //数字在s2中
		}
		else      
		{
			if (s1.size() < s2.size())     //长的存在s1中
				s1 = s2;
			else            //s2短的话直接清空s2
				s2.clear();
		}
	}
	if (s1.size() == 0)   //全数字情况
		s1 = s2;
	cout << s1;
	system("pause");
	return 0;
}

//#include<vector>
//int main()
//{
//	string s;
//	cin >> s;
//	vector <int> v1;
//	vector <int> v2;
//	for (int i = 0; i < s.length(); i++)
//	{
//		int a = s[i] - '0';
//		if (a >= 0 && a <= 9)  //找到数字
//			v2.push_back(a);   //放在v2里
//		else               //碰到下个字符
//		{
//			if (v1.size() < v2.size())   //v2较长，用v1保存
//				v1 = v2;
//			else     //v2较短，直接清空
//				v2.clear();
//		}
//	}
//	if (v2.size()>v1.size())   //全数字情况
//		v1 = v2;
//	for (const auto&e : v1)
//		cout << e;
//	system("pause");
//	return 0;
//}