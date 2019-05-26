#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
bool HuiWen(const string &s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin<end)
	{
		if (s[begin] != s[end])
			return false;
		++begin;
		++end;
	}
	return true;
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	size_t count = 0;
	for (size_t i = 0; i<s1.size(); ++i)
	{
		string s = s1;
		s.insert(i, s2);
		if (HuiWen(s))
			++count;
	}
	cout << count << endl;
	system("pause");
	return 0;
}