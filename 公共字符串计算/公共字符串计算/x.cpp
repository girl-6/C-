//#include<iostream>
//#include<string>
//using namespace std;
//
//int Common(string s1, string s2)
//{
//	if (s1.size() > s2.size())    //取较短的串记为s1
//		swap(s1, s2);
//	int count = 0;      //最终返回的长度
//	for (int i = 0; i < s1.size(); i++)
//	{
//		int ret = 0;
//		int j = 0;
//		while (j<s2.size())
//		{
//			int m = i;
//			j = s2.find(s1[m], j);   //在s2中找s1的字母
//			while (s1[m]==s2[j]&& m<s1.size())   //如果找到，ret计数++，并继续查找
//			{
//				ret++;
//				m++; j++;
//			}
//			if (ret>count)   //比较ret 与count，取较大的值
//				count = ret;
//			ret = 0;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		for (int i = 0; i < s1.size(); i++)
//		{
//			if (s1[i] >= 'A'&&s1[i] <= 'Z')
//				s1[i] += 32;
//		}
//		for (int i = 0; i < s2.size(); i++)
//		{
//			if (s2[i] >= 'A'&&s2[i] <= 'Z')
//				s2[i] += 32;
//		}
//		int m = Common(s1, s2);
//		cout << m << endl;
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

int Common(string s1, string s2)
{
	if (s1.size() > s2.size())    //取较短的串记为s1
		swap(s1, s2);
	int count = 0;      //最终返回的长度
	for (int i = 0; i < s1.size(); i++)
	{
		int ret = 0;
		for (int j = 0; j<s2.size(); j++)
		{
			int m = i;
			int n = 0;   //用n 标记，是否进过while循环，否则j中间会被跳过去一个
			while (s1[m] == s2[j] && m<s1.size())
			{
				n = 1;
				ret++;
				m++; j++;
			}
			count = ret>count ? ret : count;
			if (n == 1)
				j--;
			ret = 0;
		}
	}
	return count;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int m = Common(s1, s2);
		cout << m << endl;
	}
	return 0;
}