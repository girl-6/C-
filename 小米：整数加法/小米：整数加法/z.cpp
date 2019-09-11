#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i<100; i++)
		v.push_back(i + 1);
	int n = 0;
	while (cin >> n)
	{
		int sum = 0;
		int i = 0;
		for (; i < 100; i++)
		{
			sum += v[i];
			if (sum == n)
				break;
		}
		if (i<100)
			cout << (i + 1) << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}