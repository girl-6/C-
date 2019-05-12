#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;


//1. 将数组中的数据挨个放在set中，记下在每一次插入前的pre_size和插入后的cur_size,
//因为set中的元素不允许重复，所以若 `pre_size= = cur_size`，则当前的值即为要找的值。
//class Solution {
//public:
//	int repeatedNTimes(vector<int>& A) {
//		set<int> s;
//		int i = 0;
//		for (; i<A.size(); i++){
//			int pre_size = s.size();
//			s.insert(A[i]);
//			int cur_size = s.size();
//			if (pre_size == cur_size)
//				break;
//		}
//		return A[i];
//	}
//};

//2. 有一半的数相等。那么在排列中若所有相同的数都不相邻，
//这两个相同数的下标一定相差2，也即只有第一个数和第二个数可能是要找的数，
//否则就必定存在两个相同的数相邻并相等的情形。
//class Solution {
//public:
//	int repeatedNTimes(vector<int>& A) {
//		int i = 0;
//		if (A[1] == A[3])
//			return A[1];
//		for (; i<A.size() - 1; i++)
//		{
//			if (A[i] == A[i + 1])
//				return A[i];
//		}
//		return A[0];
//	}
//};

//1.完成各个元素出现次数的统计，然后比较若`it->second == size() / 2`则输出`it->first`。
class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int s = A.size() / 2;
		unordered_map <int, int> m;
		for (auto e : A)
			m[e]++;     //将所有数存在map中
		for (auto e : m)
		{
			if (e.second == s)    //如果e的个数有s个则输出
				return e.first;
		}
		return 0;
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

