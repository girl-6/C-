#include <iostream>
#include <string>
#define INT_MAX (pow(2,31)-1)
#define INT_MIN (-pow(2,31))
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		auto i = 0;     //str ���±�
		double s = 0;     //��¼ int ����
		string s1 = "";     //��¼�����ַ�
		int f = 1;  //��¼������

		//�����ո�
		while (i<str.size() && str[i] == ' ')
			i++;

		//��֤������ֻ����һ��
		/* int z=i;
		while(i<str.size()&&(str[i]=='+'||str[i]=='-'))
		{
		if(i==z&&str[i]=='-')    //i==z ��ʶ��һ�γ���
		f=-1;
		else if(i==z&&str[i]=='+')
		f=1;
		else    //���������ų���
		return 0;
		i++;
		}*/
		if (i<str.size() && (str[i] == '+' || str[i] == '-'))   //��һ�γ���������
		{
			if (str[i] == '-')
				f = -1;
			i++;
		}
		if (i<str.size() && !(str[i] >= '0'&&str[i] <= '9'))    //�����ź�������
			return 0;

		//��ȡ�����ַ���
		while (i<str.size() && (str[i] >= '0'&&str[i] <= '9'))
		{
			s1 += str[i];
			i++;
		}

		// �ַ���ת����
		if (s1 != "")
		{
			for (int j = 0; j<s1.size(); j++)
				s += (s1[j] - '0')*pow(10, s1.size() - 1 - j);
			s *= f;    //��ӷ���

			//�ж��Ƿ����
			if (s>INT_MAX)
				return (INT_MAX);
			else if (s<INT_MIN)
				return (INT_MIN);
			else
				return s;
		}
		return 0;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution q;
	double n = q.myAtoi(s);
	cout << n << endl;
	system("pause");
	return 0;
}