#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
		int i = 0;
		for (int j = m; j<v1.size(); j++)
			v1[j] = v2[i++];
		sort(v1.begin(), v1.end());
	}
};
int main()
{
	Solution s;
	vector <int> v1 = { 1, 2, 3, 0, 0, 0 };
	vector <int> v2 = { 2, 5, 6 };
	s.merge(v1, 3, v2, 3);
	for (auto &e : v1)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}
