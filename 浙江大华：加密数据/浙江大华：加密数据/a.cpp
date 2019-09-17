//每3个二进制位一组，用“ABCDabcd”进行加密

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string PassWd(string s)
{
	string R = "ABCDabcd";
	vector<int> v;
	string ret;
	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] & 255;   //与8位二进制位全1的数进行 与运算既可以得到八个bit位
		while (n != 0)
		{
			int a = n & 1;
			v.push_back(a);     //将所有的二进制位取出并依次放在vector中
			n = n >> 1;
		}
	}
	if ((v.size() % 3) != 0)   //若所有二进制的总个数非3的整数倍，则在后面补0
	{
		for (int i = 0; i < 3 - v.size() % 3; i++)
			v.push_back(0);
	}
	for (int i = 0; i < v.size(); i += 3)    //从前向后，每3个二进制一组进行加密
	{
		int sum = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
		ret.push_back(R[sum]);        //所有加密组成最后密码
	}
	return  ret;
}
	int main()
	{
		string s;
		cin >> s;
		cout << PassWd(s) << endl;
		return 0;
	}