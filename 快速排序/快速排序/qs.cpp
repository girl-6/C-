#include <iostream>
#include <vector>
using namespace std;

//int PartSort(vector<int> &v,int left,int right)
//{
//	int key = left;
//	while (left<right)
//	{
//		while (left<right&&v[right] >= v[key])
//			right--;
//		while (left<right&&v[left] <= v[key])
//			left++;
//		swap(v[left], v[right]);
//	}
//	swap(v[left], v[key]);
//	return left;
//}
//void QuickSort(vector<int>& v,int left,int right)
//{
//	if (left>right)
//		return ;
//	int i = PartSort(v, left, right);
//	QuickSort(v, left, i-1);
//	QuickSort(v, i+1, right);
//}

void quickSort(vector<int> &num, int l, int r) {
	if (l >= r)     //�ȼ����������
		return;
	int i = l, j = r, x = num[l];
	while (i < j) {
		while (i < j && num[j] >= x)//���������ҵ���һ��С��x��
			j--;
		if (i < j)
			num[i++] = num[j];//���֮��i++
		while (i < j && num[i] <= x)//���������ҵ�һ������x����
			i++;
		if (i < j)
			num[j--] = num[i];
	}
	num[i] = x;     //���ʼȡ������x�ŵ�i��
	quickSort(num, l, i - 1);//��iΪ�м�ֵ�������������ֵݹ����
	quickSort(num, i + 1, r);
}


int main()
{
	vector<int> v = {1,3,6,4,5,8,2};
	quickSort(v,0,v.size()-1);
	for (auto &e : v)
		cout <<e<< " ";
	system("pause");
	return 0;
}