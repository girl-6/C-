#include <iostream>
#include <string>
using namespace std;
#include<math.h>

long Bin2Int(string a)
{
	int len = a.length();
	long res = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] == '1')
		{
			res += pow(2.0, i);
		}
	}
	return res;
}

string Int2Bin(long a)
{
	string res(1000, '0');
	string finres(1000, '0');
	long i = 0;
	while (a)
	{
		res[i++] = 48 + a % 2;
		a /= 2;
	}
	res[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
	{
		finres[i - j - 1] = res[j];
	}
	finres[i] = '\0';
	return finres;
}

class Solution {
public:
	string addBinary(string a, string b) {

		long aa = Bin2Int(a);
		long bb = Bin2Int(b);
		return Int2Bin(aa + bb);
	}
};