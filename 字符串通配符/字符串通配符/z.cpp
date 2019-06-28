#include <iostream>
#include <string>
using namespace std;

bool Compar(string &s1, string &s2)
{
	if (s2.empty())
		return false;
	for (int i = 0; i < s2.size(); i++)
	{
		if (s1[i] >= 'A'&&s1[i] <= 'Z')
			s1[i] += 32;
		if (s2[i] >= 'A'&&s2[i] <= 'Z')
			s2[i] += 32;

		if (s1[i] == s2[i] || s1[i] == '?')
			continue;

		else if (s1[i] == '*')
		{
			int j = i;
			while (j < s2.size())
			{
				if (s2[j] == '.')
					break;
				else
					j++;
			}
			if (j == s2.size())
				//return true;
				break;
			else
			{
				int k = i;
				while (k < s1.size())
				{
					if (s1[k] == '.')
						break;
					else
						k++;
				}
				if (k == s1.size())
					return false;
				else
				{
					s1 = s1.substr(k, s1.size() - k);
					s2 = s2.substr(j, s2.size() - j);
					Compar(s1, s2);
				}
			}
		}
		else
			return false;
	}
	return true;
}

int main()
{
	string s3;
	string s4;
	while (cin>>s3>>s4)
	/*getline(cin, s3);
	getline(cin, s4);*/
	cout << Compar(s3, s4) << endl;
	system("pause");
	return 0;
}