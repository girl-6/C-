# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int MinRoad(vector<vector<int>> vv)
{
	int l = 0;
	vector<int> v;
	for (int i = 2; i<vv.size(); i++)

		if (find(vv[1].begin(), vv[1].end(), vv[i][0]) != vv[1].end())
		{
			if (find(vv[1].begin(), vv[1].end(), vv[i][1]) != vv[1].end())
				v.push_back(vv[i][2]);
		}
	sort(v.begin(), v.end());
	for (int i = 0; i<vv[0][2] - 1; i++)
		l += v[i];
	return l;
}
int main()
{
	vector<vector<int>> vv;
	int N, M, R;
	vector<int> v;
	cin >> N >> M >> R;
	v.push_back(N);
	v.push_back(M);
	v.push_back(R);
	vv.push_back(v);
	v.clear();
	for (int i = 0; i<R; i++)
	{
		int r = 0;
		cin >> r;
		v.push_back(r);
	}
	vv.push_back(v);
	v.clear();
	for (int i = 0; i<M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		vv.push_back(v);
		v.clear();
	}
	cout << MinRoad(vv) << endl;
	return 0;
}
