#include <iostream>
#include <string>
using namespace std;

string Find(string s1, string s2)
{
	string s = "";
	for (size_t i = 0; i<s1.size(); i++)
	{
		string ret = "";
		for (size_t j = 0; j<s2.size(); j++)
		{
			size_t m = i;
			while (s1[m] == s2[j])
			{
				ret += s1[m];
				m++; j++;
			}
			if (ret.size()>s.size())
				s = ret;
			ret = "";
		}
	}
	return s;
}
int main()
{
	string a;
	string b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);
		string s = Find(a, b);
		cout << s << endl;
	}
	system("pause");
	return 0;
}