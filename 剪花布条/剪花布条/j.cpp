#include <iostream>
#include <string>

using namespace  std;

int Number(string s1, string s2)
{
	int number = 0;
	size_t i = 0;
	while (i<s1.size())
	{
		size_t pos = 0;
		pos = s1.find(s2, i);
		if (pos != -1)   //��s1���ҵ���s2,���������һ���Ҽ�����pos + s2.size()��λ�ÿ�ʼ����
		{
			number++;
			i = pos + s2.size();
		}
		else
			break;   //��s1��û�ҵ�s2��ֱ������
	}
	return number;
}


//int Number(string s1, string s2)
//{
//	int n = 0;
//	for (int i = 0; i<s1.size(); i++)
//	{
//		if (s1[i] == s2[0])  //���s1���ҵ�s2����Ԫ��
//		{
//			int k = i + 1;
//			int j = 1;
//			for(j = 1; j<s2.size(); j++)    //�Ƚ���Ԫ��֮���Ԫ�� 
//			{
//				if (s1[k] == s2[j])    //����Ԫ��֮���Ԫ����ͬ������Ƚ� 
//				k++;
//				else       //������ͬ��ֱ��������������s1��Ѱ��s2����Ԫ��
//					break;
//			}
//			if (j = s2.size())  //��s1�����ַ�����s2��ȫƥ�䣬�������һ��s1�����ӣ�k-1����λ�ò���
//			{
//				n++;
//				i = k - 1;
//			}
//
//		}
//	}
//	return n;
//}

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int n = Number(s, t);
		cout << n << endl;
	}
	return 0;
}