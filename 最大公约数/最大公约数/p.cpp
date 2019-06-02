#include<iostream>
using namespace std;

//辗转相除法
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int a;
//	while ((a = n%m) != 0)
//	{
//		n = m;
//		m = a;
//	}
//	cout << m << endl;
//	return 0;
//}

//更相减损法
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	while (n != m)
//	{
//		if (n>m)n = n - m;
//		else m = m - n;
//	}
//	cout << m << endl;
//	return 0;
//}

//定义法
int main()
{
	int n, m;
	cin >> n >> m;
	int x = n<m ? n : m;
	int i;
	for (i = x; i >= 1; i--)
	{
		if (n%i == 0 && m%i == 0)break;
	}
	cout << i << endl;
	return 0;
}