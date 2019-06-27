#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2;
	string s ="";
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
			swap(s1, s2);
		for (int i = 0; i < s1.size(); i++)
		{
			string ret = "";
			for (int j = 0; j < s2.size(); j++)
			{
				int k = i;
				int g = j;
				while (s1[k] == s2[g])
				{
					ret += s1[k];
					k++;
					g++;
				}
					if (ret.size()>s.size())
						s = ret;
					ret = "";
			}
		}
		cout << s << endl;
	}
	
	system("pause");
	return 0;
}