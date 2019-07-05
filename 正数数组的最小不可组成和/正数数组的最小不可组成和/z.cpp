#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {

		if (len == 1)  return arr[0] + 1;
		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = arr[0];
		for (int i = 1; i<len; i++)
			max += arr[i];
		//int table[max - min + 2] = { 0 };
		int table[100001] = { 0 };
		for (int i = 0; i<len; i++)
		{
			int a = arr[i];
			table[a - min] = 1;
			for (int j = i + 1; j<len; j++)
			{
				a += arr[j];
				table[a - min] = 1;
			}
		}
		for (int i = 0; i<100001; i++)
		{
			if (table[i] == 0)
				return i + min;
		}
	}
};

int main()
{
	Solution s;
	vector<int > v;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	int su=s.getFirstUnFormedNum(v, v.size());
	cout << su << endl;
	system("pause");
	return 0;
}

