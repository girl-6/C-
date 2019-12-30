#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return{};
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		res.push_back(intervals[0]);
		for (int i = 1; i<intervals.size(); ++i){
			if (res.back()[1] >= intervals[i][0]){
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
			else{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> vv;
	Solution so;
	vector < vector<int>> result;
	result=so.merge(vv);

	system("pause");
	return 0;
}