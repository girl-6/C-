#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void Rep(string s, unordered_map<char, int>& m)
{
	string ret;
	ret.push_back(s[0]);
	for (size_t i = 1; i<s.size(); i++)
	{
		if (s[i] == ret[0])
			ret.push_back(s[i]);
		else{
			if (ret.size()>1)
			{
				for (auto &e : ret)
					m[e]++;
			}
			ret.clear();
			ret.push_back(s[i]);
		}
	}
	if (ret.size()>1)
	{
		for (auto &e : ret)
			m[e]++;
	}
}
int main()
{
	string s;
	cin >> s;
	unordered_map <char, int> um;
	Rep(s, um);
	vector <pair<char, int>> vt;
	for (auto it = um.begin(); it != um.end(); it++)    //将map中数据按value排序
		vt.push_back(make_pair(it->first, it->second));
	sort(vt.begin(), vt.end(), [](const pair<char, int> &x, const pair<char, int> &y)->int{return x.second > y.second; });
	for (auto it = vt.begin(); it != vt.end(); it++)
		cout << it->first << ":" << it->second << endl;
	cout << endl;
	system("pause");
	return 0;
}