#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	char firstUniqChar(string &str) {
		vector<char> v;
		for (int i = 0; i<str.size(); i++)
		{
			/*string str1 = str;
			str1.erase(str1.begin() + i);
			if (str1.find(str[i])==-1)
				return str[i];*/
			if (find(v.begin(), v.end(), str[i]) == v.end())
			{
				if (find(str.begin() + 1 + i, str.end(), str[i]) != str.end())  //不用vector的话有bug，对于aab会输出a
					v.push_back(str[i]);
				else
					return str[i];
			}	
		}
	}
};

int main()
{
	Solution s;
	string str;
	cin >> str;
	cout<<s.firstUniqChar(str) << endl;
	system("pause");
	return 0;
}