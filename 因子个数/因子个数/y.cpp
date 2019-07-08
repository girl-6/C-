//// write your code here cpp
//#include <iostream>
//#include <vector>
////#include <cmath>
//using namespace std;
//
//bool IsSu(int n)   //ÅĞ¶ÏËØÊı
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//
//bool Same(int a, vector <int> v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == a)
//			return true;
//	}
//	return false;
//}
//
//int Number(int n)
//{
//	vector <int> v ;
//	for (int i = 2; i < n; i++)
//	{
//		if (n%i == 0&&IsSu(i))
//		{
//			if (!Same(i,v))
//				v.push_back(i);
//			n/=i;
//			//i--;
//		}
//		if (IsSu(n) && !Same(n, v))
//		{
//			v.push_back(n);
//			break;
//		}
//	}
//	return v.size();
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		cout << Number(n) << endl;
//	system("pause");
//	return 0;
//}


// write your code here cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int Number(int n)
{
	int sum = 0;
	for (int i = 2; i<sqrt(n); i++)
	{
		if (n%i == 0)
		{
			while (n%i == 0)
				n /= i;
			sum++;
		}
	}
	if (n>1) sum++;
	return sum;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << Number(n) << endl;
	return 0;
}