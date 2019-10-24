#include <iostream>
#include <vector>

using namespace std;

int maxCount(vector<int> v)
{
	int count = v[0];
	int max = v[0];
	int ret = max;
	for (int i = 1; i < v.size(); i++)
	{
		max += v[i];
		if (max>ret)
			ret = max;
		if (max < 0)
			max = 0;
		count = ret>count ? ret : count;
	}
	return count;
}
int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
	cout << maxCount(v) << endl;
	system("pause");
	return 0;
}