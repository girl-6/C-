#include<vector>
#include <iostream>
using namespace std;

//在vector 中，按位挨着替换
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		vector<int> v1;
//		vector<int> v2;
//		int count = 0;
//		while (n)
//		{
//			v1.push_back(n & 1);
//			n = n >> 1;
//		}
//		while (m)
//		{
//			v2.push_back(m & 1);
//			m = m >> 1;
//		}
//		for (int a = 0; a<v2.size(); a++)
//		{
//			v1[j++] = v2[a];
//		}
//		for (int b = 0; b<v1.size(); b++)
//			count += v1[b] * pow(2, b);
//		return count;
//	}
//};


//直接让二进制位对齐再用或运算
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m = m << j;
		n = n | m;
		return n;
	}
};

int main()
{
	int n = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	cin >> n;
	cin >> m;
	cin >> i;
	cin >> j;
	BinInsert b;
	int a=b.binInsert(n, m, i, j);
	cout << a << endl;


	return 0;
}