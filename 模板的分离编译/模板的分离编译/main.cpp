#define _CRT_SECURE_NO_WARNINGS 1
#include "a.h"


//ģ�������������
int main()
{
	cout << add(1, 2) << endl;    //��ֻ����δ����Żᷢ�����Ӵ���
	cout << Add(1, 2) << endl;   
	//һ����������ԭ������ʱ��ȥcall������ַ����չ����.h�в�û�����ɿ����ӵĻ����룬���������ʽʵ����ʹ�����������õ�ַ
	//��������ʱ����ȥcall������ַ����������Ѿ����˺���չ��������ֱ��ʹ��
	system("pause");
	return 0;
}


//ģ����ػ�
//template <class T>
//bool IsEqual(T&left, T& right)
//{
//	return left == right;
//}
//
////�ػ�
//template<>
//bool IsEqual <char*>(char*& left, char* & right)   //��������char
//{
//	return (strcmp(left, right) == 0);
//}
//
//int main()
//{
//	int a = 1; int b = 2;
//	IsEqual(a, b);
//
//	//char* p1 = "hello";	char* p2 = "hello";   //��ʱ��ͬ����Ϊָ��ͬһ���ַ
//	char* p1 = new char[6];
//	char* p2 = new char[6];
//	strcpy(p1, "hello");
//	strcpy(p2, "hello");
//	if (IsEqual(p1, p2))
//		cout << "��ͬ" << endl;
//	else
//		cout << "����ͬ" << endl;
//
//	system("pause");
//	return 0;
//}
