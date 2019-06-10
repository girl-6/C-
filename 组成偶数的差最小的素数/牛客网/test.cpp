
#include <iostream>
#include <cmath>
using namespace std;

bool IsOnly(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int left = n / 2 ;
		int right = n - left;
		while (!IsOnly(left) || !IsOnly(right))
		{
			left--;
			right++;
		}
		cout << left << endl;
		cout << right << endl;
	}
	return 0;
}


//# include <iostream>
//#include <cmath>
//using namespace std;
//
//bool IsOnly(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int a = n / 2;
//		int b = 0;
//		while (a)
//		{
//			b = n - a;
//			if (IsOnly(a) && IsOnly(b))
//			{
//				break;
//			}
//			a--;
//		}
//		cout << a << endl;
//		cout << b << endl;
//	}
//	return 0;
//}


