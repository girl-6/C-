#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

int add(int, int);

template<class T>
T Add(const T&a, const T&b);


//�������������һ����ʽʵ��������ʵ�ã�
template
int Add(const int&a, const int&b);

//ģ�����������������������Ͷ��岻����
//.hpp һ��ͱ�ʾ�����Ͷ������һ��
//template <class T>
//T Add(const T&a, const T&b)
//{
//	return a + b;
//}