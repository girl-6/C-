#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//�������پֲ�
//#include <algorithm>
//int main()
//{
//	string s;
//	getline(cin, s);
//	reverse(s.begin(), s.end());
//	string::iterator start = s.begin();
//	while (start != s.end())
//	{
//		string::iterator end = start;
//		while (end!=s.end()&&*end != ' ')
//			end++;
//		reverse(start, end);
//		if (end != s.end())
//			start = end + 1;
//		else
//			start = end;
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}


//����cin �ָ������ַ���
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2;
//	system("pause");
//	return 0;
//}


//vector�洢����
#include <vector>
int main()
{
	string s;
	getline(cin, s);
	vector<string> v;
	
	int start = 0;
	int pos = 0;
	do
	{
		pos = s.find(' ', start);
		string s1 = s.substr(start, pos - start);
		v.push_back(s1);
		start = pos + 1;
	} while (pos < s.size());
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i]<<" ";
	//vector<string>::reverse_iterator it = v.rbegin();
	//while (it != v.rend())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	system("pause");
	return 0;
}

