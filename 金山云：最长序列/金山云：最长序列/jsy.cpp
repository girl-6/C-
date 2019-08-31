#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. ������������еĳ���
//
//˼·������retΪ��ǰ�������еĳ��ȣ�maxΪ��ǰ���������������еĳ��ȡ�ÿ���ҵ��µĵ������оͽ�ret��max�Ƚϣ�ȡ�ϴ��ֵ����max��
//
//��󷵻ص�max��Ϊ����������������еĳ��ȡ�

int MaxLength(vector <int> v){
	int ret = 1;
	int max = 1;
	for (int i = 0; i<v.size() - 1; i++){
		if (v[i]<v[i + 1])
			ret++;
		else
		{
			max = ret>max ? ret : max;
			ret = 1;
		}
	}
	return max;
}



//2. �����������
//
//˼·�����ҵ����ȴ���1�����е��������ö�ά���鱣�棬����ÿ���������е����ֵΪ��׼�ں����ҵ�����Ҫ��ĵݼ����У���󷵻س���������С�
//�ҵ����ȴ���1�����е�������
vector<vector<int>> MaxA(vector<int> v)     
{
	vector<vector<int>> vv;
	vector<int> rv;
	rv.push_back(v[0]);
	for (int i = 1; i<v.size(); i++){
		if (v[i]>v[i - 1])
			rv.push_back(v[i]);
		else{
			if (rv.size()>1)
				vv.push_back(rv);
			rv.clear();
			rv.push_back(v[i]);
		}
	}
	return vv;
}

//��������Ҫ�������
vector<int> Create(vector<int> v)
{
	vector<vector <int>> vv = MaxA(v);
	vector<int> result(vv[0]);
	for (int i = 0; i<vv.size(); i++)
	{
		int max = vv[i][vv[i].size() - 1];
		auto poss =find (v.begin(), v.end(), max);    //�ҵ���ǰ�������е����ֵ��ԭ�����е�λ��
		int pos = distance(v.begin(), poss);    //�ҵ�Ԫ���±�
		cout << "pos " << pos << endl;
		for (int j = pos + 1; j<v.size(); j++)
		{
			if (v[j]<max){     //��maxΪ��׼�ĵݼ����в���������
				vv[i].push_back(v[j]);
				max = v[j];
			}
		}
		if (result.size()<vv[i].size())    //���µ�ǰ������е�����
			result = vv[i];
	}
	return result;
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << "length= " << MaxLength(v) << endl;
	vector <int> result=Create(v);
	cout << "result:  ";
	for (auto &e : result)
		cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}

