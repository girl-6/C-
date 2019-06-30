#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Distance(string s1, string s2)
{
	int d = 0;
	int j = 0;
	if (s1.size() - s2.size() >= 2)
		return -1;
	else{
		int j = 0;
		for (int i = 0; i<s1.size(); i++)
		{
			j = i;
			int j1 = j + 1;
			int i1 = i + 1;
			if (i < s2.size())
			{
				if (s1[i] == s2[j])
					continue;
				else if (s1[i1] == s2[j1])
					d++;
				else if (s1[i] == s2[j1])
					d++;
				else if (s1[i1] == s2[j])
					d++;
			}
			else if (i == s2.size())
				d++;
			else
				return -1;
		}
		return d;
	}
}
int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int n = Distance(s1, s2);
	cout << n << endl;
	system("pause");
	return 0;
}