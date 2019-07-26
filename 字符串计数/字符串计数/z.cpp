#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int Count(string s1, string s2, int l1, int l2)
{
	int num = 0;
	//char bb = 96;   //a的ASCII 码值是97
	//if (s1.length() < l2)
	//	s1.append(l2 - s1.size(), bb);
	//if (s2.length() < l2)
	//	s2.append(l2 - s2.size(), bb);
	for (int i = l1; i <= l2; i++)   //长度的控制
	for (int j = 0; j<i; j++)    //字符的控制
		num = num + (s2[j] - s1[j])*pow(26, i - j - 1);
	return num - 1;
}


int main()
{
	string s1,s2;
	int l1,l2;
	while (cin >> s1>>s2>>l1>>l2)
	{
		cout << Count(s1,s2, l1, l2) << endl;
	}
	system("pause");
	return 0;
}