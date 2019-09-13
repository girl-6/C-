#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<string, int> m;
	int p = 0;
	int pos = s.find(',');
	while (p<s.size() && (pos - 1)<s.size())
	{
		if (s[pos - 1] == 'd' || s[pos - 1] == 'e')
		{
			string ret = s.substr(p, pos - p);
			m[ret]++;
		}
		p = pos + 1;
		pos = s.find(',', p);
	}
	cout << "{";
	auto it = m.begin();
	for (int i = 0; i < m.size() - 1; i++)
	{
		cout << it->first << "=" << it->second << ",";
		it++;
	}
	cout << it->first <<"="<< it->second << "}" << endl;
	system("pause");
	return 0;
}


