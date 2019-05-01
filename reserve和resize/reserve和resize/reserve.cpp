#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> myV;
	//reserve
	myV.reserve(10);     
	//cout << myV[1]<<endl;      //运行错误。新元素还没有构造，无法用[]访问元素
	for (int i = 0; i < 10; i++)
	{
		myV.push_back(i);        //进行新元素构造
		cout << myV[i] << " ";  //此时才可以用[]访问
	}
	cout << endl;
	

	//resize():n值大于当前容器大小
	myV.resize(12);    //用元素的默认构造函数构造了两个新元素
	myV[11] = 11;       //直接通过[]操作myV[11] 
	for (int i = 0; i < 12;i++)
		cout << myV[i] << " ";      //直接通过[]访问myV[10]  
	cout << endl;

	//resize():n值小于当前容器大小
	myV.resize(9);      //直接删除末尾元素
	for (const auto &e : myV)     //用范围for遍历
		cout << myV[e] << " ";
	cout << endl;

	system("pause");
	return 0;
}