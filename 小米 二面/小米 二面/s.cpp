#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector <int> v;
	cin >> n;
	int flag=0;
	if (n < 0)
	{
		flag = -1;
		n *= flag;
	}
	v.push_back(n%10);
	n /= 10;
	while (n != 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}
	if (flag == -1)
		cout << '-';
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	system("pause");
	return 0;
}