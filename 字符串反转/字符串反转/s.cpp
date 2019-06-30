#include <iostream>
#include <string>
using namespace std;

//string Reverse(string s)
//{
//	for (int i = 0; i < s.size() / 2; i++)
//		swap(s[i], s[s.size() - 1 - i]);
//	return s;
//}
//
//int main()
//{
//	string s;
//	while (cin >> s)
//		cout << Reverse(s) << endl;
//	system("pause");
//	return 0;
//}


#include<algorithm>
int main()
{
	string s;
	while (cin >> s)
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	system("pause");
	return 0;
}