//#include <iostream>
//#include <vector>
//using namespace std;
//
//int GetMax(int x, int y)
//{
//	return (x) > (y) ? (x) : (y);
//}
//int GetMaxArray(vector<int>& v)
//{
//	if (v.size() == 0)
//		return 0;
//	int sum = v[0];
//	int max = v[0];
//	for (int i = 1; i < v.size(); ++i)
//	{
//		sum = GetMax(sum + v[i], v[i]);
//		if (sum > max)
//			max = sum;
//	}
//	return max;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int max = GetMaxArray(v);
//	cout << max << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i<n; i++)
	{
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	int count = v[0];
	int s1 = 0;
	int s2 = v[0];
	for (int i = 0; i<n; i++)
	{
		s1 += v[i];
		if (s2<s1)
			s2 = s1;
		if (s1<0)
			s1 = 0;
		count = count>s2 ? count : s2;

	}
	cout << count;
	return 0;
}
