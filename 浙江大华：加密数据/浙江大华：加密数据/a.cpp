//ÿ3��������λһ�飬�á�ABCDabcd�����м���

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string PassWd(string s)
{
	string R = "ABCDabcd";
	vector<int> v;
	string ret;
	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] & 255;   //��8λ������λȫ1�������� ������ȿ��Եõ��˸�bitλ
		while (n != 0)
		{
			int a = n & 1;
			v.push_back(a);     //�����еĶ�����λȡ�������η���vector��
			n = n >> 1;
		}
	}
	if ((v.size() % 3) != 0)   //�����ж����Ƶ��ܸ�����3�������������ں��油0
	{
		for (int i = 0; i < 3 - v.size() % 3; i++)
			v.push_back(0);
	}
	for (int i = 0; i < v.size(); i += 3)    //��ǰ���ÿ3��������һ����м���
	{
		int sum = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
		ret.push_back(R[sum]);        //���м�������������
	}
	return  ret;
}
	int main()
	{
		string s;
		cin >> s;
		cout << PassWd(s) << endl;
		return 0;
	}