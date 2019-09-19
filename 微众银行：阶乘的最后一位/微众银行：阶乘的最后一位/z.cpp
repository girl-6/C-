#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v;
	int sum = n;
	for (int i = n - 1; i>0; i--)
	{
		sum *= i;
		while (sum>1000000000)
		{
			int ret = sum / 1000000000;
			v.push_back(ret);
			sum %= 1000000000;
			if (sum == 0)
				sum = 1;
		}
	}
	v.push_back(sum);
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i]>0)
		{
			sum = v[i];
			break;
		}
	}
	int result = sum % 10;
	while (result == 0)
	{
		sum /= 10;
		result = sum % 10;
	}
	cout << result << endl;

	return 0;
}