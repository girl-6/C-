#include <iostream>
#include <string>
#include <vector>
using namespace std;

string niXu(string s)
{
	vector <string> v;
	string s1 = "";
	for (int i = 0 ; i < s.size(); i++)
	{
			if (s[i] >= 'a'&&s[i] <= 'z' || s[i] >= 'A'&& s[i] <= 'Z')  //找到每个单词
			{
				s1.push_back(s[i]);
			}
			else     //找到分隔符
			{
				if (s1.size()>0)    //若s1中存有已找到的字符串
				{
					v.push_back(s1);   //放在vector中
					s1 = "";    //置空s1
				}
			}
	}
	if (s1.size()>0)      //若最后一个字符串有单词则放入vector中
		v.push_back(s1);
	string ret = "";
	for (int j = v.size()-1; j > 0; j--)    //按要求逆序输出vector
	{
		ret += v[j];
		ret.push_back(' ');
	}
	ret += v[0];
	return ret;
}

int main()
{
	string s;
	while(getline(cin, s))
		cout << niXu(s) << endl;
	return 0;
}