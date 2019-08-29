#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	//直接遍历vector
	/*int singleNumber(vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A[A.size() - 1];
	for (int i = 0; i<A.size() - 1; i += 2)
	{
		if (A[i] != A[i + 1])
		{
			n = A[i];
			break;
		}
	}
	return n;
	}*/

	//Map 的应用
	int singleNumber(vector<int> &A) {
		map<int, int> m;
		for (auto &e : A)
			m[e]++;
		for (auto &e : m)
		{
			if (e.second == 1)
				return e.first;
		}
	}

	
};

int main()
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
	Solution s;
	cout<<s.singleNumber(v)<<endl;
	system("pause");
	return 0;
}