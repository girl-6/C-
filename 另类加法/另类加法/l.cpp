
class UnusualAdd
{
public:
	int addAB(int A, int B)
	{
		int sum = 0, carry = 0;
		while (B != 0)
		{      
			sum = A^B;      //��Ӧλ�ĺ� 
			carry = (A&B)<<1;   //��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ     
			A = sum;
			B = carry;
		}  return sum;
	}
};