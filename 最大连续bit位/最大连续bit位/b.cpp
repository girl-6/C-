#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int s = 0;
		int count = 0;
		while (n)
		{
			if (n & 1 == 1)
			{
				++s;
				count = s>count ? s : count;
			}
			else
				s = 0;
			n = n >> 1;
		}
		cout << count << endl;
	}
	return 0;
}