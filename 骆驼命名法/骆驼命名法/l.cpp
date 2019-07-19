#include <iostream>
#include <string>
using namespace std;

//string CtoJ(string s)   //C风格转化成Java风格
//{
//	string s1 = "";   //定义一个空串
//	for (int i = 0; i < s.size(); i++)   //遍历原串
//	{
//		if (s[i] == '_')    //若碰到下划线，则将它的下一个改成大写字母
//			s[i+1] -= 32;
//		else            //否则直接将字符放入新的字符串
//		s1.push_back(s[i]);
//	}
//	return s1;    //返回新字符串
//}


string CtoJ(string s)   //C风格转化成Java风格
{
	string s1="";
	int i = 0;
	while (i < s.size())  
	{
		int pos = s.find('_', i);   //每次从第一个字符开始找到下划线
		if (pos <s.size())   //如果找到
		{
			s1 += s.substr(i, pos - i);   //将下划线的前半部分放入s1中
			s[pos+1] -= 32;   //下划线的下一个字符改成大写
			s = s.substr(pos+1, s.size() -(pos+1));   //在下划线的后半部分继续找下一个下划线
		}
		else     //如果s中没有下划线则直接将s放入s1中，循环结束
		{
			s1 += s;
			break;
		}
	}
	return s1;
}

int main()
{
	string s;
	while (cin >> s)
		cout << CtoJ(s) << endl;
	return 0;
}