#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int GYS(int a, int b)    //求最大公约数
{
	int c = 0;
	while (c=a%b)
	{
		 a = b;
		 b = c;
	}
	return b;
}

string Itoa(int n)    //实现int 到 string的类型转换
{
	string s = "";
	int c = 0;
	while (c = n % 10)
	{
		char a = c + '0';
		s.push_back(a);
		n /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}
vector<int> SzhuanV(string s)  //将string 的字符串存放在vector中
{
	vector<int> v;
	int pos=s.find('/', 0);
	int a = 0;
	int b = 0;
	for (int i = 0; i <pos; i++)
		a += (s[i] - '0')*pow(10,(pos - 1 - i));
	for (int i = pos+1; i <s.size(); i++)
		b += (s[i] - '0')*pow(10,(s.size() - 1 - i));
	v.push_back(b);
	v.push_back(a);
	return v;
}

string VzhuanF(vector<int> v)    //将vector中的数据转化成分数形式
{
	string s = "";
	if (v[0] == 0)
		s = "Ifo";
	else if (v[1] == 0)
		s = "0";
	else
	{
		string a = Itoa(v[1] / v[0]);
		string b = Itoa(v[1] % v[0]);
		string c = Itoa(v[0]);
		char d = '/';
		char e = ' ';
		if (a != "0")
		{
			s += a;
			s.push_back(e);
		}
		if (b != "")
		{
			s += b;
			s.push_back(d);
			s += c;
		}
	}
	return s;
}

vector <int> Add(vector<int> v1, vector<int>v2)   //两个正有理数相加
{
	vector<int> v;
	if (v1[1] == 0)
		v = v2;
	else if (v2[1] == 0)
		v = v1;
	else
	{
		int a = v1[0] * v2[0];
		int b = v1[1] * v2[0] + v2[1] * v1[0];
		int c = GYS(a, b);
		v.push_back(a / c);
		v.push_back(b / c);
	}
	return v;
}

vector <int> Sub(vector<int> v1, vector<int>v2)   //结果为正的减法
{
	vector<int> v;
	if (v1[1] == 0)
		v = v2;
	else if (v2[1] == 0)
		v = v1;
	else
	{
		int a = v1[0] * v2[0];
		int b = v1[1] * v2[0] - v2[1] * v1[0];
		int c = GYS(a, b);
		v.push_back(a / c);
		v.push_back(b / c);
	}
	return v;
}

vector <int> Mul(vector<int> v1, vector<int>v2)   //两个正有理数的乘法
{
	vector<int> v;
	if (v1[1] == 0 || v2[1] == 0)
	{
		v.push_back(v1[0]);
		v.push_back(0);
	}
	else
	{
		int b = v1[1] * v2[1];
		int a = v1[0] * v2[0];
		int c = GYS(a, b);
		v.push_back(a / c);
		v.push_back(b / c);
	}
	return v;
}

vector <int> Dev(vector<int> v1, vector<int>v2)   //两个正有理数的除法
{
	vector<int> v;
	if (v1[1] == 0)
	{
		v.push_back(v1[0]);
		v.push_back(0);
	}
	else if (v2[1] == 0)
	{
		v.push_back(0);
	}
	else
	{
		int a = v1[0] * v2[1];
		int b = v1[1] * v2[0];
		int c = GYS(a, b);
		v.push_back(a / c);
		v.push_back(b / c);
	}
	return v;
}

int main()
{
	string s1,s2;
	while (cin>>s1>>s2)
	{
		vector<int> v1 = SzhuanV(s1);
		vector<int> v2 = SzhuanV(s2);

		vector <int> v_add = Add(v1, v2);
		string s_add = VzhuanF(v_add); 
		cout <<"加法的结果是："<< s_add << endl;

		vector <int> v_sub = Sub(v1, v2);
		string s_sub = VzhuanF(v_sub);
		cout << "减法的结果是：" << s_sub << endl;

		vector <int> v_mul = Mul(v1, v2);
		string s_mul = VzhuanF(v_mul);
		cout << "乘法的结果是：" << s_mul << endl;

		vector <int> v_dev = Dev(v1, v2);
		string s_dev = VzhuanF(v_dev);
		cout << "除法的结果是：" << s_dev << endl;
	}
	return 0;
}