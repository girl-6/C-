#include <iostream>
#include <string>

using namespace  std;

int Number(string s1, string s2)
{
	int number = 0;
	size_t i = 0;
	while (i<s1.size())
	{
		size_t pos = 0;
		pos = s1.find(s2, i);
		if (pos != -1)   //若s1中找到了s2,则计数器加一，且继续从pos + s2.size()的位置开始查找
		{
			number++;
			i = pos + s2.size();
		}
		else
			break;   //若s1中没找到s2则直接跳出
	}
	return number;
}


//int Number(string s1, string s2)
//{
//	int n = 0;
//	for (int i = 0; i<s1.size(); i++)
//	{
//		if (s1[i] == s2[0])  //如果s1中找到s2的首元素
//		{
//			int k = i + 1;
//			int j = 1;
//			for(j = 1; j<s2.size(); j++)    //比较首元素之后的元素 
//			{
//				if (s1[k] == s2[j])    //若首元素之后的元素相同则继续比较 
//				k++;
//				else       //若不相同则直接跳出，继续在s1中寻找s2的首元素
//					break;
//			}
//			if (j = s2.size())  //若s1中有字符串与s2完全匹配，则计数加一，s1继续从（k-1）的位置查找
//			{
//				n++;
//				i = k - 1;
//			}
//
//		}
//	}
//	return n;
//}

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int n = Number(s, t);
		cout << n << endl;
	}
	return 0;
}