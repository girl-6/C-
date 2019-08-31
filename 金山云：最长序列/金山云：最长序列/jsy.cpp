#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. 求最长递增子序列的长度
//
//思路：定义ret为当前递增序列的长度，max为当前数组中最大递增序列的长度。每次找到新的递增序列就将ret与max比较，取较大的值更新max。
//
//最后返回的max即为数组中最长递增子序列的长度。

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



//2. 创建最长子序列
//
//思路：先找到长度大于1的所有递增序列用二维数组保存，再以每个递增序列的最大值为标准在后面找到满足要求的递减序列，最后返回长度最长的序列。
//找到长度大于1的所有递增序列
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

//创建满足要求的序列
vector<int> Create(vector<int> v)
{
	vector<vector <int>> vv = MaxA(v);
	vector<int> result(vv[0]);
	for (int i = 0; i<vv.size(); i++)
	{
		int max = vv[i][vv[i].size() - 1];
		auto poss =find (v.begin(), v.end(), max);    //找到当前递增序列的最大值在原序列中的位置
		int pos = distance(v.begin(), poss);    //找到元素下标
		cout << "pos " << pos << endl;
		for (int j = pos + 1; j<v.size(); j++)
		{
			if (v[j]<max){     //以max为标准的递减序列插入数组中
				vv[i].push_back(v[j]);
				max = v[j];
			}
		}
		if (result.size()<vv[i].size())    //更新当前最长子序列的数组
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

