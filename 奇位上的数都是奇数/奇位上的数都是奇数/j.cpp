#include<iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		int i = 1;
//		int j = 0;
//		while (i<len)
//		{
//			if (arr[i] % 2 == 0)
//			{
//				for (; j<len; j += 2)
//				{
//					if (arr[j] % 2 != 0)
//					{
//						swap(arr[i], arr[j]);
//						break;
//					}
//				}
//			}
//			i += 2;
//		}
//	}
//};

//class Solution {
//public:
//	void oddInOddEvenInEven(vector<int>& arr, int len) {  
//		int j = 1;
//		for (int i = 0; i<arr.size(); i += 2)   //�ж�ż��λ����ż��
//			if (arr[i] % 2 != 0)     //��ż��λ����ż��
//				for (; j<arr.size(); j+=2)    //����λ�ҳ�ż��
//					if (arr[j] % 2 == 0)
//					{
//						swap(arr[i], arr[j]);    //�������ߵ�ֵ
//						break;
//					}
//	}
//};



class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0;
		int j = 1;
		while (i < len && j < len)
		{
			while (i < len && arr[i] % 2 == 0) i += 2;
			while (j < len && arr[j] % 2 == 1) j += 2;
			if (i < len && j < len)
				swap(arr[i], arr[j]);
		}
	}
};


int main()
{
	Solution s;
	vector <int>v;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	s.oddInOddEvenInEven(v, v.size());
	for (auto &e : v)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}