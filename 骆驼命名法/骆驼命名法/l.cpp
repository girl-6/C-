#include <iostream>
#include <string>
using namespace std;

//string CtoJ(string s)   //C���ת����Java���
//{
//	string s1 = "";   //����һ���մ�
//	for (int i = 0; i < s.size(); i++)   //����ԭ��
//	{
//		if (s[i] == '_')    //�������»��ߣ���������һ���ĳɴ�д��ĸ
//			s[i+1] -= 32;
//		else            //����ֱ�ӽ��ַ������µ��ַ���
//		s1.push_back(s[i]);
//	}
//	return s1;    //�������ַ���
//}


string CtoJ(string s)   //C���ת����Java���
{
	string s1="";
	int i = 0;
	while (i < s.size())  
	{
		int pos = s.find('_', i);   //ÿ�δӵ�һ���ַ���ʼ�ҵ��»���
		if (pos <s.size())   //����ҵ�
		{
			s1 += s.substr(i, pos - i);   //���»��ߵ�ǰ�벿�ַ���s1��
			s[pos+1] -= 32;   //�»��ߵ���һ���ַ��ĳɴ�д
			s = s.substr(pos+1, s.size() -(pos+1));   //���»��ߵĺ�벿�ּ�������һ���»���
		}
		else     //���s��û���»�����ֱ�ӽ�s����s1�У�ѭ������
		{
			s1 += s;
			break;
		}
	}
	return s1;
}

int main()
{
	string s;
	while (cin >> s)
		cout << CtoJ(s) << endl;
	return 0;
}