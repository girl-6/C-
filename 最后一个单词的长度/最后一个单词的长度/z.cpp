#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int pos = s.find(' ');
		if (pos == -1)
			return s.size();
		int z = pos;
		int p = s.find(' ', pos + 1);
		while (p != -1)
		{
			if ((p - pos - 1) != 0)
				z = p - pos - 1;
			pos = p;
			p = s.find(' ', pos + 1);
		}
		if (pos != s.size() - 1)
			z = s.size() - pos - 1;
		return z;
	}
};
int main()
{
	string s;
	Solution so;
	while (getline(cin,s))
		cout << so.lengthOfLastWord(s) << endl;
	system("pause");
	return 0;
}