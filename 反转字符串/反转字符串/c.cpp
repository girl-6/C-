#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void reverseString(vector<char>& s) {
		char temp = ' ';
		for (int i = 0; i < s.size() / 2; i++){
			temp = s[i];
			s[i] = s[s.size() - 1 - i];
			s[s.size() - 1 - i] = temp;
		}
	}
};