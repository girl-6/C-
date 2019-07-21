#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		int min = A[0]<A[n - 1] ? A[0] : A[n - 1];
		sort(A.begin(), A.end());
		int max = A[n - 1];
		return max - min;


	}
};

int main()
{
	MaxGap mg;
	int n;
	vector<int> v;
	cin >> n;
	int m = n;
	while (n--)
	{
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	int max=mg.findMaxGap(v, m);
	cout << max << endl;
	system("pause");
	return 0;
}