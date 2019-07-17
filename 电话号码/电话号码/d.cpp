# include <iostream>
#include <string>
#include <set>
using namespace std;

string AtoS(string s2,string s1)   //��������ַ���ת�ɱ�׼�ַ���
{
	string s = "";
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i]>='0'&&s2[i]<='9')   //����1-9 ֱ�ӷ����ַ���
			s.push_back(s2[i]);
		else if (s2[i] == '-')   //�ַ� '-' ����
			continue;
		else       //�ַ�A-Z ת������
		{
			char b = s1[s2[i] - 'A'];
				s.push_back(b);
		}
	}
	//���ַ����ָ��������֣���д�ɱ�׼��ʽ
	string ret1 = s.substr(0, 3);
	string ret2 = s.substr(3, 4);
	s = "";
	s += ret1;
	s.push_back('-');   
	s += ret2;
	return s;
}

int main()
{
	string s1 = "22233344455566677778889999";
	int n;
	while (cin >> n)
	{
		set <string> data;   //set ��ʵ�������ȥ��
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			string s = AtoS(a, s1);
			data.insert(s);
		}
		for (auto &e : data)
		{
			cout << e << endl;
		}
		cout << endl;
	}
	return 0;
}