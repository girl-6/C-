#include <iostream>
#include <string>
#include <vector>
using namespace std;

string niXu(string s)
{
	vector <string> v;
	string s1 = "";
	for (int i = 0 ; i < s.size(); i++)
	{
			if (s[i] >= 'a'&&s[i] <= 'z' || s[i] >= 'A'&& s[i] <= 'Z')  //�ҵ�ÿ������
			{
				s1.push_back(s[i]);
			}
			else     //�ҵ��ָ���
			{
				if (s1.size()>0)    //��s1�д������ҵ����ַ���
				{
					v.push_back(s1);   //����vector��
					s1 = "";    //�ÿ�s1
				}
			}
	}
	if (s1.size()>0)      //�����һ���ַ����е��������vector��
		v.push_back(s1);
	string ret = "";
	for (int j = v.size()-1; j > 0; j--)    //��Ҫ���������vector
	{
		ret += v[j];
		ret.push_back(' ');
	}
	ret += v[0];
	return ret;
}

int main()
{
	string s;
	while(getline(cin, s))
		cout << niXu(s) << endl;
	return 0;
}