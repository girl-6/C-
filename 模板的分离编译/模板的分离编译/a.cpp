#define _CRT_SECURE_NO_WARNINGS 1
#include "a.h"

int add(int a, int b)
{
	return a + b;
}



//һ��������ʽʵ�������ڱ���ʱT�޷�����ȷ�����ͣ����Բ����ɶ�Ӧ������
template <class T>
T Add(const T&a, const T&b)
{
	return a + b;
}