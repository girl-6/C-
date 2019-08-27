#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Find(vector<vector<int>> v, int a,int &s)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == a)
			{
				s = i;
				return true;
			}
		}
	}
	return false;
}
int DouY(vector<vector<int>> vv)
{
	int s = 0;
	vector<vector<int>> v = { { 0 } };
	for (int i = 1; i < vv.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vv[i][j] >= 3)
			{
					if (Find(v, i, s))
						v[s].push_back(j);
					else if (Find(v, j, s))
						v[s].push_back(i);
					else
					{
						cout << "ÕÒ²»µ½" << endl;
						vector<int> v2;
						v2.push_back(i);
						v2.push_back(j);
						v.push_back(v2);
					}
			}
		}
	}
	int num = 0;
	int sum = v.size();
	for (int i = 0; i < v.size(); i++)
		num += v[i].size();
	if (num < vv.size())
		sum+= vv.size() - num;
	return sum;


}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> vv;
	for (int i = 0; i < n; i++)
	{
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			v.push_back(0);
			cin >> v[j];
		}
		vv.push_back(v);
	}
	cout << DouY(vv) << endl;
	system("pause");
	return 0;
}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int GYS(int a, int b)
//{
//	int x;
//	while ((x = a%b) != 0)
//	{
//		a = b;
//		b = x;
//	}
//	return b;
//}
//bool Find(vector<vector<int>> v, int a,int &s)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			if (GYS(v[i][j],a)>1)
//			{
//				s = i;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//int Tang(vector<int> v)
//{
//	int s = 0;
//	vector<vector<int>> vv = { { v[0] } };
//	for (int i = 1; i < v.size(); i++)
//	{
//
//		if (Find(vv, v[i], s))
//			vv[s].push_back(v[i]);
//		else
//		{
//			vector<int> v1;
//			v1.push_back(v[i]);
//			vv.push_back(v1);
//		}
//	}
//	int max = 1;
//	for (int i = 0; i < vv.size(); i++)
//		max = vv[i].size()>max ? vv[i].size() : max;
//	return max;
//}
//int main()
//{
//	vector<int> v;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		v.push_back(a);
//	}
//	cout << Tang(v) << endl;
//	system("pause");
//
//	return 0;
//}