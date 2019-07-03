#include<iostream>
#include<vector>
using namespace std;

vector<int> XiPai(vector <int> v, int n)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i<n; i++)
		v1.push_back(v[i]);     //左手中的牌
	for (int i = n; i<2 * n; i++)
		v2.push_back(v[i]);      //右手中的牌
	for (int i = 0; i<n; i++)
	{
		v[i * 2] = v1[i];   //洗一次牌后左手牌的新位置
		v[i * 2 + 1] = v2[i];    //洗一次牌后右手牌的新位置
	}
	return v;
}

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)    //T组数据
	{
		vector<int> v;    
		cin >> n >> k;
		for (int i = 0; i<2 * n; i++)
		{
			int a = 0;
			cin >> a;
			v.push_back(a);    //用数组存储牌号
		}
		while (k--)     //洗k次牌
			v = XiPai(v, n);
		if (T != 0)       //带空格的组
		{
			for (auto &e : v)
				cout << e << " ";
		}
		else     //最后一组的最后一个数据直接数超出，不能加空格
		{
			for (int i = 0; i < (v.size() - 1); i++)  
				cout << v[i] << " ";
			cout << v[2 * n - 1];
		}
		cout << endl;   //每组数据后要换行
	}
	system("pause");
	return 0;
}