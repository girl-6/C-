#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

		//C���Ե�����ת��
//void Test() 
//{
//	int i = 1;     // ��ʽ����ת��     
//	double d = i;    
//	printf("%d, %.2f\n" , i, d);
//
//	int* p = &i;     // ��ʾ��ǿ������ת��     
//	int address = (int) p;
//
//	printf("%x, %d\n", p, address);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}


		//C++��ǿ������ת��
		//1��static_cast
//int main()
//{
//	double d = 12.34;   
//	int a = static_cast<int>(d);   
//	cout << a << endl;    
//	system("pause");
//	return 0;
//}

		//reinterpret_cast
//typedef void(*FUNC)(); 
//int DoSomething(int i) 
//{
//	cout << "DoSomething" << endl;     
//	return 0; 
//}
//void Test() 
//{  
//	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����     
//	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������     
//	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��     
//	FUNC f = reinterpret_cast< FUNC>(DoSomething );     
//	f(); 
//}

		//const_cast
//void Test() 
//{
//	const int a = 2;     
//	int* p = const_cast< int*>(&a);     
//	*p = 3;
//	cout << a << endl;  //2
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}


		//dynamic_cast
class A 
{
public:
	virtual void f(){} 
};
class B : public A 
{};

void fun(A* pa) 
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�0   
	B* pb1 = static_cast<B*>(pa);   
	B* pb2 = dynamic_cast<B*>(pa);      
	cout<<"pb1:" <<pb1<< endl;   
	cout<<"pb2:" <<pb2<< endl; 
}
int main() 
{
	//pb1:006FFE20
    //pb2:00000000
    //pb1 : 006FFE14
    //pb2 : 006FFE14
	A a;    
	B b;    
	fun(&a);    
	fun(&b);     
	system("pause");
	return 0; 
}


		//explicit
//class A 
//{
//public:
//	explicit A(int a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& a)    
//	{
//		cout << "A(const A& a)" << endl; 
//	}
//private:
//	int _a;
//};
//int main() 
//{
//	A a1(1);
//	// �����ᷢ����ʽת��-> A tmp(1);	A a2(tmp);     
//	A a2 = 1; 
//} 
