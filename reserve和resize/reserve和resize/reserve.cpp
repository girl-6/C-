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
	//cout << myV[1]<<endl;      //���д�����Ԫ�ػ�û�й��죬�޷���[]����Ԫ��
	for (int i = 0; i < 10; i++)
	{
		myV.push_back(i);        //������Ԫ�ع���
		cout << myV[i] << " ";  //��ʱ�ſ�����[]����
	}
	cout << endl;
	

	//resize():nֵ���ڵ�ǰ������С
	myV.resize(12);    //��Ԫ�ص�Ĭ�Ϲ��캯��������������Ԫ��
	myV[11] = 11;       //ֱ��ͨ��[]����myV[11] 
	for (int i = 0; i < 12;i++)
		cout << myV[i] << " ";      //ֱ��ͨ��[]����myV[10]  
	cout << endl;

	//resize():nֵС�ڵ�ǰ������С
	myV.resize(9);      //ֱ��ɾ��ĩβԪ��
	for (const auto &e : myV)     //�÷�Χfor����
		cout << myV[e] << " ";
	cout << endl;

	system("pause");
	return 0;
}