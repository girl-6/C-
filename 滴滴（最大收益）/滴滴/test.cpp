#include <iostream>
#include <vector>

using namespace std;

int Max(vector <vector<int>> vv, int N, int M)
{
	int max = 0;

	for (int i = 0; i<M; i++)
	{
		int j = 0;
		int ret = vv[j][i];
		for (j = 1; j<N; j++)
		{
			if (vv[j][i]>ret)
				ret = vv[j][i];
		}
		max += ret;
	}
	return max;
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector <vector<int>> vv;
	for (int i = 0; i<N; i++)
	{
		vector<int> v;
		for (int j = 0; j<M; j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		vv.push_back(v);
	}
	cout << Max(vv, N, M) << endl;
	system("pause");
	return 0;
}