#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, int> m;
	int count = 1;
	string s;
	cin >> s;
	for (auto &e : s)
		m[e]++;
	for (auto &e : m)
	{
		if (e.second>count)
			count = e.second;
	}
	cout << count << endl;
	system("pause");
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	map<int, int> m;
//	int N, M;
//	cin >> N>>M;
//	vector<int>v;
//	for (int i = 0; i<M; i++)
//	{
//		int a = 0;
//		cin >> a;
//		v.push_back(a);
//	}
//	sort(v.begin(), v.end());
//	int max = v[v.size() - 1];
//	int n = N - max;
//	for (int i = 1; i <= n; i++)
//		m[i]++;
//	for (int i = N; i > max; i--)
//		m[i]++;
//	for (auto &e : m)
//		cout << e.first << " "<<e.second<<endl;
//	cout << m.size() << endl;
//	system("pause");
//	return 0;
//}