#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool UpData(string s1, string s2)
{
	vector<string> v1;
	vector<string> v2;
	string a = "";
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != '.')
			a += s1[i];
		else
		{
			v1.push_back(a);
			a = "";
		}
	}
	v1.push_back(a);
	a = "";
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] != '.')
			a += s2[i];
		else
		{
			v2.push_back(a);
			a = "";
		}
	}
	v2.push_back(a);
	int a1 = v1.size();
	int a2 = v2.size();
	if (a1 < a2)
	{
		for (int j = 1; j <= a2-a1 ; j++)
			v1.push_back("0");
	}
	if (a2 <a1)
	{
		for (int j = 0; j <a1-a2; j++)
			v2.push_back("0");
	}

	int len = v1.size();
	for (int i = 0; i < len; i++)
	{
		if (v1[i].size()>v2[i].size())
			return false;
		else if (v1[i].size() < v2[i].size())
			return true;
		else
		{
			for (int j = 0; j < v1[i].size();j++)
			if (v1[i][j] > v2[i][j])
				return false;	
		}
	}
	return true;
}
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i<m; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (UpData(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}