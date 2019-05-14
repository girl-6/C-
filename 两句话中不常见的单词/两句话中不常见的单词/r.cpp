#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	vector<string> uncommonFromSentences(string A, string B)
	{
		string s = A + ' ' + B;
		vector<string> v;
		int start = 0;
		int last = 0;
		string words;
		do
		{
			last = s.find(' ', start);
			words = s.substr(start, last - start);
			v.push_back(words);
			start = last + 1;
		} while (-1 != last);
		unordered_map<string, int> m;
		for (auto &e : v)
			m[e]++;
		vector<string> str;
		for (auto &e : m)
		{
			if (e.second == 1)
				str.push_back(e.first);
		}
		return str;
	}
};
int main()
{
	Solution s;
	string A = "i am apple";
	string B = "i am a";
	vector<string> v=s.uncommonFromSentences(A, B);
	for (auto &e : v)
		cout << e << endl;
	system("pause");
	return 0;
}