#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int index[256] = { 0 };
//		for (int i = 0; i<256; i++)
//		{
//			index[i] = -1;
//		}
//		int maxl = 0;
//		int ret = 0;
//		for (int i = 0; i<s.size(); i++)
//		{
//			if (i - ret <= index[s[i]])
//				ret = i - index[s[i]];
//			else
//				ret++;
//			index[s[i]] = i;
//			cout <<ret <<" "<<index[s[i]] << endl;
//			maxl = max(ret, maxl);
//		}
//		return maxl;
//	}
//};


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;
		int len = 0;
		string ret;
		ret.push_back(s[0]);
		for (int i = 1; i<s.size(); i++)
		{
			int pos = ret.find(s[i]);
			ret.push_back(s[i]);
			if (pos != -1)
			{
				len = ret.size() - 1>len ? ret.size() - 1 : len;
				ret.erase(ret.begin(), ret.begin() + pos + 1);
			}
		}
		len = ret.size()>len ? ret.size() : len;
		return len;
	}
};
int main()
{
	string s;
	Solution so;
	while (cin >> s)
		cout<<so.lengthOfLongestSubstring(s)<<endl;
	system("pause");
	return 0;
}