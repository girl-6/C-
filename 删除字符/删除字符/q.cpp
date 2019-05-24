#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;


//删除——挪动数据
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (int i = 0; i < s2.size(); i++)
//	{
//		int j = 0;
//		while (s1[j] != NULL)
//		{
//			if (s1[j] == s2[i])
//			{
//				int k = j;
//				while (s1[k] != NULL)
//				{
//					s1[k] = s1[k + 1];
//					++k;
//				}
//			}
//			j++;
//		}
//	}
//	cout << s1 << endl;
//	system("pause");
//	return 0;
//}

//应用哈希表
int main()
{
	string s1, s2;
	getline(cin, s1);   //不能用cin接收，因为cin遇到空格就结束了
	getline(cin, s2);
	int hashtable[256] = { 0 }; //使用哈希映射统计出现的字符
	for (size_t i = 0; i < s2.size(); ++i)
		hashtable[s2[i]]++;
	//遍历s1,没出现在哈希表中的字符都添加在s中
	string s;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (hashtable[s1[i]] == 0)
			s += s1[i];
	}
	cout << s;
	system("pause");
	return 0;
}


