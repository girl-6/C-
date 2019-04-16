#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

int add(int, int);

template<class T>
T Add(const T&a, const T&b);


//分离编译解决方法一：显式实例化（不实用）
template
int Add(const int&a, const int&b);

//模板分离编译解决方法二：声明和定义不分离
//.hpp 一般就表示声明和定义放在一起
//template <class T>
//T Add(const T&a, const T&b)
//{
//	return a + b;
//}