#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int  IsCont(char a, int i, string s)
{
	int pos = s.find(a, i);
	if (pos < s.size())
		return pos;
	else
		return -1;
}
int Length(string s1, string s2)   //abtre  abret  正确答案4 计算3 
{
	if (s2.size()<s1.size())
		swap(s1, s2);
	int i = 0;
	int count = 0;
	while (i < s1.size())
	{
		int j = s2.find(s1[i], 0);
		if (j != -1)
		{
			int ret = 1;
			for (int m = i+1; m < s1.size(); m++)
			{
				if ((j + 1) == s2.size())
					break;
				int p1 = IsCont(s1[m], j+1, s2);
				if (p1 != -1)
				{
					++ret;
					j = p1;
				}				
			}
			count = ret>count ? ret : count;
		}
			i++;
	}
	return count;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << Length(s1, s2) << endl;
	return 0;
}