// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

bool Ignore(string s1, string s2)
{
	for (size_t i = 0; i<s1.size(); i++)
	{
		string t = "";
		if (s1[i] == '"')
		{
			i++;
			while (i<s1.size() && s1[i] != '"')
			{
				t += s1[i];
				i++;
			}
			if (t == s2)
				return true;
		}
		//else if (s1[i] != ',')
		else
		{
			while (i<s1.size() && s1[i] != ',')
			{
				t += s1[i];
				i++;
			}
			if (t == s2)
				return true;
		}
	}
	return false;
}

int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		if (Ignore(s1, s2))
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}