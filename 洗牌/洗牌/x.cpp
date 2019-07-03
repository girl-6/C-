#include<iostream>
#include<vector>
using namespace std;

vector<int> XiPai(vector <int> v, int n)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i<n; i++)
		v1.push_back(v[i]);     //�����е���
	for (int i = n; i<2 * n; i++)
		v2.push_back(v[i]);      //�����е���
	for (int i = 0; i<n; i++)
	{
		v[i * 2] = v1[i];   //ϴһ���ƺ������Ƶ���λ��
		v[i * 2 + 1] = v2[i];    //ϴһ���ƺ������Ƶ���λ��
	}
	return v;
}

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)    //T������
	{
		vector<int> v;    
		cin >> n >> k;
		for (int i = 0; i<2 * n; i++)
		{
			int a = 0;
			cin >> a;
			v.push_back(a);    //������洢�ƺ�
		}
		while (k--)     //ϴk����
			v = XiPai(v, n);
		if (T != 0)       //���ո����
		{
			for (auto &e : v)
				cout << e << " ";
		}
		else     //���һ������һ������ֱ�������������ܼӿո�
		{
			for (int i = 0; i < (v.size() - 1); i++)  
				cout << v[i] << " ";
			cout << v[2 * n - 1];
		}
		cout << endl;   //ÿ�����ݺ�Ҫ����
	}
	system("pause");
	return 0;
}