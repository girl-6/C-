#include <iostream>
#include <string>
#define INT_MAX (pow(2,31)-1)
#define INT_MIN (-pow(2,31))
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		auto i = 0;     //str 的下标
		double s = 0;     //记录 int 整数
		string s1 = "";     //记录数字字符
		int f = 1;  //记录正负号

		//跳过空格
		while (i<str.size() && str[i] == ' ')
			i++;

		//保证正负号只出现一次
		/* int z=i;
		while(i<str.size()&&(str[i]=='+'||str[i]=='-'))
		{
		if(i==z&&str[i]=='-')    //i==z 标识第一次出现
		f=-1;
		else if(i==z&&str[i]=='+')
		f=1;
		else    //有连续符号出现
		return 0;
		i++;
		}*/
		if (i<str.size() && (str[i] == '+' || str[i] == '-'))   //第一次出现正负号
		{
			if (str[i] == '-')
				f = -1;
			i++;
		}
		if (i<str.size() && !(str[i] >= '0'&&str[i] <= '9'))    //正负号后不是数字
			return 0;

		//提取数字字符串
		while (i<str.size() && (str[i] >= '0'&&str[i] <= '9'))
		{
			s1 += str[i];
			i++;
		}

		// 字符串转整型
		if (s1 != "")
		{
			for (int j = 0; j<s1.size(); j++)
				s += (s1[j] - '0')*pow(10, s1.size() - 1 - j);
			s *= f;    //添加符号

			//判断是否溢出
			if (s>INT_MAX)
				return (INT_MAX);
			else if (s<INT_MIN)
				return (INT_MIN);
			else
				return s;
		}
		return 0;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution q;
	double n = q.myAtoi(s);
	cout << n << endl;
	system("pause");
	return 0;
}