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
			s2 += s[i];    //������s2��
		}
		else      
		{
			if (s1.size() < s2.size())     //���Ĵ���s1��
				s1 = s2;
			else            //s2�̵Ļ�ֱ�����s2
				s2.clear();
		}
	}
	if (s1.size() == 0)   //ȫ�������
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
//		if (a >= 0 && a <= 9)  //�ҵ�����
//			v2.push_back(a);   //����v2��
//		else               //�����¸��ַ�
//		{
//			if (v1.size() < v2.size())   //v2�ϳ�����v1����
//				v1 = v2;
//			else     //v2�϶̣�ֱ�����
//				v2.clear();
//		}
//	}
//	if (v2.size()>v1.size())   //ȫ�������
//		v1 = v2;
//	for (const auto&e : v1)
//		cout << e;
//	system("pause");
//	return 0;
//}