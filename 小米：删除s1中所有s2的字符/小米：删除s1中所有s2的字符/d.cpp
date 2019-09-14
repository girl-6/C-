#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string s, s1, s2;
	cin >> s1 >> s2;
	map<char, int> m;
	for (auto &e : s2)
		m[e]++;
	for (auto &e : s1)
	{
		if (m.find(e) == m.end())
			s += e;
	}
	cout << s << endl;
	system("pause");
	return 0;
}

