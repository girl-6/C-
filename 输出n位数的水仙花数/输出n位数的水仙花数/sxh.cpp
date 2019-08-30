#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	/**
	* @param n: The number of digits
	* @return: All narcissistic numbers with n digits
	*/
	
	/*bool isS(int i, int n)
	{
		int ii = i;
		double sum = 0;
		int a = i % 10;
		while (i /= 10)
		{
			sum += pow(a, n);
			a = i % 10;
		}
		sum += pow(a, n);
		if (sum == ii)
			return true;
		else
			return false;
	}*/
	bool isS(int i, int n)
	{
		int ret = i;
		int sum = 0;
		while (ret)
		{
			sum += pow(ret % 10, n);
			ret /= 10;
		}
		if (sum == i)
			return true;
		else
			return false;
	}

	vector<int> getNarcissisticNumbers(int n) {
		vector <int> v;
		if (n == 1)
			v.push_back(0);
		if (n == 2)
			return v;
		for (int i = pow(10, n - 1); i < pow(10, n); i++)
		{
			if (isS(i, n))
				v.push_back(i);
		}
		return v;
	}
};

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		Solution s;
		vector <int> v = s.getNarcissisticNumbers(n);
		for (auto &e : v)
			cout << e << " ";
		cout << endl;
	}
	return 0;
}