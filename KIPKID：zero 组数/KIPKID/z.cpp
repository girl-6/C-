//#include <iostream>
//
//using namespace std;
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n = n >> 1;
//	}
//	cout << count << endl;
//	return 0;
//}


# include <iostream>
# include <vector>
# include <map>
using namespace std;

int Count(vector<int> v)
{
	vector<vector<int>> vv;
	for (int i = 0; i<v.size(); i++)
	for (int j = i + 1; j<v.size(); j++)
	{
		if (v[j] == -v[i])
		{
			vector<int> ret;
			int a = v[i]>=0? v[i] : v[j];
			int b = -a;
			ret.push_back(a);
			ret.push_back(b);
			vv.push_back(ret);
			v[j] = v[i];
			break;
		}
	}
	return vv.size();
}

int main()
{
	while (1)
	{
		vector<int> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a = 0;
			cin >> a;
			v.push_back(a);
		}

		cout << Count(v) << endl;
	}
	system("pause");
	return 0;
}