#include <iostream>
#include <string>

using namespace  std;

int Number(string s1, string s2)
{
	int number = 0;
	size_t i = 0;
	while (i<s1.size())
	{
		size_t pos = 0;
		pos = s1.find(s2, i);
		if (pos != -1)
		{
			number++;
			i = pos + s2.size();
		}
		else
			break;
	}
	return number;
}

//
//int Number(string s1, string s2)
//{
//	int n = 0;
//	for (int i = 0; i<s1.size(); i++)
//	{
//		if (s1[i] == s2[0])
//		{
//			int k = i + 1;
//			int j = 1;
//			for(j = 1; j<s2.size(); j++)
//			{
//				if (s1[k] == s2[j])
//				k++;
//				else
//					break;
//			}
//			if (j = s2.size())
//				n++;
//		}
//	}
//	return n;
//}

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int n = Number(s, t);
		cout << n << endl;
	}
	return 0;
}