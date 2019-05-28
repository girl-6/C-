#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<iostream>
#include <string>
#include<stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> s;
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] == '(')
				s.push(A[i]);
			else if (A[i] == ')')
			{
				if (s.empty() || s.top() != '(')
					return false;
				else
					s.pop();
			}
			else
				return false;
		}
		if (!s.empty())
			return false;
		return true;
	}
};

class Paren {
public:
	bool chkParenthesis(string A, int n) {
		int left = 0;
		int right = 0;
		int s = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '(')
			{
				++left;
				s = left;
			}
			else if (A[i] == ')')
			{
				++right;
				s = left - right;
				if (s < 0)
					return false;
			}
			else
				return false;
		}
		if (s != 0)
			return false;
		return true;
	}
};

int main()
{
	//Parenthesis p;
	Paren p;
	string A = "(((((";
	int n = 5;
	cout << p.chkParenthesis(A, n) << endl;

	system("pause");
	return 0;
}

