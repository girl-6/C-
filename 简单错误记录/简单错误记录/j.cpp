#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string iToS(int n)     //����ת�ַ���
{
	string s;
	int a = n % 10;
	s.push_back(a + '0');
	n /= 10;
	while (n)
	{
		a = n % 10;
		s.push_back(a + '0');
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;

}

string getFile(string s, int n)    //��ȡ�ļ�����ͬʱ�����������ַ�����
{
	string s1;
	int i = 0;
	int pos = s.find('\\', i);
	while (pos<s.size())     //�ҵ����һ��\����¼��ʱi
	{
		i = pos + 1;
		pos = s.find('\\', i);
	}
	for (i; i < s.size(); i++)      //��s1��¼�ļ���
		s1.push_back(s[i]);
	if (s1.size()>16)       //����ļ����ַ�����16��ֻȡ��16λ
		s1 = s1.substr(s1.size() - 16, 16);
	s1.push_back(' ');
	string s2 = iToS(n);
	s1 += s2;
	return s1;
}

int main()
{
	string s;
	int n;
	map<string, int> m;
	int k = 0;
	while (cin >> s >> n)     //ѭ������
	{
		string s1 = getFile(s, n);    //������ת��һ���ַ���
		auto ret = m.insert(make_pair(s1, 1));    //�������ݲ���map��
		if (!ret.second)         //����ַ����Ѿ������������һ
			ret.first->second += 1;
		if (m.size()>8)    //���map����Ч��������8����ɾ�����һ����������ݲ�����ѭ��
		{
			m.erase(s1);  
			break;
		}
	}
	for (auto &e : m)     //���map������
		cout << e.first << " " << e.second << " ";
	system("pause");
	return 0;
}