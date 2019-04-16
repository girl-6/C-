#define _CRT_SECURE_NO_WARNINGS 1
#include "a.h"

int add(int a, int b)
{
	return a + b;
}



//一、若不显式实例化则在编译时T无法生成确定类型，所以不生成对应汇编代码
template <class T>
T Add(const T&a, const T&b)
{
	return a + b;
}