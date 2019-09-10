#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Max(vector<int> v)
{
	int max = 0;
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		int sum = 0;
		if (ret > v[i])
			ret = v[i];
		else
			max = (v[i] - ret) > max ? v[i] - ret : max;
	}
	return max;
}

int main()
{
	int n;
	vector<int> v;
	while (1)
	{
		for (int i = 0; i < 7; i++)
		{
			cin >> n;
			v.push_back(n);
		}
		cout << Max(v) << endl;
	}
	system("pause");
	return 0;
}