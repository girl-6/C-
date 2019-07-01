#include <iostream>
#include <math.h>

using namespace std;

int JumpFloor(int n)     //ÌøÌ¨½×
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n>2)
		return JumpFloor(n - 1) + JumpFloor(n - 2);
}

int JumpFloorII(int n)     //±äÌ¬ÌøÌ¨½×
{
	/*if (n == 1)
		return 1;
	if (n > 1)
		return 2 * JumpFloorII(n - 1);*/

	return pow(2, n - 1);
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int sum = JumpFloorII(n);
		cout << sum<<endl;
	}
	system("pause");
	return 0; 
}

