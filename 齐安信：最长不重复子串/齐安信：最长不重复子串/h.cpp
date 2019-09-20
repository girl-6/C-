#include <iostream>
#include <vector>
#include <string>

using namespace std;


int max_length_substring(string s) {
	if (s.size() == 0)
		return 0;
	int len = 1;
	string ret;
	ret.push_back(s[0]);
	for (int i = 1; i<s.size(); i++)
	{
		int pos = ret.find(s[i]);
		if (pos == -1)
			ret.push_back(s[i]);
		else
		{
			len = ret.size()>len ? ret.size() : len;
			ret.erase(ret.begin(),ret.begin() + pos+1);
			ret.push_back(s[i]);
			cout << ret << endl;
		}
	}
	cout << ret << endl;
	len = ret.size()>len ? ret.size() : len;
	return len;
}


int main() {
	int res;

	string _s;
	getline(cin, _s);

	res = max_length_substring(_s);
	cout << res << endl;
	system("pause");
	return 0;

}