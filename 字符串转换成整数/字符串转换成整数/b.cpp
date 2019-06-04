//#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int s = 0;
		int s1 = 0;
		if (str[0] == '+' || str[0] == '-' || (str[0] >= '0'&&str[0] <= '9'))
		{
			int f = 1;
			if (str[0] >= '0'&&str[0] <= '9')
				s = (str[0] - '0')*pow(10, str.size() - 1);
			if (str[0] == '-')
				f = -1;
			for (int i = str.size() - 1; i>0; --i)
			{
				if (str[i] >= '0'&&str[i] <= '9')
					s += (str[i] - '0')*pow(10, s1++);
				else
					return 0;
			}
			return s*f;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	string str;
	cin >> str;
	int ret=s.StrToInt(str);
	cout << ret << endl;
	system("pause");
	return 0;
}
