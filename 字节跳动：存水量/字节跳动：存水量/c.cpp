#include <iostream>
#include <vector>

using namespace std;
int Max(vector <int> v)
{
	int ret = 0;  //存水量
	int max = v[0];
	int a = 0;
	for (int i = 1; i<v.size(); i++)
	{
		if (v[i]>max)
		{
			max = v[i];
			a = i;
		}
	}

	if (a != v.size() - 1)
	{
		int mm = 0;  //记录左边目前最大值
		for (int i = 0; i<a; i++)
		{
			if (v[i]<mm)
				ret += mm - v[i];
			else
				mm = v[i];
		}
		mm = 0;
		for (int i = v.size() - 1; i>a; i--)
		{
			if (v[i]<mm)
				ret += mm - v[i];
			else
				mm = v[i];
		}
	}
	return ret;
}
int main() {
	vector <int> v{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	/*int a;
	while(cin>>a)
	v.push_back(a);
	*/
	cout << Max(v) << endl;
	return 0;
}