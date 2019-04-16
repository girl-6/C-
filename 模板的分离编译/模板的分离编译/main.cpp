#define _CRT_SECURE_NO_WARNINGS 1
#include "a.h"


//模板声明定义分离
int main()
{
	cout << add(1, 2) << endl;    //若只声明未定义才会发生链接错误
	cout << Add(1, 2) << endl;   
	//一、发生错误原因：链接时才去call函数地址，但展开的.h中并没有生成可链接的汇编代码，解决方法显式实例化使函数产生可用地址
	//二、链接时不用去call函数地址，编译过程已经将此函数展开，可以直接使用
	system("pause");
	return 0;
}


//模板的特化
//template <class T>
//bool IsEqual(T&left, T& right)
//{
//	return left == right;
//}
//
////特化
//template<>
//bool IsEqual <char*>(char*& left, char* & right)   //必须两个char
//{
//	return (strcmp(left, right) == 0);
//}
//
//int main()
//{
//	int a = 1; int b = 2;
//	IsEqual(a, b);
//
//	//char* p1 = "hello";	char* p2 = "hello";   //此时相同，因为指向同一块地址
//	char* p1 = new char[6];
//	char* p2 = new char[6];
//	strcpy(p1, "hello");
//	strcpy(p2, "hello");
//	if (IsEqual(p1, p2))
//		cout << "相同" << endl;
//	else
//		cout << "不相同" << endl;
//
//	system("pause");
//	return 0;
//}
