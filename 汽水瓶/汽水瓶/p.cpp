#include <iostream>
using namespace std;


int Count(int n)
{
	int sum = 0;
	while (n >= 2)
	{
		if (n == 2)       //��ʱ��һƿ�������öһ���ֻ�ܽ�һ��
		{
			sum += 1;     //�ʿ��Զ�ȵ�һƿ 
			break;
		}
		int ret = n / 3;       //�����ÿ�ƿ�һ�������ˮ��
		sum += ret;      //�ܹ����Ժȵ�����ˮ��
		n = n % 3 + ret;     //�ȵ���ˮ�Ժ�ӵ�еĿ�ƿ��
	}
	return sum;    //������ˮ��
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Count(n) << endl;
	}
	return 0;
}
