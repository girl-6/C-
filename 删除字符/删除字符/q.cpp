#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;


//ɾ������Ų������
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (int i = 0; i < s2.size(); i++)
//	{
//		int j = 0;
//		while (s1[j] != NULL)
//		{
//			if (s1[j] == s2[i])
//			{
//				int k = j;
//				while (s1[k] != NULL)
//				{
//					s1[k] = s1[k + 1];
//					++k;
//				}
//			}
//			j++;
//		}
//	}
//	cout << s1 << endl;
//	system("pause");
//	return 0;
//}

//Ӧ�ù�ϣ��
int main()
{
	string s1, s2;
	getline(cin, s1);   //������cin���գ���Ϊcin�����ո�ͽ�����
	getline(cin, s2);
	int hashtable[256] = { 0 }; //ʹ�ù�ϣӳ��ͳ�Ƴ��ֵ��ַ�
	for (size_t i = 0; i < s2.size(); ++i)
		hashtable[s2[i]]++;
	//����s1,û�����ڹ�ϣ���е��ַ��������s��
	string s;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (hashtable[s1[i]] == 0)
			s += s1[i];
	}
	cout << s;
	system("pause");
	return 0;
}


