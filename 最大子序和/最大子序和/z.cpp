#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& v) {
		int ret = v[0];
		int sum = 0;
		for (int i = 0; i<v.size(); i++)
		{
			if (sum>0)
				sum += v[i];
			else
				sum = v[i];
			ret = sum>ret ? sum : ret;
		}
		return ret;
	}
};