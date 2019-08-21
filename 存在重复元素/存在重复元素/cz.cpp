#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//≈≈–Ú
class Solution {
public:
	bool containsDuplicate(vector<int>& v) {
		if (v.size()<2)
			return false;
		sort(v.begin(), v.end());
		for (int i = 0; i<v.size() - 1; i++)
		{
			if (v[i] == v[i + 1])
				return true;
		}
		return false;
	}
};
////set
//#include <set>
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& v) {
//		set<int> s;
//		for (auto &e : v)
//			s.insert(e);
//		if (s.size() == v.size())
//			return false;
//		else
//			return true;
//	}
//};

int main()
{
	Solution s;
	vector<int> v = { 1, 2, 1 };
	bool b = s.containsDuplicate(v);
	cout << b << endl;
	system("pause");
	return 0;
}