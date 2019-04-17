#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
 

	/* find��key�� + iterator  insert(make_pair()) 
	ԭ��find��key���ɷ��ز���key ���������λ�ã�insert�ɲ���������Ĳο�λ��
������find����map �ں�key�ļ�ֵ��, ���ҵ���ֱ���޸ĸ�λ�õ�valueֵ����û���ҵ�����Ҫ������ο�λ����insert �����µļ�ֵ�ԣ�make_pair()��*/
void Test1()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto&e : strs)     //��������
	{
		map<string, int>::iterator it = countmap.find(e);
		if (it != countmap.end())     //��map���ҵ��ˣ���ֱ���޸�valueֵ
			it->second++;
		else                         //��map��û�ҵ����������λ��insert�����ֵ��
			countmap.insert(make_pair(e, 1));   
	}
	map<string, int>::iterator cit = countmap.begin();  //������ӡ
	while (cit != countmap.end())
	{
		cout<< cit->first << ":" << cit->second << endl;
		++cit;
	}
}

	/*pair <iterator,bool> insert��make_pair()��
	ԭ���˺����������жϲ���keyֵ�Ƿ�ɹ��������������bool��
�������ǲ���Ҫ��find �����жϣ�ֱ����bool�Ľ�����в�������bool==true ���������ɹ�����bool ==false ������Ѳ����һ��ֻ���޸�valueֵ����*/
void Test2()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		pair<map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e,1));    //bool==true�����ɹ�
		if (ret.second == false)       //�����key �ļ�ֵ���Ѿ����ڣ���ֻ�޸�value ��ֵ
			ret.first->second++;
	}
	map<string, int>::iterator cit = countmap.begin();        //������ӡ
	while (cit != countmap.end())      
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}

	/*operator[]
	ԭ��m[key] ��ֱ�ӷ���key ��Ӧ��valueֵ
������key��Ӧ��value ֵ�Ѿ��������޸ģ���δ���ھͻ��Զ�����*/
void Test3()
{
	string strs[] = { "a", "a", "f", "i", "c", "c", "b" };
	map<string, int> countmap;
	for (const auto&e : strs)
	{
		countmap[e]++;        //��������value�Ƿ񶼴���
	}
	map<string, int>::iterator cit = countmap.begin();       //������ӡ
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}