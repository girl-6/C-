#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

//strlen �� sizeof
void Test1()
{
	char p[] = "hello";
	cout << "p: " << p << "   " << strlen(p) << "   " << sizeof(p) << endl;
	char p1[] = "hello\0";
	cout << "p1: " << p1 << "   " << strlen(p1) << "   " << sizeof(p1) << endl;
	char p2[] = "hello\\0";
	cout << "p2: " << p2 << "   " << strlen(p2) << "   " << sizeof(p2) << endl;
	char p3[] = "hello\\\0";
	cout << "p3: " << p3 << "   " << strlen(p3) << "   " << sizeof(p3) << endl;
	char p4[] = "hel\0lo";
	cout << "p4: " << p4 << "   " << strlen(p4) << "   " << sizeof(p4) << endl;
	char p5[] = "hel\\0lo";
	cout << "p5: " << p5 << "   " << strlen(p5) << "   " << sizeof(p5) << endl;
}

//C�����е��ڴ����ʽ
void Test2()
{
	int *p1 = (int*)malloc(sizeof(int));
	free(p1);
	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int*)* 10);
	//free(p2);    // ����free��p2������Ϊp3��һ��free
	free(p3);
}

//C++ ���ڴ����ʽ
void Test3()
{
	//��̬����һ��int�͵Ŀռ�
	int* p1 = new int;
	//��̬����һ��int�͵Ŀռ䲢��ʼ��Ϊ10
	int* p2 = new int(10);
	//��̬����3��int�Ϳռ�
	int* p3 = new int[3];
	delete p1;
	delete p2;
	delete[] p3;
}

class Test
{
public:
	Test() :_data(0)
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
private:
	int _data;
};
void Test4()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free (p1);
	cout << "������new��delete" << endl;
	Test* p2 = new Test;
	delete p2;
	Test* p3 = new Test[4];
	delete[] p3;
}

int main()
{
	Test1();
	//Test2();
	//Test3();
	//Test4();
	system("pause");
	return 0;
}
