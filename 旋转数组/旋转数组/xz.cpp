#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& v, int k) {
		if (v.size()<2)
			return;
		k %= v.size();
		reverse(v.begin(), v.begin() + v.size() - k);
		reverse(v.begin() + v.size() - k, v.end());
		reverse(v.begin(), v.end());

	}
};

int main()
{
	Solution s;
	vector <int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	s.rotate(v, 3);
	for (auto &e : v)
		cout << e<<" ";
	cout << endl;
	system("pause");
	return 0;
}