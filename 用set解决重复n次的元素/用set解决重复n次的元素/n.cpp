#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		set<int> s;
		int i = 0;
		for (; i<A.size(); i++){
			int pre_size = s.size();
			s.insert(A[i]);
			int cur_size = s.size();
			if (pre_size == cur_size)
				break;
		}
		return A[i];
	}
};
int main()
{
	Solution s ;
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(3);
	int ret = 0;
	ret = s.repeatedNTimes(A);
	cout << ret << endl;
	system("pause");
	return 0;
}

