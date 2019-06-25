#include <iostream>
using namespace std;


int Count(int n)
{
	int sum = 0;
	while (n >= 2)
	{
		if (n == 2)       //此时借一瓶即可正好兑换，只能借一次
		{
			sum += 1;     //故可以多喝到一瓶 
			break;
		}
		int ret = n / 3;       //可以用空瓶兑换到的汽水数
		sum += ret;      //总共可以喝到的汽水数
		n = n % 3 + ret;     //喝掉汽水以后拥有的空瓶数
	}
	return sum;    //返回汽水数
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
	return 0;
}
