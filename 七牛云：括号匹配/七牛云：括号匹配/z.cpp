#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool IsT(string s)
{
	if (s.size() % 2 != 0)
		return false;
	else
	{
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '{' || s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (!st.empty() && s[i] == '}')
			{
				if (st.top() == '{')
					st.pop();
				else
					break;
			}	
			else if (!st.empty() && s[i] == ')')
			{
				if (st.top() == '(')
					st.pop();
				else
					break;
			}		
			else if (!st.empty() && s[i] == ']')
			{
				if (st.top() == '[')
					st.pop();
				else
					break;
			}	
		}
		if (st.empty())
			return true;
		else
			return false;
	}
}
int main()
{
	string s;
	cin >> s;
	cout << IsT(s) << endl;
	system("pause");
	return 0;
}