#include <iostream>
#include <string>

using namespace std;


void getString(string s,string &result)
{
	int pos = s.find('[');
	if (pos == -1)
		return;
	int num = 0;
	result = s.substr(0, pos);
	for (int i = result.size() - 1; i >= 0; i--)
	{
		if (result[i] >= '0'&&result[i] <= '9')
			num += (result[i] - '0')* pow(10, (result.size() - 1 - i));
		else
		{
			result = result.substr(0, i + 1);
			break;
		}
	}
	string ret,rr;
	ret = s.substr(pos + 1, s.find(']') - pos -1);
	for (int i = 0; i < num; i++)
		result += ret;
}
int main()
{
	string s;
	string result;
	cin >> s;
	result = s;
	getString(s,result);
	cout << result << endl;
	system("pause");
	return 0;
}
