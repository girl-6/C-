#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;


//1. �������е����ݰ�������set�У�������ÿһ�β���ǰ��pre_size�Ͳ�����cur_size,
//��Ϊset�е�Ԫ�ز������ظ��������� `pre_size= = cur_size`����ǰ��ֵ��ΪҪ�ҵ�ֵ��
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

//2. ��һ�������ȡ���ô����������������ͬ�����������ڣ�
//��������ͬ�����±�һ�����2��Ҳ��ֻ�е�һ�����͵ڶ�����������Ҫ�ҵ�����
//����ͱض�����������ͬ�������ڲ���ȵ����Ρ�
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

//1.��ɸ���Ԫ�س��ִ�����ͳ�ƣ�Ȼ��Ƚ���`it->second == size() / 2`�����`it->first`��
class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int s = A.size() / 2;
		unordered_map <int, int> m;
		for (auto e : A)
			m[e]++;     //������������map��
		for (auto e : m)
		{
			if (e.second == s)    //���e�ĸ�����s�������
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

