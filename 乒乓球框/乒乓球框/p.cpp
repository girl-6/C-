#include <iostream>
#include <string>
using namespace std;

string IsContain(string s1,string s2)
{
	int j = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		int pos = s1.find(s2[i], j);  //��s1����s2���ַ�
		if (pos < s1.size())    //�ҵ���ɾ��
			s1.erase(pos, 1);
		else                //�Ҳ����ͷ��� "No"
			return "No";
	}
	return "Yes";
}


int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
		cout << IsContain(s1, s2) << endl;
	return 0;
}