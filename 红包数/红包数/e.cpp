#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		map<int, int > m;
		for (const auto&e : gifts)
			m[e]++;
		for (const auto&e : m)
		{
			if (e.second>n / 2)
				return e.first;
		}
		return 0;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	Gift g;
	int n=g.getValue(v, v.size());
	cout << n << endl;
	system("pause");
	return 0;
}