// write your code here cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	for (int i = 2; i<100000; i++)
	{
		v.push_back(0);
		v[i] = (v[i - 1] + v[i - 2]) % 1000000;   //保证输出六位数
	}
	int n = 0;
	while (cin >> n)
	{
		if (n<31)
			cout << v[n - 1] << endl;
		else
			cout << setw(6) << setfill('0') << v[n - 1] << endl;   //设置输出6位
	}
	return 0;
}